//Copyright 2019, Jorge Calleros Ramirez (Karma), All rights reserved.

#include "SShelfButton.h"
#include "Widgets/Input/SButton.h"
#include "PythonEditorStyle.h"
#include "Widgets/Images/SImage.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "Framework/Application/SlateApplication.h"
#include "Engine.h"
#include "PythonShelfToolkit.h"
#include "PythonEditor.h"

THIRD_PARTY_INCLUDES_START
#include "Python.h"
#include "structmember.h"
THIRD_PARTY_INCLUDES_END

void SShelfButton::Construct(const FArguments& InArgs)
{
	ShelfButton = InArgs._ShelfButton;
	ShelfOwnerID = InArgs._ShelfOwnerID;

	const int32 IconSize = 40;

	FName ID = FName(*FGuid::NewGuid().ToString());
	if (ShelfButton->Icon.Num() > 10)
	{	
		if (FSlateApplication::IsInitialized() &&
			FSlateApplication::Get().GetRenderer()->GenerateDynamicImageResource(ID, IconSize, IconSize, ShelfButton->Icon))
		{
			DynamicBrushe = new FSlateDynamicImageBrush(
				ID,
				FVector2D(IconSize, IconSize),
				FLinearColor::White,
				ESlateBrushTileType::NoTile,
				ESlateBrushImageType::FullColor);
		}
		Style = new FButtonStyle();
		Style->Normal = *DynamicBrushe;
		Style->Hovered = *DynamicBrushe;
		Style->Pressed = *DynamicBrushe;
	}
	else
	{
		Style = const_cast<FButtonStyle*>(&FPythonEditorStyle::Get().GetWidgetStyle<FButtonStyle>("Shelf.ShelfButtonStyle"));
	}

	ChildSlot[
		SNew(SBox)
		.HeightOverride(IconSize)
		.WidthOverride(IconSize)
		[
			SAssignNew(Button, SButton)
			.ContentPadding(0)
			.ButtonStyle(Style)
			.OnClicked(FOnClicked::CreateRaw(this, &SShelfButton::ExecuteScript))
			[
				SNew(STextBlock)
				.Text(FText::FromString(ShelfButton->DisplayName))
				.ColorAndOpacity(FSlateColor(FLinearColor::White))
			]
		]
	];
}

SShelfButton::~SShelfButton()
{
	if (Style)
	{
		Style = NULL;
		delete Style;
	}

	if (DynamicBrushe)
	{
		DynamicBrushe = NULL;
		delete DynamicBrushe;
	}
}

FReply SShelfButton::ExecuteScript()
{
	const int32 Value = PyRun_SimpleString(TCHAR_TO_UTF8(*ShelfButton->Code));
	return (Value > 0) ? FReply::Handled() : FReply::Unhandled();
}

FReply SShelfButton::OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (IsEnabled() && (MouseEvent.GetEffectingButton() == EKeys::RightMouseButton || MouseEvent.IsTouchEvent()))
	{
		CreateContextMenu();
		Invalidate(EInvalidateWidget::Layout);
		return  FReply::Handled();
	}
	return FReply::Unhandled();
}

FReply SShelfButton::OnMouseButtonDoubleClick(const FGeometry& InMyGeometry, const FPointerEvent& InMouseEvent)
{
	UE_LOG(LogTemp, Log, TEXT("open custom menu"));
	return FReply::Unhandled();
}

void SShelfButton::SetIcon()
{
	FPythonShelfToolkit::Get()->SetButtonIcon(ShelfOwnerID, ShelfButton->ID);
}

void SShelfButton::CreateContextMenu()
{
	FMenuBuilder MenuBuilder(true, NULL);
	MenuBuilder.BeginSection("Main Options");
	{
		// 1st entry should be a label, name or whatever
		MenuBuilder.AddWidget(SNew(STextBlock).Text(FText::FromString("	Options...")), FText(), true);
		MenuBuilder.AddMenuSeparator();

		//Rename SIGLAS
		MenuBuilder.AddMenuEntry(FText::FromString("Rename"), FText(), FSlateIcon(), FUIAction(FExecuteAction::CreateRaw(this, &SShelfButton::Rename)));
		MenuBuilder.AddMenuSeparator();

		//Edit Script
		MenuBuilder.AddMenuEntry(FText::FromString("Edit"), FText(), FSlateIcon(), FUIAction(FExecuteAction::CreateRaw(this, &SShelfButton::Edit)));

		//Edit Script
		MenuBuilder.AddMenuEntry(FText::FromString("Set Icon"), FText(), FSlateIcon(), FUIAction(FExecuteAction::CreateRaw(this, &SShelfButton::SetIcon)));

		//Delete
		MenuBuilder.AddMenuEntry(FText::FromString("Delete"), FText(), FSlateIcon(), FUIAction(FExecuteAction::CreateRaw(this, &SShelfButton::Delete)));
		MenuBuilder.AddMenuSeparator();

		//Swap left
		MenuBuilder.AddMenuEntry(FText::FromString("Move Left"), FText(), FSlateIcon(), FUIAction(FExecuteAction::CreateRaw(this, &SShelfButton::MoveLeft)));

		//Swap Right
		MenuBuilder.AddMenuEntry(FText::FromString("Move Right"), FText(), FSlateIcon(), FUIAction(FExecuteAction::CreateRaw(this, &SShelfButton::MoveRight)));
	}
	MenuBuilder.EndSection();

	FPythonContextMenu::SpawnContextMenu(SharedThis(this), MenuBuilder);
}

void SShelfButton::Rename()
{
	FPythonContextMenu::InputMenu(
		SharedThis(this),
		FText::FromString(" Create New"),
		FText::FromString(ShelfButton->DisplayName),
		FOnInputReceived::CreateLambda([this](const FText& Name)
		{
			FPythonShelfToolkit::Get()->RenameButton(ShelfOwnerID, ShelfButton->ID, Name.ToString());
		}));
}

void SShelfButton::Edit()
{
	// To Do
}

void SShelfButton::Delete()
{
	FPythonContextMenu::ConfirmMenu(
		SharedThis(this),
		FText::FromString(" Are you sure?"),
		FOnConfirmReceived::CreateLambda([this](const bool& bConfirm)
		{
			if (bConfirm)
			{
				FPythonShelfToolkit::Get()->RemoveButtonFromShelf(ShelfOwnerID, ShelfButton->ID);
			}
		}));
}

void SShelfButton::MoveLeft()
{
	FPythonShelfToolkit::Get()->ShiftButtonLeft(ShelfOwnerID, ShelfButton->ID);
}

void SShelfButton::MoveRight()
{
	FPythonShelfToolkit::Get()->ShiftButtonRight(ShelfOwnerID, ShelfButton->ID);
}




//Copyright 2019, Jorge Calleros Ramirez (Karma), All rights reserved.

#include "SShelfTab.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/SOverlay.h"
#include "Widgets/Images/SImage.h"
#include "Widgets/Layout/SBox.h"
#include "PythonEditorStyle.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "Framework/Application/SlateApplication.h"
#include "Widgets/Input/SEditableTextBox.h"
#include "PythonShelfToolkit.h"
#include "PythonEditor.h"

void SShelfTab::Construct(const FArguments& InArgs)
{
	OnShelfTabSelected = InArgs._OnShelfTabSelected;
	ShelfName = InArgs._Label;

	bIsSelected = false;

	ChildSlot[
		SNew(SBox)
		.WidthOverride(100)
		.HeightOverride(20)
		[
			SNew(SOverlay)
			+ SOverlay::Slot()
			[
				SNew(SButton)
				.ButtonStyle(&FPythonEditorStyle::Get().GetWidgetStyle<FButtonStyle>("Shelf.ButtonStyle"))
				[
					SNew(STextBlock)
					.ColorAndOpacity(FSlateColor(FLinearColor::White))
					.Text(FText::FromName(ShelfName))
					.Justification(ETextJustify::Center)
				]
			]
			+ SOverlay::Slot()
			[
				SNew(SBox)
				.WidthOverride(20)
				.HeightOverride(5)
				[
					SAssignNew(Image, SImage)
					.Image(FPythonEditorStyle::Get().GetBrush("Shelf.selected"))
					.ColorAndOpacity(FSlateColor(NoneSelected))
				]
			]
		]
	];
}

FReply SShelfTab::OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (IsEnabled() && (MouseEvent.GetEffectingButton() == EKeys::RightMouseButton || MouseEvent.IsTouchEvent()))
	{
		CreateContextMenu();
		Invalidate(EInvalidateWidget::Layout);
		return  FReply::Handled();
	}

	
	if (IsEnabled() && (MouseEvent.GetEffectingButton() == EKeys::LeftMouseButton || MouseEvent.IsTouchEvent()))
	{
		SelectTab_Internal();
		Invalidate(EInvalidateWidget::Layout);
		return  FReply::Handled();
	}
	return FReply::Unhandled();
}

void SShelfTab::SelectTab_Internal()
{
	bIsSelected = true;
	Image->SetColorAndOpacity(Selected);
	OnShelfTabSelected.ExecuteIfBound(ShelfName);
}


void SShelfTab::ShelfTabSelected()
{

}

void SShelfTab::Rename()
{
	FPythonContextMenu::InputMenu(
		SharedThis(this),
		FText::FromString(" Rename shelf..."),
		FText::FromName(ShelfName),
		FOnInputReceived::CreateLambda([this](const FText& Name)
		{
			FPythonShelfToolkit::Get()->RenameShelf(ShelfName,FName(*Name.ToString()));
		}));
}

void SShelfTab::CreateNew()
{
	FPythonContextMenu::InputMenu(
		SharedThis(this),
		FText::FromString(" Create New"),
		FText::FromString(" New Shelf"),
		FOnInputReceived::CreateLambda([this](const FText& Name)
		{
			FPythonShelfToolkit::Get()->CreateShelf(FName(*Name.ToString()));
		}));
}

void SShelfTab::Delete()
{
	FPythonContextMenu::ConfirmMenu(
		SharedThis(this), 
		FText::FromString(" Are you sure?"),
		FOnConfirmReceived::CreateLambda([this](const bool& bConfirm)
		{
			if (bConfirm)
			{
				FPythonShelfToolkit::Get()->DeleteShelf(ShelfName);
			}
		}));
}

void SShelfTab::MoveLeft()
{
	FPythonShelfToolkit::Get()->ShiftShelfLeft(ShelfName);
}

void SShelfTab::MoveRight()
{
	FPythonShelfToolkit::Get()->ShiftShelfRight(ShelfName);
}

bool SShelfTab::IsSelected() const
{
	return bIsSelected;
}

FName SShelfTab::GetShelfName() const
{
	return ShelfName;
}

void SShelfTab::SelectTab(bool bSelected)
{
	bIsSelected = bSelected;
	if (bSelected)
	{
		Image->SetColorAndOpacity(Selected);
	}
	else
	{
		Image->SetColorAndOpacity(NoneSelected);
	}
}

void SShelfTab::CreateContextMenu()
{
	const bool CloseAfterSelection = true;

	// Create menu builder. Note that you don't have to pass optional parameters!
	FMenuBuilder MenuBuilder(CloseAfterSelection, NULL);

	MenuBuilder.BeginSection("Main Options");
	{
		// 1st entry should be a label, name or whatever
		MenuBuilder.AddWidget(SNew(STextBlock).Text(FText::FromString("  Options...")), FText(), true);
		MenuBuilder.AddMenuSeparator();
		//Rename
		MenuBuilder.AddMenuEntry(FText::FromString("Rename"), FText(), FSlateIcon(), FUIAction(FExecuteAction::CreateRaw(this, &SShelfTab::Rename)));
	}
	MenuBuilder.EndSection();

	MenuBuilder.BeginSection("creation Options");
	{
		//Create new shelf
		MenuBuilder.AddMenuEntry(FText::FromString("Create new"), FText(), FSlateIcon(), FUIAction(FExecuteAction::CreateRaw(this, &SShelfTab::CreateNew)));
		//Delete shelf
		MenuBuilder.AddMenuEntry(FText::FromString("Delete"), FText(), FSlateIcon(), FUIAction(FExecuteAction::CreateRaw(this, &SShelfTab::Delete)));
	}
	MenuBuilder.EndSection();


	MenuBuilder.BeginSection("Move options");
	{
		//move shelf to left
		MenuBuilder.AddMenuEntry(FText::FromString("Move Left"), FText(), FSlateIcon(), FUIAction(FExecuteAction::CreateRaw(this, &SShelfTab::MoveLeft)));
		//move shelf to right
		MenuBuilder.AddMenuEntry(FText::FromString("Move Right"), FText(), FSlateIcon(), FUIAction(FExecuteAction::CreateRaw(this, &SShelfTab::MoveRight)));
	}
	MenuBuilder.EndSection();

	FPythonContextMenu::SpawnContextMenu(SharedThis(this), MenuBuilder);
}



//Copyright 2019, Jorge Calleros Ramirez (Karma), All rights reserved.

#include "IPythonContextMenu.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "Widgets/Text/STextBlock.h"
#include "Framework/Application/SlateApplication.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Input/SEditableTextBox.h"

void FPythonContextMenu::ConfirmMenu(TSharedRef<SWidget> Owner, const FText& InTittle, FOnConfirmReceived Action, FVector2D MenuOffset /*= FVector2D(50, 50)*/)
{
	FMenuBuilder MenuBuilder(true, NULL);
	MenuBuilder.BeginSection("Main Options");
	{
		// 1st entry should be a label, name or whatever
		MenuBuilder.AddWidget(SNew(STextBlock).Text(InTittle), FText(), true);

		TSharedPtr<SWidget> PopWidget = SNew(SBox)
			.WidthOverride(200)
			.HeightOverride(20)
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
				[
				SNew(SButton)
				.OnClicked_Lambda([Action] {
					Action.ExecuteIfBound(true);
					FSlateApplication::Get().DismissAllMenus();
					return FReply::Handled();
					})
					[
						SNew(STextBlock).Text(FText::FromString("Ok"))
					]
				]
				+ SHorizontalBox::Slot()
				[
					SNew(SButton)
					.OnClicked_Lambda([Action] {
						Action.ExecuteIfBound(false);
						FSlateApplication::Get().DismissAllMenus();
						return FReply::Handled();
					})
					[
						SNew(STextBlock).Text(FText::FromString("Cancel"))
					]
				]
			];
		MenuBuilder.AddWidget(PopWidget->AsShared(), FText(), true);
	}
	MenuBuilder.EndSection();

	FVector2D Position = FSlateApplication::Get().GetCursorPos() - MenuOffset;
	FSlateApplication::Get().PushMenu(Owner, FWidgetPath(), MenuBuilder.MakeWidget(), Position, FPopupTransitionEffect(FPopupTransitionEffect::ContextMenu));
}

void FPythonContextMenu::InputMenu(TSharedRef<SWidget> Owner, const FText& InTittle, const FText& InitialText, FOnInputReceived Action, FVector2D MenuOffset /*= FVector2D(50, 50)*/)
{
	FMenuBuilder MenuBuilder(true, NULL);
	MenuBuilder.BeginSection("Main Options");
	{
		// 1st entry should be a label, name or whatever
		MenuBuilder.AddWidget(SNew(STextBlock).Text(InTittle), FText(), true);
		MenuBuilder.AddMenuSeparator();


		TSharedPtr<SEditableTextBox> TextBox = SNew(SEditableTextBox).Text(InitialText);

		TSharedPtr<SWidget> PopWidget = SNew(SBox)
			.WidthOverride(200)
			.HeightOverride(57)
			[
				SNew(SVerticalBox)
				+ SVerticalBox::Slot()
				.VAlign(VAlign_Top)
				.Padding(4)
				[
					TextBox->AsShared()
				]
				+ SVerticalBox::Slot()
				.VAlign(VAlign_Top)
				.Padding(4)
				[
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot()
				[
					SNew(SButton)
					.OnClicked_Lambda([Action, TextBox] {
						Action.ExecuteIfBound(TextBox->GetText());
						FSlateApplication::Get().DismissAllMenus();
						return FReply::Handled();
					})
					[
						SNew(STextBlock).Text(FText::FromString("Ok"))
					]
				]
				+ SHorizontalBox::Slot()
				[
					SNew(SButton)
					.OnClicked_Lambda([] {
						FSlateApplication::Get().DismissAllMenus();
						return FReply::Handled();
					})
					[
						SNew(STextBlock).Text(FText::FromString("Cancel"))
					]
				]
			]
			];

		//Rename
		MenuBuilder.AddWidget(PopWidget->AsShared(), FText(), true);
	}
	MenuBuilder.EndSection();

	FVector2D Position = FSlateApplication::Get().GetCursorPos() - MenuOffset;
	FSlateApplication::Get().PushMenu(Owner, FWidgetPath(), MenuBuilder.MakeWidget(), Position, FPopupTransitionEffect(FPopupTransitionEffect::ContextMenu));
}

void FPythonContextMenu::SpawnContextMenu(TSharedRef<SWidget> Owner, FMenuBuilder& Builder)
{
	const FVector2D ScreenPosition = FSlateApplication::Get().GetCursorPos();
	FSlateApplication::Get().PushMenu(Owner, FWidgetPath(), Builder.MakeWidget(), ScreenPosition, FPopupTransitionEffect(FPopupTransitionEffect::ContextMenu));
}

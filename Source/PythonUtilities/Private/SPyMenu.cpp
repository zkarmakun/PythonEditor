//Copyright 2019, Jorge Calleros Ramirez (Karma), All rights reserved.

#include "SPyMenu.h"
#include "SButton.h"
#include "PyMenu.h"
#include "Runtime/SlateCore/Public/Styling/CoreStyle.h"
#include "Widgets/SWindow.h"

#if WITH_EDITOR
#include "PropertyEditorModule.h"
#include "ModuleManager.h"
#include "IDetailsView.h"
#endif

#define LOCTEXT_NAMESPACE "PyMenus"

void SPyMenu::Construct(const FArguments& Args)
{
#if WITH_EDITOR

	Window = Args._Window;
	PyMenu = Args._PyMenu;
	check(PyMenu.Get());

	FPropertyEditorModule& PropertyEditorModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");
	const FDetailsViewArgs DetailsViewArgs(false, false, true, FDetailsViewArgs::HideNameArea, true);
	DetailsView = PropertyEditorModule.CreateDetailView(DetailsViewArgs);
	DetailsView->SetObject(PyMenu.Get());

	PyMenu->Setup();

	ChildSlot
	[
		SNew(SBorder)
		.BorderImage(FCoreStyle::Get().GetBrush("GenericWhiteBox"))
		.BorderBackgroundColor(FSlateColor(FColor(96,96,96,255)))
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				DetailsView.ToSharedRef()
			]
			+ SVerticalBox::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Bottom)
			.AutoHeight()
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
				.HAlign(HAlign_Fill)
				.Padding(2)
				[
					SNew(SButton)
					.Text(LOCTEXT("Run", "Run"))
					.OnClicked(this, &SPyMenu::OnRun)
				]
				+ SHorizontalBox::Slot()
				.HAlign(HAlign_Fill)
				.Padding(2)
				[
					SNew(SButton)
					.Text(LOCTEXT("Apply", "Apply"))
					.OnClicked(this, &SPyMenu::OnApply)
				]
				+ SHorizontalBox::Slot()
				.HAlign(HAlign_Fill)
				.Padding(2)
				[
					SNew(SButton)
					.Text(LOCTEXT("Cancel", "Cancel"))
					.OnClicked(this, &SPyMenu::OnCancel)
				]
			]
		]
	];

#endif
}

FReply SPyMenu::OnRun()
{
	if ( PyMenu.IsValid() && Window.IsValid())
	{
		PyMenu->Run();
		Window->RequestDestroyWindow();
	}
	return FReply::Handled();
}

FReply SPyMenu::OnApply()
{
	if (PyMenu.IsValid())
	{
		PyMenu->Run();
	}
	return FReply::Handled();
}

FReply SPyMenu::OnCancel()
{
	if (Window.IsValid())
	{
		Window->RequestDestroyWindow();
	}
	return FReply::Handled();
}


#undef  LOCTEXT_NAMESPACE
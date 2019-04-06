//Copyright 2019, Jorge Calleros Ramirez (Karma), All rights reserved.

#include "SShelf.h"
#include "Widgets/SBoxPanel.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "Framework/Application/SlateApplication.h"
#include "Widgets/Layout/SBox.h"
#include "SShelfHolder.h"
#include "ScriptShelfs.h"
#include "Widgets/Input/SButton.h"
#include "SShelfTab.h"
#include "PythonShelfToolkit.h"
#include "PythonEditor.h"

void SShelf::Construct(const FArguments& InArgs)
{
	TSharedPtr<FPythonShelfToolkit> ToolKit = FPythonShelfToolkit::Get();
	check(ToolKit);

	ScriptShelfObject = ToolKit->GetScriptShelfs();

	ChildSlot[
		SNew(SVerticalBox)
		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(FMargin(5,0,0,0))
		.VAlign(VAlign_Top)
		.HAlign(HAlign_Fill)
		[
			SAssignNew(ShelfHeaderContainer, SHorizontalBox)
		]
		+ SVerticalBox::Slot()
		.AutoHeight()
		.VAlign(VAlign_Fill)
		.Padding(FMargin(5, 0, 0, 0))
		[
			SNew(SBox)
			.HeightOverride(50)
			[
				SAssignNew(ShelfHolderContainer, SHorizontalBox)
			]
		]
	];
	UpdateWidget();
}

void SShelf::UpdateShelfs()
{
	ShelfHeaderContainer->ClearChildren();
	ShelfTabsWidgets.Empty();

	if (ScriptShelfObject->Tabs.Num() == 0)
	{
		FShelfTab Tab1(FName(TEXT("New Shelf")));
		ScriptShelfObject->Tabs.Add(Tab1);
		ScriptShelfObject->SaveConfig();
	}

	int32 IndexToSelect = -1;
	for (int32 i = 0; i < ScriptShelfObject->Tabs.Num(); i++)
	{
		GenerateShelfTabButtons(&ScriptShelfObject->Tabs[i]);
	}

	if (ScriptShelfObject->Tabs.IsValidIndex(ScriptShelfObject->LastSelectionID))
	{
		ShelfTabsWidgets[ScriptShelfObject->LastSelectionID]->SelectTab(true);
	}
}

void SShelf::UpdateButtons()
{
	ShelfHolderContainer->ClearChildren();
	SHorizontalBox::FSlot& PosSlot = ShelfHolderContainer->AddSlot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill);
	PosSlot[
		SNew(SShelfHolder)
			.Shelf(&ScriptShelfObject->Tabs[ScriptShelfObject->LastSelectionID])
	];
}

void SShelf::GenerateShelfTabButtons(FShelfTab * InShelf)
{
	TSharedPtr<SShelfTab> NewShelf = SNew(SShelfTab)
		.Label(InShelf->TabId)
		.OnShelfTabSelected(FOnShelfTabSelected::CreateRaw(this, &SShelf::OnShelfSelected));

	ShelfTabsWidgets.Add(NewShelf);

	SHorizontalBox::FSlot& PosSlot = ShelfHeaderContainer->AddSlot()
		.HAlign(HAlign_Left)
		.VAlign(VAlign_Top)
		.AutoWidth()
		.Padding(FMargin(1, 5, 1, 2));
	PosSlot[
		NewShelf->AsShared()
	];
}

void SShelf::OnShelfSelected(const FName& InShelf)
{
	for (int32 i = 0; i < ShelfTabsWidgets.Num(); i++)
	{
		if (!InShelf.IsEqual(ShelfTabsWidgets[i]->GetShelfName()))
		{
			ShelfTabsWidgets[i]->SelectTab(false);
		}
		else
		{
			ScriptShelfObject->LastSelectionID = i;
			ScriptShelfObject->SaveConfig();
		}
	}

	UpdateButtons();
}

void SShelf::UpdateWidget()
{
	UpdateShelfs();
	UpdateButtons();
}

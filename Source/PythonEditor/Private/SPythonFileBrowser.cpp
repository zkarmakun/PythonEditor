//Copyright 2019, Jorge Calleros Ramirez (Karma), All rights reserved.

#include "SPythonFileBrowser.h"
#include "HAL/FileManager.h"
#include "Templates/SharedPointer.h"
#include "Widgets/Images/SImage.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "Misc/FileHelper.h"
#include "HAL/PlatformFilemanager.h"
#include "PythonEditorStyle.h"
#include "SPythonFileBrowserItem.h"
#include "PythonEditorToolKit.h"
#include "PythonEditor.h"
#include "SSearchBox.h"
#include "SScrollBox.h"
#include "PythonProject.h"


#define LOCTEXT_NAMESPACE "PythonFileBrowser"


FReply SPythonFileBrowser::OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (MouseEvent.GetEffectingButton() == EKeys::RightMouseButton)
	{
		ClearSelection();
		OnSelectionChanged(nullptr);
		CreateContextMenuOpt(EScriptTreeType::None);
	}
	return FReply::Handled();
}

void SPythonFileBrowser::MouseButtonDoubleClick(TSharedPtr<FPyScriptModel> Script)
{
	FPythonEditorToolKit::Get()->OpenFile(Script);
}

void SPythonFileBrowser::OnSelectionChanged(TSharedPtr<FPyScriptModel> Item)
{
	LastSelection = Item;
	OnElemSelected.ExecuteIfBound(LastSelection);
}

void SPythonFileBrowser::Construct(const FArguments& Args)
{
	OnElemSelected = Args._OnElemSelected;

	ChildSlot[
		SNew(SBorder)
			.BorderImage(FPythonEditorStyle::Get().GetBrush("PythonEditor.BG"))
			[
				//SAssignNew(Container, SHorizontalBox
				SNew(SVerticalBox)
				+ SVerticalBox::Slot()
				.AutoHeight()
				.Padding(4)
				[
					SAssignNew(SearchBox, SSearchBox)
					.HintText(LOCTEXT("FilterSearch", "Search..."))
					.ToolTipText(LOCTEXT("FilterSearchHint", "Type here to search (pressing enter selects the results)"))
					.OnTextChanged(this, &SPythonFileBrowser::OnSearchBoxChanged)
					.OnTextCommitted(this, &SPythonFileBrowser::OnSearchBoxCommitted)
				]
				+ SVerticalBox::Slot()
				.VAlign(VAlign_Fill)
				.Padding(4)
				[
					SNew(SScrollBox)
					+ SScrollBox::Slot()
					.Padding(0)
					[
						SAssignNew(Container, SVerticalBox)
						+ SVerticalBox::Slot()
						[
							SAssignNew(ScriptTreeView, STreeView<TSharedPtr<FPyScriptModel>>)
							.TreeItemsSource(&RootDirectory)
							.SelectionMode(ESelectionMode::Single)
							.OnGenerateRow(this, &SPythonFileBrowser::OnGenerateRow)
							.OnGetChildren(this, &SPythonFileBrowser::OnGetChildren)
							.OnMouseButtonDoubleClick(this, &SPythonFileBrowser::MouseButtonDoubleClick)
							.OnExpansionChanged(this, &SPythonFileBrowser::OnExpansionChanged)
						]
					]
				]
			]
	];

	// Create the filter for searching in the tree
	SearchBoxPyFilter = MakeShareable(new PyTextFilter(PyTextFilter::FItemToStringArray::CreateSP(this, &SPythonFileBrowser::TransformScriptToString)));

	FilterHandler = MakeShareable(new TreeFilterHandler< TSharedPtr<FPyScriptModel> >());
	FilterHandler->SetFilter(SearchBoxPyFilter.Get());
	FilterHandler->SetGetChildrenDelegate(TreeFilterHandler< TSharedPtr<FPyScriptModel> >::FOnGetChildren::CreateRaw(this, &SPythonFileBrowser::WidgetHierarchy_OnGetChildren));

	//~ Load file browser last positions
	ExpandedItems.Empty();
	UPythonProject* PythonProject = GetMutableDefault<UPythonProject>();
	check(PythonProject);
	for (auto& Elem : PythonProject->ExpanedFileBrowser)
	{
		TSharedPtr<FPyScriptModel> expandedTemp = MakeShareable(new FPyScriptModel());
		expandedTemp->Name = Elem.Key;
		expandedTemp->Path = Elem.Value;
		ExpandedItems.Add(expandedTemp);
	}

	Update();
}

void SPythonFileBrowser::GetChildrenTree(TSharedPtr<FPyScriptModel> InScriptTree, TArray<TSharedPtr<FPyScriptModel>>& LinearOut)
{
	if (FPaths::DirectoryExists(InScriptTree->Path) && InScriptTree.IsValid())
	{
		FString Left;
		InScriptTree->Path.Split("/", &Left, nullptr, ESearchCase::IgnoreCase, ESearchDir::FromEnd);
		Left.Split("/", nullptr, &InScriptTree->Name, ESearchCase::IgnoreCase, ESearchDir::FromEnd);


		TArray<FString> Folders;
		TArray<FString> Files;
		FString FinalPath = InScriptTree->Path / TEXT("*");

		IFileManager& FileManager = IFileManager::Get();
		FileManager.FindFiles(Folders, *FinalPath, false, true);
		FileManager.FindFiles(Files, *FinalPath, true, false);

		for (FString& Folder : Folders)
		{
			FString FullFolder = InScriptTree->Path + Folder + "/";
			TSharedPtr<FPyScriptModel> NewRoot = MakeShareable(new FPyScriptModel());
			NewRoot->Path = FullFolder;
			GetChildrenTree(NewRoot, LinearOut);
			
			InScriptTree->AddChild(NewRoot, InScriptTree);
			LinearOut.Add(NewRoot);
		}

		for (FString& File : Files)
		{
			if(File.EndsWith(".pyc")) continue;

			TSharedPtr<FPyScriptModel> NewRoot = MakeShareable(new FPyScriptModel());
			NewRoot->Type = EScriptTreeType::File;
			NewRoot->Name = File;
			NewRoot->Path = InScriptTree->Path + File;

			InScriptTree->AddChild(NewRoot, InScriptTree);
			LinearOut.Add(NewRoot);
		}
		
	}
}

void SPythonFileBrowser::Update()
{
	//Container->ClearChildren();
	TArray<TSharedPtr<FPyScriptModel>> LinearTree;

	FPythonProjectSourcePath Project = FPythonEditorModule::GetProjectPythonSourcePath();

	TSharedPtr<FPyScriptModel> MainRoot = MakeShareable(new FPyScriptModel());

	TSharedPtr<FPyScriptModel> RootProject = MakeShareable(new FPyScriptModel());
	LinearTree.Add(RootProject);
	LinearTree.Add(MainRoot);


	RootProject->Path = Project.SourcePath;
	RootProject->Type = EScriptTreeType::Root;
	GetChildrenTree(RootProject, LinearTree);
	RootProject->Name = Project.Name;

	MainRoot->AddChild(RootProject, MainRoot);
	

	for (auto& Plugin : Project.Plugins)
	{
		for (auto& Module : Plugin.Modules)
		{
			TSharedPtr<FPyScriptModel> RootModule = MakeShareable(new FPyScriptModel());
			LinearTree.Add(RootModule);
			RootModule->Path = Module.SourcePath;
			RootModule->Type = EScriptTreeType::Root;
			GetChildrenTree(RootModule, LinearTree);
			RootModule->Name = Module.ModuleName;

			MainRoot->AddChild(RootModule, MainRoot);
		}
	}
	
	ScriptTreeView->GetExpandedItems(ExpandedItems);

	Items.Empty();
	RootDirectory = MainRoot->Children;
	ScriptTreeView->RequestTreeRefresh();

	for (auto& Elem : LinearTree)
	{
		for (auto& Expanded : ExpandedItems)
		{
			if (Elem->Name == Expanded->Name && Elem->Path == Expanded->Path)
			{
				ScriptTreeView->SetItemExpansion(Elem, true);
				continue;
			}
		}
	}
}

void SPythonFileBrowser::CreateNew()
{
	FPythonContextMenu::InputMenu(
		SharedThis(this),
		FText::FromString(" Create New"),
		FText::FromString("NewScript.py"),
		FOnInputReceived::CreateLambda([this](const FText& Name)
	{
		FPythonEditorToolKit::Get()->CreateNewScript(LastSelection, Name.ToString());
		Update();
	}));
}

void SPythonFileBrowser::Delete()
{
	FPythonContextMenu::ConfirmMenu(
		SharedThis(this),
		FText::FromString(" Are you sure?"),
		FOnConfirmReceived::CreateLambda([this](const bool& bConfirm)
	{
		if (bConfirm)
		{
			/* remove physical file*/
			FPythonEditorToolKit::Get()->DeleteFile(LastSelection);

			/* Close tab if open*/
			CloseFile(LastSelection);

			/* Update widget */
			Update();
		}
	}));
}

void SPythonFileBrowser::Edit()
{
	FPythonEditorToolKit::Get()->OpenFile(LastSelection);
}

void SPythonFileBrowser::Rename()
{
	FPythonContextMenu::InputMenu(
		SharedThis(this),
		FText::FromString(" Rename file"),
		FText::FromString(LastSelection->Name),
		FOnInputReceived::CreateLambda([this](const FText& Name)
	{
		FPythonEditorToolKit::Get()->RenameFileOrFolder(LastSelection, Name.ToString());
		Update();
	}));
}

void SPythonFileBrowser::CreateNewFolder()
{
	FPythonContextMenu::InputMenu(
		SharedThis(this),
		FText::FromString(" Create New"),
		FText::FromString("New Folder"),
		FOnInputReceived::CreateLambda([this](const FText& Name)
	{
		FPythonEditorToolKit::Get()->CreateNewScriptFolder(LastSelection, Name.ToString());
		Update();
	}));
}

void SPythonFileBrowser::FindInExplorer()
{
	ensure(LastSelection);
	FString AbsPath = FPaths::ConvertRelativePathToFull(LastSelection->Path);
	FPlatformProcess::ExploreFolder(*AbsPath);
}

void SPythonFileBrowser::OnSearchBoxChanged(const FText& Text)
{
	FilterHandler->SetIsEnabled(!Text.IsEmpty());
	SearchBoxPyFilter->SetRawFilterText(Text);
	SearchBox->SetError(SearchBoxPyFilter->GetFilterErrorText());
	FilterHandler->RefreshAndFilterTree();
}

void SPythonFileBrowser::OnSearchBoxCommitted(const FText& Text, ETextCommit::Type TextCommitType)
{
	OnSearchBoxChanged(Text);
}

void SPythonFileBrowser::OnExpansionChanged(TSharedPtr<FPyScriptModel> Item, bool bValue)
{
	//~ Save temporally expanded tree to PythonProject object to load in another session
	TSet<TSharedPtr<FPyScriptModel>> ExpandedItemsToSave;
	ScriptTreeView->GetExpandedItems(ExpandedItemsToSave);

	UPythonProject* PythonProject = GetMutableDefault<UPythonProject>();
	check(PythonProject);
	PythonProject->ExpanedFileBrowser.Empty();

	for (auto& Elem : ExpandedItemsToSave)
	{
		PythonProject->ExpanedFileBrowser.Add(Elem->Name, Elem->Path);
	}
	PythonProject->SaveConfig();
}

void SPythonFileBrowser::TransformScriptToString(TSharedPtr<FPyScriptModel> Script, OUT TArray< FString >& Array)
{
	Array.Add(Script->Name);
}

void SPythonFileBrowser::WidgetHierarchy_OnGetChildren(TSharedPtr<FPyScriptModel> InParent, TArray< TSharedPtr<FPyScriptModel> >& OutChildren)
{
	UE_LOG(LogTemp, Warning, TEXT("%s"), *InParent->Name);
	for (auto& model : OutChildren)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), *model->Name);
	}
}

void SPythonFileBrowser::RebuldTreeView()
{
	float OldScrollOffset = 0.0f;
	if (ScriptTreeView.IsValid())
	{
		OldScrollOffset = ScriptTreeView->GetScrollOffset();
	}

}

TSharedRef<ITableRow> SPythonFileBrowser::OnGenerateRow(TSharedPtr<FPyScriptModel> Item, const TSharedRef<STableViewBase>& OwnerTable)
{
	check(Item.IsValid());

	TSharedPtr<SPythonFileBrowserItem> BrowserItem = SNew(SPythonFileBrowserItem)
		.InScriptTree(Item)
		.OnSelectionChanged(this, &SPythonFileBrowser::OnSelectionChanged)
		.InOwner(SharedThis(this));

	Items.Add(BrowserItem);

	return 	SNew(STableRow<TSharedPtr<FPyScriptModel>>, OwnerTable)
		.Padding(0)
		[
			BrowserItem->AsShared()
		];
}

void SPythonFileBrowser::OnGetChildren(TSharedPtr<FPyScriptModel> Item, TArray<TSharedPtr<FPyScriptModel>>& OutChildren)
{
	check(Item.IsValid());
	OutChildren = Item->Children;
}

	
void SPythonFileBrowser::CloseFile(TSharedPtr<FPyScriptModel> ScriptToClose)
{
	FPythonEditorToolKit::Get()->CloseOrDeleteFile(ScriptToClose);
}

TSharedPtr<FPyScriptModel> SPythonFileBrowser::GetLastSelection()
{
	return LastSelection;
}

void SPythonFileBrowser::ClearSelection()
{
	ScriptTreeView->ClearSelection();
	for (int32 i = 0; i < Items.Num(); i++)
	{
		if (Items[i].IsValid())
		{
			Items[i]->Select(false);
		}
	}
}

void SPythonFileBrowser::CreateContextMenuOpt(const EScriptTreeType& Type)
{
	if (Type == EScriptTreeType::None) return;

	FMenuBuilder MenuBuilder(true, NULL);
	MenuBuilder.BeginSection("Main Options");
	{
		// 1st entry should be a label, name or whatever
		MenuBuilder.AddWidget(SNew(STextBlock).Text(FText::FromString("	Options...")), FText(), true);
		MenuBuilder.AddMenuSeparator();

		//Rename SIGLAS
		MenuBuilder.AddMenuEntry(FText::FromString("Create New File"), FText(), FSlateIcon(), FUIAction(FExecuteAction::CreateRaw(this, &SPythonFileBrowser::CreateNew)));

		MenuBuilder.AddMenuEntry(FText::FromString("Create New Folder"), FText(), FSlateIcon(), FUIAction(FExecuteAction::CreateRaw(this, &SPythonFileBrowser::CreateNewFolder)));


		MenuBuilder.AddMenuSeparator();

		if (Type != EScriptTreeType::Root)
		{
			
			if (Type == EScriptTreeType::File)
			{
				//Edit Script
				MenuBuilder.AddMenuEntry(FText::FromString("Edit File"), FText(), FSlateIcon(), FUIAction(FExecuteAction::CreateRaw(this, &SPythonFileBrowser::Edit)));
			}

			//Rename Script
			MenuBuilder.AddMenuEntry(FText::FromString("Rename"), FText(), FSlateIcon(), FUIAction(FExecuteAction::CreateRaw(this, &SPythonFileBrowser::Rename)));

			//Delete Script
			MenuBuilder.AddMenuEntry(FText::FromString("Delete"), FText(), FSlateIcon(), FUIAction(FExecuteAction::CreateRaw(this, &SPythonFileBrowser::Delete)));
		}
		

		//find folder or file in explorer 
		MenuBuilder.AddMenuEntry(FText::FromString("Open in explorer"), FText(), FSlateIcon(), FUIAction(FExecuteAction::CreateRaw(this, &SPythonFileBrowser::FindInExplorer)));
		
	}
	MenuBuilder.EndSection();

	FPythonContextMenu::SpawnContextMenu(SharedThis(this), MenuBuilder);
}


#undef LOCTEXT_NAMESPAC
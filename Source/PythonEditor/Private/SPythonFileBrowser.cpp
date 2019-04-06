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



FReply SPythonFileBrowser::OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (MouseEvent.GetEffectingButton() == EKeys::RightMouseButton)
	{
		ClearSelection();
		OnSelectionChanged(nullptr);
		CreateContextMenuOpt(false);
	}
	return FReply::Handled();
}

void SPythonFileBrowser::MouseButtonDoubleClick(TSharedPtr<FPyScriptTree> Script)
{
	FPythonEditorToolKit::Get()->OpenFile(Script);
}

void SPythonFileBrowser::OnSelectionChanged(TSharedPtr<FPyScriptTree> Item)
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
				SAssignNew(Container, SHorizontalBox)
			]
	];
	Update();
}

void SPythonFileBrowser::GetChildrenTree(TSharedPtr<FPyScriptTree> InScriptTree)
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
			TSharedPtr<FPyScriptTree> NewRoot = MakeShareable(new FPyScriptTree());
			NewRoot->Path = FullFolder;
			GetChildrenTree(NewRoot);
			InScriptTree->Children.Add(NewRoot);
			//	UE_LOG(LogTemp, Log, TEXT("folder %s"), *FullFolder);
		}

		for (FString& File : Files)
		{
			if(File.EndsWith(".pyc")) continue;

			TSharedPtr<FPyScriptTree> NewRoot = MakeShareable(new FPyScriptTree());
			NewRoot->Type = EScriptTreeType::File;
			NewRoot->Name = File;
			NewRoot->Path = InScriptTree->Path + File;
			InScriptTree->Children.Add(NewRoot);
			//UE_LOG(LogTemp, Log, TEXT("file %s"), *FullFilePath);
		}

	}
}

void SPythonFileBrowser::Update()
{
	Container->ClearChildren();
	Items.Empty();

	TSharedPtr<FPyScriptTree> RootScriptFolder = MakeShareable(new FPyScriptTree());
	RootScriptFolder->Path = FPythonEditorModule::GetProjectScriptDir();
	RootScriptFolder->Type = EScriptTreeType::Directory;
	GetChildrenTree(RootScriptFolder);

	RootDirectory = RootScriptFolder->Children;

	SHorizontalBox::FSlot& Slot = Container->AddSlot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		.Padding(FMargin(0));
	Slot[
		SAssignNew(ScriptTree, STreeView<TSharedPtr<FPyScriptTree>>)
			.TreeItemsSource(&RootDirectory)
			.OnGenerateRow(this, &SPythonFileBrowser::OnGenerateRow)
			.OnGetChildren(this, &SPythonFileBrowser::OnGetChildren)
			.OnMouseButtonDoubleClick(this, &SPythonFileBrowser::MouseButtonDoubleClick)
	];
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

TSharedRef<ITableRow> SPythonFileBrowser::OnGenerateRow(TSharedPtr<FPyScriptTree> Item, const TSharedRef<STableViewBase>& OwnerTable)
{
	const FSlateBrush* Brush = Item->Type == EScriptTreeType::Directory ? FPythonEditorStyle::Get().GetBrush("PythonEditor.FolderIcon") : FPythonEditorStyle::Get().GetBrush("PythonEditor.FileIcon");
	TSharedPtr<SPythonFileBrowserItem> BrowserItem = SNew(SPythonFileBrowserItem)
		.InScriptTree(Item)
		.OnSelectionChanged(this, &SPythonFileBrowser::OnSelectionChanged)
		.InOwner(SharedThis(this));

	Items.Add(BrowserItem);

	return 	SNew(STableRow<TSharedPtr<FPyScriptTree>>, OwnerTable)
		.Padding(0)
		[
			BrowserItem->AsShared()
		];
}

void SPythonFileBrowser::OnGetChildren(TSharedPtr<FPyScriptTree> Item, TArray<TSharedPtr<FPyScriptTree>>& OutChildren)
{
	OutChildren = Item->Children;
}

	
void SPythonFileBrowser::CloseFile(TSharedPtr<FPyScriptTree> ScriptToClose)
{
	FPythonEditorToolKit::Get()->CloseOrDeleteFile(ScriptToClose);
}

TSharedPtr<FPyScriptTree> SPythonFileBrowser::GetLastSelection()
{
	return LastSelection;
}

void SPythonFileBrowser::ClearSelection()
{
	ScriptTree->ClearSelection();
	for (int32 i = 0; i < Items.Num(); i++)
	{
		if (Items[i].IsValid())
		{
			Items[i]->Select(false);
		}
	}
}

void SPythonFileBrowser::CreateContextMenuOpt(const bool& bFullContextMenu)
{
	FMenuBuilder MenuBuilder(true, NULL);
	MenuBuilder.BeginSection("Main Options");
	{
		// 1st entry should be a label, name or whatever
		MenuBuilder.AddWidget(SNew(STextBlock).Text(FText::FromString("	Options...")), FText(), true);
		MenuBuilder.AddMenuSeparator();

		//Rename SIGLAS
		MenuBuilder.AddMenuEntry(FText::FromString("Create New File"), FText(), FSlateIcon(), FUIAction(FExecuteAction::CreateRaw(this, &SPythonFileBrowser::CreateNew)));

		MenuBuilder.AddMenuEntry(FText::FromString("Create New Folder"), FText(), FSlateIcon(), FUIAction(FExecuteAction::CreateRaw(this, &SPythonFileBrowser::CreateNewFolder)));

		if (bFullContextMenu)
		{
			MenuBuilder.AddMenuSeparator();

			//Edit Script
			MenuBuilder.AddMenuEntry(FText::FromString("Edit File"), FText(), FSlateIcon(), FUIAction(FExecuteAction::CreateRaw(this, &SPythonFileBrowser::Edit)));

			//Rename Script
			MenuBuilder.AddMenuEntry(FText::FromString("Rename"), FText(), FSlateIcon(), FUIAction(FExecuteAction::CreateRaw(this, &SPythonFileBrowser::Rename)));

			//Delete Script
			MenuBuilder.AddMenuEntry(FText::FromString("Delete"), FText(), FSlateIcon(), FUIAction(FExecuteAction::CreateRaw(this, &SPythonFileBrowser::Delete)));

			//find folder or file in explorer 
			MenuBuilder.AddMenuEntry(FText::FromString("Open in explorer"), FText(), FSlateIcon(), FUIAction(FExecuteAction::CreateRaw(this, &SPythonFileBrowser::FindInExplorer)));
		}
	}
	MenuBuilder.EndSection();

	FPythonContextMenu::SpawnContextMenu(SharedThis(this), MenuBuilder);
}


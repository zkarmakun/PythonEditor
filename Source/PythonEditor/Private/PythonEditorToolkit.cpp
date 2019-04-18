//Copyright 2019, Jorge Calleros Ramirez (Karma), All rights reserved.

#include "PythonEditorToolKit.h"
#include "PythonProject.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "PythonEditorStyle.h"
#include "Editor/EditorStyle/Public/EditorStyleSet.h"
#include "widgets/Docking/SDockTab.h"
#include "SPythonFileBrowser.h"
#include "Misc/FileHelper.h"
#include "SPythonCodeEditor.h"
#include "HAL/PlatformFilemanager.h"
#include "AutoCompleteWorker.h"
#include "PythonEditorCommands.h"
#include "PythonEditor.h"
#include "SPythonDocumentation.h"
#include "SPip.h"

const FName FPythonEditorAppName = FName(TEXT("FPythonEditorApp"));
TWeakPtr<FPythonEditorToolKit> FPythonEditorToolKit::PythonToolKit;

namespace FPythonToolKitNamespace
{
	static const FName AppIdentifier("PythonEditorToolKit");
	static const FName FileBrowserID("PythonFileBrowser");
	static const FName WebBrowserID("PythonDocs");
	static const FName PipID("Pip Install");
	static const FName DetailsViewTab("PythonMainView");
}

FPythonEditorToolKit::FPythonEditorToolKit()
{
	AutoCompleteWorker = nullptr;
}

FPythonEditorToolKit::~FPythonEditorToolKit()
{
	PythonProject->OpenedTabs.Empty();
	for (auto& item : OpenedScripts)
	{
		PythonProject->OpenedTabs.Add(FName(*item.Key), item.Value->GetFilePath());
	}
	PythonProject->SaveConfig();

	if (AutoCompleteWorker)
	{
		AutoCompleteWorker->Stop();
	}
}

void FPythonEditorToolKit::RegisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager)
{
	WorkspaceMenuCategory = InTabManager->AddLocalWorkspaceMenuCategory(FText::FromString("Python Editor"));
	auto WorkspaceMenuCategoryRef = WorkspaceMenuCategory.ToSharedRef();

	FAssetEditorToolkit::RegisterTabSpawners(InTabManager);

	//Register Data table palette tab
	InTabManager->RegisterTabSpawner(FPythonToolKitNamespace::FileBrowserID, FOnSpawnTab::CreateSP(this, &FPythonEditorToolKit::HandleTabManagerSpawnTab, FPythonToolKitNamespace::FileBrowserID))
		.SetDisplayName(FText::FromString("File browser"))
		.SetGroup(WorkspaceMenuCategoryRef)
		.SetIcon(FSlateIcon(FEditorStyle::GetStyleSetName(), "LevelEditor.Tabs.Details"));

	InTabManager->RegisterTabSpawner(FPythonToolKitNamespace::WebBrowserID, FOnSpawnTab::CreateSP(this, &FPythonEditorToolKit::HandleTabManagerSpawnTab, FPythonToolKitNamespace::WebBrowserID))
		.SetDisplayName(FText::FromString("Python Docs"))
		.SetGroup(WorkspaceMenuCategoryRef)
		.SetIcon(FSlateIcon(FEditorStyle::GetStyleSetName(), "LevelEditor.Tabs.Details"));

	InTabManager->RegisterTabSpawner(FPythonToolKitNamespace::PipID, FOnSpawnTab::CreateSP(this, &FPythonEditorToolKit::HandleTabManagerSpawnTab, FPythonToolKitNamespace::PipID))
		.SetDisplayName(FText::FromString("Pip Install"))
		.SetGroup(WorkspaceMenuCategoryRef)
		.SetIcon(FSlateIcon(FEditorStyle::GetStyleSetName(), "LevelEditor.Tabs.Details"));

}

void FPythonEditorToolKit::UnregisterTabSpawners(const TSharedRef<FTabManager>& InTabManager)
{
	FAssetEditorToolkit::UnregisterTabSpawners(InTabManager);
	InTabManager->UnregisterTabSpawner(FPythonToolKitNamespace::FileBrowserID);
	InTabManager->UnregisterTabSpawner(FPythonToolKitNamespace::WebBrowserID);
	InTabManager->UnregisterTabSpawner(FPythonToolKitNamespace::PipID);
}

TSharedRef<SDockTab> FPythonEditorToolKit::HandleTabManagerSpawnTab(const FSpawnTabArgs& Args, FName TabIdentifier)
{
	if (TabIdentifier == FPythonToolKitNamespace::FileBrowserID)
	{
		return SNew(SDockTab)
			.TabRole(ETabRole::PanelTab)
			[
				SNew(SPythonFileBrowser)
				.OnElemSelected(this, &FPythonEditorToolKit::OnFileBrowserSelectionChanged)
			];
	}

	if (TabIdentifier == FPythonToolKitNamespace::WebBrowserID)
	{
		return SNew(SDockTab)
			.TabRole(ETabRole::PanelTab)
			[
				SAssignNew(PythonDocs, SPythonDocumentation)
			];
	}

	if (TabIdentifier == FPythonToolKitNamespace::PipID)
	{
		return SNew(SDockTab)
			.TabRole(ETabRole::PanelTab)
			[
				SNew(SPip)
			];
	}

	return SNew(SDockTab);
}

FName FPythonEditorToolKit::GetToolkitFName() const
{
	return FName("Python Editor");
}

FText FPythonEditorToolKit::GetBaseToolkitName() const
{
	return FText::FromString("Python Editor");
}

FText FPythonEditorToolKit::GetToolkitName() const
{
	return FText::FromString("Python Editor");
}

FText FPythonEditorToolKit::GetToolkitToolTipText() const
{
	return FText::FromString("Editor python code with this editor");
}

FLinearColor FPythonEditorToolKit::GetWorldCentricTabColorScale() const
{
	return FLinearColor(0.3f, 0.2f, 0.5f, 0.5f);
}

FString FPythonEditorToolKit::GetWorldCentricTabPrefix() const
{
	return FString("Python Editor");
}

void FPythonEditorToolKit::AddReferencedObjects(FReferenceCollector& Collector)
{
	//Collector.AddReferencedObject(PythonProject);
}

void FPythonEditorToolKit::InitCodeEditor(const EToolkitMode::Type Mode, const TSharedPtr< class IToolkitHost >& InitToolkitHost, UPythonProject* CodeProject)
{
	FAssetEditorManager::Get().CloseOtherEditors(CodeProject, this);
	PythonProject = CodeProject;

	TSharedPtr<FPythonEditorToolKit> ThisPtr(SharedThis(this));
	PythonToolKit = ThisPtr;

	// create tab layout
	const TSharedRef<FTabManager::FLayout> Layout = FTabManager::NewLayout("Standalone_Python_Editor_1.0")
		->AddArea
		(
			FTabManager::NewPrimaryArea()
			->SetOrientation(Orient_Horizontal)
			->Split
			(
				FTabManager::NewSplitter()
				->SetOrientation(Orient_Vertical)
				->SetSizeCoefficient(0.2f)
				->Split
				(
					// tool bar
					FTabManager::NewStack()
					->AddTab(GetToolbarTabId(), ETabState::OpenedTab)
					->SetHideTabWell(true)
					->SetSizeCoefficient(0.01f)

				)
				->Split
				(
					FTabManager::NewSplitter()
					->SetOrientation(Orient_Horizontal)
					->SetSizeCoefficient(.66f)
					->Split
					(
						// File Browser
						FTabManager::NewStack()
						->AddTab(FPythonToolKitNamespace::FileBrowserID, ETabState::OpenedTab)
						->SetHideTabWell(true)
						->SetSizeCoefficient(0.2f)
					)
				)
			)
			->Split
			(

				FTabManager::NewSplitter()
				->SetOrientation(Orient_Horizontal)
				->SetSizeCoefficient(.66f)
				->Split
				(
					// Web Browser ID documentation
					FTabManager::NewStack()
					->AddTab(FPythonToolKitNamespace::WebBrowserID, ETabState::OpenedTab)
					->SetHideTabWell(false)
					->SetSizeCoefficient(0.7f)
				)
				->Split
				(
					FTabManager::NewStack()
					->AddTab(FPythonToolKitNamespace::PipID, ETabState::OpenedTab)
					->SetHideTabWell(false)
					->SetSizeCoefficient(0.7f)
				)
			)
			
		);

	InitAssetEditor(Mode, 
		InitToolkitHost, 
		FPythonEditorAppName, 
		Layout, 
		/*bCreateDefaultStandaloneMenu=*/ true, 
		/*bCreateDefaultToolbar=*/ true, 
		CodeProject);


	AutoCompleteWorker = new FAutoCompleteWorker();

	BindCommands();
	ExtendToolBar();
	RegenerateMenusAndToolbars();

	RestoreTabs();
}

FString FPythonEditorToolKit::GetCode(TSharedPtr<FPyScriptTree> InScript)
{
	FString Code;
	if (InScript->Type == EScriptTreeType::File)
	{
		TSharedPtr<SPythonCodeEditor> ScriptEditor = GetCurrentPythonCodeEditor(InScript);
		if (ScriptEditor.IsValid())
		{
			return ScriptEditor->GetCode();
		}
		FFileHelper::LoadFileToString(Code, *InScript->Path);
	}
	return Code;
}

void FPythonEditorToolKit::OpenFile(TSharedPtr<FPyScriptTree> InScript)
{
	FName TabId(*InScript->Name);
	TSharedPtr<SDockTab> ExistingTab = TabManager->FindExistingLiveTab(TabId);
	if (ExistingTab.IsValid())
	{
		TabManager->InvokeTab(TabId);
	}
	else
	{
		TabManager->RegisterTabSpawner(TabId, FOnSpawnTab::CreateSP(this, &FPythonEditorToolKit::HandleScriptTab, InScript))
			.SetDisplayName(FText::FromString(InScript->Name))
			.SetIcon(FSlateIcon(FPythonEditorStyle::Get().GetStyleSetName(), "PythonEditor.FileIcon"));
		TabManager->InvokeTab(TabId);
	}
}

void FPythonEditorToolKit::DeleteFile(TSharedPtr<FPyScriptTree> ScriptTree)
{
	ensure(ScriptTree);
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
	if (ScriptTree->Type == EScriptTreeType::File)
	{
		FPlatformFileManager::Get().GetPlatformFile().DeleteFile(*ScriptTree->Path);
	}
	else
	{
		FPlatformFileManager::Get().GetPlatformFile().DeleteDirectoryRecursively(*ScriptTree->Path);
	}
}

void FPythonEditorToolKit::RenameFileOrFolder(TSharedPtr<FPyScriptTree> ScriptTree, const FString& NewName)
{
	ensure(ScriptTree);

	FString FileName = NewName;
	if (FileName.IsEmpty())
	{
		UE_LOG(LogTemp, Log, TEXT("Cannot rename file %s from empty name"), *ScriptTree->Name);
		return;
	}

	if (!FileName.EndsWith(".py") && ScriptTree->Type == EScriptTreeType::File)
	{
		FileName += ".py";
	}

	if (ScriptTree->Type == EScriptTreeType::File)
	{
		FString RenamedPath;
		ScriptTree->Path.Split("/", &RenamedPath, nullptr, ESearchCase::IgnoreCase, ESearchDir::FromEnd);
		RenamedPath += "/" + FileName;
		if (FPlatformFileManager::Get().GetPlatformFile().MoveFile(*RenamedPath, *ScriptTree->Path))
		{
			CloseOrDeleteFile(ScriptTree);
		}
	}
	else
	{
		FString RenamedPath;
		ScriptTree->Path.Split("/", &RenamedPath, nullptr, ESearchCase::IgnoreCase, ESearchDir::FromEnd);
		RenamedPath.Split("/", &RenamedPath, nullptr, ESearchCase::IgnoreCase, ESearchDir::FromEnd);
		RenamedPath += "/" + FileName;
		FPlatformFileManager::Get().GetPlatformFile().MoveFile( *RenamedPath, *ScriptTree->Path);
	}
}

void FPythonEditorToolKit::CloseOrDeleteFile(TSharedPtr<FPyScriptTree> InScript)
{
	FName TabId(*InScript->Name);
	TSharedPtr<SDockTab> ExistingTab = TabManager->FindExistingLiveTab(TabId);
	if (ExistingTab.IsValid())
	{
		ExistingTab->RequestCloseTab();
		TabManager->UnregisterTabSpawner(TabId);
		RemoveScriptEditor(InScript->Name);
	}

	UE_LOG(LogTemp, Log, TEXT("Removed file: %s"), *InScript->Name);
}

TSharedPtr<SPythonCodeEditor> FPythonEditorToolKit::GetCurrentPythonCodeEditor(TSharedPtr<FPyScriptTree> InScript) const
{
	for (auto& ScriptEditor : OpenedScripts)
	{
		if (InScript->Name == ScriptEditor.Key)
		{
			return ScriptEditor.Value;
		}
	}
	return nullptr;
}

void FPythonEditorToolKit::SaveAsset_Execute()
{
	FAssetEditorToolkit::SaveAsset_Execute();
	if (CurrentCodeEditor.IsValid() && CurrentScript.IsValid())
	{
		if (CurrentCodeEditor->Save())
		{
			
		}
	}
}

void FPythonEditorToolKit::FindInContentBrowser_Execute()
{
	FAssetEditorToolkit::FindInContentBrowser_Execute();

	if (CurrentScript.IsValid())
	{
		FString AbsPath = FPaths::ConvertRelativePathToFull(CurrentScript->Path);
		FPlatformProcess::ExploreFolder(*AbsPath);
	}
}

void FPythonEditorToolKit::RunScript_Execute()
{
	if (CurrentCodeEditor.IsValid() && CurrentScript.IsValid())
	{
		CurrentCodeEditor->RunScript();
	}
}

void FPythonEditorToolKit::OpenDocs(const FString& Link)
{
	TabManager->InvokeTab(FPythonToolKitNamespace::WebBrowserID);
	if (!Link.IsNumeric())
	{
		PythonDocs->OpenDocLink(Link);
	}
}

void FPythonEditorToolKit::CreateNewScriptFolder(TSharedPtr<FPyScriptTree> ScriptTree, const FString& Name)
{
	if (Name.IsEmpty())
	{
		UE_LOG(LogTemp, Warning, TEXT("cannot create folder from empty name"));
		return;
	}

	FString folder = FPythonEditorModule::GetProjectScriptDir();
	EScriptTreeType Type = EScriptTreeType::Directory;
	if (ScriptTree.IsValid())
	{
		folder = ScriptTree->Path;
		Type = ScriptTree->Type;
	}

	FString FullPath = folder + "/" + Name;
	if (Type == EScriptTreeType::File)
	{
		folder.Split("/", &folder, nullptr, ESearchCase::IgnoreCase, ESearchDir::FromEnd);
		FullPath = folder + "/" + Name;
	}

	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();

	if (PlatformFile.CreateDirectoryTree(*FullPath))
	{
		UE_LOG(LogTemp, Log, TEXT("File created: %s"), *FullPath);
	}
}

void FPythonEditorToolKit::CreateNewScript(TSharedPtr<FPyScriptTree> ScriptTree, const FString& Name)
{
	if (Name.IsEmpty())
	{
		UE_LOG(LogTemp, Log, TEXT("cannot create file with empty name"));
		return;
	}

	FString folder = FPythonEditorModule::GetProjectScriptDir();
	EScriptTreeType Type = EScriptTreeType::Directory;
	if (ScriptTree.IsValid())
	{
		folder = ScriptTree->Path;
		Type = ScriptTree->Type;
	}

	FString FileName = Name;
	if (!FileName.EndsWith(".py"))
	{
		FileName += ".py";
	}

	FString ContentFile = "import unreal";
	FString FullPath = folder + "/" + FileName;
	if (Type == EScriptTreeType::File)
	{
		folder.Split("/", &folder, nullptr, ESearchCase::IgnoreCase, ESearchDir::FromEnd);
		FullPath = folder + "/" + FileName;
	}

	if (FFileHelper::SaveStringToFile(*ContentFile, *FullPath))
	{
		UE_LOG(LogTemp, Log, TEXT("File created: %s"), *FullPath);
	}
}

TSharedRef<SDockTab> FPythonEditorToolKit::HandleScriptTab(const FSpawnTabArgs& Args, TSharedPtr<FPyScriptTree> Script)
{
	TSharedPtr<SPythonCodeEditor> CodeEditor = SNew(SPythonCodeEditor).File(Script->Path).TabName(Script->Name);
	OpenedScripts.Add(Script->Name, CodeEditor);

	TSharedRef<SDockTab> Tab = SNew(SDockTab)
		.TabRole(PanelTab)
		.OnTabClosed(this, &FPythonEditorToolKit::OnTabClosed, FName(*Script->Name))
		[
			CodeEditor->AsShared()
		];
	Tab->SetOnTabActivated(SDockTab::FOnTabActivatedCallback::CreateRaw(this, &FPythonEditorToolKit::OnTabActive, Script, CodeEditor));
	
	CodeEditor->SetOwner(Tab);
	return Tab;
}


void FPythonEditorToolKit::OnTabActive(TSharedRef<SDockTab> Tab, ETabActivationCause Cause, TSharedPtr<FPyScriptTree> Script, TSharedPtr<SPythonCodeEditor> InCodeEditor)
{
	CurrentScript = Script;
	CurrentCodeEditor = InCodeEditor;
	PythonProject->LastTabFocused = FName(*Script->Name);
	PythonProject->SaveConfig();
}

void FPythonEditorToolKit::OnFileBrowserSelectionChanged(TSharedPtr<FPyScriptTree> NewSelection)
{
	CurrentBroswerScriptSelected = NewSelection;
}

void FPythonEditorToolKit::OnTabClosed(TSharedRef<SDockTab>, FName ID)
{
	TabManager->UnregisterTabSpawner(ID);
	RemoveScriptEditor(ID.ToString());
}

void FPythonEditorToolKit::RemoveScriptEditor(const FString& Name)
{
	for (auto& ScriptEditor : OpenedScripts)
	{
		if (Name == ScriptEditor.Key)
		{
			OpenedScripts.Remove(Name);
			return;
		}
	}
}

void FPythonEditorToolKit::RestoreTabs()
{
	ensure(PythonProject.IsValid());
	for (auto& Elem : PythonProject->OpenedTabs)
	{
		TSharedPtr<SDockTab> ExistingTab = TabManager->FindExistingLiveTab(Elem.Key);
		if (ExistingTab.IsValid())
		{
			ExistingTab->RequestCloseTab();
			TabManager->UnregisterTabSpawner(Elem.Key);
		}
	}

	for (auto& Elem : PythonProject->OpenedTabs)
	{
		if (FPaths::FileExists(Elem.Value))
		{
			TSharedPtr<FPyScriptTree> Restored = MakeShareable(new FPyScriptTree());
			Restored->Name = Elem.Key.ToString();
			Restored->Path = Elem.Value;
			OpenFile(Restored);
		}
	}
}

void FPythonEditorToolKit::BindCommands()
{
	FPythonEditorCommands::Register();

// 	Commands = MakeShareable(new FUICommandList);
// 
// 	Commands->MapAction(
// 		FPythonEditorCommands::Get().RunScript,
// 		FExecuteAction::CreateRaw(this, &FPythonEditorToolKit::RunScript_Execute),
// 		FCanExecuteAction());
}

void FPythonEditorToolKit::ExtendToolBar()
{

	struct ToolBarCalls
	{
		static void RunScript()
		{
			FPythonEditorToolKit::Get()->RunScript_Execute();
		}

		static void OpenDocs()
		{
			FString TheURL = "https://api.unrealengine.com/INT/PythonAPI/";
			FPythonEditorToolKit::Get()->OpenDocs(TheURL);
			//FPlatformProcess::LaunchURL(*TheURL, nullptr, nullptr);
		}

		static void OpenPipInstall()
		{
			FPythonEditorToolKit::Get()->TabManager->InvokeTab(FPythonToolKitNamespace::PipID);
		}
	};


	struct LocalToolBar
	{
		static void FillToolbar(FToolBarBuilder& ToolbarBuilder)
		{
			ToolbarBuilder.BeginSection("Python menu");
			{
				//RunPythonScript
				ToolbarBuilder.AddToolBarButton(FUIAction(FExecuteAction::CreateStatic( &ToolBarCalls::RunScript)),
					TEXT("Run"), 
					FText::FromString("Run"), 
					FText::FromString("Run current script (ctrl + Enter) ... has to be saved before"), 
					FSlateIcon(FPythonEditorStyle::GetStyleSetName(), "PythonEditor.Run"));
			}
			ToolbarBuilder.EndSection();

			ToolbarBuilder.BeginSection("Python Extra");
			{
				ToolbarBuilder.AddToolBarButton(FUIAction(FExecuteAction::CreateStatic(&ToolBarCalls::OpenDocs)),
					TEXT("Docs"),
					FText::FromString("Docs"),
					FText::FromString("Open python documentation"),
					FSlateIcon(FPythonEditorStyle::GetStyleSetName(), "PythonEditor.NewFile"));

				ToolbarBuilder.AddToolBarButton(FUIAction(FExecuteAction::CreateStatic(&ToolBarCalls::OpenPipInstall)),
					TEXT("Pip"),
					FText::FromString("Pip"),
					FText::FromString("Open Pip Installer"),
					FSlateIcon(FPythonEditorStyle::GetStyleSetName(), "PythonEditor.Pip"));
			}
			ToolbarBuilder.EndSection();
		}
	};

	TSharedPtr<FExtender> ToolbarExtender = MakeShareable(new FExtender);

	ToolbarExtender->AddToolBarExtension(
		"Asset",
		EExtensionHook::After,
		GetToolkitCommands(),
		FToolBarExtensionDelegate::CreateStatic(&LocalToolBar::FillToolbar)
	);

	AddToolbarExtender(ToolbarExtender);
}



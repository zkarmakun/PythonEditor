//Copyright 2019, Jorge Calleros Ramirez (Karma), All rights reserved.

#include "PythonEditor.h"
#include "PythonEditorStyle.h"
#include "PythonEditorCommands.h"
#include "Misc/MessageDialog.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "PythonEditorToolKit.h"
#include "PythonProject.h"
#include "HAL/PlatformFilemanager.h"
#include "PythonShelfToolkit.h"
#include "Widgets/Docking/SDockTab.h"
#include "AutoCompleteWorker.h"
#include "PyUnrealLib.h"

#include "LevelEditor.h"
#include "SPythonDocumentation.h"

DEFINE_LOG_CATEGORY(LogPythonEditor)

static const FName PythonEditorTabName("PyEditor");
static const FName PythonShelfEditorTabName("PyShelf");

#define LOCTEXT_NAMESPACE "FPythonEditorModule"

void FPythonEditorModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	FPythonEditorStyle::Initialize();
	FPythonEditorStyle::ReloadTextures();
	

	//Create scripts directory
	if (!FPaths::DirectoryExists(FPythonEditorModule::GetProjectScriptDir()))
	{
		FPlatformFileManager::Get().GetPlatformFile().CreateDirectoryTree(*FPythonEditorModule::GetProjectScriptDir());
	}

	//Create scripts temps directory
	if (!FPaths::DirectoryExists(FPythonEditorModule::GetScriptSavedDire()))
	{
		FPlatformFileManager::Get().GetPlatformFile().CreateDirectoryTree(*FPythonEditorModule::GetScriptSavedDire());
	}

	//Init Shelf toolkit (this is not a real toolkit, that is why we init here) will have some ram hit but is like 1 or 2 mb depending on how many shelfs you have
	TSharedRef<FPythonShelfToolkit> NewShelfToolKit(new FPythonShelfToolkit());
	ShelfToolKit = NewShelfToolKit;

	// Add code editor extension to main menu
	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	{
		TSharedPtr<FExtender> Extender = MakeShareable(new FExtender());
		Extender->AddMenuExtension("LevelEditor",EExtensionHook::First,TSharedPtr<FUICommandList>(),FMenuExtensionDelegate::CreateRaw(this, &FPythonEditorModule::ExtendMenu));
		LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(Extender);
	}

	// Register a tab spawner so that our tab can be automatically restored from layout files
	FGlobalTabmanager::Get()->RegisterTabSpawner(PythonEditorTabName, FOnSpawnTab::CreateStatic(&FPythonEditorModule::SpawnPythonEditorTab))
		.SetDisplayName(LOCTEXT("PythonEditorTabTitle", "PyEditor"))
		.SetMenuType(ETabSpawnerMenuType::Hidden);

	// Register a tab spawner so that our tab can be automatically restored from layout files
	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(PythonShelfEditorTabName, FOnSpawnTab::CreateRaw(this, &FPythonEditorModule::SpawnShelfEditorTab))
		.SetDisplayName(LOCTEXT("FShelfsEditorTabTitle", "PyShelf"))
		.SetMenuType(ETabSpawnerMenuType::Hidden);

	//Get lasted installed python modules
	FAutoCompleteWorker::LoadPythonInstalledModules();

	//~ Register Script directory as module holder sys.path.append(OUR_MODULE)
	ResisterPythonUserModules();
}

void FPythonEditorModule::ShutdownModule()
{
	FPythonEditorStyle::Shutdown();
	FPythonEditorCommands::Unregister();
	FGlobalTabmanager::Get()->UnregisterTabSpawner(PythonEditorTabName);
	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(PythonShelfEditorTabName);
}

FString FPythonEditorModule::GetProjectScriptDir()
{
	return FPaths::ConvertRelativePathToFull(FPaths::ProjectDir()) + "Scripts/PyScripts/";
}

FString FPythonEditorModule::GetScriptSavedDire()
{
	return FPaths::ProjectDir() + "Scripts/Saved/";
}

TSharedRef<SDockTab> FPythonEditorModule::SpawnShelfEditorTab(const FSpawnTabArgs& TabArgs)
{
	check(ShelfToolKit);
	ShelfToolKit->Init(GetMutableDefault<UScriptShelfs>());
	return ShelfToolKit->GetDockTab();
}

void FPythonEditorModule::OpenPyShelf()
{
	FGlobalTabmanager::Get()->InvokeTab(PythonShelfEditorTabName);
}

void FPythonEditorModule::ExtendMenu(class FMenuBuilder& MenuBuilder)
{
	MenuBuilder.AddSubMenu(
		LOCTEXT("PythonEditorSubMenu", "Python"),
		LOCTEXT("PythonEditorSubMenuToolTip", "Check submenu for pythonic options"),
		FNewMenuDelegate::CreateRaw(this, &FPythonEditorModule::PythonSubMenu),
		false,
		FSlateIcon(FPythonEditorStyle::Get().GetStyleSetName(), "PythonEditor.FileIcon")
	);
}

void FPythonEditorModule::PythonSubMenu(class FMenuBuilder& MenuBuilder)
{
	MenuBuilder.AddMenuEntry
	(
		LOCTEXT("PythonEditorTabTitle", "PyEditor"),
		LOCTEXT("PythonEditorTooltipText", "Open the Python Editor tab."),
		FSlateIcon(FPythonEditorStyle::Get().GetStyleSetName(), "PythonEditor.FileIcon"),
		FUIAction
		(
			FExecuteAction::CreateStatic(&FPythonEditorModule::OpenPythonEditor)
		)
	);

	MenuBuilder.AddMenuEntry
	(
		LOCTEXT("FShelfsEditorTabTitle", "PyShelf"),
		LOCTEXT("FShelfsEditorToolTip", "Open the PyShelf"),
		FSlateIcon(FPythonEditorStyle::Get().GetStyleSetName(), "PythonEditor.Shelf"),
		FUIAction
		(
			FExecuteAction::CreateRaw(this, &FPythonEditorModule::OpenPyShelf)
		)
	);
}

TSharedRef<SDockTab> FPythonEditorModule::SpawnPythonEditorTab(const FSpawnTabArgs& TabArgs)
{
	TSharedRef<FPythonEditorToolKit> NewPythonEditor(new FPythonEditorToolKit());
	NewPythonEditor->InitCodeEditor(EToolkitMode::Standalone, TSharedPtr<class IToolkitHost>(), GetMutableDefault<UPythonProject>());
	return FGlobalTabmanager::Get()->GetMajorTabForTabManager(NewPythonEditor->GetTabManager().ToSharedRef()).ToSharedRef();
}

void FPythonEditorModule::OpenPythonEditor()
{
	SpawnPythonEditorTab(FSpawnTabArgs(TSharedPtr<SWindow>(), FTabId()));
}

void FPythonEditorModule::ResisterPythonUserModules()
{
	RegisterFolderModule(GetProjectScriptDir(), true);
}

void FPythonEditorModule::RegisterFolderModule(const FString& Folder, const bool& Recursive)
{
	check(FPaths::DirectoryExists(Folder));

	FString PyCode =
		"import sys\n"\
		"sys.path.append(\"" + Folder + "\")\n"\
		;

	PyRun_SimpleString(
		TCHAR_TO_UTF8(*PyCode)
	);

	UE_LOG(LogPythonEditor, Warning, TEXT("Resgister Folder Module: %s"), *Folder);

	if (!Recursive) return;

	TArray<FString> FoldersFound;
	IFileManager& FileManager = IFileManager::Get();
	FString FolderPath = Folder / TEXT("*");
	FileManager.FindFiles(FoldersFound, *FolderPath, false, true);

	for (auto& Dir : FoldersFound)
	{
		FString FullDirectory = Folder + Dir + "/";
		RegisterFolderModule(FullDirectory, Recursive);
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FPythonEditorModule, PythonEditor)
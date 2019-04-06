//Copyright 2019, Jorge Calleros Ramirez (Karma), All rights reserved.

#pragma once
#include "Framework/Docking/TabManager.h"
#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

DECLARE_LOG_CATEGORY_EXTERN(LogPythonEditor, Log, All);

class FToolBarBuilder;
class FMenuBuilder;
class FPythonShelfToolkit;

class FPythonEditorModule : public IModuleInterface
{
public:
	TSharedPtr<FPythonShelfToolkit> ShelfToolKit;

public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	//~ Get Project script directory
	static FString GetProjectScriptDir();

	//~ Get Project script saved directory
	static FString GetScriptSavedDire();

	static inline FPythonEditorModule& Get()
	{
		return FModuleManager::LoadModuleChecked<FPythonEditorModule>("PythonEditor");
	}

private:


	TSharedPtr<class FUICommandList> PluginCommands;
	

	//~ Extend window menu
	void ExtendMenu(class FMenuBuilder& MenuBuilder);

	//~ Crates the python sub menu
	void PythonSubMenu(class FMenuBuilder& MenuBuilder);

	//~Handles Python editor tab spawn
	static TSharedRef<class SDockTab> SpawnPythonEditorTab(const FSpawnTabArgs& TabArgs);

	//~ Handles shelf tab spawn
	TSharedRef<class SDockTab> SpawnShelfEditorTab(const FSpawnTabArgs& TabArgs);

	//~ Open the python editor tab
	static void OpenPythonEditor();

	//~ Open shelf tab 
	void OpenPyShelf();

	//~ Register Script directory as module holder sys.path.append(OUR_MODULE)
	void ResisterPythonUserModules();

	//~ Register a unique folder recusevely or not into the sys.path of python
	static void RegisterFolderModule(const FString& Folder, const bool& Recursive);

};

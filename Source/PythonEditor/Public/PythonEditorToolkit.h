//Copyright 2019, Jorge Calleros Ramirez (Karma), All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/GCObject.h"
#include "WorkflowOrientedApp/WorkflowCentricApplication.h"
#include "Editor/Kismet/Public/WorkflowOrientedApp/WorkflowTabManager.h"
#include "AutoCompleteWorker.h"


class UPythonProject;
class FPyScriptTree;
class SPythonCodeEditor;

class FAutoCompleteWorker;

/**
 * 
 */
class FPythonEditorToolKit : public FWorkflowCentricApplication, public FGCObject
{
public:
	FPythonEditorToolKit();
	~FPythonEditorToolKit();

	//~ IToolkit interface
	virtual void RegisterTabSpawners(const TSharedRef<class FTabManager>& TabManager) override;
	virtual void UnregisterTabSpawners(const TSharedRef<FTabManager>& InTabManager) override;
	// End of IToolkit interface

private:
	//~ Handler for every tab generation
	TSharedRef<SDockTab> HandleTabManagerSpawnTab(const FSpawnTabArgs& Args, FName TabIdentifier);

public:

	//~ FAssetEditorToolkit
	virtual FName GetToolkitFName() const override;
	virtual FText GetBaseToolkitName() const override;
	virtual FText GetToolkitName() const override;
	virtual FText GetToolkitToolTipText() const override;
	virtual FLinearColor GetWorldCentricTabColorScale() const override;
	virtual FString GetWorldCentricTabPrefix() const override;
	// End of FAssetEditorToolkit

	// FSerializableObject interface
	virtual void AddReferencedObjects(FReferenceCollector& Collector) override;
	// End of FSerializableObject interface

	static TSharedPtr<FPythonEditorToolKit> Get()
	{
		return PythonToolKit.Pin();
	}

	FAutoCompleteWorker* GetAutoCompleteWorker()
	{
		return AutoCompleteWorker;
	}
	
public:
	//~ Initialize the code editor 
	void InitCodeEditor(const EToolkitMode::Type Mode, const TSharedPtr< class IToolkitHost >& InitToolkitHost, UPythonProject* CodeProject);

	//~ Get Code from script tree
	FString GetCode(TSharedPtr<FPyScriptTree> InScript);

	//~ Close or delete tab
	void CloseOrDeleteFile(TSharedPtr<FPyScriptTree> InScript);

	//~ Get selected Python Editor widget
	TSharedPtr<SPythonCodeEditor> GetCurrentPythonCodeEditor(TSharedPtr<FPyScriptTree> InScript) const;

	//~ Save current python file in edition
	virtual void SaveAsset_Execute() override;

	//~ Find python file in windows explorer
	virtual void FindInContentBrowser_Execute() override;

	//~ Run current python file in edition
	virtual void RunScript_Execute();

	//~ Open docs tab
	virtual void OpenDocs(const FString& Link);

	//~ Creates a new folder
	virtual void CreateNewScriptFolder(TSharedPtr<FPyScriptTree> ScriptTree, const FString& Name);

	//~ Creates a new script
	virtual void CreateNewScript(TSharedPtr<FPyScriptTree> ScriptTree, const FString& Name);

	//~ Open tab to edit file
	virtual void OpenFile(TSharedPtr<FPyScriptTree> ScriptTree);

	//~ Remove file
	virtual void DeleteFile(TSharedPtr<FPyScriptTree> ScriptTree);

	//~ Close tab
	virtual void RenameFileOrFolder(TSharedPtr<FPyScriptTree> ScriptTree, const FString& NewName);

private:
	//~ Handler for python editor normal tabs( not for editing a file)
	TSharedRef<SDockTab> HandleScriptTab(const FSpawnTabArgs& Args, TSharedPtr<FPyScriptTree> Script);

	//~ Retrieves las tab selected when open or change focus of editable script tab
	void OnTabActive(TSharedRef<SDockTab> Tab, ETabActivationCause Cause, TSharedPtr<FPyScriptTree> Script, TSharedPtr<SPythonCodeEditor> InCodeEditor);

	//~ Retrieves last selection from the python file browser
	void OnFileBrowserSelectionChanged(TSharedPtr<FPyScriptTree> NewSelection);

	//~ Check whenever a tab is closed to perform some clean up
	void OnTabClosed(TSharedRef<SDockTab>, FName ID);

	//~ Remove Script editor from the tab list
	void RemoveScriptEditor(const FString& Name);

	//~ Restore all tabs where opened from the last session
	void RestoreTabs();


protected:
	/* Binds the UI commands to delegates.*/
	void BindCommands();

	/* Build Main Menu toolbar for Editable mesh editor*/
	void ExtendToolBar();

protected:

	/** The code project we are currently editing */
	TWeakObjectPtr<UPythonProject> PythonProject;

	//~ hold the unique Python editor pointer
	static TWeakPtr<FPythonEditorToolKit> PythonToolKit;

	//~ List with all the tabs are open at a given moment
	TMap<FString, TSharedPtr<SPythonCodeEditor>> OpenedScripts;

	//~ Holds the current script we are modifying
	TSharedPtr<FPyScriptTree> CurrentScript;

	//~ Holds the last file browser selection
	TSharedPtr<FPyScriptTree> CurrentBroswerScriptSelected;

	//~ Holds the last python code editor widget
	TSharedPtr<SPythonCodeEditor> CurrentCodeEditor;

	//~ Hold WebBroswerReference
	TSharedPtr<class SPythonDocumentation> PythonDocs;

	//~ Hold the auto complete thread
	FAutoCompleteWorker* AutoCompleteWorker;

};

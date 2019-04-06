//Copyright 2019, Jorge Calleros Ramirez (Karma), All rights reserved.

#pragma once
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Widgets/SCompoundWidget.h"
#include "Widgets/Views/STreeView.h"
#include "CoreMinimal.h"
#include "IPythonContextMenu.h"

//~ Type of element in view
enum EScriptTreeType
{
	Directory,
	File,
};

//~ Tree view element
class FPyScriptTree
{

public:
	//~ Name to be display
	FString Name;

	//~ it can be folder or python file
	FString Path;

	//~ Children
	TArray<TSharedPtr<FPyScriptTree>> Children;

	//~ Element tree type
	EScriptTreeType Type;

	FPyScriptTree() {
		Type = EScriptTreeType::Directory;
	};
};


DECLARE_DELEGATE_OneParam(FOnElemSelected, TSharedPtr<FPyScriptTree>)

/**
 * File browser widget for python files
 */
class SPythonFileBrowser : public SCompoundWidget , public IPythonContextMenu
{
public:
	SLATE_BEGIN_ARGS(SPythonFileBrowser)
	{}
	SLATE_EVENT(FOnElemSelected, OnElemSelected)
	SLATE_END_ARGS()

public:

	//~ SWidget
	virtual FReply OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;

private:
	//~ STreeView
	void MouseButtonDoubleClick(TSharedPtr<FPyScriptTree> Script);
	TSharedRef<ITableRow> OnGenerateRow(TSharedPtr<FPyScriptTree> Item, const TSharedRef<STableViewBase>& OwnerTable);
	void OnGetChildren(TSharedPtr<FPyScriptTree> Item, TArray<TSharedPtr<FPyScriptTree>>& OutChildren);
	void OnSelectionChanged(TSharedPtr<FPyScriptTree> Item);
	//~

	//~ Gathers all tree, it ask for the root to begin
	void GetChildrenTree(TSharedPtr<FPyScriptTree> InScriptTree);

private:
	//~ Delegates to send last element selected
	FOnElemSelected OnElemSelected;

	//~ Holds last selection
	TSharedPtr<FPyScriptTree> LastSelection;

	//~ STreeView widget
	TSharedPtr<STreeView<TSharedPtr<FPyScriptTree>>> ScriptTree;

	//~ The directory, basically root folder
	TArray<TSharedPtr<FPyScriptTree>> RootDirectory;

	//~ Container for the STreeView, an easy way to refresh
	TSharedPtr<SHorizontalBox> Container;

	//~ All item widgets
	TArray<TSharedPtr<class SPythonFileBrowserItem>> Items;

private:

	//~ IPythonContextMenu
	virtual void CreateNew() override;
	virtual void Delete() override;
	virtual void Edit() override;
	virtual void Rename() override;
	//~

	//~ Calls create new folder from toolkit
	virtual void CreateNewFolder();

	//~ Open some file or folder in windows explorer
	void FindInExplorer();
	

public:
	/** Widget constructor */
	void Construct(const FArguments& Args);

	//~ Update Widget
	void Update();

	//~ Request close tab from toolkit
	void CloseFile(TSharedPtr<FPyScriptTree> ScriptToClose);

	//~ Get Last selection
	TSharedPtr<FPyScriptTree> GetLastSelection();

	//~ Clear the selection
	void ClearSelection();

	//~ Create context menu  options
	void CreateContextMenuOpt(const bool& bFullContextMenu);

};

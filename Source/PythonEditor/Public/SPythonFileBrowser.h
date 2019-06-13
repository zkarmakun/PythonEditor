//Copyright 2019, Jorge Calleros Ramirez (Karma), All rights reserved.

#pragma once
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Widgets/SCompoundWidget.h"
#include "Widgets/Views/STreeView.h"
#include "CoreMinimal.h"
#include "IPythonContextMenu.h"
#include "TextFilter.h"
#include "TreeFilterHandler.h"

//~ Type of element in view
enum EScriptTreeType
{
	None,
	Root,
	Directory,
	File,
};

//~ Tree view element
class FPyScriptModel
{

public:
	//~ Name to be display
	FString Name;

	//~ it can be folder or python file
	FString Path;

	//~ Children
	TArray<TSharedPtr<FPyScriptModel>> Children;

	TSharedPtr<FPyScriptModel> Parent;

	//~ Element tree type
	EScriptTreeType Type;

	FPyScriptModel() {
		Type = EScriptTreeType::Directory;
		Name = FString();
		Path = FString();
		Children = TArray<TSharedPtr<FPyScriptModel>>();
	};

	void AddChild(TSharedPtr<FPyScriptModel>& Child, TSharedPtr<FPyScriptModel>& InParent)
	{
		Child->Parent = InParent;
		Children.Add(Child);
	}
};



DECLARE_DELEGATE_OneParam(FOnElemSelected, TSharedPtr<FPyScriptModel>)

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

	//~ Widget for search
	void OnSearchBoxCommitted(const FText& Text, ETextCommit::Type TextCommitType);
	void OnSearchBoxChanged(const FText& Text);
	//~

	//~ STreeView
	void OnExpansionChanged(TSharedPtr<FPyScriptModel> Item, bool bValue);

	/** Transforms the Script into a searchable string */
	void TransformScriptToString(TSharedPtr<FPyScriptModel> Script, OUT TArray< FString >& Array);

	void WidgetHierarchy_OnGetChildren(TSharedPtr<FPyScriptModel> InParent, TArray< TSharedPtr<FPyScriptModel> >& OutChildren);


	//~ Here rebuild ***************************************************************
	void RebuldTreeView();

	//~ STreeView
	void MouseButtonDoubleClick(TSharedPtr<FPyScriptModel> Script);
	TSharedRef<ITableRow> OnGenerateRow(TSharedPtr<FPyScriptModel> Item, const TSharedRef<STableViewBase>& OwnerTable);
	void OnGetChildren(TSharedPtr<FPyScriptModel> Item, TArray<TSharedPtr<FPyScriptModel>>& OutChildren);
	void OnSelectionChanged(TSharedPtr<FPyScriptModel> Item);
	//~

	//~ Gathers all tree, it ask for the root to begin
	void GetChildrenTree(TSharedPtr<FPyScriptModel> InScriptTree, TArray<TSharedPtr<FPyScriptModel>>& LinearOut);

public:

	//~ SWidget
	virtual FReply OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;

	/** Widget constructor */
	void Construct(const FArguments& Args);

	//~ Update Widget
	void Update();

	//~ Request close tab from toolkit
	void CloseFile(TSharedPtr<FPyScriptModel> ScriptToClose);

	//~ Get Last selection
	TSharedPtr<FPyScriptModel> GetLastSelection();

	//~ Clear the selection
	void ClearSelection();

	//~ Create context menu  options
	void CreateContextMenuOpt(const EScriptTreeType& Type);

private:
	//~ Delegates to send last element selected
	FOnElemSelected OnElemSelected;

	//~ Holds last selection
	TSharedPtr<FPyScriptModel> LastSelection;

	//~ STreeView widget
	TSharedPtr<STreeView<TSharedPtr<FPyScriptModel>>> ScriptTreeView;

	//~ The directory, basically root folder
	TArray<TSharedPtr<FPyScriptModel>> RootDirectory;

	//~ Container 
	TSharedPtr<SVerticalBox> Container;

	//~ All item widgets
	TArray<TSharedPtr<class SPythonFileBrowserItem>> Items;

	//~ Search box
	TSharedPtr<class SSearchBox> SearchBox;

	//~ Expanded items;
	TSet<TSharedPtr<FPyScriptModel>> ExpandedItems;

	/** Handles filtering the hierarchy based on an IFilter. */
	TSharedPtr< TreeFilterHandler< TSharedPtr<FPyScriptModel> > > FilterHandler;

	typedef TTextFilter< TSharedPtr<FPyScriptModel> > PyTextFilter;

	/** The filter used by the search box */
	TSharedPtr<PyTextFilter> SearchBoxPyFilter;

};

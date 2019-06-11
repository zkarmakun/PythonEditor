//Copyright 2019, Jorge Calleros Ramirez (Karma), All rights reserved.

#pragma once
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Widgets/SCompoundWidget.h"
#include "CoreMinimal.h"
#include "SPythonFileBrowser.h"
#include "IPythonContextMenu.h"

class FPyScriptTree;
enum EScriptTreeType;


/**
 * 
 */
class PYTHONEDITOR_API SPythonFileBrowserItem : public SCompoundWidget 
{
public:

	SLATE_BEGIN_ARGS(SPythonFileBrowserItem)
	{}

	SLATE_ARGUMENT(TSharedPtr<FPyScriptTree>, InScriptTree)
	SLATE_ARGUMENT(TSharedPtr<class SPythonFileBrowser>, InOwner)
	SLATE_EVENT(FOnElemSelected, OnSelectionChanged)
	SLATE_END_ARGS()

	//~ SWidget
	virtual FReply OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual FReply OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual FReply OnDragDetected(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	//~

private:
	//~ Hold if this item is selected
	bool bIsSelected = false;

	//~ On Selection changed
	FOnElemSelected OnSelectionChanged;

private:
	//~ Hold this tree item
	TSharedPtr<FPyScriptTree> ScriptTree;

	//~ A reference to the file browser owner
	TSharedPtr<class SPythonFileBrowser> PythonFileBrowser;

	//~ Widget to draw selection
	TSharedPtr<class SBorder> SelectedBorder;

public:
	/** Widget constructor */
	void Construct(const FArguments& Args);

	//~ Force select this item
	void Select(const bool& bSelect);

	bool IsSame(TSharedPtr<FPyScriptTree> Compare);

	TSharedPtr<FPyScriptTree> GetItem() const;
};


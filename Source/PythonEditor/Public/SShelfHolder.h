//Copyright 2019, Jorge Calleros Ramirez (Karma), All rights reserved.

#pragma once
#include "ScriptShelfs.h"
#include "CoreMinimal.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Widgets/SCompoundWidget.h"

class SHorizontalBox;

/**
 * Widget container of shelf buttons
 */
class  SShelfHolder : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SShelfHolder)
	{}
	SLATE_ARGUMENT(FShelfTab*, Shelf)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);


private:

	//~ shelf reference
	FShelfTab* Shelf;

	//~ Button container
	TSharedPtr<SHorizontalBox> Container;

	//~ SWidget
	virtual void OnDragEnter(const FGeometry& MyGeometry, const FDragDropEvent& DragDropEvent) override;
	virtual void OnDragLeave(const FDragDropEvent& DragDropEvent);
	virtual FReply OnDrop(const FGeometry& MyGeometry, const FDragDropEvent& DragDropEvent) override;
	//~

private:
	//~ update widget redrawuing all buttons inside
	void UpdateButtons();


};

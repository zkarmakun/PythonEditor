//Copyright 2019, Jorge Calleros Ramirez (Karma), All rights reserved.

#pragma once
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Widgets/SCompoundWidget.h"
#include "CoreMinimal.h"
#include "ScriptShelfs.h"
#include "IPythonContextMenu.h"

class SImage;
class STextBlock;

DECLARE_DELEGATE_OneParam(FOnShelfTabSelected,const FName&);

/*
* Widget that represents a shelf tab
*/

class SShelfTab : public SCompoundWidget , public IPythonContextMenu
{
public:

	SLATE_BEGIN_ARGS(SShelfTab)
	{}

	SLATE_EVENT(FOnShelfTabSelected, OnShelfTabSelected)
	SLATE_ARGUMENT(FName, Label)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);



private:
	//~ SWidget
	virtual FReply OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent);
	//~

private:
	//~ whenever is this tab selected
	bool bIsSelected;

	//~ Shelf friendly name
	FName ShelfName;

	//~ Delegate that triggers when this shelf is selected
	FOnShelfTabSelected OnShelfTabSelected;

	//~ Selected color
	const FLinearColor Selected = FLinearColor::Green;

	//~ Not selected color
	const FLinearColor NoneSelected = FLinearColor(0, 0, 0, 0);

	//~ Background image
	TSharedPtr<SImage> Image;

	//~ Widget for the shelf name
	TSharedPtr<STextBlock> Tittle;

	//~ Internal call to select a tab
	void SelectTab_Internal();


	void ShelfTabSelected();

private:
	//~ IShelfContextMenu
	virtual void CreateContextMenu() override;
	virtual void Rename() override;
	virtual void Delete() override;
	virtual void CreateNew() override;
	virtual void MoveLeft() override;
	virtual void MoveRight() override;

public:

	//~ Check if is selected
	bool IsSelected() const;

	//~ Get shelf name
	FName GetShelfName() const;

	//~Select this shelf
	void SelectTab(bool bSelected);
};

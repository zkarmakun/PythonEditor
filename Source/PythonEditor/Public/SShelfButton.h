//Copyright 2019, Jorge Calleros Ramirez (Karma), All rights reserved.

#pragma once
#include "IPythonContextMenu.h"
#include "ScriptShelfs.h"
#include "CoreMinimal.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Widgets/SCompoundWidget.h"
#include "Runtime/SlateCore/Public/Brushes/SlateImageBrush.h"
#include "Runtime/SlateCore/Public/Brushes/SlateDynamicImageBrush.h"

/**
 * Widget represtation of shelf button
 */
class  SShelfButton : public SCompoundWidget , public IPythonContextMenu
{
public:
	SLATE_BEGIN_ARGS(SShelfButton)
	{}
	SLATE_ARGUMENT(FShelfButtonInfo*, ShelfButton)
	SLATE_ARGUMENT(FName, ShelfOwnerID)

	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);
	~SShelfButton();

	//~ Execute python simple string with this code
	FReply ExecuteScript();

private:
	//~ SWidget
	virtual FReply OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual FReply OnMouseButtonDoubleClick(const FGeometry& InMyGeometry, const FPointerEvent& InMouseEvent) override;
	//~


	virtual void SetIcon();

	//~ IShelfContextMenu
	virtual void CreateContextMenu() override;
	virtual void Rename() override;
	virtual void Edit() override;
	virtual void Delete() override;
	virtual void MoveLeft() override;
	virtual void MoveRight() override;
	//~
private:

	//~ Button reference
	TSharedPtr<class SButton> Button;

	//~ Pointer to shelf button info 
	FShelfButtonInfo* ShelfButton;

	//~ ID
	FName ShelfOwnerID;

	FButtonStyle* Style = nullptr;
	FSlateDynamicImageBrush* DynamicBrushe = nullptr;
};

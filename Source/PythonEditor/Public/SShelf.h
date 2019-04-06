//Copyright 2019, Jorge Calleros Ramirez (Karma), All rights reserved.

#pragma once
#include "ScriptShelfs.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Widgets/SCompoundWidget.h"
#include "CoreMinimal.h"


class SShelfTab;
class SHorizontalBox;

/**
 * Main widget to represent all shelfs
 */
class SShelf : public SCompoundWidget
{
public:

	SLATE_BEGIN_ARGS(SShelf)
	{}

	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

private:
	//~ Redraw shelfs
	void UpdateShelfs();

	//~ Redraw buttons
	void UpdateButtons();

	//~ Generate widget for shelf
	void GenerateShelfTabButtons(FShelfTab* InShelf);

	//~ Gets when a shelf is selected
	void OnShelfSelected(const FName& InShelf);


private:
	//~ List for all shelf tab widgets
	TArray<TSharedPtr<SShelfTab>> ShelfTabsWidgets;

	//~ Shelf holder container
	TSharedPtr<SHorizontalBox> ShelfHolderContainer;

	//~ Shelf header container
	TSharedPtr<SHorizontalBox> ShelfHeaderContainer;

	//~ Reference to UScriptShelf config class
	TWeakObjectPtr<UScriptShelfs> ScriptShelfObject;

public:
	//~ Redraw whole widget
	void UpdateWidget();
};

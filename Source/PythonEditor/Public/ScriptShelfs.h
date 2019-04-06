//Copyright 2019, Jorge Calleros Ramirez (Karma), All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScriptShelfs.generated.h"

/*
* Struct container for Shelf buttons
*/
USTRUCT()
struct FShelfButtonInfo
{
	GENERATED_BODY()

public:
	//~ Friendly name to be display in the widget
	UPROPERTY()
		FString DisplayName;

	//~ FName composed by a unique FGUid 
	UPROPERTY()
		FName ID;

	//~ The python code hold in this button
	UPROPERTY()
		FString Code;

	//~ PNG data for and icon 30x30 hard coded
	UPROPERTY()
		TArray<uint8> Icon;

	FShelfButtonInfo() {
	};

	FShelfButtonInfo(FString InName) {
		DisplayName = InName;
	};
};

/*
* struct to hold the shelf info
*/
USTRUCT()
struct FShelfTab
{
	GENERATED_BODY()

public:
	//~ Shelf name, it cannot be 2 equals the system will not allow it
	UPROPERTY()
		FName TabId;

	//~ List of every button
	UPROPERTY()
		TArray<FShelfButtonInfo> Buttons;

	FShelfTab()
	{

	};

	FShelfTab(FName InTabID)
	{
		TabId = InTabID;
	};

	bool operator==(const FShelfTab& OtherTab)
	{
		return TabId.ToString() == OtherTab.TabId.ToString();
	}

	bool operator!=(const FShelfTab& OtherTab)
	{
		return TabId.ToString() != OtherTab.TabId.ToString();
	}
};

/*
*	Config class container of all shelfs
*/

UCLASS(/*Config = ScriptShelfs, defaultconfig*/)
class UScriptShelfs : public UObject
{

	GENERATED_BODY()

private:
	//~ Get Index if the shelf does exist
	int32 FindShelf(const FName& InID);

	//~ Get Button Index if the button does exist in shelf index
	int32 FindButton(int32& OutShelfIndex, const FName& ShelfID, const FName& ButtonID);

	//~ Whenever a shelf contain already a button
	bool ContainButton(const int32& IdIndex, const FShelfButtonInfo& ButtonInfo);

public:
	UScriptShelfs();
	
	UPROPERTY(/*Config, */EditAnywhere, Category = "Shelfs")
		int32 LastSelectionID;

	UPROPERTY(/*Config, */EditAnywhere, Category = "Shelfs")
		TArray<FShelfTab> Tabs;

	//~ Gets shelf file folder. This is where we store our custom binary
	FString GetSavedShelfFilePath() const;

	//~ Saves all shelfs
	void SaveShelfs();

	//~ Load shelfs
	void LoadShelfs();

	//~ Remove shelf if ID exist
	bool RemoveShelf(const FName& InID);

	//~ Check if shelf exist
	bool ContainsShelf(const FName& InID);

	//~ Create a new shelf, fails if shelf already exist
	bool CreateNewShelf(const FName& NewID);

	//~ Rename shelf if exists
	bool RenameShelf(const FName& OldID, const FName& NewId);

	//~ Shift shelf position to the left, clamped
	bool ShiftLeft(const FName& InID);

	//~ Shift shelf position to the right, clamped
	bool ShiftRight(const FName& InID);

	//~ Add button to shelf if shelf exist
	bool AddButtonToShelf(const FName& InID, const FShelfButtonInfo& ButtonInfo);

	//~ Remove button from shelf
	bool RemoveButtonFromShelf(const FName& ShelfID, const FName& ButtonID);

	//~ Rename button from shelf
	bool RenameButton(const FName& ShelfID, const FName& ButtonID, const FString& DisplayName);

	//~ Shift button position array to the left
	bool ShiftButtonLeft(const FName& ShelfID, const FName& ButtonID);

	//~ Shift button position array to the right
	bool ShiftButtonRight(const FName& ShelfID, const FName& ButtonID);

	//~ Set button's icon, this will produce a 30x30 PNG data from no matter what image you have picked
	bool SetButtonIcon(const FName& ShelfID, const FName& ButtonID);

};

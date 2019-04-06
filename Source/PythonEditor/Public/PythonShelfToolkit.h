//Copyright 2019, Jorge Calleros Ramirez (Karma), All rights reserved.

#pragma once
#include "Widgets/SWidget.h"
#include "UObject/GCObject.h"
#include "Toolkits/IToolkitHost.h"
#include "Editor/UnrealEd/Public/EditorUndoClient.h"
#include "Editor/UnrealEd/Public/Toolkits/AssetEditorToolkit.h"
#include "EngineMinimal.h"
#include "CoreMinimal.h"
#include "ScriptShelfs.h"
#include "UObject/GCObject.h"

class SDockTab;
class SShelf;

/**
 * 
 */
class FPythonShelfToolkit : public TSharedFromThis<FPythonShelfToolkit>, public FGCObject
{

private:
	//~ Config class to store all the shelf information to serialize
	UScriptShelfs* ScriptShelfs;

	//~ Holds a references from the shelf widget
	TSharedPtr<SShelf> ShelfWidget;
public:
	FPythonShelfToolkit();

	// FSerializableObject interface
	virtual void AddReferencedObjects(FReferenceCollector& Collector) override;
	// End of FSerializableObject interface

	static TSharedPtr<FPythonShelfToolkit> Get();

	//~ Init basically loads the UScriptShelf config file
	void Init(UScriptShelfs* InScriptShelfs);

	//~ Creates a new SDockTab for the shelfs
	TSharedRef<SDockTab> GetDockTab();

	//~ Getter ScriptShelfs
	UScriptShelfs* GetScriptShelfs();

	//~ Remove shelf from UScriptShelfs config class and refresh shelf widget
	void DeleteShelf(const FName& ShelfID);

	//~ Create shelf for UScriptShelfs config class and refresh shelf widget
	void CreateShelf(const FName& NewShelfID);

	//~ Rename shelf for UScriptShelfs config class and refresh shelf widget
	void RenameShelf(const FName& OldShelfID, const FName& NewShelfID);

	//~ Swap array shelf to the left in UScriptShelfs config class and refresh shelf widget
	void ShiftShelfLeft(const FName& ShelfID);

	//~ Swap array shelf to the right in UScriptShelfs config class and refresh shelf widget
	void ShiftShelfRight(const FName& ShelfID);

	//~ Add a new button to the current shelf
	void AddButtonToShelf(const FName& ShelfID, const FShelfButtonInfo& ButtonInfo);

	//~ Remove button from shelf
	void RemoveButtonFromShelf(const FName& ShelfID, const FName& ButtonID);

	//~ Swap shelf button to the left
	void ShiftButtonLeft(const FName& ShelfID, const FName& ButtonID);

	//~ Swap shelf button to the right
	void ShiftButtonRight(const FName& ShelfID, const FName& ButtonID);

	//~ Rename shelf button
	void RenameButton(const FName& ShelfID, const FName& ButtonID, const FString& DisplayName);

	//~ Set shelf button icon // this generates a custom ID for the slate registry
	void SetButtonIcon(const FName& ShelfID, const FName& ButtonID);

};

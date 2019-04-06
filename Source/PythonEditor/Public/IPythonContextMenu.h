//Copyright 2019, Jorge Calleros Ramirez (Karma), All rights reserved.

#pragma once
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "CoreMinimal.h"

DECLARE_DELEGATE_OneParam(FOnConfirmReceived, const bool&)
DECLARE_DELEGATE_OneParam(FOnInputReceived, const FText&)


class SWidget;
/**
 * 
 */
class IPythonContextMenu
{
public:
	virtual void CreateContextMenu() {}
	virtual void Rename() {}
	virtual void Edit() {}
	virtual void Delete() {}
	virtual void CreateNew() {}
	virtual void MoveLeft() {}
	virtual void MoveRight() {}
	virtual void OnConfirm(const bool&) {}
	virtual void OnInputReceived(const FText&) {}
};

class FPythonContextMenu
{
public:
	/*
		Spawn a confirm menu with ok or cancel before continue with a task
		@ Owner			- Widget that owns this pop up
		@ InTittle		- pop up tittle
		@ Action		- Delegate to output the status
		@ MenuOffset	- optional pixel offset
	*/
	static void ConfirmMenu(TSharedRef<SWidget> Owner, const FText& InTittle, FOnConfirmReceived Action, FVector2D MenuOffset = FVector2D(50, 50));


	/*
		Crates a pop up menu to write and input and retrieved like and answer to continue a task
		@ Owner			- Widget that owns this pop up
		@ InTittle		- pop up tittle
		@ Action		- Delegate to output the text
		@ MenuOffset	- optional pixel offset
	*/
	static void InputMenu(TSharedRef<SWidget> Owner, const FText& InTittle, const FText& InitialText, FOnInputReceived Action, FVector2D MenuOffset = FVector2D(50, 50));


	/*
		Creates a pop up menu based in a menu builder
		@ Owner			- Widget that owns this pop up
		@ Builder		- Builder reference
	*/
	static void SpawnContextMenu(TSharedRef<SWidget> Owner, FMenuBuilder& Builder);
};

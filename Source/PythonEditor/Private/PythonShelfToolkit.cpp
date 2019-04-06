//Copyright 2019, Jorge Calleros Ramirez (Karma), All rights reserved.

#include "PythonShelfToolkit.h"
#include "PythonEditor.h"
#include "widgets/Docking/SDockTab.h"
#include "Runtime/Core/Public/Templates/SharedPointer.h"
#include "SShelf.h"
#include "PythonEditor.h"


FPythonShelfToolkit::FPythonShelfToolkit()
{

}

void FPythonShelfToolkit::AddReferencedObjects(FReferenceCollector& Collector)
{

}

TSharedPtr<FPythonShelfToolkit> FPythonShelfToolkit::Get()
{
	return FPythonEditorModule::Get().ShelfToolKit;
}

void FPythonShelfToolkit::Init(UScriptShelfs* InScriptShelfs)
{
	check(InScriptShelfs);
	ScriptShelfs = InScriptShelfs;
	InScriptShelfs->LoadShelfs();
}

TSharedRef<class SDockTab> FPythonShelfToolkit::GetDockTab()
{
	return SNew(SDockTab)
		.TabRole(NomadTab)
		[
			SAssignNew(ShelfWidget, SShelf)
		];
}

UScriptShelfs* FPythonShelfToolkit::GetScriptShelfs()
{
	return ScriptShelfs;
}

void FPythonShelfToolkit::DeleteShelf(const FName& ShelfID)
{
	if (ScriptShelfs->RemoveShelf(ShelfID))
	{
		ScriptShelfs->SaveShelfs();
		ShelfWidget->UpdateWidget();
		UE_LOG(LogPythonEditor, Log, TEXT("Delete shelf: %s"), *ShelfID.ToString());
	}
	
}

void FPythonShelfToolkit::CreateShelf(const FName& NewShelfID)
{
	if (ScriptShelfs->CreateNewShelf(NewShelfID))
	{
		ScriptShelfs->SaveShelfs();
		ShelfWidget->UpdateWidget();
		UE_LOG(LogPythonEditor, Log, TEXT("Create new shelf: %s"), *NewShelfID.ToString());
	}
}

void FPythonShelfToolkit::RenameShelf(const FName& OldShelfID, const FName& NewShelfID)
{
	if (ScriptShelfs->RenameShelf(OldShelfID, NewShelfID))
	{
		ScriptShelfs->SaveShelfs();
		ShelfWidget->UpdateWidget();
		UE_LOG(LogPythonEditor, Log, TEXT("Rename shelf form: %s m to: %s"), *OldShelfID.ToString(), *NewShelfID.ToString());
	}
	
}

void FPythonShelfToolkit::ShiftShelfLeft(const FName& ShelfID)
{
	if (ScriptShelfs->ShiftLeft(ShelfID))
	{
		ScriptShelfs->SaveShelfs();
		ShelfWidget->UpdateWidget();
		UE_LOG(LogPythonEditor, Log, TEXT("Shift shelf to left: %s"), *ShelfID.ToString());
	}
}

void FPythonShelfToolkit::ShiftShelfRight(const FName& ShelfID)
{
	if (ScriptShelfs->ShiftRight(ShelfID))
	{
		ScriptShelfs->SaveShelfs();
		ShelfWidget->UpdateWidget();
		UE_LOG(LogPythonEditor, Log, TEXT("Shift shelf to Right: %s"), *ShelfID.ToString());
	}
}

void FPythonShelfToolkit::AddButtonToShelf(const FName& ShelfID, const FShelfButtonInfo& ButtonInfo)
{
	if (ScriptShelfs->AddButtonToShelf(ShelfID, ButtonInfo))
	{
		ScriptShelfs->SaveShelfs();
		ShelfWidget->UpdateWidget();
		UE_LOG(LogPythonEditor, Log, TEXT("Added button to shelf: %s , Button Name %s"), *ShelfID.ToString(), *ButtonInfo.DisplayName);
	}
}

void FPythonShelfToolkit::RemoveButtonFromShelf(const FName& ShelfID, const FName& ButtonID)
{
	if (ScriptShelfs->RemoveButtonFromShelf(ShelfID, ButtonID))
	{
		ScriptShelfs->SaveShelfs();
		ShelfWidget->UpdateWidget();
		UE_LOG(LogPythonEditor, Log, TEXT("Remove button from shelf: %s, Button ID %s"), *ShelfID.ToString(), *ButtonID.ToString());
	}
}

void FPythonShelfToolkit::ShiftButtonLeft(const FName& ShelfID, const FName& ButtonID)
{
	if (ScriptShelfs->ShiftButtonLeft(ShelfID, ButtonID))
	{
		ScriptShelfs->SaveShelfs();
		ShelfWidget->UpdateWidget();
		UE_LOG(LogPythonEditor, Log, TEXT("Button shift to left from shelf: %s, Button ID %s"), *ShelfID.ToString(), *ButtonID.ToString());
	}
}

void FPythonShelfToolkit::ShiftButtonRight(const FName& ShelfID, const FName& ButtonID)
{
	if (ScriptShelfs->ShiftButtonRight(ShelfID, ButtonID))
	{
		ScriptShelfs->SaveShelfs();
		ShelfWidget->UpdateWidget();
		UE_LOG(LogPythonEditor, Log, TEXT("Button shift to right from shelf: %s, Button ID %s"), *ShelfID.ToString(), *ButtonID.ToString());
	}
}

void FPythonShelfToolkit::RenameButton(const FName& ShelfID, const FName& ButtonID, const FString& DisplayName)
{
	if (ScriptShelfs->RenameButton(ShelfID, ButtonID, DisplayName))
	{
		ScriptShelfs->SaveShelfs();
		ShelfWidget->UpdateWidget();
		UE_LOG(LogPythonEditor, Log, TEXT("Rename button from shelf: %s, Button ID %s"), *ShelfID.ToString(), *ButtonID.ToString());
	}
}

void FPythonShelfToolkit::SetButtonIcon(const FName& ShelfID, const FName& ButtonID)
{
	if (ScriptShelfs->SetButtonIcon(ShelfID, ButtonID))
	{
		ScriptShelfs->SaveShelfs();
		ShelfWidget->UpdateWidget();
		UE_LOG(LogPythonEditor, Log, TEXT("Set button icon from shelf: %s, Button ID %s"), *ShelfID.ToString(), *ButtonID.ToString());
	}
}


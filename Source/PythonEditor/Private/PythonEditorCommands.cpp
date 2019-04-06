//Copyright 2019, Jorge Calleros Ramirez (Karma), All rights reserved.

#include "PythonEditorCommands.h"

#define LOCTEXT_NAMESPACE "FPythonEditorModule"

void FPythonEditorCommands::RegisterCommands()
{
	UI_COMMAND(OpenPythonEditor, "PythonEditor", "Bring up Python Editor window", EUserInterfaceActionType::Button, FInputGesture());
	UI_COMMAND(OpenShelfs, "PyShelf", "Bring up shelfs tab", EUserInterfaceActionType::Button, FInputGesture());
	UI_COMMAND(Save, "Save", "Save the currently active document (ctrl + s)", EUserInterfaceActionType::Button, FInputChord(EModifierKey::Control, EKeys::S));
	UI_COMMAND(SaveAll, "Save All", "Save all open documents.", EUserInterfaceActionType::Button, FInputChord(EModifierKey::Control | EModifierKey::Shift, EKeys::S));
	UI_COMMAND(RunScript, "RunScript", "Run currect tab python script (ctrl + Enter)", EUserInterfaceActionType::Button, FInputChord(EKeys::F5));
}

#undef LOCTEXT_NAMESPACE

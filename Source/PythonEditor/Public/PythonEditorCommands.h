//Copyright 2019, Jorge Calleros Ramirez (Karma), All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "PythonEditorStyle.h"

class FPythonEditorCommands : public TCommands<FPythonEditorCommands>
{
public:

	FPythonEditorCommands()
		: TCommands<FPythonEditorCommands>(TEXT("PythonEditor"), NSLOCTEXT("Contexts", "PythonEditor", "PythonEditor Plugin"), NAME_None, FPythonEditorStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr<FUICommandInfo> OpenPythonEditor;
	TSharedPtr<FUICommandInfo> OpenShelfs;
	TSharedPtr<FUICommandInfo> Save;
	TSharedPtr<FUICommandInfo> SaveAll;
	TSharedPtr<FUICommandInfo> RunScript;
};

//Copyright 2019, Jorge Calleros Ramirez (Karma), All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PythonProject.generated.h"

/**
 *  This is just a config class to store what tabs where opened in the session and the next time the editor toolkit will open those again
 */
UCLASS(Config = PythonProject, defaultconfig)
class UPythonProject : public UObject
{
	GENERATED_BODY()

public:
	//~ Last Tab in use
	UPROPERTY(Config, EditAnywhere, Category = "Shelfs")
		FName LastTabFocused;

	//~ List of all tab are open
	UPROPERTY(Config, EditAnywhere, Category = "Shelfs")
		TMap<FName, FString> OpenedTabs;

	UPROPERTY(Config, EditAnywhere, Category = "Shelds")
		TMap<FString, FString> ExpanedFileBrowser;
	
};

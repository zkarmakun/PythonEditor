//Copyright 2019, Jorge Calleros Ramirez (Karma), All rights reserved.

#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "PyTools.generated.h"



/**
 * 
 */
UCLASS()
class PYTHONUTILITIES_API UPyTools : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

#if WITH_EDITOR

	UFUNCTION(BlueprintCallable, Category = "PyTool", meta = (DevelopmentOnly))
		static void SetFolderColor(FString Path, FLinearColor Color);

	UFUNCTION(BlueprintCallable, Category = "PyTool", meta = (DevelopmentOnly))
		static TArray<FString> GetAllProperties(UObject* Object);

	UFUNCTION(BlueprintCallable, Category = "PyTool", meta = (DevelopmentOnly))
		static TArray<FString> GetAllFunctions(UObject* Object);

	UFUNCTION(BlueprintCallable, Category = "PyTool", meta = (DevelopmentOnly))
		static UBlueprint* GetBlueprintFromObject(UObject* Object);

	UFUNCTION(BlueprintCallable, Category = "PyTool", meta = (DevelopmentOnly))
		static bool CopyBlueprintProperty(UBlueprint* Source, FName VarName);




	UFUNCTION(BlueprintCallable, Category = "PyTool", meta = (DevelopmentOnly))
		static void CHECKFUNCTIONS(const FString& File);

#endif

};

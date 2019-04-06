//Copyright 2019, Jorge Calleros Ramirez (Karma), All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#if WITH_EDITOR
THIRD_PARTY_INCLUDES_START
#include "Python.h"
#include "structmember.h"
THIRD_PARTY_INCLUDES_END
#endif

#include "PyUnrealLib.generated.h"

UENUM(BlueprintType)
enum class EPyAttrType : uint8
{
	None,
	Module,
	Class,
	Method,
	Enum,
	Keyword,
};

USTRUCT(BlueprintType)
struct FCustomStruct
{
	GENERATED_BODY()

	FCustomStruct()
	{

	}
};

USTRUCT(BlueprintType)
struct FSuggestion
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Python")
		FString Suggestion;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Python")
		EPyAttrType Type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Python")
		FString WordCompletiton;

	FSuggestion() {}

	FSuggestion(const FString& InSuggestion, const EPyAttrType& InType, const FString& InWordCompletiton)
	{
		Suggestion = InSuggestion;
		Type = InType;
		WordCompletiton = InWordCompletiton;
	}
};

/**
 * 
 */
UCLASS()
class PYTHONUTILITIES_API UPyUnrealLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
#if WITH_EDITOR

	UFUNCTION(BlueprintCallable, Category = "Python", meta = (DevelopmentOnly))
		static TArray<FString> GetPyModuleAttrs(const FString& ModuleName);

	static PyObject* GetPyModuleAttrs(const FString& ModuleName, int32& OutSize);

	UFUNCTION(BlueprintCallable, Category = "Python", meta = (DevelopmentOnly))
		static TArray<FString> GetPyInstalledModules();

	UFUNCTION(BlueprintCallable, Category = "Python", meta = (DevelopmentOnly))
		static void FindSuggetion(const TArray<FString>& Tokens, UPARAM(ref) TArray<FSuggestion>& OutSuggestions, UPARAM(ref) TArray<FString>& Favorites, bool FullEvaluation = false, bool bReloadModule = false);

	UFUNCTION(BlueprintCallable, Category = "Python", meta = (DevelopmentOnly))
		static bool IsValidSuggestion(const FString& InSuggetion, const FString& TrimWord);

	UFUNCTION(BlueprintCallable, Category = "Python", meta = (DevelopmentOnly))
		static bool FindCompletitionList(const FString& ModuleName, const TArray<FString>& Tokens, UPARAM(ref) TArray<FSuggestion>& OutList, bool bFullEval, UPARAM(ref) TArray<FString>& Favorites);

	UFUNCTION(BlueprintCallable, Category = "Python", meta = (DevelopmentOnly))
		static void FindSuggetionFromEditable(const FString& ExistingFile, UPARAM(ref) TArray<FSuggestion>& OutSuggestions, UPARAM(ref) TArray<FString>& Favorites);

	UFUNCTION(BlueprintCallable, Category = "Python", meta = (DevelopmentOnly))
		static void ReloadModule(const FString& Module);

	UFUNCTION(BlueprintCallable, Category = "Python", meta = (DevelopmentOnly))
		static FString GetHelp(const FString& Expression, const FString& ExintingFile, bool bIncludeFile);

	UFUNCTION(BlueprintPure, Category = "Python", meta = (DevelopmentOnly))
		static FString GetProjectScriptDir();

	static EPyAttrType GetAttrType(PyObject*& InAttr);


#endif
};

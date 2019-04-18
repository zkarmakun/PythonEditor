// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PythonUtilities/Public/PyUnrealLib.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePyUnrealLib() {}
// Cross Module References
	PYTHONUTILITIES_API UEnum* Z_Construct_UEnum_PythonUtilities_EPyAttrType();
	UPackage* Z_Construct_UPackage__Script_PythonUtilities();
	PYTHONUTILITIES_API UScriptStruct* Z_Construct_UScriptStruct_FSuggestion();
	PYTHONUTILITIES_API UScriptStruct* Z_Construct_UScriptStruct_FCustomStruct();
	PYTHONUTILITIES_API UClass* Z_Construct_UClass_UPyUnrealLib_NoRegister();
	PYTHONUTILITIES_API UClass* Z_Construct_UClass_UPyUnrealLib();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	PYTHONUTILITIES_API UFunction* Z_Construct_UFunction_UPyUnrealLib_FindCompletitionList();
	PYTHONUTILITIES_API UFunction* Z_Construct_UFunction_UPyUnrealLib_FindSuggetion();
	PYTHONUTILITIES_API UFunction* Z_Construct_UFunction_UPyUnrealLib_FindSuggetionFromEditable();
	PYTHONUTILITIES_API UFunction* Z_Construct_UFunction_UPyUnrealLib_GetHelp();
	PYTHONUTILITIES_API UFunction* Z_Construct_UFunction_UPyUnrealLib_GetProjectScriptDir();
	PYTHONUTILITIES_API UFunction* Z_Construct_UFunction_UPyUnrealLib_GetPyInstalledModules();
	PYTHONUTILITIES_API UFunction* Z_Construct_UFunction_UPyUnrealLib_GetPyModuleAttrs();
	PYTHONUTILITIES_API UFunction* Z_Construct_UFunction_UPyUnrealLib_IsValidSuggestion();
	PYTHONUTILITIES_API UFunction* Z_Construct_UFunction_UPyUnrealLib_ReloadModule();
// End Cross Module References
	static UEnum* EPyAttrType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_PythonUtilities_EPyAttrType, Z_Construct_UPackage__Script_PythonUtilities(), TEXT("EPyAttrType"));
		}
		return Singleton;
	}
	template<> PYTHONUTILITIES_API UEnum* StaticEnum<EPyAttrType>()
	{
		return EPyAttrType_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EPyAttrType(EPyAttrType_StaticEnum, TEXT("/Script/PythonUtilities"), TEXT("EPyAttrType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_PythonUtilities_EPyAttrType_Hash() { return 2891890800U; }
	UEnum* Z_Construct_UEnum_PythonUtilities_EPyAttrType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_PythonUtilities();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EPyAttrType"), 0, Get_Z_Construct_UEnum_PythonUtilities_EPyAttrType_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EPyAttrType::None", (int64)EPyAttrType::None },
				{ "EPyAttrType::Module", (int64)EPyAttrType::Module },
				{ "EPyAttrType::Class", (int64)EPyAttrType::Class },
				{ "EPyAttrType::Method", (int64)EPyAttrType::Method },
				{ "EPyAttrType::Enum", (int64)EPyAttrType::Enum },
				{ "EPyAttrType::Keyword", (int64)EPyAttrType::Keyword },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ModuleRelativePath", "Public/PyUnrealLib.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_PythonUtilities,
				nullptr,
				"EPyAttrType",
				"EPyAttrType",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
class UScriptStruct* FSuggestion::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern PYTHONUTILITIES_API uint32 Get_Z_Construct_UScriptStruct_FSuggestion_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FSuggestion, Z_Construct_UPackage__Script_PythonUtilities(), TEXT("Suggestion"), sizeof(FSuggestion), Get_Z_Construct_UScriptStruct_FSuggestion_Hash());
	}
	return Singleton;
}
template<> PYTHONUTILITIES_API UScriptStruct* StaticStruct<FSuggestion>()
{
	return FSuggestion::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FSuggestion(FSuggestion::StaticStruct, TEXT("/Script/PythonUtilities"), TEXT("Suggestion"), false, nullptr, nullptr);
static struct FScriptStruct_PythonUtilities_StaticRegisterNativesFSuggestion
{
	FScriptStruct_PythonUtilities_StaticRegisterNativesFSuggestion()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("Suggestion")),new UScriptStruct::TCppStructOps<FSuggestion>);
	}
} ScriptStruct_PythonUtilities_StaticRegisterNativesFSuggestion;
	struct Z_Construct_UScriptStruct_FSuggestion_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_WordCompletiton_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_WordCompletiton;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Type_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_Type;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Type_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Suggestion_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Suggestion;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSuggestion_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/PyUnrealLib.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FSuggestion_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSuggestion>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSuggestion_Statics::NewProp_WordCompletiton_MetaData[] = {
		{ "Category", "Python" },
		{ "ModuleRelativePath", "Public/PyUnrealLib.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FSuggestion_Statics::NewProp_WordCompletiton = { "WordCompletiton", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSuggestion, WordCompletiton), METADATA_PARAMS(Z_Construct_UScriptStruct_FSuggestion_Statics::NewProp_WordCompletiton_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FSuggestion_Statics::NewProp_WordCompletiton_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSuggestion_Statics::NewProp_Type_MetaData[] = {
		{ "Category", "Python" },
		{ "ModuleRelativePath", "Public/PyUnrealLib.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FSuggestion_Statics::NewProp_Type = { "Type", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSuggestion, Type), Z_Construct_UEnum_PythonUtilities_EPyAttrType, METADATA_PARAMS(Z_Construct_UScriptStruct_FSuggestion_Statics::NewProp_Type_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FSuggestion_Statics::NewProp_Type_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FSuggestion_Statics::NewProp_Type_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSuggestion_Statics::NewProp_Suggestion_MetaData[] = {
		{ "Category", "Python" },
		{ "ModuleRelativePath", "Public/PyUnrealLib.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FSuggestion_Statics::NewProp_Suggestion = { "Suggestion", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSuggestion, Suggestion), METADATA_PARAMS(Z_Construct_UScriptStruct_FSuggestion_Statics::NewProp_Suggestion_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FSuggestion_Statics::NewProp_Suggestion_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSuggestion_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSuggestion_Statics::NewProp_WordCompletiton,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSuggestion_Statics::NewProp_Type,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSuggestion_Statics::NewProp_Type_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSuggestion_Statics::NewProp_Suggestion,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSuggestion_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_PythonUtilities,
		nullptr,
		&NewStructOps,
		"Suggestion",
		sizeof(FSuggestion),
		alignof(FSuggestion),
		Z_Construct_UScriptStruct_FSuggestion_Statics::PropPointers,
		ARRAY_COUNT(Z_Construct_UScriptStruct_FSuggestion_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FSuggestion_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FSuggestion_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FSuggestion()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FSuggestion_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_PythonUtilities();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("Suggestion"), sizeof(FSuggestion), Get_Z_Construct_UScriptStruct_FSuggestion_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FSuggestion_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FSuggestion_Hash() { return 1918269525U; }
class UScriptStruct* FCustomStruct::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern PYTHONUTILITIES_API uint32 Get_Z_Construct_UScriptStruct_FCustomStruct_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FCustomStruct, Z_Construct_UPackage__Script_PythonUtilities(), TEXT("CustomStruct"), sizeof(FCustomStruct), Get_Z_Construct_UScriptStruct_FCustomStruct_Hash());
	}
	return Singleton;
}
template<> PYTHONUTILITIES_API UScriptStruct* StaticStruct<FCustomStruct>()
{
	return FCustomStruct::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FCustomStruct(FCustomStruct::StaticStruct, TEXT("/Script/PythonUtilities"), TEXT("CustomStruct"), false, nullptr, nullptr);
static struct FScriptStruct_PythonUtilities_StaticRegisterNativesFCustomStruct
{
	FScriptStruct_PythonUtilities_StaticRegisterNativesFCustomStruct()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("CustomStruct")),new UScriptStruct::TCppStructOps<FCustomStruct>);
	}
} ScriptStruct_PythonUtilities_StaticRegisterNativesFCustomStruct;
	struct Z_Construct_UScriptStruct_FCustomStruct_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCustomStruct_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/PyUnrealLib.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FCustomStruct_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FCustomStruct>();
	}
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FCustomStruct_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_PythonUtilities,
		nullptr,
		&NewStructOps,
		"CustomStruct",
		sizeof(FCustomStruct),
		alignof(FCustomStruct),
		nullptr,
		0,
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FCustomStruct_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FCustomStruct_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FCustomStruct()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FCustomStruct_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_PythonUtilities();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("CustomStruct"), sizeof(FCustomStruct), Get_Z_Construct_UScriptStruct_FCustomStruct_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FCustomStruct_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FCustomStruct_Hash() { return 2137266628U; }
	void UPyUnrealLib::StaticRegisterNativesUPyUnrealLib()
	{
#if WITH_EDITOR
		UClass* Class = UPyUnrealLib::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "FindCompletitionList", &UPyUnrealLib::execFindCompletitionList },
			{ "FindSuggetion", &UPyUnrealLib::execFindSuggetion },
			{ "FindSuggetionFromEditable", &UPyUnrealLib::execFindSuggetionFromEditable },
			{ "GetHelp", &UPyUnrealLib::execGetHelp },
			{ "GetProjectScriptDir", &UPyUnrealLib::execGetProjectScriptDir },
			{ "GetPyInstalledModules", &UPyUnrealLib::execGetPyInstalledModules },
			{ "GetPyModuleAttrs", &UPyUnrealLib::execGetPyModuleAttrs },
			{ "IsValidSuggestion", &UPyUnrealLib::execIsValidSuggestion },
			{ "ReloadModule", &UPyUnrealLib::execReloadModule },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
#endif // WITH_EDITOR
	}
#if WITH_EDITOR
	struct Z_Construct_UFunction_UPyUnrealLib_FindCompletitionList_Statics
	{
		struct PyUnrealLib_eventFindCompletitionList_Parms
		{
			FString ModuleName;
			TArray<FString> Tokens;
			TArray<FSuggestion> OutList;
			bool bFullEval;
			TArray<FString> Favorites;
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Favorites;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Favorites_Inner;
		static void NewProp_bFullEval_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bFullEval;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_OutList;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_OutList_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Tokens_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Tokens;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Tokens_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ModuleName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ModuleName;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UPyUnrealLib_FindCompletitionList_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PyUnrealLib_eventFindCompletitionList_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPyUnrealLib_FindCompletitionList_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(PyUnrealLib_eventFindCompletitionList_Parms), &Z_Construct_UFunction_UPyUnrealLib_FindCompletitionList_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UPyUnrealLib_FindCompletitionList_Statics::NewProp_Favorites = { "Favorites", nullptr, (EPropertyFlags)0x0010000008000180, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PyUnrealLib_eventFindCompletitionList_Parms, Favorites), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPyUnrealLib_FindCompletitionList_Statics::NewProp_Favorites_Inner = { "Favorites", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UPyUnrealLib_FindCompletitionList_Statics::NewProp_bFullEval_SetBit(void* Obj)
	{
		((PyUnrealLib_eventFindCompletitionList_Parms*)Obj)->bFullEval = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPyUnrealLib_FindCompletitionList_Statics::NewProp_bFullEval = { "bFullEval", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(PyUnrealLib_eventFindCompletitionList_Parms), &Z_Construct_UFunction_UPyUnrealLib_FindCompletitionList_Statics::NewProp_bFullEval_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UPyUnrealLib_FindCompletitionList_Statics::NewProp_OutList = { "OutList", nullptr, (EPropertyFlags)0x0010000008000180, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PyUnrealLib_eventFindCompletitionList_Parms, OutList), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPyUnrealLib_FindCompletitionList_Statics::NewProp_OutList_Inner = { "OutList", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FSuggestion, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPyUnrealLib_FindCompletitionList_Statics::NewProp_Tokens_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UPyUnrealLib_FindCompletitionList_Statics::NewProp_Tokens = { "Tokens", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PyUnrealLib_eventFindCompletitionList_Parms, Tokens), METADATA_PARAMS(Z_Construct_UFunction_UPyUnrealLib_FindCompletitionList_Statics::NewProp_Tokens_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UPyUnrealLib_FindCompletitionList_Statics::NewProp_Tokens_MetaData)) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPyUnrealLib_FindCompletitionList_Statics::NewProp_Tokens_Inner = { "Tokens", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPyUnrealLib_FindCompletitionList_Statics::NewProp_ModuleName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPyUnrealLib_FindCompletitionList_Statics::NewProp_ModuleName = { "ModuleName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PyUnrealLib_eventFindCompletitionList_Parms, ModuleName), METADATA_PARAMS(Z_Construct_UFunction_UPyUnrealLib_FindCompletitionList_Statics::NewProp_ModuleName_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UPyUnrealLib_FindCompletitionList_Statics::NewProp_ModuleName_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPyUnrealLib_FindCompletitionList_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPyUnrealLib_FindCompletitionList_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPyUnrealLib_FindCompletitionList_Statics::NewProp_Favorites,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPyUnrealLib_FindCompletitionList_Statics::NewProp_Favorites_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPyUnrealLib_FindCompletitionList_Statics::NewProp_bFullEval,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPyUnrealLib_FindCompletitionList_Statics::NewProp_OutList,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPyUnrealLib_FindCompletitionList_Statics::NewProp_OutList_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPyUnrealLib_FindCompletitionList_Statics::NewProp_Tokens,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPyUnrealLib_FindCompletitionList_Statics::NewProp_Tokens_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPyUnrealLib_FindCompletitionList_Statics::NewProp_ModuleName,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPyUnrealLib_FindCompletitionList_Statics::Function_MetaDataParams[] = {
		{ "Category", "Python" },
		{ "DevelopmentOnly", "" },
		{ "ModuleRelativePath", "Public/PyUnrealLib.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPyUnrealLib_FindCompletitionList_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPyUnrealLib, nullptr, "FindCompletitionList", sizeof(PyUnrealLib_eventFindCompletitionList_Parms), Z_Construct_UFunction_UPyUnrealLib_FindCompletitionList_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UPyUnrealLib_FindCompletitionList_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x24422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPyUnrealLib_FindCompletitionList_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UPyUnrealLib_FindCompletitionList_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPyUnrealLib_FindCompletitionList()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPyUnrealLib_FindCompletitionList_Statics::FuncParams);
		}
		return ReturnFunction;
	}
#endif //WITH_EDITOR
#if WITH_EDITOR
	struct Z_Construct_UFunction_UPyUnrealLib_FindSuggetion_Statics
	{
		struct PyUnrealLib_eventFindSuggetion_Parms
		{
			TArray<FString> Tokens;
			TArray<FSuggestion> OutSuggestions;
			TArray<FString> Favorites;
			bool FullEvaluation;
			bool bReloadModule;
		};
		static void NewProp_bReloadModule_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bReloadModule;
		static void NewProp_FullEvaluation_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_FullEvaluation;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Favorites;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Favorites_Inner;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_OutSuggestions;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_OutSuggestions_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Tokens_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Tokens;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Tokens_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UPyUnrealLib_FindSuggetion_Statics::NewProp_bReloadModule_SetBit(void* Obj)
	{
		((PyUnrealLib_eventFindSuggetion_Parms*)Obj)->bReloadModule = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPyUnrealLib_FindSuggetion_Statics::NewProp_bReloadModule = { "bReloadModule", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(PyUnrealLib_eventFindSuggetion_Parms), &Z_Construct_UFunction_UPyUnrealLib_FindSuggetion_Statics::NewProp_bReloadModule_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UPyUnrealLib_FindSuggetion_Statics::NewProp_FullEvaluation_SetBit(void* Obj)
	{
		((PyUnrealLib_eventFindSuggetion_Parms*)Obj)->FullEvaluation = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPyUnrealLib_FindSuggetion_Statics::NewProp_FullEvaluation = { "FullEvaluation", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(PyUnrealLib_eventFindSuggetion_Parms), &Z_Construct_UFunction_UPyUnrealLib_FindSuggetion_Statics::NewProp_FullEvaluation_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UPyUnrealLib_FindSuggetion_Statics::NewProp_Favorites = { "Favorites", nullptr, (EPropertyFlags)0x0010000008000180, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PyUnrealLib_eventFindSuggetion_Parms, Favorites), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPyUnrealLib_FindSuggetion_Statics::NewProp_Favorites_Inner = { "Favorites", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UPyUnrealLib_FindSuggetion_Statics::NewProp_OutSuggestions = { "OutSuggestions", nullptr, (EPropertyFlags)0x0010000008000180, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PyUnrealLib_eventFindSuggetion_Parms, OutSuggestions), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPyUnrealLib_FindSuggetion_Statics::NewProp_OutSuggestions_Inner = { "OutSuggestions", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FSuggestion, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPyUnrealLib_FindSuggetion_Statics::NewProp_Tokens_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UPyUnrealLib_FindSuggetion_Statics::NewProp_Tokens = { "Tokens", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PyUnrealLib_eventFindSuggetion_Parms, Tokens), METADATA_PARAMS(Z_Construct_UFunction_UPyUnrealLib_FindSuggetion_Statics::NewProp_Tokens_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UPyUnrealLib_FindSuggetion_Statics::NewProp_Tokens_MetaData)) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPyUnrealLib_FindSuggetion_Statics::NewProp_Tokens_Inner = { "Tokens", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPyUnrealLib_FindSuggetion_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPyUnrealLib_FindSuggetion_Statics::NewProp_bReloadModule,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPyUnrealLib_FindSuggetion_Statics::NewProp_FullEvaluation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPyUnrealLib_FindSuggetion_Statics::NewProp_Favorites,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPyUnrealLib_FindSuggetion_Statics::NewProp_Favorites_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPyUnrealLib_FindSuggetion_Statics::NewProp_OutSuggestions,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPyUnrealLib_FindSuggetion_Statics::NewProp_OutSuggestions_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPyUnrealLib_FindSuggetion_Statics::NewProp_Tokens,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPyUnrealLib_FindSuggetion_Statics::NewProp_Tokens_Inner,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPyUnrealLib_FindSuggetion_Statics::Function_MetaDataParams[] = {
		{ "Category", "Python" },
		{ "CPP_Default_bReloadModule", "false" },
		{ "CPP_Default_FullEvaluation", "false" },
		{ "DevelopmentOnly", "" },
		{ "ModuleRelativePath", "Public/PyUnrealLib.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPyUnrealLib_FindSuggetion_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPyUnrealLib, nullptr, "FindSuggetion", sizeof(PyUnrealLib_eventFindSuggetion_Parms), Z_Construct_UFunction_UPyUnrealLib_FindSuggetion_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UPyUnrealLib_FindSuggetion_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x24422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPyUnrealLib_FindSuggetion_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UPyUnrealLib_FindSuggetion_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPyUnrealLib_FindSuggetion()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPyUnrealLib_FindSuggetion_Statics::FuncParams);
		}
		return ReturnFunction;
	}
#endif //WITH_EDITOR
#if WITH_EDITOR
	struct Z_Construct_UFunction_UPyUnrealLib_FindSuggetionFromEditable_Statics
	{
		struct PyUnrealLib_eventFindSuggetionFromEditable_Parms
		{
			FString ExistingFile;
			TArray<FSuggestion> OutSuggestions;
			TArray<FString> Favorites;
		};
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Favorites;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Favorites_Inner;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_OutSuggestions;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_OutSuggestions_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ExistingFile_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ExistingFile;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UPyUnrealLib_FindSuggetionFromEditable_Statics::NewProp_Favorites = { "Favorites", nullptr, (EPropertyFlags)0x0010000008000180, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PyUnrealLib_eventFindSuggetionFromEditable_Parms, Favorites), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPyUnrealLib_FindSuggetionFromEditable_Statics::NewProp_Favorites_Inner = { "Favorites", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UPyUnrealLib_FindSuggetionFromEditable_Statics::NewProp_OutSuggestions = { "OutSuggestions", nullptr, (EPropertyFlags)0x0010000008000180, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PyUnrealLib_eventFindSuggetionFromEditable_Parms, OutSuggestions), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPyUnrealLib_FindSuggetionFromEditable_Statics::NewProp_OutSuggestions_Inner = { "OutSuggestions", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FSuggestion, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPyUnrealLib_FindSuggetionFromEditable_Statics::NewProp_ExistingFile_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPyUnrealLib_FindSuggetionFromEditable_Statics::NewProp_ExistingFile = { "ExistingFile", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PyUnrealLib_eventFindSuggetionFromEditable_Parms, ExistingFile), METADATA_PARAMS(Z_Construct_UFunction_UPyUnrealLib_FindSuggetionFromEditable_Statics::NewProp_ExistingFile_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UPyUnrealLib_FindSuggetionFromEditable_Statics::NewProp_ExistingFile_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPyUnrealLib_FindSuggetionFromEditable_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPyUnrealLib_FindSuggetionFromEditable_Statics::NewProp_Favorites,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPyUnrealLib_FindSuggetionFromEditable_Statics::NewProp_Favorites_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPyUnrealLib_FindSuggetionFromEditable_Statics::NewProp_OutSuggestions,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPyUnrealLib_FindSuggetionFromEditable_Statics::NewProp_OutSuggestions_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPyUnrealLib_FindSuggetionFromEditable_Statics::NewProp_ExistingFile,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPyUnrealLib_FindSuggetionFromEditable_Statics::Function_MetaDataParams[] = {
		{ "Category", "Python" },
		{ "DevelopmentOnly", "" },
		{ "ModuleRelativePath", "Public/PyUnrealLib.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPyUnrealLib_FindSuggetionFromEditable_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPyUnrealLib, nullptr, "FindSuggetionFromEditable", sizeof(PyUnrealLib_eventFindSuggetionFromEditable_Parms), Z_Construct_UFunction_UPyUnrealLib_FindSuggetionFromEditable_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UPyUnrealLib_FindSuggetionFromEditable_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x24422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPyUnrealLib_FindSuggetionFromEditable_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UPyUnrealLib_FindSuggetionFromEditable_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPyUnrealLib_FindSuggetionFromEditable()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPyUnrealLib_FindSuggetionFromEditable_Statics::FuncParams);
		}
		return ReturnFunction;
	}
#endif //WITH_EDITOR
#if WITH_EDITOR
	struct Z_Construct_UFunction_UPyUnrealLib_GetHelp_Statics
	{
		struct PyUnrealLib_eventGetHelp_Parms
		{
			FString Expression;
			FString ExintingFile;
			bool bIncludeFile;
			FString ReturnValue;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static void NewProp_bIncludeFile_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIncludeFile;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ExintingFile_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ExintingFile;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Expression_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Expression;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPyUnrealLib_GetHelp_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PyUnrealLib_eventGetHelp_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UPyUnrealLib_GetHelp_Statics::NewProp_bIncludeFile_SetBit(void* Obj)
	{
		((PyUnrealLib_eventGetHelp_Parms*)Obj)->bIncludeFile = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPyUnrealLib_GetHelp_Statics::NewProp_bIncludeFile = { "bIncludeFile", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(PyUnrealLib_eventGetHelp_Parms), &Z_Construct_UFunction_UPyUnrealLib_GetHelp_Statics::NewProp_bIncludeFile_SetBit, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPyUnrealLib_GetHelp_Statics::NewProp_ExintingFile_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPyUnrealLib_GetHelp_Statics::NewProp_ExintingFile = { "ExintingFile", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PyUnrealLib_eventGetHelp_Parms, ExintingFile), METADATA_PARAMS(Z_Construct_UFunction_UPyUnrealLib_GetHelp_Statics::NewProp_ExintingFile_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UPyUnrealLib_GetHelp_Statics::NewProp_ExintingFile_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPyUnrealLib_GetHelp_Statics::NewProp_Expression_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPyUnrealLib_GetHelp_Statics::NewProp_Expression = { "Expression", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PyUnrealLib_eventGetHelp_Parms, Expression), METADATA_PARAMS(Z_Construct_UFunction_UPyUnrealLib_GetHelp_Statics::NewProp_Expression_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UPyUnrealLib_GetHelp_Statics::NewProp_Expression_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPyUnrealLib_GetHelp_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPyUnrealLib_GetHelp_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPyUnrealLib_GetHelp_Statics::NewProp_bIncludeFile,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPyUnrealLib_GetHelp_Statics::NewProp_ExintingFile,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPyUnrealLib_GetHelp_Statics::NewProp_Expression,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPyUnrealLib_GetHelp_Statics::Function_MetaDataParams[] = {
		{ "Category", "Python" },
		{ "DevelopmentOnly", "" },
		{ "ModuleRelativePath", "Public/PyUnrealLib.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPyUnrealLib_GetHelp_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPyUnrealLib, nullptr, "GetHelp", sizeof(PyUnrealLib_eventGetHelp_Parms), Z_Construct_UFunction_UPyUnrealLib_GetHelp_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UPyUnrealLib_GetHelp_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x24022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPyUnrealLib_GetHelp_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UPyUnrealLib_GetHelp_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPyUnrealLib_GetHelp()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPyUnrealLib_GetHelp_Statics::FuncParams);
		}
		return ReturnFunction;
	}
#endif //WITH_EDITOR
#if WITH_EDITOR
	struct Z_Construct_UFunction_UPyUnrealLib_GetProjectScriptDir_Statics
	{
		struct PyUnrealLib_eventGetProjectScriptDir_Parms
		{
			FString ReturnValue;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPyUnrealLib_GetProjectScriptDir_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PyUnrealLib_eventGetProjectScriptDir_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPyUnrealLib_GetProjectScriptDir_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPyUnrealLib_GetProjectScriptDir_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPyUnrealLib_GetProjectScriptDir_Statics::Function_MetaDataParams[] = {
		{ "Category", "Python" },
		{ "DevelopmentOnly", "" },
		{ "ModuleRelativePath", "Public/PyUnrealLib.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPyUnrealLib_GetProjectScriptDir_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPyUnrealLib, nullptr, "GetProjectScriptDir", sizeof(PyUnrealLib_eventGetProjectScriptDir_Parms), Z_Construct_UFunction_UPyUnrealLib_GetProjectScriptDir_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UPyUnrealLib_GetProjectScriptDir_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x34022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPyUnrealLib_GetProjectScriptDir_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UPyUnrealLib_GetProjectScriptDir_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPyUnrealLib_GetProjectScriptDir()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPyUnrealLib_GetProjectScriptDir_Statics::FuncParams);
		}
		return ReturnFunction;
	}
#endif //WITH_EDITOR
#if WITH_EDITOR
	struct Z_Construct_UFunction_UPyUnrealLib_GetPyInstalledModules_Statics
	{
		struct PyUnrealLib_eventGetPyInstalledModules_Parms
		{
			TArray<FString> ReturnValue;
		};
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UPyUnrealLib_GetPyInstalledModules_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PyUnrealLib_eventGetPyInstalledModules_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPyUnrealLib_GetPyInstalledModules_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPyUnrealLib_GetPyInstalledModules_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPyUnrealLib_GetPyInstalledModules_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPyUnrealLib_GetPyInstalledModules_Statics::NewProp_ReturnValue_Inner,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPyUnrealLib_GetPyInstalledModules_Statics::Function_MetaDataParams[] = {
		{ "Category", "Python" },
		{ "DevelopmentOnly", "" },
		{ "ModuleRelativePath", "Public/PyUnrealLib.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPyUnrealLib_GetPyInstalledModules_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPyUnrealLib, nullptr, "GetPyInstalledModules", sizeof(PyUnrealLib_eventGetPyInstalledModules_Parms), Z_Construct_UFunction_UPyUnrealLib_GetPyInstalledModules_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UPyUnrealLib_GetPyInstalledModules_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x24022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPyUnrealLib_GetPyInstalledModules_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UPyUnrealLib_GetPyInstalledModules_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPyUnrealLib_GetPyInstalledModules()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPyUnrealLib_GetPyInstalledModules_Statics::FuncParams);
		}
		return ReturnFunction;
	}
#endif //WITH_EDITOR
#if WITH_EDITOR
	struct Z_Construct_UFunction_UPyUnrealLib_GetPyModuleAttrs_Statics
	{
		struct PyUnrealLib_eventGetPyModuleAttrs_Parms
		{
			FString ModuleName;
			TArray<FString> ReturnValue;
		};
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ModuleName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ModuleName;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UPyUnrealLib_GetPyModuleAttrs_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PyUnrealLib_eventGetPyModuleAttrs_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPyUnrealLib_GetPyModuleAttrs_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPyUnrealLib_GetPyModuleAttrs_Statics::NewProp_ModuleName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPyUnrealLib_GetPyModuleAttrs_Statics::NewProp_ModuleName = { "ModuleName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PyUnrealLib_eventGetPyModuleAttrs_Parms, ModuleName), METADATA_PARAMS(Z_Construct_UFunction_UPyUnrealLib_GetPyModuleAttrs_Statics::NewProp_ModuleName_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UPyUnrealLib_GetPyModuleAttrs_Statics::NewProp_ModuleName_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPyUnrealLib_GetPyModuleAttrs_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPyUnrealLib_GetPyModuleAttrs_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPyUnrealLib_GetPyModuleAttrs_Statics::NewProp_ReturnValue_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPyUnrealLib_GetPyModuleAttrs_Statics::NewProp_ModuleName,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPyUnrealLib_GetPyModuleAttrs_Statics::Function_MetaDataParams[] = {
		{ "Category", "Python" },
		{ "DevelopmentOnly", "" },
		{ "ModuleRelativePath", "Public/PyUnrealLib.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPyUnrealLib_GetPyModuleAttrs_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPyUnrealLib, nullptr, "GetPyModuleAttrs", sizeof(PyUnrealLib_eventGetPyModuleAttrs_Parms), Z_Construct_UFunction_UPyUnrealLib_GetPyModuleAttrs_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UPyUnrealLib_GetPyModuleAttrs_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x24022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPyUnrealLib_GetPyModuleAttrs_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UPyUnrealLib_GetPyModuleAttrs_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPyUnrealLib_GetPyModuleAttrs()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPyUnrealLib_GetPyModuleAttrs_Statics::FuncParams);
		}
		return ReturnFunction;
	}
#endif //WITH_EDITOR
#if WITH_EDITOR
	struct Z_Construct_UFunction_UPyUnrealLib_IsValidSuggestion_Statics
	{
		struct PyUnrealLib_eventIsValidSuggestion_Parms
		{
			FString InSuggetion;
			FString TrimWord;
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TrimWord_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_TrimWord;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InSuggetion_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_InSuggetion;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UPyUnrealLib_IsValidSuggestion_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PyUnrealLib_eventIsValidSuggestion_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPyUnrealLib_IsValidSuggestion_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(PyUnrealLib_eventIsValidSuggestion_Parms), &Z_Construct_UFunction_UPyUnrealLib_IsValidSuggestion_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPyUnrealLib_IsValidSuggestion_Statics::NewProp_TrimWord_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPyUnrealLib_IsValidSuggestion_Statics::NewProp_TrimWord = { "TrimWord", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PyUnrealLib_eventIsValidSuggestion_Parms, TrimWord), METADATA_PARAMS(Z_Construct_UFunction_UPyUnrealLib_IsValidSuggestion_Statics::NewProp_TrimWord_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UPyUnrealLib_IsValidSuggestion_Statics::NewProp_TrimWord_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPyUnrealLib_IsValidSuggestion_Statics::NewProp_InSuggetion_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPyUnrealLib_IsValidSuggestion_Statics::NewProp_InSuggetion = { "InSuggetion", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PyUnrealLib_eventIsValidSuggestion_Parms, InSuggetion), METADATA_PARAMS(Z_Construct_UFunction_UPyUnrealLib_IsValidSuggestion_Statics::NewProp_InSuggetion_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UPyUnrealLib_IsValidSuggestion_Statics::NewProp_InSuggetion_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPyUnrealLib_IsValidSuggestion_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPyUnrealLib_IsValidSuggestion_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPyUnrealLib_IsValidSuggestion_Statics::NewProp_TrimWord,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPyUnrealLib_IsValidSuggestion_Statics::NewProp_InSuggetion,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPyUnrealLib_IsValidSuggestion_Statics::Function_MetaDataParams[] = {
		{ "Category", "Python" },
		{ "DevelopmentOnly", "" },
		{ "ModuleRelativePath", "Public/PyUnrealLib.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPyUnrealLib_IsValidSuggestion_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPyUnrealLib, nullptr, "IsValidSuggestion", sizeof(PyUnrealLib_eventIsValidSuggestion_Parms), Z_Construct_UFunction_UPyUnrealLib_IsValidSuggestion_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UPyUnrealLib_IsValidSuggestion_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x24022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPyUnrealLib_IsValidSuggestion_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UPyUnrealLib_IsValidSuggestion_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPyUnrealLib_IsValidSuggestion()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPyUnrealLib_IsValidSuggestion_Statics::FuncParams);
		}
		return ReturnFunction;
	}
#endif //WITH_EDITOR
#if WITH_EDITOR
	struct Z_Construct_UFunction_UPyUnrealLib_ReloadModule_Statics
	{
		struct PyUnrealLib_eventReloadModule_Parms
		{
			FString Module;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Module_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Module;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPyUnrealLib_ReloadModule_Statics::NewProp_Module_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPyUnrealLib_ReloadModule_Statics::NewProp_Module = { "Module", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PyUnrealLib_eventReloadModule_Parms, Module), METADATA_PARAMS(Z_Construct_UFunction_UPyUnrealLib_ReloadModule_Statics::NewProp_Module_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UPyUnrealLib_ReloadModule_Statics::NewProp_Module_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPyUnrealLib_ReloadModule_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPyUnrealLib_ReloadModule_Statics::NewProp_Module,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPyUnrealLib_ReloadModule_Statics::Function_MetaDataParams[] = {
		{ "Category", "Python" },
		{ "DevelopmentOnly", "" },
		{ "ModuleRelativePath", "Public/PyUnrealLib.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPyUnrealLib_ReloadModule_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPyUnrealLib, nullptr, "ReloadModule", sizeof(PyUnrealLib_eventReloadModule_Parms), Z_Construct_UFunction_UPyUnrealLib_ReloadModule_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UPyUnrealLib_ReloadModule_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x24022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPyUnrealLib_ReloadModule_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UPyUnrealLib_ReloadModule_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPyUnrealLib_ReloadModule()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPyUnrealLib_ReloadModule_Statics::FuncParams);
		}
		return ReturnFunction;
	}
#endif //WITH_EDITOR
	UClass* Z_Construct_UClass_UPyUnrealLib_NoRegister()
	{
		return UPyUnrealLib::StaticClass();
	}
	struct Z_Construct_UClass_UPyUnrealLib_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_EDITOR
		static const FClassFunctionLinkInfo FuncInfo[];
#endif //WITH_EDITOR
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPyUnrealLib_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_PythonUtilities,
	};
#if WITH_EDITOR
	const FClassFunctionLinkInfo Z_Construct_UClass_UPyUnrealLib_Statics::FuncInfo[] = {
#if WITH_EDITOR
		{ &Z_Construct_UFunction_UPyUnrealLib_FindCompletitionList, "FindCompletitionList" }, // 3537872361
#endif //WITH_EDITOR
#if WITH_EDITOR
		{ &Z_Construct_UFunction_UPyUnrealLib_FindSuggetion, "FindSuggetion" }, // 642144369
#endif //WITH_EDITOR
#if WITH_EDITOR
		{ &Z_Construct_UFunction_UPyUnrealLib_FindSuggetionFromEditable, "FindSuggetionFromEditable" }, // 2299807242
#endif //WITH_EDITOR
#if WITH_EDITOR
		{ &Z_Construct_UFunction_UPyUnrealLib_GetHelp, "GetHelp" }, // 3189971905
#endif //WITH_EDITOR
#if WITH_EDITOR
		{ &Z_Construct_UFunction_UPyUnrealLib_GetProjectScriptDir, "GetProjectScriptDir" }, // 1335303068
#endif //WITH_EDITOR
#if WITH_EDITOR
		{ &Z_Construct_UFunction_UPyUnrealLib_GetPyInstalledModules, "GetPyInstalledModules" }, // 3667823941
#endif //WITH_EDITOR
#if WITH_EDITOR
		{ &Z_Construct_UFunction_UPyUnrealLib_GetPyModuleAttrs, "GetPyModuleAttrs" }, // 3281318060
#endif //WITH_EDITOR
#if WITH_EDITOR
		{ &Z_Construct_UFunction_UPyUnrealLib_IsValidSuggestion, "IsValidSuggestion" }, // 2735565111
#endif //WITH_EDITOR
#if WITH_EDITOR
		{ &Z_Construct_UFunction_UPyUnrealLib_ReloadModule, "ReloadModule" }, // 2387273745
#endif //WITH_EDITOR
	};
#endif //WITH_EDITOR
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPyUnrealLib_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "PyUnrealLib.h" },
		{ "ModuleRelativePath", "Public/PyUnrealLib.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPyUnrealLib_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPyUnrealLib>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UPyUnrealLib_Statics::ClassParams = {
		&UPyUnrealLib::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		IF_WITH_EDITOR(FuncInfo, nullptr),
		nullptr,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		IF_WITH_EDITOR(ARRAY_COUNT(FuncInfo), 0),
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UPyUnrealLib_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UPyUnrealLib_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UPyUnrealLib()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UPyUnrealLib_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UPyUnrealLib, 2778705098);
	template<> PYTHONUTILITIES_API UClass* StaticClass<UPyUnrealLib>()
	{
		return UPyUnrealLib::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UPyUnrealLib(Z_Construct_UClass_UPyUnrealLib, &UPyUnrealLib::StaticClass, TEXT("/Script/PythonUtilities"), TEXT("UPyUnrealLib"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPyUnrealLib);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

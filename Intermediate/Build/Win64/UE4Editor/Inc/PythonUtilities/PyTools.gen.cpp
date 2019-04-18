// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PythonUtilities/Public/PyTools.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePyTools() {}
// Cross Module References
	PYTHONUTILITIES_API UClass* Z_Construct_UClass_UPyTools_NoRegister();
	PYTHONUTILITIES_API UClass* Z_Construct_UClass_UPyTools();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_PythonUtilities();
	PYTHONUTILITIES_API UFunction* Z_Construct_UFunction_UPyTools_CHECKFUNCTIONS();
	PYTHONUTILITIES_API UFunction* Z_Construct_UFunction_UPyTools_CopyBlueprintProperty();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprint_NoRegister();
	PYTHONUTILITIES_API UFunction* Z_Construct_UFunction_UPyTools_GetAllFunctions();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	PYTHONUTILITIES_API UFunction* Z_Construct_UFunction_UPyTools_GetAllProperties();
	PYTHONUTILITIES_API UFunction* Z_Construct_UFunction_UPyTools_GetBlueprintFromObject();
	PYTHONUTILITIES_API UFunction* Z_Construct_UFunction_UPyTools_SetFolderColor();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
// End Cross Module References
	void UPyTools::StaticRegisterNativesUPyTools()
	{
#if WITH_EDITOR
		UClass* Class = UPyTools::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CHECKFUNCTIONS", &UPyTools::execCHECKFUNCTIONS },
			{ "CopyBlueprintProperty", &UPyTools::execCopyBlueprintProperty },
			{ "GetAllFunctions", &UPyTools::execGetAllFunctions },
			{ "GetAllProperties", &UPyTools::execGetAllProperties },
			{ "GetBlueprintFromObject", &UPyTools::execGetBlueprintFromObject },
			{ "SetFolderColor", &UPyTools::execSetFolderColor },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
#endif // WITH_EDITOR
	}
#if WITH_EDITOR
	struct Z_Construct_UFunction_UPyTools_CHECKFUNCTIONS_Statics
	{
		struct PyTools_eventCHECKFUNCTIONS_Parms
		{
			FString File;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_File_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_File;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPyTools_CHECKFUNCTIONS_Statics::NewProp_File_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPyTools_CHECKFUNCTIONS_Statics::NewProp_File = { "File", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PyTools_eventCHECKFUNCTIONS_Parms, File), METADATA_PARAMS(Z_Construct_UFunction_UPyTools_CHECKFUNCTIONS_Statics::NewProp_File_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UPyTools_CHECKFUNCTIONS_Statics::NewProp_File_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPyTools_CHECKFUNCTIONS_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPyTools_CHECKFUNCTIONS_Statics::NewProp_File,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPyTools_CHECKFUNCTIONS_Statics::Function_MetaDataParams[] = {
		{ "Category", "PyTool" },
		{ "DevelopmentOnly", "" },
		{ "ModuleRelativePath", "Public/PyTools.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPyTools_CHECKFUNCTIONS_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPyTools, nullptr, "CHECKFUNCTIONS", sizeof(PyTools_eventCHECKFUNCTIONS_Parms), Z_Construct_UFunction_UPyTools_CHECKFUNCTIONS_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UPyTools_CHECKFUNCTIONS_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x24022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPyTools_CHECKFUNCTIONS_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UPyTools_CHECKFUNCTIONS_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPyTools_CHECKFUNCTIONS()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPyTools_CHECKFUNCTIONS_Statics::FuncParams);
		}
		return ReturnFunction;
	}
#endif //WITH_EDITOR
#if WITH_EDITOR
	struct Z_Construct_UFunction_UPyTools_CopyBlueprintProperty_Statics
	{
		struct PyTools_eventCopyBlueprintProperty_Parms
		{
			UBlueprint* Source;
			FName VarName;
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_VarName;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Source;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UPyTools_CopyBlueprintProperty_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PyTools_eventCopyBlueprintProperty_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPyTools_CopyBlueprintProperty_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(PyTools_eventCopyBlueprintProperty_Parms), &Z_Construct_UFunction_UPyTools_CopyBlueprintProperty_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UPyTools_CopyBlueprintProperty_Statics::NewProp_VarName = { "VarName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PyTools_eventCopyBlueprintProperty_Parms, VarName), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPyTools_CopyBlueprintProperty_Statics::NewProp_Source = { "Source", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PyTools_eventCopyBlueprintProperty_Parms, Source), Z_Construct_UClass_UBlueprint_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPyTools_CopyBlueprintProperty_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPyTools_CopyBlueprintProperty_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPyTools_CopyBlueprintProperty_Statics::NewProp_VarName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPyTools_CopyBlueprintProperty_Statics::NewProp_Source,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPyTools_CopyBlueprintProperty_Statics::Function_MetaDataParams[] = {
		{ "Category", "PyTool" },
		{ "DevelopmentOnly", "" },
		{ "ModuleRelativePath", "Public/PyTools.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPyTools_CopyBlueprintProperty_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPyTools, nullptr, "CopyBlueprintProperty", sizeof(PyTools_eventCopyBlueprintProperty_Parms), Z_Construct_UFunction_UPyTools_CopyBlueprintProperty_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UPyTools_CopyBlueprintProperty_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x24022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPyTools_CopyBlueprintProperty_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UPyTools_CopyBlueprintProperty_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPyTools_CopyBlueprintProperty()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPyTools_CopyBlueprintProperty_Statics::FuncParams);
		}
		return ReturnFunction;
	}
#endif //WITH_EDITOR
#if WITH_EDITOR
	struct Z_Construct_UFunction_UPyTools_GetAllFunctions_Statics
	{
		struct PyTools_eventGetAllFunctions_Parms
		{
			UObject* Object;
			TArray<FString> ReturnValue;
		};
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Inner;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Object;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UPyTools_GetAllFunctions_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PyTools_eventGetAllFunctions_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPyTools_GetAllFunctions_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPyTools_GetAllFunctions_Statics::NewProp_Object = { "Object", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PyTools_eventGetAllFunctions_Parms, Object), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPyTools_GetAllFunctions_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPyTools_GetAllFunctions_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPyTools_GetAllFunctions_Statics::NewProp_ReturnValue_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPyTools_GetAllFunctions_Statics::NewProp_Object,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPyTools_GetAllFunctions_Statics::Function_MetaDataParams[] = {
		{ "Category", "PyTool" },
		{ "DevelopmentOnly", "" },
		{ "ModuleRelativePath", "Public/PyTools.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPyTools_GetAllFunctions_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPyTools, nullptr, "GetAllFunctions", sizeof(PyTools_eventGetAllFunctions_Parms), Z_Construct_UFunction_UPyTools_GetAllFunctions_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UPyTools_GetAllFunctions_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x24022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPyTools_GetAllFunctions_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UPyTools_GetAllFunctions_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPyTools_GetAllFunctions()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPyTools_GetAllFunctions_Statics::FuncParams);
		}
		return ReturnFunction;
	}
#endif //WITH_EDITOR
#if WITH_EDITOR
	struct Z_Construct_UFunction_UPyTools_GetAllProperties_Statics
	{
		struct PyTools_eventGetAllProperties_Parms
		{
			UObject* Object;
			TArray<FString> ReturnValue;
		};
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Inner;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Object;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UPyTools_GetAllProperties_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PyTools_eventGetAllProperties_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPyTools_GetAllProperties_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPyTools_GetAllProperties_Statics::NewProp_Object = { "Object", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PyTools_eventGetAllProperties_Parms, Object), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPyTools_GetAllProperties_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPyTools_GetAllProperties_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPyTools_GetAllProperties_Statics::NewProp_ReturnValue_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPyTools_GetAllProperties_Statics::NewProp_Object,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPyTools_GetAllProperties_Statics::Function_MetaDataParams[] = {
		{ "Category", "PyTool" },
		{ "DevelopmentOnly", "" },
		{ "ModuleRelativePath", "Public/PyTools.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPyTools_GetAllProperties_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPyTools, nullptr, "GetAllProperties", sizeof(PyTools_eventGetAllProperties_Parms), Z_Construct_UFunction_UPyTools_GetAllProperties_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UPyTools_GetAllProperties_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x24022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPyTools_GetAllProperties_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UPyTools_GetAllProperties_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPyTools_GetAllProperties()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPyTools_GetAllProperties_Statics::FuncParams);
		}
		return ReturnFunction;
	}
#endif //WITH_EDITOR
#if WITH_EDITOR
	struct Z_Construct_UFunction_UPyTools_GetBlueprintFromObject_Statics
	{
		struct PyTools_eventGetBlueprintFromObject_Parms
		{
			UObject* Object;
			UBlueprint* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Object;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPyTools_GetBlueprintFromObject_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PyTools_eventGetBlueprintFromObject_Parms, ReturnValue), Z_Construct_UClass_UBlueprint_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPyTools_GetBlueprintFromObject_Statics::NewProp_Object = { "Object", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PyTools_eventGetBlueprintFromObject_Parms, Object), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPyTools_GetBlueprintFromObject_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPyTools_GetBlueprintFromObject_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPyTools_GetBlueprintFromObject_Statics::NewProp_Object,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPyTools_GetBlueprintFromObject_Statics::Function_MetaDataParams[] = {
		{ "Category", "PyTool" },
		{ "DevelopmentOnly", "" },
		{ "ModuleRelativePath", "Public/PyTools.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPyTools_GetBlueprintFromObject_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPyTools, nullptr, "GetBlueprintFromObject", sizeof(PyTools_eventGetBlueprintFromObject_Parms), Z_Construct_UFunction_UPyTools_GetBlueprintFromObject_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UPyTools_GetBlueprintFromObject_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x24022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPyTools_GetBlueprintFromObject_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UPyTools_GetBlueprintFromObject_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPyTools_GetBlueprintFromObject()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPyTools_GetBlueprintFromObject_Statics::FuncParams);
		}
		return ReturnFunction;
	}
#endif //WITH_EDITOR
#if WITH_EDITOR
	struct Z_Construct_UFunction_UPyTools_SetFolderColor_Statics
	{
		struct PyTools_eventSetFolderColor_Parms
		{
			FString Path;
			FLinearColor Color;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Color;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Path;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPyTools_SetFolderColor_Statics::NewProp_Color = { "Color", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PyTools_eventSetFolderColor_Parms, Color), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPyTools_SetFolderColor_Statics::NewProp_Path = { "Path", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PyTools_eventSetFolderColor_Parms, Path), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPyTools_SetFolderColor_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPyTools_SetFolderColor_Statics::NewProp_Color,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPyTools_SetFolderColor_Statics::NewProp_Path,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPyTools_SetFolderColor_Statics::Function_MetaDataParams[] = {
		{ "Category", "PyTool" },
		{ "DevelopmentOnly", "" },
		{ "ModuleRelativePath", "Public/PyTools.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPyTools_SetFolderColor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPyTools, nullptr, "SetFolderColor", sizeof(PyTools_eventSetFolderColor_Parms), Z_Construct_UFunction_UPyTools_SetFolderColor_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UPyTools_SetFolderColor_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x24822401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPyTools_SetFolderColor_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UPyTools_SetFolderColor_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPyTools_SetFolderColor()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPyTools_SetFolderColor_Statics::FuncParams);
		}
		return ReturnFunction;
	}
#endif //WITH_EDITOR
	UClass* Z_Construct_UClass_UPyTools_NoRegister()
	{
		return UPyTools::StaticClass();
	}
	struct Z_Construct_UClass_UPyTools_Statics
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
	UObject* (*const Z_Construct_UClass_UPyTools_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_PythonUtilities,
	};
#if WITH_EDITOR
	const FClassFunctionLinkInfo Z_Construct_UClass_UPyTools_Statics::FuncInfo[] = {
#if WITH_EDITOR
		{ &Z_Construct_UFunction_UPyTools_CHECKFUNCTIONS, "CHECKFUNCTIONS" }, // 3994980248
#endif //WITH_EDITOR
#if WITH_EDITOR
		{ &Z_Construct_UFunction_UPyTools_CopyBlueprintProperty, "CopyBlueprintProperty" }, // 1374323011
#endif //WITH_EDITOR
#if WITH_EDITOR
		{ &Z_Construct_UFunction_UPyTools_GetAllFunctions, "GetAllFunctions" }, // 2534355351
#endif //WITH_EDITOR
#if WITH_EDITOR
		{ &Z_Construct_UFunction_UPyTools_GetAllProperties, "GetAllProperties" }, // 2543700886
#endif //WITH_EDITOR
#if WITH_EDITOR
		{ &Z_Construct_UFunction_UPyTools_GetBlueprintFromObject, "GetBlueprintFromObject" }, // 1009470829
#endif //WITH_EDITOR
#if WITH_EDITOR
		{ &Z_Construct_UFunction_UPyTools_SetFolderColor, "SetFolderColor" }, // 3349599243
#endif //WITH_EDITOR
	};
#endif //WITH_EDITOR
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPyTools_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "PyTools.h" },
		{ "ModuleRelativePath", "Public/PyTools.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPyTools_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPyTools>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UPyTools_Statics::ClassParams = {
		&UPyTools::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UPyTools_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UPyTools_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UPyTools()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UPyTools_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UPyTools, 45009635);
	template<> PYTHONUTILITIES_API UClass* StaticClass<UPyTools>()
	{
		return UPyTools::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UPyTools(Z_Construct_UClass_UPyTools, &UPyTools::StaticClass, TEXT("/Script/PythonUtilities"), TEXT("UPyTools"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPyTools);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PythonEditor/Public/ScriptShelfs.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeScriptShelfs() {}
// Cross Module References
	PYTHONEDITOR_API UScriptStruct* Z_Construct_UScriptStruct_FShelfTab();
	UPackage* Z_Construct_UPackage__Script_PythonEditor();
	PYTHONEDITOR_API UScriptStruct* Z_Construct_UScriptStruct_FShelfButtonInfo();
	PYTHONEDITOR_API UClass* Z_Construct_UClass_UScriptShelfs_NoRegister();
	PYTHONEDITOR_API UClass* Z_Construct_UClass_UScriptShelfs();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
// End Cross Module References
class UScriptStruct* FShelfTab::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern PYTHONEDITOR_API uint32 Get_Z_Construct_UScriptStruct_FShelfTab_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FShelfTab, Z_Construct_UPackage__Script_PythonEditor(), TEXT("ShelfTab"), sizeof(FShelfTab), Get_Z_Construct_UScriptStruct_FShelfTab_Hash());
	}
	return Singleton;
}
template<> PYTHONEDITOR_API UScriptStruct* StaticStruct<FShelfTab>()
{
	return FShelfTab::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FShelfTab(FShelfTab::StaticStruct, TEXT("/Script/PythonEditor"), TEXT("ShelfTab"), false, nullptr, nullptr);
static struct FScriptStruct_PythonEditor_StaticRegisterNativesFShelfTab
{
	FScriptStruct_PythonEditor_StaticRegisterNativesFShelfTab()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("ShelfTab")),new UScriptStruct::TCppStructOps<FShelfTab>);
	}
} ScriptStruct_PythonEditor_StaticRegisterNativesFShelfTab;
	struct Z_Construct_UScriptStruct_FShelfTab_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Buttons_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Buttons;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Buttons_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TabId_MetaData[];
#endif
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_TabId;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FShelfTab_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ScriptShelfs.h" },
		{ "ToolTip", "* struct to hold the shelf info" },
	};
#endif
	void* Z_Construct_UScriptStruct_FShelfTab_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FShelfTab>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FShelfTab_Statics::NewProp_Buttons_MetaData[] = {
		{ "ModuleRelativePath", "Public/ScriptShelfs.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FShelfTab_Statics::NewProp_Buttons = { "Buttons", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FShelfTab, Buttons), METADATA_PARAMS(Z_Construct_UScriptStruct_FShelfTab_Statics::NewProp_Buttons_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FShelfTab_Statics::NewProp_Buttons_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FShelfTab_Statics::NewProp_Buttons_Inner = { "Buttons", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FShelfButtonInfo, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FShelfTab_Statics::NewProp_TabId_MetaData[] = {
		{ "ModuleRelativePath", "Public/ScriptShelfs.h" },
	};
#endif
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FShelfTab_Statics::NewProp_TabId = { "TabId", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FShelfTab, TabId), METADATA_PARAMS(Z_Construct_UScriptStruct_FShelfTab_Statics::NewProp_TabId_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FShelfTab_Statics::NewProp_TabId_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FShelfTab_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FShelfTab_Statics::NewProp_Buttons,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FShelfTab_Statics::NewProp_Buttons_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FShelfTab_Statics::NewProp_TabId,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FShelfTab_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_PythonEditor,
		nullptr,
		&NewStructOps,
		"ShelfTab",
		sizeof(FShelfTab),
		alignof(FShelfTab),
		Z_Construct_UScriptStruct_FShelfTab_Statics::PropPointers,
		ARRAY_COUNT(Z_Construct_UScriptStruct_FShelfTab_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FShelfTab_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FShelfTab_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FShelfTab()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FShelfTab_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_PythonEditor();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("ShelfTab"), sizeof(FShelfTab), Get_Z_Construct_UScriptStruct_FShelfTab_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FShelfTab_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FShelfTab_Hash() { return 2302154307U; }
class UScriptStruct* FShelfButtonInfo::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern PYTHONEDITOR_API uint32 Get_Z_Construct_UScriptStruct_FShelfButtonInfo_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FShelfButtonInfo, Z_Construct_UPackage__Script_PythonEditor(), TEXT("ShelfButtonInfo"), sizeof(FShelfButtonInfo), Get_Z_Construct_UScriptStruct_FShelfButtonInfo_Hash());
	}
	return Singleton;
}
template<> PYTHONEDITOR_API UScriptStruct* StaticStruct<FShelfButtonInfo>()
{
	return FShelfButtonInfo::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FShelfButtonInfo(FShelfButtonInfo::StaticStruct, TEXT("/Script/PythonEditor"), TEXT("ShelfButtonInfo"), false, nullptr, nullptr);
static struct FScriptStruct_PythonEditor_StaticRegisterNativesFShelfButtonInfo
{
	FScriptStruct_PythonEditor_StaticRegisterNativesFShelfButtonInfo()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("ShelfButtonInfo")),new UScriptStruct::TCppStructOps<FShelfButtonInfo>);
	}
} ScriptStruct_PythonEditor_StaticRegisterNativesFShelfButtonInfo;
	struct Z_Construct_UScriptStruct_FShelfButtonInfo_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Icon_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Icon;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Icon_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Code_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Code;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ID_MetaData[];
#endif
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_ID;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DisplayName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_DisplayName;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FShelfButtonInfo_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ScriptShelfs.h" },
		{ "ToolTip", "* Struct container for Shelf buttons" },
	};
#endif
	void* Z_Construct_UScriptStruct_FShelfButtonInfo_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FShelfButtonInfo>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FShelfButtonInfo_Statics::NewProp_Icon_MetaData[] = {
		{ "ModuleRelativePath", "Public/ScriptShelfs.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FShelfButtonInfo_Statics::NewProp_Icon = { "Icon", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FShelfButtonInfo, Icon), METADATA_PARAMS(Z_Construct_UScriptStruct_FShelfButtonInfo_Statics::NewProp_Icon_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FShelfButtonInfo_Statics::NewProp_Icon_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FShelfButtonInfo_Statics::NewProp_Icon_Inner = { "Icon", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FShelfButtonInfo_Statics::NewProp_Code_MetaData[] = {
		{ "ModuleRelativePath", "Public/ScriptShelfs.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FShelfButtonInfo_Statics::NewProp_Code = { "Code", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FShelfButtonInfo, Code), METADATA_PARAMS(Z_Construct_UScriptStruct_FShelfButtonInfo_Statics::NewProp_Code_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FShelfButtonInfo_Statics::NewProp_Code_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FShelfButtonInfo_Statics::NewProp_ID_MetaData[] = {
		{ "ModuleRelativePath", "Public/ScriptShelfs.h" },
	};
#endif
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FShelfButtonInfo_Statics::NewProp_ID = { "ID", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FShelfButtonInfo, ID), METADATA_PARAMS(Z_Construct_UScriptStruct_FShelfButtonInfo_Statics::NewProp_ID_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FShelfButtonInfo_Statics::NewProp_ID_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FShelfButtonInfo_Statics::NewProp_DisplayName_MetaData[] = {
		{ "ModuleRelativePath", "Public/ScriptShelfs.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FShelfButtonInfo_Statics::NewProp_DisplayName = { "DisplayName", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FShelfButtonInfo, DisplayName), METADATA_PARAMS(Z_Construct_UScriptStruct_FShelfButtonInfo_Statics::NewProp_DisplayName_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FShelfButtonInfo_Statics::NewProp_DisplayName_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FShelfButtonInfo_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FShelfButtonInfo_Statics::NewProp_Icon,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FShelfButtonInfo_Statics::NewProp_Icon_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FShelfButtonInfo_Statics::NewProp_Code,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FShelfButtonInfo_Statics::NewProp_ID,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FShelfButtonInfo_Statics::NewProp_DisplayName,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FShelfButtonInfo_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_PythonEditor,
		nullptr,
		&NewStructOps,
		"ShelfButtonInfo",
		sizeof(FShelfButtonInfo),
		alignof(FShelfButtonInfo),
		Z_Construct_UScriptStruct_FShelfButtonInfo_Statics::PropPointers,
		ARRAY_COUNT(Z_Construct_UScriptStruct_FShelfButtonInfo_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FShelfButtonInfo_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FShelfButtonInfo_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FShelfButtonInfo()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FShelfButtonInfo_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_PythonEditor();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("ShelfButtonInfo"), sizeof(FShelfButtonInfo), Get_Z_Construct_UScriptStruct_FShelfButtonInfo_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FShelfButtonInfo_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FShelfButtonInfo_Hash() { return 4034231884U; }
	void UScriptShelfs::StaticRegisterNativesUScriptShelfs()
	{
	}
	UClass* Z_Construct_UClass_UScriptShelfs_NoRegister()
	{
		return UScriptShelfs::StaticClass();
	}
	struct Z_Construct_UClass_UScriptShelfs_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Tabs_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Tabs;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Tabs_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LastSelectionID_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_LastSelectionID;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UScriptShelfs_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_PythonEditor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UScriptShelfs_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "ScriptShelfs.h" },
		{ "ModuleRelativePath", "Public/ScriptShelfs.h" },
		{ "ToolTip", "Config = ScriptShelfs, defaultconfig" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UScriptShelfs_Statics::NewProp_Tabs_MetaData[] = {
		{ "Category", "Shelfs" },
		{ "ModuleRelativePath", "Public/ScriptShelfs.h" },
		{ "ToolTip", "Config," },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UScriptShelfs_Statics::NewProp_Tabs = { "Tabs", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UScriptShelfs, Tabs), METADATA_PARAMS(Z_Construct_UClass_UScriptShelfs_Statics::NewProp_Tabs_MetaData, ARRAY_COUNT(Z_Construct_UClass_UScriptShelfs_Statics::NewProp_Tabs_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UScriptShelfs_Statics::NewProp_Tabs_Inner = { "Tabs", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FShelfTab, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UScriptShelfs_Statics::NewProp_LastSelectionID_MetaData[] = {
		{ "Category", "Shelfs" },
		{ "ModuleRelativePath", "Public/ScriptShelfs.h" },
		{ "ToolTip", "Config," },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_UScriptShelfs_Statics::NewProp_LastSelectionID = { "LastSelectionID", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UScriptShelfs, LastSelectionID), METADATA_PARAMS(Z_Construct_UClass_UScriptShelfs_Statics::NewProp_LastSelectionID_MetaData, ARRAY_COUNT(Z_Construct_UClass_UScriptShelfs_Statics::NewProp_LastSelectionID_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UScriptShelfs_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UScriptShelfs_Statics::NewProp_Tabs,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UScriptShelfs_Statics::NewProp_Tabs_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UScriptShelfs_Statics::NewProp_LastSelectionID,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UScriptShelfs_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UScriptShelfs>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UScriptShelfs_Statics::ClassParams = {
		&UScriptShelfs::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UScriptShelfs_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		ARRAY_COUNT(Z_Construct_UClass_UScriptShelfs_Statics::PropPointers),
		0,
		0x000000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UScriptShelfs_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UScriptShelfs_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UScriptShelfs()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UScriptShelfs_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UScriptShelfs, 3165692442);
	template<> PYTHONEDITOR_API UClass* StaticClass<UScriptShelfs>()
	{
		return UScriptShelfs::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UScriptShelfs(Z_Construct_UClass_UScriptShelfs, &UScriptShelfs::StaticClass, TEXT("/Script/PythonEditor"), TEXT("UScriptShelfs"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UScriptShelfs);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

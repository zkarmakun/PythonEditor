// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PythonEditor/Public/PythonProject.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePythonProject() {}
// Cross Module References
	PYTHONEDITOR_API UClass* Z_Construct_UClass_UPythonProject_NoRegister();
	PYTHONEDITOR_API UClass* Z_Construct_UClass_UPythonProject();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_PythonEditor();
// End Cross Module References
	void UPythonProject::StaticRegisterNativesUPythonProject()
	{
	}
	UClass* Z_Construct_UClass_UPythonProject_NoRegister()
	{
		return UPythonProject::StaticClass();
	}
	struct Z_Construct_UClass_UPythonProject_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OpenedTabs_MetaData[];
#endif
		static const UE4CodeGen_Private::FMapPropertyParams NewProp_OpenedTabs;
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_OpenedTabs_Key_KeyProp;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_OpenedTabs_ValueProp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LastTabFocused_MetaData[];
#endif
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_LastTabFocused;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPythonProject_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_PythonEditor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPythonProject_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "PythonProject.h" },
		{ "ModuleRelativePath", "Public/PythonProject.h" },
		{ "ToolTip", "This is just a config class to store what tabs where opened in the session and the next time the editor toolkit will open those again" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPythonProject_Statics::NewProp_OpenedTabs_MetaData[] = {
		{ "Category", "Shelfs" },
		{ "ModuleRelativePath", "Public/PythonProject.h" },
	};
#endif
	const UE4CodeGen_Private::FMapPropertyParams Z_Construct_UClass_UPythonProject_Statics::NewProp_OpenedTabs = { "OpenedTabs", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPythonProject, OpenedTabs), METADATA_PARAMS(Z_Construct_UClass_UPythonProject_Statics::NewProp_OpenedTabs_MetaData, ARRAY_COUNT(Z_Construct_UClass_UPythonProject_Statics::NewProp_OpenedTabs_MetaData)) };
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UClass_UPythonProject_Statics::NewProp_OpenedTabs_Key_KeyProp = { "OpenedTabs_Key", nullptr, (EPropertyFlags)0x0000000000004001, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_UPythonProject_Statics::NewProp_OpenedTabs_ValueProp = { "OpenedTabs", nullptr, (EPropertyFlags)0x0000000000004001, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 1, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPythonProject_Statics::NewProp_LastTabFocused_MetaData[] = {
		{ "Category", "Shelfs" },
		{ "ModuleRelativePath", "Public/PythonProject.h" },
	};
#endif
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UClass_UPythonProject_Statics::NewProp_LastTabFocused = { "LastTabFocused", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPythonProject, LastTabFocused), METADATA_PARAMS(Z_Construct_UClass_UPythonProject_Statics::NewProp_LastTabFocused_MetaData, ARRAY_COUNT(Z_Construct_UClass_UPythonProject_Statics::NewProp_LastTabFocused_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPythonProject_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPythonProject_Statics::NewProp_OpenedTabs,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPythonProject_Statics::NewProp_OpenedTabs_Key_KeyProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPythonProject_Statics::NewProp_OpenedTabs_ValueProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPythonProject_Statics::NewProp_LastTabFocused,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPythonProject_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPythonProject>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UPythonProject_Statics::ClassParams = {
		&UPythonProject::StaticClass,
		"PythonProject",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UPythonProject_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		ARRAY_COUNT(Z_Construct_UClass_UPythonProject_Statics::PropPointers),
		0,
		0x000000A6u,
		METADATA_PARAMS(Z_Construct_UClass_UPythonProject_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UPythonProject_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UPythonProject()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UPythonProject_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UPythonProject, 1764818109);
	template<> PYTHONEDITOR_API UClass* StaticClass<UPythonProject>()
	{
		return UPythonProject::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UPythonProject(Z_Construct_UClass_UPythonProject, &UPythonProject::StaticClass, TEXT("/Script/PythonEditor"), TEXT("UPythonProject"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPythonProject);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PythonUtilities/Public/PyMenu.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePyMenu() {}
// Cross Module References
	PYTHONUTILITIES_API UClass* Z_Construct_UClass_UPyMenu_NoRegister();
	PYTHONUTILITIES_API UClass* Z_Construct_UClass_UPyMenu();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_PythonUtilities();
	PYTHONUTILITIES_API UFunction* Z_Construct_UFunction_UPyMenu_Get();
	PYTHONUTILITIES_API UFunction* Z_Construct_UFunction_UPyMenu_OpenMenu();
	PYTHONUTILITIES_API UFunction* Z_Construct_UFunction_UPyMenu_Run();
	PYTHONUTILITIES_API UFunction* Z_Construct_UFunction_UPyMenu_Setup();
// End Cross Module References
	static FName NAME_UPyMenu_Run = FName(TEXT("Run"));
	void UPyMenu::Run()
	{
		ProcessEvent(FindFunctionChecked(NAME_UPyMenu_Run),NULL);
	}
	static FName NAME_UPyMenu_Setup = FName(TEXT("Setup"));
	void UPyMenu::Setup()
	{
		ProcessEvent(FindFunctionChecked(NAME_UPyMenu_Setup),NULL);
	}
	void UPyMenu::StaticRegisterNativesUPyMenu()
	{
		UClass* Class = UPyMenu::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Get", &UPyMenu::execGet },
			{ "OpenMenu", &UPyMenu::execOpenMenu },
			{ "Run", &UPyMenu::execRun },
			{ "Setup", &UPyMenu::execSetup },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPyMenu_Get_Statics
	{
		struct PyMenu_eventGet_Parms
		{
			UPyMenu* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPyMenu_Get_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PyMenu_eventGet_Parms, ReturnValue), Z_Construct_UClass_UPyMenu_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPyMenu_Get_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPyMenu_Get_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPyMenu_Get_Statics::Function_MetaDataParams[] = {
		{ "Category", "Python" },
		{ "DevelopmentOnly", "" },
		{ "ModuleRelativePath", "Public/PyMenu.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPyMenu_Get_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPyMenu, nullptr, "Get", sizeof(PyMenu_eventGet_Parms), Z_Construct_UFunction_UPyMenu_Get_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UPyMenu_Get_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPyMenu_Get_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UPyMenu_Get_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPyMenu_Get()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPyMenu_Get_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPyMenu_OpenMenu_Statics
	{
		struct PyMenu_eventOpenMenu_Parms
		{
			UPyMenu* Menu;
			FString Tittle;
			int32 Width;
			int32 height;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_height;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_Width;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Tittle;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Menu;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPyMenu_OpenMenu_Statics::NewProp_height = { "height", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PyMenu_eventOpenMenu_Parms, height), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPyMenu_OpenMenu_Statics::NewProp_Width = { "Width", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PyMenu_eventOpenMenu_Parms, Width), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPyMenu_OpenMenu_Statics::NewProp_Tittle = { "Tittle", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PyMenu_eventOpenMenu_Parms, Tittle), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPyMenu_OpenMenu_Statics::NewProp_Menu = { "Menu", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PyMenu_eventOpenMenu_Parms, Menu), Z_Construct_UClass_UPyMenu_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPyMenu_OpenMenu_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPyMenu_OpenMenu_Statics::NewProp_height,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPyMenu_OpenMenu_Statics::NewProp_Width,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPyMenu_OpenMenu_Statics::NewProp_Tittle,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPyMenu_OpenMenu_Statics::NewProp_Menu,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPyMenu_OpenMenu_Statics::Function_MetaDataParams[] = {
		{ "Category", "Python Menu" },
		{ "CPP_Default_height", "200" },
		{ "CPP_Default_Tittle", "Py Tool" },
		{ "CPP_Default_Width", "320" },
		{ "DevelopmentOnly", "" },
		{ "ModuleRelativePath", "Public/PyMenu.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPyMenu_OpenMenu_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPyMenu, nullptr, "OpenMenu", sizeof(PyMenu_eventOpenMenu_Parms), Z_Construct_UFunction_UPyMenu_OpenMenu_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UPyMenu_OpenMenu_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPyMenu_OpenMenu_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UPyMenu_OpenMenu_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPyMenu_OpenMenu()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPyMenu_OpenMenu_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPyMenu_Run_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPyMenu_Run_Statics::Function_MetaDataParams[] = {
		{ "Category", "Python menu" },
		{ "DevelopmentOnly", "" },
		{ "ModuleRelativePath", "Public/PyMenu.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPyMenu_Run_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPyMenu, nullptr, "Run", 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPyMenu_Run_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UPyMenu_Run_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPyMenu_Run()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPyMenu_Run_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPyMenu_Setup_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPyMenu_Setup_Statics::Function_MetaDataParams[] = {
		{ "Category", "Python menu" },
		{ "DevelopmentOnly", "" },
		{ "ModuleRelativePath", "Public/PyMenu.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPyMenu_Setup_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPyMenu, nullptr, "Setup", 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPyMenu_Setup_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UPyMenu_Setup_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPyMenu_Setup()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPyMenu_Setup_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UPyMenu_NoRegister()
	{
		return UPyMenu::StaticClass();
	}
	struct Z_Construct_UClass_UPyMenu_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPyMenu_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_PythonUtilities,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UPyMenu_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPyMenu_Get, "Get" }, // 3129787451
		{ &Z_Construct_UFunction_UPyMenu_OpenMenu, "OpenMenu" }, // 2434640953
		{ &Z_Construct_UFunction_UPyMenu_Run, "Run" }, // 8120000
		{ &Z_Construct_UFunction_UPyMenu_Setup, "Setup" }, // 3625049258
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPyMenu_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "PyMenu.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/PyMenu.h" },
		{ "ToolTip", "The purpose of this class is generate children in Python code, and python you can add variables to your class with the\nreflection system, it will automatically generate a menu for you with the IDetailView class\nYou can access every variable in the python's way:\n\n#example class\nclass MyMenu(unreal.PyMenu)\n\n      myint = unreal.uproperty(int)\n\n      @unreal.ufunction(Override = True)\n      def run(self):\n              #here goes your logic, you can access your variables like: self.myint" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPyMenu_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPyMenu>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UPyMenu_Statics::ClassParams = {
		&UPyMenu::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UPyMenu_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UPyMenu_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UPyMenu()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UPyMenu_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UPyMenu, 1174056781);
	template<> PYTHONUTILITIES_API UClass* StaticClass<UPyMenu>()
	{
		return UPyMenu::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UPyMenu(Z_Construct_UClass_UPyMenu, &UPyMenu::StaticClass, TEXT("/Script/PythonUtilities"), TEXT("UPyMenu"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPyMenu);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

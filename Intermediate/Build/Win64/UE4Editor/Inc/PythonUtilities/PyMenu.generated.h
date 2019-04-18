// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPyMenu;
#ifdef PYTHONUTILITIES_PyMenu_generated_h
#error "PyMenu.generated.h already included, missing '#pragma once' in PyMenu.h"
#endif
#define PYTHONUTILITIES_PyMenu_generated_h

#define PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyMenu_h_28_RPC_WRAPPERS \
	virtual void Setup_Implementation(); \
	virtual void Run_Implementation(); \
 \
	DECLARE_FUNCTION(execOpenMenu) \
	{ \
		P_GET_OBJECT(UPyMenu,Z_Param_Menu); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Tittle); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Width); \
		P_GET_PROPERTY(UIntProperty,Z_Param_height); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UPyMenu::OpenMenu(Z_Param_Menu,Z_Param_Tittle,Z_Param_Width,Z_Param_height); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetup) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Setup_Implementation(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRun) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Run_Implementation(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGet) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UPyMenu**)Z_Param__Result=UPyMenu::Get(); \
		P_NATIVE_END; \
	}


#define PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyMenu_h_28_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOpenMenu) \
	{ \
		P_GET_OBJECT(UPyMenu,Z_Param_Menu); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Tittle); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Width); \
		P_GET_PROPERTY(UIntProperty,Z_Param_height); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UPyMenu::OpenMenu(Z_Param_Menu,Z_Param_Tittle,Z_Param_Width,Z_Param_height); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetup) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Setup_Implementation(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRun) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Run_Implementation(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGet) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UPyMenu**)Z_Param__Result=UPyMenu::Get(); \
		P_NATIVE_END; \
	}


#define PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyMenu_h_28_EVENT_PARMS
#define PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyMenu_h_28_CALLBACK_WRAPPERS
#define PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyMenu_h_28_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPyMenu(); \
	friend struct Z_Construct_UClass_UPyMenu_Statics; \
public: \
	DECLARE_CLASS(UPyMenu, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/PythonUtilities"), NO_API) \
	DECLARE_SERIALIZER(UPyMenu)


#define PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyMenu_h_28_INCLASS \
private: \
	static void StaticRegisterNativesUPyMenu(); \
	friend struct Z_Construct_UClass_UPyMenu_Statics; \
public: \
	DECLARE_CLASS(UPyMenu, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/PythonUtilities"), NO_API) \
	DECLARE_SERIALIZER(UPyMenu)


#define PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyMenu_h_28_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPyMenu(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPyMenu) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPyMenu); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPyMenu); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPyMenu(UPyMenu&&); \
	NO_API UPyMenu(const UPyMenu&); \
public:


#define PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyMenu_h_28_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPyMenu(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPyMenu(UPyMenu&&); \
	NO_API UPyMenu(const UPyMenu&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPyMenu); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPyMenu); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPyMenu)


#define PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyMenu_h_28_PRIVATE_PROPERTY_OFFSET
#define PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyMenu_h_25_PROLOG \
	PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyMenu_h_28_EVENT_PARMS


#define PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyMenu_h_28_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyMenu_h_28_PRIVATE_PROPERTY_OFFSET \
	PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyMenu_h_28_RPC_WRAPPERS \
	PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyMenu_h_28_CALLBACK_WRAPPERS \
	PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyMenu_h_28_INCLASS \
	PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyMenu_h_28_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyMenu_h_28_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyMenu_h_28_PRIVATE_PROPERTY_OFFSET \
	PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyMenu_h_28_RPC_WRAPPERS_NO_PURE_DECLS \
	PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyMenu_h_28_CALLBACK_WRAPPERS \
	PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyMenu_h_28_INCLASS_NO_PURE_DECLS \
	PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyMenu_h_28_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PYTHONUTILITIES_API UClass* StaticClass<class UPyMenu>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyMenu_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS

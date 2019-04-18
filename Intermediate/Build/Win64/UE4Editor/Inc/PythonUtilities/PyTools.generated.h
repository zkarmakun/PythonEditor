// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UBlueprint;
class UObject;
struct FLinearColor;
#ifdef PYTHONUTILITIES_PyTools_generated_h
#error "PyTools.generated.h already included, missing '#pragma once' in PyTools.h"
#endif
#define PYTHONUTILITIES_PyTools_generated_h

#define PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyTools_h_17_RPC_WRAPPERS
#define PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyTools_h_17_RPC_WRAPPERS_NO_PURE_DECLS
#if WITH_EDITOR
#define PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyTools_h_17_EDITOR_ONLY_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execCHECKFUNCTIONS) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_File); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UPyTools::CHECKFUNCTIONS(Z_Param_File); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCopyBlueprintProperty) \
	{ \
		P_GET_OBJECT(UBlueprint,Z_Param_Source); \
		P_GET_PROPERTY(UNameProperty,Z_Param_VarName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=UPyTools::CopyBlueprintProperty(Z_Param_Source,Z_Param_VarName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetBlueprintFromObject) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_Object); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UBlueprint**)Z_Param__Result=UPyTools::GetBlueprintFromObject(Z_Param_Object); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAllFunctions) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_Object); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FString>*)Z_Param__Result=UPyTools::GetAllFunctions(Z_Param_Object); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAllProperties) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_Object); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FString>*)Z_Param__Result=UPyTools::GetAllProperties(Z_Param_Object); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetFolderColor) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Path); \
		P_GET_STRUCT(FLinearColor,Z_Param_Color); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UPyTools::SetFolderColor(Z_Param_Path,Z_Param_Color); \
		P_NATIVE_END; \
	}


#define PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyTools_h_17_EDITOR_ONLY_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execCHECKFUNCTIONS) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_File); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UPyTools::CHECKFUNCTIONS(Z_Param_File); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCopyBlueprintProperty) \
	{ \
		P_GET_OBJECT(UBlueprint,Z_Param_Source); \
		P_GET_PROPERTY(UNameProperty,Z_Param_VarName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=UPyTools::CopyBlueprintProperty(Z_Param_Source,Z_Param_VarName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetBlueprintFromObject) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_Object); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UBlueprint**)Z_Param__Result=UPyTools::GetBlueprintFromObject(Z_Param_Object); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAllFunctions) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_Object); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FString>*)Z_Param__Result=UPyTools::GetAllFunctions(Z_Param_Object); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAllProperties) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_Object); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FString>*)Z_Param__Result=UPyTools::GetAllProperties(Z_Param_Object); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetFolderColor) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Path); \
		P_GET_STRUCT(FLinearColor,Z_Param_Color); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UPyTools::SetFolderColor(Z_Param_Path,Z_Param_Color); \
		P_NATIVE_END; \
	}


#else
#define PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyTools_h_17_EDITOR_ONLY_RPC_WRAPPERS
#define PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyTools_h_17_EDITOR_ONLY_RPC_WRAPPERS_NO_PURE_DECLS
#endif //WITH_EDITOR
#define PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyTools_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPyTools(); \
	friend struct Z_Construct_UClass_UPyTools_Statics; \
public: \
	DECLARE_CLASS(UPyTools, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/PythonUtilities"), NO_API) \
	DECLARE_SERIALIZER(UPyTools)


#define PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyTools_h_17_INCLASS \
private: \
	static void StaticRegisterNativesUPyTools(); \
	friend struct Z_Construct_UClass_UPyTools_Statics; \
public: \
	DECLARE_CLASS(UPyTools, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/PythonUtilities"), NO_API) \
	DECLARE_SERIALIZER(UPyTools)


#define PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyTools_h_17_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPyTools(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPyTools) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPyTools); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPyTools); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPyTools(UPyTools&&); \
	NO_API UPyTools(const UPyTools&); \
public:


#define PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyTools_h_17_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPyTools(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPyTools(UPyTools&&); \
	NO_API UPyTools(const UPyTools&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPyTools); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPyTools); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPyTools)


#define PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyTools_h_17_PRIVATE_PROPERTY_OFFSET
#define PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyTools_h_14_PROLOG
#define PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyTools_h_17_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyTools_h_17_PRIVATE_PROPERTY_OFFSET \
	PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyTools_h_17_RPC_WRAPPERS \
	PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyTools_h_17_EDITOR_ONLY_RPC_WRAPPERS \
	PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyTools_h_17_INCLASS \
	PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyTools_h_17_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyTools_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyTools_h_17_PRIVATE_PROPERTY_OFFSET \
	PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyTools_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyTools_h_17_EDITOR_ONLY_RPC_WRAPPERS_NO_PURE_DECLS \
	PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyTools_h_17_INCLASS_NO_PURE_DECLS \
	PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyTools_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PYTHONUTILITIES_API UClass* StaticClass<class UPyTools>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyTools_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS

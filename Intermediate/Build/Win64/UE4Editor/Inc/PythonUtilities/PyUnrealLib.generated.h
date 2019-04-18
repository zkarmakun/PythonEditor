// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FSuggestion;
#ifdef PYTHONUTILITIES_PyUnrealLib_generated_h
#error "PyUnrealLib.generated.h already included, missing '#pragma once' in PyUnrealLib.h"
#endif
#define PYTHONUTILITIES_PyUnrealLib_generated_h

#define PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyUnrealLib_h_42_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FSuggestion_Statics; \
	PYTHONUTILITIES_API static class UScriptStruct* StaticStruct();


template<> PYTHONUTILITIES_API UScriptStruct* StaticStruct<struct FSuggestion>();

#define PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyUnrealLib_h_31_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FCustomStruct_Statics; \
	PYTHONUTILITIES_API static class UScriptStruct* StaticStruct();


template<> PYTHONUTILITIES_API UScriptStruct* StaticStruct<struct FCustomStruct>();

#define PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyUnrealLib_h_70_RPC_WRAPPERS
#define PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyUnrealLib_h_70_RPC_WRAPPERS_NO_PURE_DECLS
#if WITH_EDITOR
#define PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyUnrealLib_h_70_EDITOR_ONLY_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetProjectScriptDir) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=UPyUnrealLib::GetProjectScriptDir(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetHelp) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Expression); \
		P_GET_PROPERTY(UStrProperty,Z_Param_ExintingFile); \
		P_GET_UBOOL(Z_Param_bIncludeFile); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=UPyUnrealLib::GetHelp(Z_Param_Expression,Z_Param_ExintingFile,Z_Param_bIncludeFile); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execReloadModule) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Module); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UPyUnrealLib::ReloadModule(Z_Param_Module); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFindSuggetionFromEditable) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_ExistingFile); \
		P_GET_TARRAY_REF(FSuggestion,Z_Param_Out_OutSuggestions); \
		P_GET_TARRAY_REF(FString,Z_Param_Out_Favorites); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UPyUnrealLib::FindSuggetionFromEditable(Z_Param_ExistingFile,Z_Param_Out_OutSuggestions,Z_Param_Out_Favorites); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFindCompletitionList) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_ModuleName); \
		P_GET_TARRAY_REF(FString,Z_Param_Out_Tokens); \
		P_GET_TARRAY_REF(FSuggestion,Z_Param_Out_OutList); \
		P_GET_UBOOL(Z_Param_bFullEval); \
		P_GET_TARRAY_REF(FString,Z_Param_Out_Favorites); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=UPyUnrealLib::FindCompletitionList(Z_Param_ModuleName,Z_Param_Out_Tokens,Z_Param_Out_OutList,Z_Param_bFullEval,Z_Param_Out_Favorites); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsValidSuggestion) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_InSuggetion); \
		P_GET_PROPERTY(UStrProperty,Z_Param_TrimWord); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=UPyUnrealLib::IsValidSuggestion(Z_Param_InSuggetion,Z_Param_TrimWord); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFindSuggetion) \
	{ \
		P_GET_TARRAY_REF(FString,Z_Param_Out_Tokens); \
		P_GET_TARRAY_REF(FSuggestion,Z_Param_Out_OutSuggestions); \
		P_GET_TARRAY_REF(FString,Z_Param_Out_Favorites); \
		P_GET_UBOOL(Z_Param_FullEvaluation); \
		P_GET_UBOOL(Z_Param_bReloadModule); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UPyUnrealLib::FindSuggetion(Z_Param_Out_Tokens,Z_Param_Out_OutSuggestions,Z_Param_Out_Favorites,Z_Param_FullEvaluation,Z_Param_bReloadModule); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetPyInstalledModules) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FString>*)Z_Param__Result=UPyUnrealLib::GetPyInstalledModules(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetPyModuleAttrs) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_ModuleName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FString>*)Z_Param__Result=UPyUnrealLib::GetPyModuleAttrs(Z_Param_ModuleName); \
		P_NATIVE_END; \
	}


#define PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyUnrealLib_h_70_EDITOR_ONLY_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetProjectScriptDir) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=UPyUnrealLib::GetProjectScriptDir(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetHelp) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Expression); \
		P_GET_PROPERTY(UStrProperty,Z_Param_ExintingFile); \
		P_GET_UBOOL(Z_Param_bIncludeFile); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=UPyUnrealLib::GetHelp(Z_Param_Expression,Z_Param_ExintingFile,Z_Param_bIncludeFile); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execReloadModule) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Module); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UPyUnrealLib::ReloadModule(Z_Param_Module); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFindSuggetionFromEditable) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_ExistingFile); \
		P_GET_TARRAY_REF(FSuggestion,Z_Param_Out_OutSuggestions); \
		P_GET_TARRAY_REF(FString,Z_Param_Out_Favorites); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UPyUnrealLib::FindSuggetionFromEditable(Z_Param_ExistingFile,Z_Param_Out_OutSuggestions,Z_Param_Out_Favorites); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFindCompletitionList) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_ModuleName); \
		P_GET_TARRAY_REF(FString,Z_Param_Out_Tokens); \
		P_GET_TARRAY_REF(FSuggestion,Z_Param_Out_OutList); \
		P_GET_UBOOL(Z_Param_bFullEval); \
		P_GET_TARRAY_REF(FString,Z_Param_Out_Favorites); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=UPyUnrealLib::FindCompletitionList(Z_Param_ModuleName,Z_Param_Out_Tokens,Z_Param_Out_OutList,Z_Param_bFullEval,Z_Param_Out_Favorites); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsValidSuggestion) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_InSuggetion); \
		P_GET_PROPERTY(UStrProperty,Z_Param_TrimWord); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=UPyUnrealLib::IsValidSuggestion(Z_Param_InSuggetion,Z_Param_TrimWord); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFindSuggetion) \
	{ \
		P_GET_TARRAY_REF(FString,Z_Param_Out_Tokens); \
		P_GET_TARRAY_REF(FSuggestion,Z_Param_Out_OutSuggestions); \
		P_GET_TARRAY_REF(FString,Z_Param_Out_Favorites); \
		P_GET_UBOOL(Z_Param_FullEvaluation); \
		P_GET_UBOOL(Z_Param_bReloadModule); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UPyUnrealLib::FindSuggetion(Z_Param_Out_Tokens,Z_Param_Out_OutSuggestions,Z_Param_Out_Favorites,Z_Param_FullEvaluation,Z_Param_bReloadModule); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetPyInstalledModules) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FString>*)Z_Param__Result=UPyUnrealLib::GetPyInstalledModules(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetPyModuleAttrs) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_ModuleName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FString>*)Z_Param__Result=UPyUnrealLib::GetPyModuleAttrs(Z_Param_ModuleName); \
		P_NATIVE_END; \
	}


#else
#define PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyUnrealLib_h_70_EDITOR_ONLY_RPC_WRAPPERS
#define PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyUnrealLib_h_70_EDITOR_ONLY_RPC_WRAPPERS_NO_PURE_DECLS
#endif //WITH_EDITOR
#define PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyUnrealLib_h_70_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPyUnrealLib(); \
	friend struct Z_Construct_UClass_UPyUnrealLib_Statics; \
public: \
	DECLARE_CLASS(UPyUnrealLib, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/PythonUtilities"), NO_API) \
	DECLARE_SERIALIZER(UPyUnrealLib)


#define PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyUnrealLib_h_70_INCLASS \
private: \
	static void StaticRegisterNativesUPyUnrealLib(); \
	friend struct Z_Construct_UClass_UPyUnrealLib_Statics; \
public: \
	DECLARE_CLASS(UPyUnrealLib, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/PythonUtilities"), NO_API) \
	DECLARE_SERIALIZER(UPyUnrealLib)


#define PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyUnrealLib_h_70_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPyUnrealLib(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPyUnrealLib) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPyUnrealLib); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPyUnrealLib); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPyUnrealLib(UPyUnrealLib&&); \
	NO_API UPyUnrealLib(const UPyUnrealLib&); \
public:


#define PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyUnrealLib_h_70_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPyUnrealLib(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPyUnrealLib(UPyUnrealLib&&); \
	NO_API UPyUnrealLib(const UPyUnrealLib&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPyUnrealLib); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPyUnrealLib); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPyUnrealLib)


#define PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyUnrealLib_h_70_PRIVATE_PROPERTY_OFFSET
#define PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyUnrealLib_h_67_PROLOG
#define PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyUnrealLib_h_70_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyUnrealLib_h_70_PRIVATE_PROPERTY_OFFSET \
	PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyUnrealLib_h_70_RPC_WRAPPERS \
	PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyUnrealLib_h_70_EDITOR_ONLY_RPC_WRAPPERS \
	PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyUnrealLib_h_70_INCLASS \
	PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyUnrealLib_h_70_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyUnrealLib_h_70_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyUnrealLib_h_70_PRIVATE_PROPERTY_OFFSET \
	PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyUnrealLib_h_70_RPC_WRAPPERS_NO_PURE_DECLS \
	PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyUnrealLib_h_70_EDITOR_ONLY_RPC_WRAPPERS_NO_PURE_DECLS \
	PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyUnrealLib_h_70_INCLASS_NO_PURE_DECLS \
	PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyUnrealLib_h_70_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PYTHONUTILITIES_API UClass* StaticClass<class UPyUnrealLib>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID PythonExample_Plugins_PythonEditor_Source_PythonUtilities_Public_PyUnrealLib_h


#define FOREACH_ENUM_EPYATTRTYPE(op) \
	op(EPyAttrType::None) \
	op(EPyAttrType::Module) \
	op(EPyAttrType::Class) \
	op(EPyAttrType::Method) \
	op(EPyAttrType::Enum) \
	op(EPyAttrType::Keyword) 

enum class EPyAttrType : uint8;
template<> PYTHONUTILITIES_API UEnum* StaticEnum<EPyAttrType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS

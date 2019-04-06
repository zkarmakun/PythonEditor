//Copyright 2019, Jorge Calleros Ramirez (Karma), All rights reserved.

#include "PyTools.h"

#if WITH_EDITOR

#include "Misc/Paths.h"
#include "Misc/FileHelper.h"
#include "Framework/Text/SyntaxTokenizer.h"
#include "Editor/UnrealEd/Public/Kismet2/BlueprintEditorUtils.h"
#include "ScopedTransaction.h"
#include "UnrealType.h"

THIRD_PARTY_INCLUDES_START
#include "Python.h"
#include "structmember.h"
THIRD_PARTY_INCLUDES_END

#define LOCTEXT_NAMESPACE "PyTools"

#include "Editor/ContentBrowser/Public/ContentBrowserModule.h"
#include "Editor/ContentBrowser/Public/IContentBrowserSingleton.h"
#include "Editor/BlueprintGraph/Classes/EdGraphSchema_K2.h"
#include "KismetEditorUtilities.h"
#include "Misc/ConfigCacheIni.h"

void UPyTools::SetFolderColor(FString Path, FLinearColor Color)
{
	GConfig->SetString(TEXT("PathColor"), *Path, *Color.ToString(), GEditorPerProjectIni);
}

TArray<FString> UPyTools::GetAllProperties(UObject* Object)
{
	TArray<FString> Output;
	if (Object != nullptr) {
		for (TFieldIterator<UProperty> It(Object->GetClass()); It; ++It) 
		{
			UProperty* Property = *It;
			if (Property->HasAnyPropertyFlags(EPropertyFlags::CPF_Edit)) 
			{
				Output.Add(Property->GetName());
			}
		}
	}
	return Output;
}

TArray<FString> UPyTools::GetAllFunctions(UObject* Object)
{
	TArray<FString> Output;
	if (Object != nullptr)
	{
		for (TFieldIterator<UFunction> It(Object->GetClass()); It; ++It) 
		{
			UFunction* Function = *It;
			Output.Add(Function->GetName());
		}
	}
	return Output;
}

UBlueprint* UPyTools::GetBlueprintFromObject(UObject* Object)
{
	UBlueprint* BP = nullptr;
	
	if (Object != nullptr) {
		BP = Cast<UBlueprint>(Object);
		
		if (BP == nullptr) {
			BP = Cast<UBlueprint>(Object->GetClass()->ClassGeneratedBy);
		}
	}
	
	return BP;
}

template<typename T>
T* GetCDO(UBlueprint* Blueprint) {
	if (Blueprint == nullptr) { return nullptr; }
	//
	const UClass* BlueprintClass = Blueprint->GeneratedClass;
	return Cast<T>(BlueprintClass->ClassDefaultObject);
}

bool UPyTools::CopyBlueprintProperty(UBlueprint* Source, FName VarName)
{
	UObject* CDO = GetCDO<UObject>(Source);
	if (!CDO) return false;

	FEdGraphPinType Type = FEdGraphPinType(UEdGraphSchema_K2::PC_Float, VarName, nullptr, EPinContainerType::None, false, FEdGraphTerminalType());
	FBlueprintEditorUtils::AddMemberVariable(Source, VarName, Type, FString("3"));
	FKismetEditorUtilities::CompileBlueprint(Source);

	UE_LOG(LogTemp, Warning, TEXT("hell yeah"));
	for (TFieldIterator<UProperty> It(CDO->GetClass()); It; ++It)
	{
		UProperty* Property = *It;
		
		if (Property->HasAnyPropertyFlags(EPropertyFlags::CPF_Edit || EPropertyFlags::CPF_BlueprintVisible))
		{
			UE_LOG(LogTemp, Warning, TEXT("var: %s"), *Property->GetName());
		}
	}

	return false;
}

void UPyTools::CHECKFUNCTIONS(const FString& File)
{
// 	PyObject* SysModuleName = PyString_FromString((char*)"sys");
// 	PyObject* SysModule = PyImport_Import(SysModuleName);
// 
// 	PyObject * VersionVar = PyObject_GetAttrString(SysModule, "version");
// 	FString value = PyString_AsString(VersionVar);
// 	UE_LOG(LogTemp, Log, TEXT("here: %s"), *value);

	//PyObject *errobj, *errdata, *errtraceback, *pystring;
	int32 retval;

	FString PyCode =
		"import " + File + "\n"\
		;

	retval = PyRun_SimpleString(
		TCHAR_TO_UTF8(*PyCode)
	);
	
	UE_LOG(LogTemp, Log, TEXT("ret val: %i"), retval);

}

#undef LOCTEXT_NAMESPACE

#endif
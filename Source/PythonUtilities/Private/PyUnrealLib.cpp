//Copyright 2019, Jorge Calleros Ramirez (Karma), All rights reserved.

#include "PyUnrealLib.h"
#include "Runtime/Core/Public/Misc/Paths.h"

#if WITH_EDITOR

PyObject* UPyUnrealLib::GetPyModuleAttrs(const FString& ModuleName, int32& OutSize)
{
	PyObject* Module = nullptr;
	Module = PyImport_Import(PyString_FromString(TCHAR_TO_UTF8(*ModuleName)));

	if (!Module) return nullptr;

	PyObject * DirList = PyObject_Dir(Module);
	OutSize = PyList_Size(DirList);

	Py_DECREF(Module);
	return DirList;
}

TArray<FString> UPyUnrealLib::GetPyModuleAttrs(const FString& ModuleName)
{
	TArray<FString> AttrList;

	int32 Size = 0;
	PyObject* List = GetPyModuleAttrs(ModuleName, Size);
	if (List)
	{
		PyObject* Elem = nullptr;
		for (int32 i = 0; i < Size; i++)
		{
			Elem = PyList_GetItem(List, i);
			if (Elem)
			{
				AttrList.Add(PyString_AsString(Elem));
			}
		}
		Py_DECREF(List);
	}
	return AttrList;
}

TArray<FString> UPyUnrealLib::GetPyInstalledModules()
{

// // 		PyTypeObject* type = presult->ob_type;
// // 		FString p = type->tp_name;

	TArray<FString> ModulesResult;

	PyObject *moduleMainString = PyString_FromString("__main__");
	PyObject *moduleMain = PyImport_Import(moduleMainString);

	PyRun_SimpleString(
		"from pydoc import ModuleScanner\n"\
		"modules = []\n"\
		"def callback(path, modname, desc, modules=modules):\n"\
		"	if modname and modname[-9:] == '.__init__':\n"\
		"		modname = modname[:-9] + ' (package)'\n"\
		"	if modname.find('.') < 0:\n"\
		"		modules.append(modname)\n"\
		"def onerror(modname):\n"\
		"	callback(None, modname, None)\n"\
		"def GetModulesList(somevar):\n"\
		"	s = somevar\n"\
		"	ModuleScanner().run(callback, onerror=onerror)\n"\
		"	modules.append(s)\n"\
		"	return modules\n"\
	);

	PyObject* pFunc = PyDict_GetItemString(PyModule_GetDict(moduleMain), (char*)"GetModulesList");
	PyObject* pValue = Py_BuildValue("(z)", (char*)"unreal");
	PyObject *result = PyObject_CallObject(pFunc, pValue);

	int32 Size = PyList_Size(result);
	PyObject* Elem = nullptr;
	for (int32 i = 0; i < Size; i++)
	{
		Elem = PyList_GetItem(result, i);
		if (Elem)
		{
			ModulesResult.Add(PyString_AsString(Elem));
		}
	}

	return ModulesResult;
}

bool UPyUnrealLib::IsValidSuggestion(const FString& InSuggetion, const FString& TrimWord)
{
	return (InSuggetion.StartsWith(TrimWord, ESearchCase::CaseSensitive) && InSuggetion != TrimWord);

}



void UPyUnrealLib::FindSuggetion(const TArray<FString>& Tokens, TArray<FSuggestion>& OutSuggestions, TArray<FString>& Favorites, bool FullEvaluation, bool bReloadModule)
{
	if (!Tokens.IsValidIndex(0)) return;

	

	PyObject* Module = nullptr;
	Module = PyImport_Import(PyString_FromString(TCHAR_TO_UTF8(*Tokens[0])));
	if (!Module) return;

	//reload module if needed
	if (bReloadModule)
	{
		Module = PyImport_ReloadModule(Module);
	}

	PyObject *moduleMainString = PyString_FromString("__main__");
	PyObject *moduleMain = PyImport_Import(moduleMainString);
	//PyObject *moduleMain = PyImport_ReloadModule(moduleMainString);

	FString FunctionToFind = "";
	const int32 LastIndex = Tokens.Num() - 1;
	FString LastToken = Tokens[LastIndex];

	if (Tokens.Num() == 1)
	{
		FunctionToFind = LastToken;
	}
	else
	{
		for (int32 i = 0; i <= LastIndex; i++)
		{
			if (i != LastIndex)
			{
				FunctionToFind += Tokens[i] + ".";
			}

			if (FullEvaluation && i == LastIndex)
			{
				FunctionToFind += Tokens[i];
			}
		}
		FunctionToFind.RemoveFromEnd(".");
	}

	FString PyCode = 
		"import " + Tokens[0] + "\n"\
		"def GetDir(some):\n"\
		"	return dir(" + FunctionToFind + ")\n"\
		;

	PyRun_SimpleString(
		TCHAR_TO_UTF8(*PyCode)
	);

	PyObject* pFunc = PyDict_GetItemString(PyModule_GetDict(moduleMain), (char*)"GetDir");
	PyObject *result = PyObject_CallObject(pFunc, Py_BuildValue("(z)", (char*)"hack"));

	if (!result || result == NULL) return;

	TArray<FSuggestion> InitsAndUselessGoesLast;
	TArray<FSuggestion> FavoritesSuggestions;
	TArray<FSuggestion> NormalSuggestions;

	int32 Size = PyList_Size(result);
	for (int32 i = 0; i < Size; i++)
	{
		FString Value = PyString_AsString(PyList_GetItem(result, i));
		if (FullEvaluation)
		{
			if (Value.StartsWith("_"))
			{
				InitsAndUselessGoesLast.Add(FSuggestion(Value, EPyAttrType::Enum, Value));
				continue;
			}

			if (Favorites.Contains(Value))
			{
				FavoritesSuggestions.Add(FSuggestion(Value, EPyAttrType::Module, Value));
				continue;
			}

			NormalSuggestions.Add(FSuggestion(Value, EPyAttrType::Module, Value));
			continue;
		}

		if (LastToken.IsEmpty())
		{
			continue;
		}

		if (IsValidSuggestion(Value, LastToken))
		{
			FString WordCompletation = Value;
			WordCompletation.RemoveFromStart(LastToken);

			if (Value.StartsWith("_"))
			{
				InitsAndUselessGoesLast.Add(FSuggestion(Value, EPyAttrType::Enum, WordCompletation));
				continue;
			}

			if (Favorites.Contains(Value))
			{
				FavoritesSuggestions.Add(FSuggestion(Value, EPyAttrType::Module, WordCompletation));
				continue;
			}

			NormalSuggestions.Add(FSuggestion(Value, EPyAttrType::Module, WordCompletation));
		}
	}

	OutSuggestions.Append(FavoritesSuggestions);
	OutSuggestions.Append(NormalSuggestions);
	OutSuggestions.Append(InitsAndUselessGoesLast);

	Py_DECREF(Module);
}


EPyAttrType UPyUnrealLib::GetAttrType(PyObject*& InAttr)
{
	if (!InAttr) return EPyAttrType::None;

	PyTypeObject* type = InAttr->ob_type;
	FString p = type->tp_name;

	if (p == "type")
	{
		return EPyAttrType::Class;
	}
	else if (p == "_EnumType")
	{
		return EPyAttrType::Enum;
	}
	else if (p == "builtin_function_or_method" || p == "function")
	{
		return EPyAttrType::Method;
	}
	else if (p == "module")
	{
		return EPyAttrType::Module;
	}
	return EPyAttrType::None;
}


bool UPyUnrealLib::FindCompletitionList(const FString& ModuleName, const TArray<FString>& Tokens, TArray<FSuggestion>& OutList, bool bFullEval, TArray<FString>& Favorites)
{
	PyObject* Module = nullptr;
	Module = PyImport_Import(PyString_FromString(TCHAR_TO_UTF8(*ModuleName)));
	if (!Module) return false;

	PyObject *moduleMainString = PyString_FromString("__main__");
	PyObject *moduleMain = PyImport_Import(moduleMainString);

	FString FunctionToFind = ModuleName;

	const int32 LastIndex = Tokens.Num() - 1;
	FString LastToken = "";
	if (Tokens.Num() > 0)
	{
		LastToken = Tokens[LastIndex];
	}

	if (Tokens.Num() > 1)
	{
		FunctionToFind += ".";
		for (int32 i = 0; i <= LastIndex; i++)
		{
			if (i != LastIndex)
			{
				FunctionToFind += Tokens[i] + ".";
			}
		}
		FunctionToFind.RemoveFromEnd(".");
	}


	FString PyCode =
		"import " + ModuleName + "\n" +
		"def GetDir(some):\n" +
		"	return dir(" + FunctionToFind + ")\n"
		;

	PyRun_SimpleString(
		TCHAR_TO_UTF8(*PyCode)
	);

	PyObject* pFunc = PyDict_GetItemString(PyModule_GetDict(moduleMain), (char*)"GetDir");
	PyObject *result = PyObject_CallObject(pFunc, Py_BuildValue("(z)", (char*)"hack"));

	TArray<FSuggestion> InitsAndUselessGoesLast;
	TArray<FSuggestion> FavoritesSuggestions;
	TArray<FSuggestion> NormalSuggestions;

	int32 Size = PyList_Size(result);
	for (int32 i = 0; i < Size; i++)
	{
		FString Value = PyString_AsString(PyList_GetItem(result, i));
		if (bFullEval)
		{
			if (Value.StartsWith("_"))
			{
				InitsAndUselessGoesLast.Add(FSuggestion(Value, EPyAttrType::Enum, Value));
				continue;
			}

			if (Favorites.Contains(Value))
			{
				FavoritesSuggestions.Add(FSuggestion(Value, EPyAttrType::Class, Value));
				continue;
			}

			NormalSuggestions.Add(FSuggestion(Value, EPyAttrType::Class, Value));
			continue;
		}

		if (LastToken.IsEmpty())
		{
			continue;
		}

		if (IsValidSuggestion(Value, LastToken))
		{
			FString WordCompletation = Value;
			WordCompletation.RemoveFromStart(LastToken);
			
			if (Value.StartsWith("_"))
			{
				InitsAndUselessGoesLast.Add(FSuggestion(Value, EPyAttrType::Enum, WordCompletation));
				continue;
			}

			if (Favorites.Contains(Value))
			{
				FavoritesSuggestions.Add(FSuggestion(Value, EPyAttrType::Class, WordCompletation));
				continue;
			}

			NormalSuggestions.Add(FSuggestion(Value, EPyAttrType::Class, WordCompletation));
		}
	}

	OutList.Append(FavoritesSuggestions);
	OutList.Append(NormalSuggestions);
	OutList.Append(InitsAndUselessGoesLast);

	Py_DECREF(Module);

	return (OutList.Num() > 0);
}

void UPyUnrealLib::FindSuggetionFromEditable(const FString& ExistingFile, TArray<FSuggestion>& OutSuggestions, TArray<FString>& Favorites)
{
	FString FileName = FPaths::GetBaseFilename(ExistingFile);
	TArray<FString> NewTokens;
	FindCompletitionList(FileName, NewTokens, OutSuggestions, true, Favorites);
}

void UPyUnrealLib::ReloadModule(const FString& Module)
{
	FString PyCode =
		"reload(" + Module + ")\n"
		;

	PyRun_SimpleString(
		TCHAR_TO_UTF8(*PyCode)
	);
}

FString UPyUnrealLib::GetHelp(const FString& Expression, const FString& ExintingFile, bool bIncludeFile)
{
	FString FileModule = FPaths::GetBaseFilename(ExintingFile);
	

	FString ModuleName;
	Expression.Split(".", &ModuleName, nullptr);

	if (ModuleName.IsEmpty())
	{
		ModuleName = "Nop";
	}
	
	PyObject *moduleMain = PyImport_Import(PyString_FromString("__main__"));

	FString ImportSelfModule = "import " + FileModule + "\n";
	FString FileExpression = "str(inspect.getargspec(" + FileModule + "." + Expression + "))\n";
	if (!bIncludeFile)
	{
		ImportSelfModule = "import unreal";
		FileExpression = "\"\"\n";
	}

	FString PyCode =
		"import inspect\n" \
		"" + ImportSelfModule + "\n" \
		"try:\n" \
		"	import " + ModuleName + "\n" \
		"except:\n"	\
		"	pass\n\n" \
		"def GetHelp(name):\n" \
		"	Line = None\n" \
		"	try:\n" \
		"		Line = " + Expression + ".__doc__\n" \
		"	except:\n" \
		"		try:\n" \
		"			Line = " + FileExpression + "\n" \
		"		except:\n" \
		"			pass\n" \
		"	return Line\n" \
		;

	int32 ReturnPython = -1;
	ReturnPython = PyRun_SimpleString(
		TCHAR_TO_UTF8(*PyCode)
	);

	
	if (ReturnPython == -1)
	{
		UE_LOG(LogTemp, Warning, TEXT("Invalid compilation python \n%s"), *PyCode);
		return FString();
	}


	PyObject* pFunc = PyDict_GetItemString(PyModule_GetDict(moduleMain), (char*)"GetHelp");
	if (!pFunc)
	{
		UE_LOG(LogTemp, Error, TEXT("Invalid Python Function"));
		return FString();
	}

	PyObject *result = PyObject_CallObject(pFunc, Py_BuildValue("(z)", (char*)"hack"));

	if (!result)
	{
		UE_LOG(LogTemp, Error, TEXT("Invalid result after calling python function"));
		return FString();
	}
		

	FString Value = PyString_AsString(result);
	return Value;
}

FString UPyUnrealLib::GetProjectScriptDir()
{
	return FPaths::ProjectDir() + "Scripts/PyScripts/";
}

#endif
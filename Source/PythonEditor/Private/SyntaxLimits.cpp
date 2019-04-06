//Copyright 2019, Jorge Calleros Ramirez (Karma), All rights reserved.

#include "SyntaxLimits.h"

FSyntaxLimits::FSyntaxLimits()
{
}

FSyntaxLimits::~FSyntaxLimits()
{
}

TArray<FString> FSyntaxLimits::Seperators;
TArray<FString> FSyntaxLimits::Keywords;
TArray<FString> FSyntaxLimits::Operators;
TArray<FString> FSyntaxLimits::PreProcessorKeywords;

TArray<FString>& FSyntaxLimits::GetSeparators()
{
	// this are python specific, maybe another language will need others
	if (Seperators.Num() < 1)
	{
		Seperators.Add("(");
		Seperators.Add(")");
		Seperators.Add(" ");
		Seperators.Add("=");
		Seperators.Add("\"");
		Seperators.Add(":");
		Seperators.Add("!");
		Seperators.Add("	");
		Seperators.Add(",");
		Seperators.Add("#");
		Seperators.Add("'");
		Seperators.Add("@");
		//Seperators.Add(".");
	}
	return Seperators;
}

bool FSyntaxLimits::ContainSeparator(const FString& InKey)
{
	return GetSeparators().Contains(InKey);
}

const TArray<FString>& FSyntaxLimits::GetPyKeywords()
{
	if (Keywords.Num() < 1)
	{
		Keywords.Add(TEXT("False"));
		Keywords.Add(TEXT("and"));
		Keywords.Add(TEXT("as"));
		Keywords.Add(TEXT("assert"));
		Keywords.Add(TEXT("break"));
		Keywords.Add(TEXT("True"));
		Keywords.Add(TEXT("class"));
		Keywords.Add(TEXT("del"));
		Keywords.Add(TEXT("elif"));
		Keywords.Add(TEXT("else"));
		Keywords.Add(TEXT("except"));
		Keywords.Add(TEXT("finally"));
		Keywords.Add(TEXT("if"));
		Keywords.Add(TEXT("import"));
		Keywords.Add(TEXT("in"));
		Keywords.Add(TEXT("or"));
		Keywords.Add(TEXT("not"));
		Keywords.Add(TEXT("is"));
		Keywords.Add(TEXT("for"));
		Keywords.Add(TEXT("print"));
		Keywords.Add(TEXT("pass"));
		Keywords.Add(TEXT("from"));
		Keywords.Add(TEXT("def"));
		Keywords.Add(TEXT("abs"));
		Keywords.Add(TEXT("all"));
		Keywords.Add(TEXT("help"));
		Keywords.Add(TEXT("any"));
		Keywords.Add(TEXT("ascii"));
		Keywords.Add(TEXT("bin"));
		Keywords.Add(TEXT("bool"));
		Keywords.Add(TEXT("bytearray"));
		Keywords.Add(TEXT("bytes"));
		Keywords.Add(TEXT("callable"));
		Keywords.Add(TEXT("chr"));
		Keywords.Add(TEXT("classmethod"));
		Keywords.Add(TEXT("cmp"));
		Keywords.Add(TEXT("compile"));
		Keywords.Add(TEXT("complex"));
		Keywords.Add(TEXT("delattr"));
		Keywords.Add(TEXT("dict"));
		Keywords.Add(TEXT("dir"));
		Keywords.Add(TEXT("divmod"));
		Keywords.Add(TEXT("enumerate"));
		Keywords.Add(TEXT("eval"));
		Keywords.Add(TEXT("execfile"));
		Keywords.Add(TEXT("file"));
		Keywords.Add(TEXT("filter"));
		Keywords.Add(TEXT("float"));
		Keywords.Add(TEXT("format"));
		Keywords.Add(TEXT("frozenset"));
		Keywords.Add(TEXT("getAttr"));
		Keywords.Add(TEXT("globals"));
		Keywords.Add(TEXT("hasattr"));
		Keywords.Add(TEXT("hash"));
		Keywords.Add(TEXT("hex"));
		Keywords.Add(TEXT("id"));
		Keywords.Add(TEXT("input"));
		Keywords.Add(TEXT("int"));
		Keywords.Add(TEXT("isinstance"));
		Keywords.Add(TEXT("issubclass"));
		Keywords.Add(TEXT("iter"));
		Keywords.Add(TEXT("len"));
		Keywords.Add(TEXT("list"));
		Keywords.Add(TEXT("locals"));
		Keywords.Add(TEXT("long"));
		Keywords.Add(TEXT("map"));
		Keywords.Add(TEXT("max"));
		Keywords.Add(TEXT("memoryview"));
		Keywords.Add(TEXT("min"));
		Keywords.Add(TEXT("next"));
		Keywords.Add(TEXT("object"));
		Keywords.Add(TEXT("oct"));
		Keywords.Add(TEXT("open"));
		Keywords.Add(TEXT("ord"));
		Keywords.Add(TEXT("pow"));
		Keywords.Add(TEXT("property"));
		Keywords.Add(TEXT("range"));
		Keywords.Add(TEXT("raw_input"));
		Keywords.Add(TEXT("reduce"));
		Keywords.Add(TEXT("reload"));
		Keywords.Add(TEXT("repr"));
		Keywords.Add(TEXT("reversed"));
		Keywords.Add(TEXT("round"));
		Keywords.Add(TEXT("set"));
		Keywords.Add(TEXT("setattr"));
		Keywords.Add(TEXT("slice"));
		Keywords.Add(TEXT("sorted"));
		Keywords.Add(TEXT("staticmethod"));
		Keywords.Add(TEXT("str"));
		Keywords.Add(TEXT("sum"));
		Keywords.Add(TEXT("super"));
		Keywords.Add(TEXT("tuple"));
		Keywords.Add(TEXT("type"));
		Keywords.Add(TEXT("unichr"));
		Keywords.Add(TEXT("unicode"));
		Keywords.Add(TEXT("vars"));
		Keywords.Add(TEXT("xrange"));
		Keywords.Add(TEXT("zip"));
		Keywords.Add(TEXT("try"));
		Keywords.Add(TEXT("None"));
	}
	return Keywords;
}

bool FSyntaxLimits::ContainKeyword(const FString& InKey)
{
	return GetPyKeywords().Contains(InKey);
}

const TArray<FString>& FSyntaxLimits::GetPyOperators()
{
	if (Operators.Num() < 1)
	{
		Operators.Add(TEXT("+"));
		Operators.Add(TEXT("-"));
		Operators.Add(TEXT("*"));
		Operators.Add(TEXT("/"));
		Operators.Add(TEXT("%"));
		Operators.Add(TEXT("**"));
		Operators.Add(TEXT("//"));
		Operators.Add(TEXT("=="));
		Operators.Add(TEXT("!="));
		Operators.Add(TEXT("<>"));
		Operators.Add(TEXT("<"));
		Operators.Add(TEXT(">"));
		Operators.Add(TEXT("<="));
		Operators.Add(TEXT(">="));
		Operators.Add(TEXT("="));
		Operators.Add(TEXT("+="));
		Operators.Add(TEXT("-="));
		Operators.Add(TEXT("*="));
		Operators.Add(TEXT("/="));
		Operators.Add(TEXT("%="));
		Operators.Add(TEXT("**="));
		Operators.Add(TEXT("//="));
		Operators.Add(TEXT("&"));
		Operators.Add(TEXT("|"));
		Operators.Add(TEXT("~"));
		Operators.Add(TEXT("^"));
		Operators.Add(TEXT("<<"));
		Operators.Add(TEXT(">>"));
	}
	return Operators;
}

bool FSyntaxLimits::ContainOperator(const FString& InKey)
{
	return GetPyOperators().Contains(InKey);
}

const TArray<FString>& FSyntaxLimits::GetPreprocessors()
{
	if (PreProcessorKeywords.Num() < 1)
	{
		PreProcessorKeywords.Add(TEXT("#include"));
		PreProcessorKeywords.Add(TEXT("#define"));
		PreProcessorKeywords.Add(TEXT("#ifndef"));
		PreProcessorKeywords.Add(TEXT("#ifdef"));
		PreProcessorKeywords.Add(TEXT("#if"));
		PreProcessorKeywords.Add(TEXT("#else"));
		PreProcessorKeywords.Add(TEXT("#endif"));
		PreProcessorKeywords.Add(TEXT("#pragma"));
		PreProcessorKeywords.Add(TEXT("#undef"));
	}
	return PreProcessorKeywords;
}

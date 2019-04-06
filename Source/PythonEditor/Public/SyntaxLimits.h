//Copyright 2019, Jorge Calleros Ramirez (Karma), All rights reserved.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class PYTHONEDITOR_API FSyntaxLimits
{
public:
	FSyntaxLimits();
	~FSyntaxLimits();

	static TArray<FString> Seperators;
	static TArray<FString>& GetSeparators();
	static bool ContainSeparator(const FString& InKey);

	static TArray<FString> Keywords;
	static const TArray<FString>& GetPyKeywords();
	static bool ContainKeyword(const FString& InKey);

	static TArray<FString> Operators;
	static const TArray<FString>& GetPyOperators();
	static bool ContainOperator(const FString& InKey);

	static TArray<FString> PreProcessorKeywords;
	static const TArray<FString>& GetPreprocessors();
};

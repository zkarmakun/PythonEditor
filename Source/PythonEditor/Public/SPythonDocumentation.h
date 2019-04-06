//Copyright 2019, Jorge Calleros Ramirez (Karma), All rights reserved.

#pragma once
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

class SWebBrowser;

/**
 * 
 */
class PYTHONEDITOR_API SPythonDocumentation : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SPythonDocumentation)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	void OpenDocLink(const FString& Link);

private:
	TSharedPtr<SWebBrowser> WebBrowser;
	const FString PyURLDocs = "https://api.unrealengine.com/INT/PythonAPI/";

};

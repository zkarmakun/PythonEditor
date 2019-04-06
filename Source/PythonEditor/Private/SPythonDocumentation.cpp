//Copyright 2019, Jorge Calleros Ramirez (Karma), All rights reserved.


#include "SPythonDocumentation.h"
#include "SlateOptMacros.h"
#include "SBoxPanel.h"
#include "WebBrowser/Public/SWebBrowser.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SPythonDocumentation::Construct(const FArguments& InArgs)
{
	ChildSlot
	[
		SAssignNew(WebBrowser, SWebBrowser)
		.InitialURL(PyURLDocs)
		.ShowControls(true)
		.SupportsTransparency(false)
	];



}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SPythonDocumentation::OpenDocLink(const FString& Link)
{
	WebBrowser->LoadURL(Link);
}


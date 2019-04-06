//Copyright 2019, Jorge Calleros Ramirez (Karma), All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "Widgets/Text/SMultiLineEditableText.h"
#include "PythonHighlightMarshaller.h"
#include "PythonEditorStyle.h"

/**
 *  This is rather a hack to have cool looking lines for a MultilineEditableText class
 *	this class can be sync with the scroll of another companion 
 */
class SCodeLinesText : public SMultiLineEditableText
{
public:
	SLATE_BEGIN_ARGS(SCodeLinesText)
		: _TextStyle(&FPythonEditorStyle::Get().GetWidgetStyle<FTextBlockStyle>("PythonEditor.TextStyle"))
	{}

	//~ Text Style Text, if you want to change this remember to have the same font size
	SLATE_STYLE_ARGUMENT(FTextBlockStyle, TextStyle)

	//~ Should auto wrap
	SLATE_ARGUMENT(bool, AutoWrapText)

	//~ Set Margin
	SLATE_ARGUMENT(FMargin, Margin)
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	//~ Sync scroll based in the scroll fraction that you can get from another SMultiLineEditableText
 	void SyncScroll(const float& ScrollFraction);

	//~ Sync the position that you can get from another SMultiLineEditableText
	void SyncScrollTo(const FTextLocation& InLocation);

private:

	/* Hold Text style*/
	const FTextBlockStyle* TextStyle;

};

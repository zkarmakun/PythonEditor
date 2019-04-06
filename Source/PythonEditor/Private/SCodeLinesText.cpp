//Copyright 2019, Jorge Calleros Ramirez (Karma), All rights reserved.

#include "SCodeLinesText.h"
#include "SlateOptMacros.h"
#include "SlateEditableTextLayout.h"


void SCodeLinesText::Construct(const FArguments& InArgs)
{
	TextStyle = InArgs._TextStyle;

	SMultiLineEditableText::Construct(
		SMultiLineEditableText::FArguments()
		.TextStyle(TextStyle)
		.Font(TextStyle->Font)
		.Text(FText::FromString("1\n2"))
		.Margin(0.0f)
		.AutoWrapText(InArgs._AutoWrapText)
		.Margin(InArgs._Margin)
		.IsReadOnly(true)
	);
}


void SCodeLinesText::SyncScroll(const float& ScrollFraction)
{
	EditableTextLayout->SetVerticalScrollFraction(ScrollFraction);
	EditableTextLayout->SetScrollOffset(EditableTextLayout->GetScrollOffset(), GetCachedGeometry());
}

void SCodeLinesText::SyncScrollTo(const FTextLocation& InLocation)
{
	EditableTextLayout->ScrollTo(InLocation);
}

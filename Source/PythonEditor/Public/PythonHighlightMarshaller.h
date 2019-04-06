//Copyright 2019, Jorge Calleros Ramirez (Karma), All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "PythonEditorStyle.h"
#include "Framework/Text/SyntaxTokenizer.h"
#include "Framework/Text/SyntaxHighlighterTextLayoutMarshaller.h"
#include "Framework/Text/TextLayout.h"


DECLARE_DELEGATE_OneParam(FOnLineNumberChanged, const int32&)
DECLARE_DELEGATE_ThreeParams(FOnLineModified, const FString& ,const int32&, const int32&);

/**
 * 
 */
class FPythonHighlightMarshaller : public FSyntaxHighlighterTextLayoutMarshaller
{
public:
	struct FSyntaxTextStyle
	{
		FSyntaxTextStyle()
			: NormalTextStyle(FPythonEditorStyle::Get().GetWidgetStyle<FTextBlockStyle>("SyntaxHighlight.Python.Normal"))
			, OperatorTextStyle(FPythonEditorStyle::Get().GetWidgetStyle<FTextBlockStyle>("SyntaxHighlight.Python.Operator"))
			, KeywordTextStyle(FPythonEditorStyle::Get().GetWidgetStyle<FTextBlockStyle>("SyntaxHighlight.Python.Keyword"))
			, StringTextStyle(FPythonEditorStyle::Get().GetWidgetStyle<FTextBlockStyle>("SyntaxHighlight.Python.String"))
			, NumberTextStyle(FPythonEditorStyle::Get().GetWidgetStyle<FTextBlockStyle>("SyntaxHighlight.Python.Number"))
			, CommentTextStyle(FPythonEditorStyle::Get().GetWidgetStyle<FTextBlockStyle>("SyntaxHighlight.Python.Comment"))
			, PreProcessorKeywordTextStyle(FPythonEditorStyle::Get().GetWidgetStyle<FTextBlockStyle>("SyntaxHighlight.Python.PreProcessorKeyword"))
		{
		}

		FTextBlockStyle NormalTextStyle;
		FTextBlockStyle OperatorTextStyle;
		FTextBlockStyle KeywordTextStyle;
		FTextBlockStyle StringTextStyle;
		FTextBlockStyle NumberTextStyle;
		FTextBlockStyle CommentTextStyle;
		FTextBlockStyle PreProcessorKeywordTextStyle;

	};

	static TSharedRef< FPythonHighlightMarshaller > Create(const FSyntaxTextStyle& InSyntaxTextStyle);

	virtual ~FPythonHighlightMarshaller();



protected:

	virtual void ParseTokens(const FString& SourceString, FTextLayout& TargetTextLayout, TArray<FSyntaxTokenizer::FTokenizedLine> TokenizedLines) override;
	virtual void OnLineModified(const FString& line, const int32& LineIndex, const int32& Offset, const FSyntaxTokenizer::FTokenizedLine& TokenLine);

	FPythonHighlightMarshaller(TSharedPtr< FSyntaxTokenizer > InTokenizer, const FSyntaxTextStyle& InSyntaxTextStyle);

	/** Styles used to display the text */
	FSyntaxTextStyle SyntaxTextStyle;

	/** String representing tabs */
	FString TabString;

	//~ Holds the maximum line number
	int32 LineNumber;

	//~ Delegates to trigger every time the maximum line numbers changes
	FOnLineNumberChanged OnLineNumberChanged;

	//~ Call every time a line is modified
	FOnLineModified OnLineModifiedCall;

	//~ Holds copy of the hold code, maybe not a good idea
	FString CodeString;

	//~ Holds the code as tokenized lines
	TArray<FSyntaxTokenizer::FTokenizedLine> Tokens;


public:

	//~ Set delegate to call every time the maximum line number changes
	void SetOnLineNumberChanged(FOnLineNumberChanged InOnLineNumberChanged);

	//~ Set delegate to call every time a lines was modified
	void SetOnLineModified(FOnLineModified InOnLineModified);

	//~ getter line number
	int32 GetLineNumber() const;

	//~ getter Get Tokenized lines
	TArray<FSyntaxTokenizer::FTokenizedLine> GetLines() const;

	//~ Get Line by index, not crash, it will return empty if fails
	FString GetLine(const FTextLocation& TextLocation, bool bUseTextLocationOffset = false);

	//~ Get line range by index, not crash, it will return empty if fails
	FTextRange GetLineRange(const int32& Index);
};

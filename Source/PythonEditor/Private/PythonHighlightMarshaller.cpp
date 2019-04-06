//Copyright 2019, Jorge Calleros Ramirez (Karma), All rights reserved.

#include "PythonHighlightMarshaller.h"
#include "Framework/Text/IRun.h"
#include "Framework/Text/TextLayout.h"
#include "Framework/Text/ISlateRun.h"
#include "Framework/Text/SlateTextRun.h"
#include "SyntaxLimits.h"
#include "TabSlateRun.h"



TSharedRef< FPythonHighlightMarshaller > FPythonHighlightMarshaller::Create(const FSyntaxTextStyle& InSyntaxTextStyle)
{
	TArray<FSyntaxTokenizer::FRule> TokenizerRules;

	// operators
	for (const auto& Operator : FSyntaxLimits::GetPyOperators())
	{
		TokenizerRules.Emplace(FSyntaxTokenizer::FRule(Operator));
	}

	// keywords
	for (const auto& Keyword : FSyntaxLimits::GetPyKeywords())
	{
		TokenizerRules.Emplace(FSyntaxTokenizer::FRule(Keyword));
	}

	// Pre-processor Keywords
	for (const auto& PreProcessorKeyword : FSyntaxLimits::GetPreprocessors())
	{
		TokenizerRules.Emplace(FSyntaxTokenizer::FRule(PreProcessorKeyword));
	}

	return MakeShareable(new FPythonHighlightMarshaller(FSyntaxTokenizer::Create(TokenizerRules), InSyntaxTextStyle));
}


FPythonHighlightMarshaller::~FPythonHighlightMarshaller()
{

}

void FPythonHighlightMarshaller::ParseTokens(const FString& SourceString, FTextLayout& TargetTextLayout, TArray<FSyntaxTokenizer::FTokenizedLine> TokenizedLines)
{
	CodeString = SourceString;

	enum class EParseState : uint8
	{
		None,
		String,
		Keyword,
		Comment,
		Numeric,
		Symbol,
		MultiLineComment,
	};


	TArray<FTextLayout::FNewLineData> LinesToAdd;
	LinesToAdd.Reserve(TokenizedLines.Num());

	int32 linesCount = 0;
	// Parse the tokens, generating the styled runs for each line
	EParseState ParseState = EParseState::None;
	int32 Status = 0;
	for (int32 i = 0; i < TokenizedLines.Num(); i++)
	{
		TSharedRef<FString> ModelString = MakeShareable(new FString());
		TArray< TSharedRef< IRun > > Runs;

		if (ParseState != EParseState::MultiLineComment)
		{
			ParseState = EParseState::None;
			Status = 0;
		}

		if (Tokens.IsValidIndex(i))
		{
			if (Tokens[i].Range.Len() != TokenizedLines[i].Range.Len())
			{
				const FString& Line = SourceString.Mid(TokenizedLines[i].Range.BeginIndex, TokenizedLines[i].Range.Len());
				OnLineModified(Line, i, TokenizedLines[i].Range.Len(), TokenizedLines[i]);
			}
		}


		for (int32 x = 0; x < TokenizedLines[i].Tokens.Num(); x++)
		{

			const FString TokenText = SourceString.Mid(TokenizedLines[i].Tokens[x].Range.BeginIndex, TokenizedLines[i].Tokens[x].Range.Len());
			const FTextRange ModelRange(ModelString->Len(), ModelString->Len() + TokenText.Len());
			ModelString->Append(TokenText);
			const bool bIsWhitespace = FString(TokenText).TrimEnd().IsEmpty();

			FRunInfo RunInfo(TEXT("SyntaxHighlight.Python.Normal"));
			FTextBlockStyle TextBlockStyle = SyntaxTextStyle.NormalTextStyle;

			if (!bIsWhitespace)
			{
				if (TokenText.Contains("'") || ParseState == EParseState::MultiLineComment)
				{
					if (TokenizedLines[i].Tokens.IsValidIndex(x + 1) && TokenizedLines[i].Tokens.IsValidIndex(x + 2))
					{
						const FString NextToken = SourceString.Mid(TokenizedLines[i].Tokens[x + 1].Range.BeginIndex, TokenizedLines[i].Tokens[x + 1].Range.Len());
						const FString NextToken2 = SourceString.Mid(TokenizedLines[i].Tokens[x + 2].Range.BeginIndex, TokenizedLines[i].Tokens[x + 2].Range.Len());
						if (NextToken.Contains("'") && NextToken2.Contains("'"))
						{
							ParseState = EParseState::MultiLineComment;
							Status += 1;
						}
					}
				}
				else if (TokenText == TEXT("#") || ParseState == EParseState::Comment)
				{
					ParseState = EParseState::Comment;
				}
				else if (TokenText.Contains("\"") || ParseState == EParseState::String)
				{
					ParseState = EParseState::String;
					if (TokenText.Contains("\""))
						Status += 1;
				}
				else if (TokenText.IsNumeric() && ParseState == EParseState::None)
				{
					ParseState = EParseState::Numeric;
				}
				else if (FSyntaxLimits::ContainSeparator(TokenText) && ParseState == EParseState::None)
				{
					ParseState = EParseState::Symbol;
				}
				else if (!bIsWhitespace && ParseState == EParseState::None && TChar<WIDECHAR>::IsAlpha(TokenText[0]) && TokenizedLines[i].Tokens[x].Type == FSyntaxTokenizer::ETokenType::Syntax)
				{
					ParseState = EParseState::Keyword;
				}

				switch (ParseState)
				{
				case EParseState::String:
					RunInfo.Name = TEXT("SyntaxHighlight.Python.String");
					TextBlockStyle = SyntaxTextStyle.StringTextStyle;
					if (Status == 2)
					{
						Status = 0;
						ParseState = EParseState::None;
					}
					break;
				case EParseState::Comment:
					RunInfo.Name = TEXT("SyntaxHighlight.Python.Comment");
					TextBlockStyle = SyntaxTextStyle.CommentTextStyle;
					break;
				case EParseState::MultiLineComment:
					RunInfo.Name = TEXT("SyntaxHighlight.Python.Comment");
					TextBlockStyle = SyntaxTextStyle.CommentTextStyle;
					if (Status == 2 && TokenizedLines[i].Tokens.IsValidIndex(x - 1) && TokenizedLines[i].Tokens.IsValidIndex(x - 2))
					{
						const FString NextToken = SourceString.Mid(TokenizedLines[i].Tokens[x - 1].Range.BeginIndex, TokenizedLines[i].Tokens[x - 1].Range.Len());
						const FString NextToken2 = SourceString.Mid(TokenizedLines[i].Tokens[x - 2].Range.BeginIndex, TokenizedLines[i].Tokens[x - 2].Range.Len());
						if (NextToken.Contains("'") && NextToken2.Contains("'"))
						{
							Status = 0;
							ParseState = EParseState::None;
						}
					}
					break;
				case EParseState::Keyword:
					RunInfo.Name = TEXT("SyntaxHighlight.Python.Keyword");
					TextBlockStyle = SyntaxTextStyle.KeywordTextStyle;
					ParseState = EParseState::None;
					break;
				case EParseState::Numeric:
					RunInfo.Name = TEXT("SyntaxHighlight.Python.Number");
					TextBlockStyle = SyntaxTextStyle.NumberTextStyle;
					ParseState = EParseState::None;
					break;
				case EParseState::Symbol:
					RunInfo.Name = TEXT("SyntaxHighlight.Python.Operator");
					TextBlockStyle = SyntaxTextStyle.OperatorTextStyle;
					ParseState = EParseState::None;
					break;
				default:
					break;
				}


				TSharedRef< ISlateRun > Run = FSlateTextRun::Create(RunInfo, ModelString, TextBlockStyle, ModelRange);
				Runs.Add(Run);
			}
			else
			{
				RunInfo.Name = TEXT("SyntaxHighlight.Python.WhiteSpace");
				TSharedRef< ISlateRun > Run = FTabTextRun::Create(RunInfo, ModelString, TextBlockStyle, ModelRange, 4);
				Runs.Add(Run);
			}
			
		}

		LinesToAdd.Emplace(MoveTemp(ModelString), MoveTemp(Runs));
		linesCount++;
	}

	TargetTextLayout.AddLines(LinesToAdd);

	Tokens = TokenizedLines;

	// Call OnLine number changed
	if (LineNumber != TokenizedLines.Num())
	{
		LineNumber = TokenizedLines.Num();
		OnLineNumberChanged.ExecuteIfBound(LineNumber);
	}
}

void FPythonHighlightMarshaller::OnLineModified(const FString& line, const int32& LineIndex, const int32& Offset, const FSyntaxTokenizer::FTokenizedLine& TokenLine)
{
	OnLineModifiedCall.ExecuteIfBound(line, LineIndex, Offset);
}

void FPythonHighlightMarshaller::SetOnLineNumberChanged(FOnLineNumberChanged InOnLineNumberChanged)
{
	OnLineNumberChanged = InOnLineNumberChanged;
}

void FPythonHighlightMarshaller::SetOnLineModified(FOnLineModified InOnLineModified)
{
	OnLineModifiedCall = InOnLineModified;
}

int32 FPythonHighlightMarshaller::GetLineNumber() const
{
	return LineNumber;
}

TArray<FSyntaxTokenizer::FTokenizedLine> FPythonHighlightMarshaller::GetLines() const
{
	return Tokens;
}

FString FPythonHighlightMarshaller::GetLine(const FTextLocation& TextLocation, bool bUseTextLocationOffset /*= false*/)
{
	const int32 Index = TextLocation.GetLineIndex();
	if (Tokens.IsValidIndex(Index))
	{
		int32 MaxRange = (bUseTextLocationOffset) ? TextLocation.GetOffset() : Tokens[Index].Range.Len();

		const FString& Line = CodeString.Mid(Tokens[Index].Range.BeginIndex, MaxRange);
		return Line;
	}
	return FString();
}

FTextRange FPythonHighlightMarshaller::GetLineRange(const int32& Index)
{
	if (Tokens.IsValidIndex(Index))
	{
		return Tokens[Index].Range;
	}
	return FTextRange();
}

FPythonHighlightMarshaller::FPythonHighlightMarshaller(TSharedPtr< FSyntaxTokenizer > InTokenizer, const FSyntaxTextStyle& InSyntaxTextStyle)
	: FSyntaxHighlighterTextLayoutMarshaller(MoveTemp(InTokenizer))
	, SyntaxTextStyle(InSyntaxTextStyle)
{

}

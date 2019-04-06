//Copyright 2019, Jorge Calleros Ramirez (Karma), All rights reserved.

#include "SCodeMultilineText.h"
#include "Widgets/SBoxPanel.h"
#include "PythonEditorStyle.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/Layout/SBox.h"
#include "Misc/FileHelper.h"
#include "Widgets/Input/SEditableTextBox.h"
#include "Framework/Application/SlateApplication.h"
#include "Editor.h"
#include "Widgets/Text/SlateEditableTextLayout.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "Widgets/Text/ISlateEditableTextWidget.h"
#include "PythonHighlightMarshaller.h"
#include "Framework/Text/ILayoutBlock.h"
#include "Framework/Text/SyntaxTokenizer.h"
#include "Runtime/Engine/Classes/Engine/UserInterfaceSettings.h"
#include "SyntaxLimits.h"
#include "AutoCompleteWorker.h"
#include "SCodeLinesText.h"
#include "Kismet/KismetStringLibrary.h"
#include "PythonEditorToolkit.h"


void SCodeMultilineText::Construct(const FArguments& InArgs)
{
	OnCodeDirty = InArgs._OnCodeDirty;
	AutoCompleteWorker = InArgs._AutoCompleteWorker;
	ensure(AutoCompleteWorker);

	FilePath = InArgs._FileName;
	TextStyle = InArgs._TextStyle;

	HScroller = InArgs._HScrollBar;
	VScroller = InArgs._VScrollBar;
	Marshaller = InArgs._Marshaller;
	ensure(Marshaller);

	FOnLineModified OnLineChangedDel = FOnLineModified::CreateRaw(this, &SCodeMultilineText::OnLineChanged);


	Marshaller->SetOnLineModified(OnLineChangedDel);
	Marshaller->SetOnLineNumberChanged(FOnLineNumberChanged::CreateRaw(this, &SCodeMultilineText::OnLineNumberChanged));


	SMultiLineEditableText::Construct(
		SMultiLineEditableText::FArguments()
		.TextStyle(TextStyle)
		.Font(TextStyle->Font)
		.Text(InArgs._Text)
		.Marshaller(Marshaller)
		.Margin(0.0f)
		.HScrollBar(HScroller)
		.VScrollBar(VScroller)
		.OnTextChanged(InArgs._OnTextChanged)
		.AutoWrapText(InArgs._AutoWrapText)
		.Margin(InArgs._Margin)
		.IsReadOnly(InArgs._IsReadOnly)
		.OnVScrollBarUserScrolled(FOnUserScrolled::CreateRaw(this, &SCodeMultilineText::OnUserVScroll))
		.ContextMenuExtender(this, &SCodeMultilineText::ExtentRightClickMenu)
		.OnCursorMoved(this, &SCodeMultilineText::OnCursorMoved)
	);

	LinePercent = 1.1f;

	FontMeasureService = FSlateApplication::Get().GetRenderer()->GetFontMeasureService();
	LineHeight = FontMeasureService->Measure("Hello", TextStyle->Font).Y * LinePercent;

	InitialDrawIndex = 0;
	SugestionBoxSelection = 0;

	AutoCompleteHandle = AutoCompleteWorker->OnAutoCompleteDone.AddRaw(this, &SCodeMultilineText::OnAutoCompleteDone);

	SetLineHeightPercentage(LinePercent);
	ComputeDrawRange();
}

SCodeMultilineText::~SCodeMultilineText()
{
	//To Do, this is not cleaning. check how to destroy the memory
	UE_LOG(LogTemp, Log, TEXT("c'est fini"));
	if (AutoCompleteWorker)
	{
		 AutoCompleteWorker->OnAutoCompleteDone.Remove(AutoCompleteHandle);
	}
}

void SCodeMultilineText::SetCodeLines(TSharedPtr < SCodeLinesText > CodeLineText)
{
	Lines = CodeLineText;
	Lines->SetLineHeightPercentage(LinePercent);
	OnLineNumberChanged(Marshaller->GetLineNumber());
}

void SCodeMultilineText::OnUserVScroll(float Offset)
{
	if (VScroller->DistanceFromBottom() != 0 && VScroller->DistanceFromTop() != 0 && VerticalScrollOffset != Offset)
	{
		VerticalScrollOffset = Offset;
	}

	Lines->SyncScroll(VerticalScrollOffset);
	ComputeDrawRange();
}

int32 SCodeMultilineText::OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const
{
	const ESlateDrawEffect DrawEffects = ESlateDrawEffect::None;
	const float AllotedWidth = AllottedGeometry.GetLocalSize().X;
	const float AllotedHeight = AllottedGeometry.GetLocalSize().Y;

	LayerId = SMultiLineEditableText::OnPaint(Args, AllottedGeometry, MyCullingRect, OutDrawElements, LayerId, InWidgetStyle, bParentEnabled);
	LayerId++;
	if (VScroller.IsValid())
	{
		//Draw Selected line
		FSlateDrawElement::MakeBox(
			OutDrawElements,
			LayerId,
			AllottedGeometry.ToPaintGeometry(FVector2D(0, (TextLocation.GetLineIndex() * LineHeight) - EditableTextLayout->GetScrollOffset().Y), FVector2D(AllotedWidth, LineHeight)),
			FPythonEditorStyle::Get().GetBrush("PythonEditor.LineSelected"),
			DrawEffects,
			FLinearColor(.5f, .5f, .5f, .5f)
		);
		LayerId++;

		if (Suggestions.Num() > 0)
		{

			FVector2D SuggetionsBoxPosition = GetSuggestionBoxPosition();

			const FVector2D BoxSize = GetSuggestionBoxSize();

			//Draw container;
			FSlateDrawElement::MakeBox(
				OutDrawElements,
				LayerId,
				AllottedGeometry.ToPaintGeometry(SuggetionsBoxPosition, BoxSize),
				FPythonEditorStyle::Get().GetBrush("PythonEditor.SuggestionBG"),
				DrawEffects,
				FLinearColor::White
			);

			//Draw suggestions
			for (int32 i = InitialDrawIndex; i < InitialDrawIndex + MAX_SUGGESTION_DRAW; i++)
			{
				if (Suggestions.IsValidIndex(i))
				{
					const float LineFraction = LineHeight / 1.5f;
					FVector2D TextSuggestionPosition = SuggetionsBoxPosition;
					TextSuggestionPosition.Y += LineHeight * (i - InitialDrawIndex);

					FVector2D Position = FVector2D(TextSuggestionPosition.X + (LineFraction /4), TextSuggestionPosition.Y + (LineFraction/4));

					FSlateDrawElement::MakeBox(
						OutDrawElements,
						LayerId,
						AllottedGeometry.ToPaintGeometry(Position, FVector2D(LineFraction, LineFraction)),
						GetSuggestionIcon(Suggestions[i]),
						DrawEffects,
						FLinearColor::White
					);

					TextSuggestionPosition.X += (LineHeight*1.5f);
					FSlateDrawElement::MakeText(
						OutDrawElements,
						LayerId,
						AllottedGeometry.ToPaintGeometry(TextSuggestionPosition, FVector2D(BoxSize.X, LineHeight)),
						Suggestions[i].Suggestion,
						TextStyle->Font,
						DrawEffects,
						FLinearColor::White);
				}
			}

			SuggetionsBoxPosition.Y += LineHeight * SugestionBoxSelection;
			//Draw sugestionSelection
			FSlateDrawElement::MakeBox(
				OutDrawElements,
				LayerId,
				AllottedGeometry.ToPaintGeometry(SuggetionsBoxPosition, FVector2D(BoxSize.X, LineHeight)),
				FPythonEditorStyle::Get().GetBrush("PythonEditor.Solid"),
				DrawEffects,
				FLinearColor(1, 1, 1, .5f)
			);
		}




		//Draw help
		
		if (!Help.IsEmpty())
		{
			FVector2D FontSize = FontMeasureService->Measure(Help, TextStyle->Font);

			FontSize.X *= 1.2f;

			//Draw container;
			FSlateDrawElement::MakeBox(
				OutDrawElements,
				LayerId,
				AllottedGeometry.ToPaintGeometry(FVector2D(HelpLineOffset, ((TextLocation.GetLineIndex() * LineHeight) - EditableTextLayout->GetScrollOffset().Y) + LineHeight), FontSize),
				FPythonEditorStyle::Get().GetBrush("PythonEditor.SuggestionBG"),
				DrawEffects,
				FLinearColor::White
			);

			//~ Draw text help
			FSlateDrawElement::MakeText(
				OutDrawElements,
				LayerId,
				AllottedGeometry.ToPaintGeometry(FVector2D(HelpLineOffset + 5, ((TextLocation.GetLineIndex() * LineHeight) - EditableTextLayout->GetScrollOffset().Y) + LineHeight), FontSize),
				Help,
				TextStyle->Font,
				DrawEffects,
				FLinearColor::White);
		}
	}

	
	return LayerId;
}

FReply SCodeMultilineText::OnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent)
{
	//~ Run file when ctrl + enter
	if (!HasSuggestion() && InKeyEvent.IsControlDown() && InKeyEvent.GetKey() == EKeys::Enter)
	{
		RunFile();
		return FReply::Handled();
	}

	//~ Add indented line if we press enter while we are at the end of class || method || statement
	if (!HasSuggestion() && InKeyEvent.GetKey() == EKeys::Enter)
	{
		AddIndentedLine();
		return FReply::Handled();
	}

	//~ Add Tab, rememba this was hard to do somehow answer lies in the Marshaller
	if (!HasSuggestion() && InKeyEvent.GetKey() == EKeys::Tab)
	{
		FString String;
		String.AppendChar(TEXT('\t'));
		InsertTextAtCursor(String);
		return FReply::Handled();
	}

	//~ Save file when ctrl + s
	if (InKeyEvent.IsControlDown() && InKeyEvent.GetKey() == EKeys::S)
	{
		SaveFile();
		return FReply::Handled();
	}

	//~ Choose a suggestion and complete the word when press enter
	if (HasSuggestion() && InKeyEvent.GetKey() == EKeys::Enter)
	{
		CompleteWord();
		return FReply::Handled();
	}

	//~ Loop up the suggestion selection
	if (HasSuggestion() && InKeyEvent.GetKey() == EKeys::Up)
	{
		SugestionBoxSelection -= 1;

		if (SugestionBoxSelection < 0)
		{
			InitialDrawIndex = FMath::Clamp(InitialDrawIndex - 1, 0, Suggestions.Num() -1);
		}

		SugestionBoxSelection = FMath::Clamp(SugestionBoxSelection, 0, FMath::Min<int32>(Suggestions.Num() - 1, MAX_SUGGESTION_DRAW));
		return FReply::Handled();
	}

	//~ Loop down the suggestion selection
	if (HasSuggestion() && InKeyEvent.GetKey() == EKeys::Down)
	{
		SugestionBoxSelection += 1;

		if (SugestionBoxSelection >  MAX_SUGGESTION_DRAW -1)
		{
			InitialDrawIndex = FMath::Clamp(InitialDrawIndex + 1, 0, (Suggestions.Num() - 1) - MAX_SUGGESTION_DRAW);
		}

		SugestionBoxSelection = FMath::Clamp(SugestionBoxSelection, 0, FMath::Min<int32>(Suggestions.Num() - 1, MAX_SUGGESTION_DRAW -1));
		return FReply::Handled();
	}

	
	//~ if nothings we pass the key to the SMUltilineEditableText super method
	return SMultiLineEditableText::OnKeyDown(MyGeometry, InKeyEvent);
}

FReply SCodeMultilineText::OnKeyChar(const FGeometry& MyGeometry, const FCharacterEvent& InCharacterEvent)
{
	const TCHAR Character = InCharacterEvent.GetCharacter();

	if (Character == TEXT('('))
	{
		FString Parentheses = TEXT("()");
		InsertTextAtCursor(Parentheses);
		FTextLocation LessParentheses(TextLocation.GetLineIndex(), TextLocation.GetOffset() - 1);
		GoTo(LessParentheses);
		return FReply::Handled();
	}

	if (Character == TEXT('\"'))
	{
		FString Parentheses = TEXT("\"\"");
		InsertTextAtCursor(Parentheses);
		FTextLocation LessQuote(TextLocation.GetLineIndex(), TextLocation.GetOffset() - 1);
		GoTo(LessQuote);
		return FReply::Handled();
	}

	return SMultiLineEditableText::OnKeyChar(MyGeometry, InCharacterEvent);
}

FReply SCodeMultilineText::OnMouseWheel(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (HasSuggestion() && Suggestions.Num() > MAX_SUGGESTION_DRAW)
	{
		if (MouseEvent.GetWheelDelta() > 0)
		{
			InitialDrawIndex = FMath::Clamp(InitialDrawIndex - 1, 0, Suggestions.Num() - MAX_SUGGESTION_DRAW);
		}
		else
		{
			InitialDrawIndex = FMath::Clamp(InitialDrawIndex + 1, 0, Suggestions.Num() - MAX_SUGGESTION_DRAW);
		}
		return FReply::Handled();
	}

	if (!HasSuggestion())
	{
		const float WheelDelta = MouseEvent.GetWheelDelta() * .1f;

		if (WheelDelta < 0 && VScroller->DistanceFromBottom() != 0)
		{
			VerticalScrollOffset += FMath::Clamp(-WheelDelta, 0.f, 1.f);
		}
		else if (WheelDelta > 0 && VScroller->DistanceFromTop() != 0)
		{
			VerticalScrollOffset -= FMath::Clamp(WheelDelta, 0.f, 1.f);
		}

		
		EditableTextLayout->SetVerticalScrollFraction(VerticalScrollOffset);
		EditableTextLayout->SetScrollOffset(EditableTextLayout->GetScrollOffset(), GetCachedGeometry());
		Lines->SyncScroll(VerticalScrollOffset);
		ComputeDrawRange();
		return FReply::Handled();
	}

	return FReply::Handled();
//	return (HasSuggestion())? FReply::Handled() : SMultiLineEditableText::OnMouseWheel(MyGeometry, MouseEvent);
}

FReply SCodeMultilineText::OnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (HasSuggestion())
	{
		FVector2D CurrentPosition = MyGeometry.AbsoluteToLocal(MouseEvent.GetScreenSpacePosition());
		if (CurrentPosition != MousePosition)
		{
			MousePosition = CurrentPosition;
			int32 CurrentSuggestion = GetSuggestionBasedOnMouse(MousePosition);

			// A valid thing
			if (CurrentSuggestion >= 0) 
			{
				SugestionBoxSelection = CurrentSuggestion;
			}
		}
	}
	return SMultiLineEditableText::OnMouseMove(MyGeometry, MouseEvent);
}

FReply SCodeMultilineText::OnFocusReceived(const FGeometry& MyGeometry, const FFocusEvent& InFocusEvent)
{
	ClearSuggestions();
	return SMultiLineEditableText::OnFocusReceived(MyGeometry, InFocusEvent);
}

FReply SCodeMultilineText::OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (HasSuggestion() && IsMouseInsideSuggestionBox())
	{
		CompleteWord();
		return FReply::Handled();
	}
	else if(HasSuggestion() && !IsMouseInsideSuggestionBox())
	{
		ClearSuggestions();
		return FReply::Handled();
	}
	return SMultiLineEditableText::OnMouseButtonDown( MyGeometry, MouseEvent);
}

void SCodeMultilineText::OnLineNumberChanged(const int32& LineNumber)
{
	if (!Lines.IsValid()) return;

	FString TextLines;
	for (int32 i = 1; i < LineNumber + 1; i++)
	{
		TextLines += FString::FromInt(i) + "\n";
	}

	TextLines.RemoveAt(TextLines.Len());
	Lines->SetText(FText::FromString(TextLines));
}

FVector2D SCodeMultilineText::GetSuggestionBoxSize() const
{
	return SuggestionBoxSize;
}


FVector2D SCodeMultilineText::GetSuggestionBoxPosition() const
{
	return SuggestionBoxPosition;
}

void SCodeMultilineText::OnCursorMoved(const FTextLocation& InLocation)
{
	//this fixes the DPI scale, otherwise will look wrong in 4k screens
	const float DPIScale = FSlateApplication::Get().FindWidgetWindow(this->AsShared())->GetNativeWindow()->GetDPIScaleFactor();

	TextLocation = InLocation;

	int32 LineParenthesisOffset = 0;
	FString Line = Marshaller->GetLine(TextLocation);
	FString Trimmed = GetMethodOverCursor(Line, TextLocation, LineParenthesisOffset);
	HelpLineOffset = FontMeasureService->Measure(Line, 0, LineParenthesisOffset, TextStyle->Font).X;


	if (!Trimmed.IsEmpty())
	{
		Help = UPyUnrealLib::GetHelp(Trimmed, FilePath, bActivePythonEditor);
	}
	else
	{
		Help = "";
	}
	
	if (Lines.IsValid())
	{
		Lines->SyncScrollTo(TextLocation);
		ComputeDrawRange();
	}


	FTextRange Range = Marshaller->GetLineRange(TextLocation.GetLineIndex());
	FVector2D OutPosition;
	FVector2D OutSize;
	EditableTextLayout->GetTextInputMethodContext()->GetTextBounds(Range.BeginIndex, TextLocation.GetOffset(), OutPosition, OutSize);

	
	SuggestionBoxPosition = FVector2D(OutSize.X, ((TextLocation.GetLineIndex() * LineHeight) - EditableTextLayout->GetScrollOffset().Y) + LineHeight);
	SuggestionBoxPosition.X /= DPIScale;
}

void SCodeMultilineText::OnLineChanged(const FString& Line, const int32& LineIndex, const int32& Offset)
{
	ComputeDrawRange();

	bDirty = true;
	OnCodeDirty.ExecuteIfBound(bDirty);

	if (bSuggestionTaken)
	{
		bSuggestionTaken = false;
		return;
	}

	FString TrimmedText = "";
	for (int32 i = TextLocation.GetOffset() - 1; i >= 0; i--)
	{
		if (!Line.IsValidIndex(i)) continue;

		FString something;
		something += Line[i];
		if (FSyntaxLimits::ContainSeparator(something)) break;

		TrimmedText.InsertAt(0, Line[i]);
	}

	if (!TrimmedText.IsEmpty())
	{
		AutoCompleteWorker->AddAutoCompleteToQueue(TrimmedText, FilePath);
		return;
	}
	ClearSuggestions();
}


bool SCodeMultilineText::HasSuggestion() const
{
	return Suggestions.Num() > 0;
}


void SCodeMultilineText::ReloadModule()
{
	FString Module = FPaths::GetBaseFilename(FilePath);
	UPyUnrealLib::ReloadModule(Module);
}

void SCodeMultilineText::OnAutoCompleteDone(TArray<FSuggestion> NewSuggestions, FString Requester)
{
	if (Requester == FilePath)
	{
		Suggestions = NewSuggestions;

		InitialDrawIndex = 0;
		SugestionBoxSelection = 0;

		//Calculate box size when we received new suggestions
		SuggestionBoxSize = FVector2D::ZeroVector;
		SuggestionBoxSize.Y = FMath::Clamp(Suggestions.Num() * LineHeight, 0.f , LineHeight * MAX_SUGGESTION_DRAW);
		for (auto& Suggestion : Suggestions)
		{
			const float width = FontMeasureService->Measure(Suggestion.Suggestion, TextStyle->Font).X + SUGGESTION_BOX_SCALE;
			if (width > SuggestionBoxSize.X)
			{
				SuggestionBoxSize.X = width;
			}
		}
	}
}

int32 SCodeMultilineText::GetSelectionWithOffset()
{
	return SugestionBoxSelection + InitialDrawIndex;
}

void SCodeMultilineText::CompleteWord()
{
	int32 SelectedIndexInBox = GetSelectionWithOffset();
	if (Suggestions.IsValidIndex(SelectedIndexInBox))
	{
		bSuggestionTaken = true;
		InsertTextAtCursor(Suggestions[SelectedIndexInBox].WordCompletiton);
		AutoCompleteWorker->AddFavoriteSearch(Suggestions[SelectedIndexInBox].Suggestion);
		ClearSuggestions();
	}
}

void SCodeMultilineText::AddIndentedLine()
{
	const TCHAR Tab = TEXT('\t');
	FString Line = Marshaller->GetLine(TextLocation);
	// count tabs
	FString NextStart = "\n";
	int32 TabCount = 0;
	for (int32 Index = 0; Index < Line.Len(); Index++)
	{
		if (Line[Index] == Tab)
		{
			NextStart += Tab;
			TabCount++;
		}
	}

	if (Line.EndsWith(":"))
	{
		NextStart += Tab;
	}
	InsertTextAtCursor(NextStart);
	ClearSelection();
	ClearSuggestions();
}

void SCodeMultilineText::ClearSuggestions()
{
	Suggestions.Empty();
	SugestionBoxSelection = 0;
	InitialDrawIndex = 0;
}

int32 SCodeMultilineText::GetSuggestionBasedOnMouse(const FVector2D& InMousePosition)
{
	FVector2D Max (GetSuggestionBoxPosition().X + GetSuggestionBoxSize().X, GetSuggestionBoxPosition().Y + GetSuggestionBoxSize().Y);
	FBox2D Box(GetSuggestionBoxPosition(), Max);

	if (Box.IsInside(InMousePosition))
	{
		bIsMouseInsideSuggetions = true;
		for (int32 i = Suggestions.Num()-1; i >= 0; i--)
		{
			const float Y = GetSuggestionBoxPosition().Y + (LineHeight * i);
			if (InMousePosition.Y > Y)
			{
				return i;
			}
		}
	}
	bIsMouseInsideSuggetions = false;
	return -1;
}

bool SCodeMultilineText::IsMouseInsideSuggestionBox() const
{
	return bIsMouseInsideSuggetions;
}

const FSlateBrush* SCodeMultilineText::GetSuggestionIcon(const FSuggestion& InSuggestion) const
{
	switch (InSuggestion.Type)
	{
	case EPyAttrType::Module:
		return FPythonEditorStyle::Get().GetBrush("PythonEditor.Method");
	case EPyAttrType::Class:
		return FPythonEditorStyle::Get().GetBrush("PythonEditor.Class");
	case EPyAttrType::Enum:
		return FPythonEditorStyle::Get().GetBrush("PythonEditor.Variable");
	}
	return FPythonEditorStyle::Get().GetBrush("PythonEditor.Keyword");
}

void SCodeMultilineText::SaveFile()
{

	FString TextAsString = GetText().ToString();

	//did you removed the file while editing?
	check(FPaths::FileExists(FilePath));

	//Save file
	const bool Result = FFileHelper::SaveStringToFile(*TextAsString, *FilePath);
	if (Result)
	{
		UE_LOG(LogTemp, Log, TEXT("Save: %s"), *FilePath);
		bDirty = false;
		OnCodeDirty.ExecuteIfBound(bDirty);
	}
}

void SCodeMultilineText::RunFile()
{
	ensure(FPaths::FileExists(FilePath));
	const FString Cmd = "py \"" + FilePath + "\"";
	GEngine->Exec(GEngine->GetWorld(), *Cmd);
}

bool SCodeMultilineText::IsFileDirty() const
{
	return bDirty;
}

void SCodeMultilineText::SetActivePythonScript(bool Status)
{
	bActivePythonEditor = Status;
}

void SCodeMultilineText::ComputeDrawRange()
{
	//~ Compute draw lines
	const int32 TotalLines = Marshaller->GetLineNumber();
	const float WidgetHeight = GetCachedGeometry().Size.Y;
	float PixelsOffset = (TotalLines * LineHeight) * VScroller->DistanceFromTop();


	DrawLines.X = PixelsOffset / LineHeight;
	DrawLines.Y = FMath::Clamp(DrawLines.X + (WidgetHeight / LineHeight), 0.f, TotalLines*1.f);
}

FIntPoint SCodeMultilineText::GetDrawLines() const
{
	return DrawLines;
}

FString SCodeMultilineText::GetMethodOverCursor(const FString& InLine, const FTextLocation& InTextLocation, int32& ParenthesisOffset)
{
	const TCHAR Left = '(';
	const TCHAR Right = ')';

	int32 Offset = -1;
	bool bSkip = false;
	for (int32 i = InTextLocation.GetOffset() -1; i >= 0; i--)
	{
		if(!InLine.IsValidIndex(i)) continue;

		if (InLine[i] == Left)
		{
			if (bSkip)
			{
				bSkip = false;
			}
			else
			{
				Offset = i;
				break;
			}
		}
		else if (InLine[i] == Right)
		{
			bSkip = true;
		}
	}

	FString TrimmedText = FString();
	for (int32 i = Offset -1; i >= 0; i--)
	{
		if (!InLine.IsValidIndex(i)) continue;

		FString something;
		something += InLine[i];
		if (FSyntaxLimits::ContainSeparator(something)) break;

		TrimmedText.InsertAt(0, InLine[i]);
	}

	ParenthesisOffset = FMath::Clamp(Offset, 0, InLine.Len());
	return TrimmedText;
}

void SCodeMultilineText::ExtentRightClickMenu(FMenuBuilder& Builder)
{
	if (!AnyTextSelected()) return;

	//Find Documentation
	Builder.AddMenuEntry(FText::FromString("Find Documentation"), FText(), FSlateIcon(FPythonEditorStyle::Get().GetStyleSetName(), "PythonEditor.OpenDocumentation"), FUIAction(FExecuteAction::CreateRaw(this, &SCodeMultilineText::FindDocumentation)));
}

void SCodeMultilineText::FindDocumentation()
{
	FString Selection = GetSelectedText().ToString();
	if (!Selection.IsEmpty())
	{
		FString TheURL = "https://api.unrealengine.com/INT/PythonAPI/search.html?q=" + Selection + "&check_keywords=yes&area=default";
		FPythonEditorToolKit::Get()->OpenDocs(TheURL);
		//FPlatformProcess::LaunchURL(*TheURL, nullptr, nullptr);
	}
}


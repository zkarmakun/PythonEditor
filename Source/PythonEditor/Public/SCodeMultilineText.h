//Copyright 2019, Jorge Calleros Ramirez (Karma), All rights reserved.

#pragma once
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "CoreMinimal.h"
#include "Styling/SlateTypes.h"
#include "Fonts/FontMeasure.h"
#include "Input/Reply.h"
#include "Widgets/Text/SMultiLineEditableText.h"
#include "Styling/CoreStyle.h"
#include "AutoCompleteWorker.h"
#include "PythonEditorStyle.h"
//#include "Tokenizer.h"


#define SUGGESTION_BOX_SCALE 40.0f
#define MAX_SUGGESTION_DRAW 15

class FPythonHighlightMarshaller;
class FAutoCompleteWorker;

DECLARE_DELEGATE_OneParam(FOnCodeDirty, const bool&);

/**
 *
 */
class SCodeMultilineText : public SMultiLineEditableText
{
public:
	SLATE_BEGIN_ARGS(SCodeMultilineText)
		: _TextStyle(&FPythonEditorStyle::Get().GetWidgetStyle<FTextBlockStyle>("PythonEditor.TextStyle"))
		, _AutoCompleteWorker(nullptr)
	{}

	SLATE_STYLE_ARGUMENT(FTextBlockStyle, TextStyle)
	SLATE_ARGUMENT(FText, Text)
	SLATE_ARGUMENT(TSharedPtr< FPythonHighlightMarshaller >, Marshaller)
	SLATE_ARGUMENT(TSharedPtr< SScrollBar >, HScrollBar)
	SLATE_ARGUMENT(TSharedPtr< SScrollBar >, VScrollBar)
	SLATE_EVENT(FOnTextChanged, OnTextChanged)
	SLATE_EVENT(FOnCodeDirty, OnCodeDirty)
	SLATE_ARGUMENT(FMargin, Margin)
	SLATE_ARGUMENT(bool, AutoWrapText)
	SLATE_ARGUMENT(bool, IsReadOnly)
	SLATE_ARGUMENT(FAutoCompleteWorker*, AutoCompleteWorker)
	SLATE_ARGUMENT(FString, FileName)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);
	~SCodeMultilineText();

	// ~ Set SCodeLinetext, this is a kind of hack, SCodeLinetext is basically another multitext that sync with this one =)
	void SetCodeLines(TSharedPtr <class SCodeLinesText > CodeLineText);

	// ~ Function called when scroll, this will match numbers with text, at the same position
	void OnUserVScroll(float Offset);

	// ~ SWidget
	virtual int32 OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const override;
	virtual FReply OnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent) override;
	virtual FReply OnKeyChar(const FGeometry& MyGeometry, const FCharacterEvent& InCharacterEvent) override;
	virtual FReply OnMouseWheel(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual FReply OnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual FReply OnFocusReceived(const FGeometry& MyGeometry, const FFocusEvent& InFocusEvent) override;
	virtual FReply OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;

	//~ Marshaller
	void OnLineNumberChanged(const int32& LineNumber);

	// ~ ISlateEditableTextWidget
	void OnCursorMoved(const FTextLocation& InLocation);

	/* Return whenever you have suggestions to draw or not*/
	bool HasSuggestion() const;

	// ~ Reload this file.py module to be capture by auto complete every time you save
	void ReloadModule();

private:
	/* Bind for Auto Complete Thread, it will update the list of suggestions every time we dequeue one trial*/
	void OnAutoCompleteDone(TArray<FSuggestion> NewSuggestions, FString Requester);

	/*Get Selection indes for the suggestion array*/
	int32 GetSelectionWithOffset();

	/* Finish to write the word depending of what suggestion is selected in that moment*/
	void CompleteWord();

	//~ Add Indent based of enter
	void AddIndentedLine();

	/* Empties the suggestions list, this automatically removes the las drawing*/
	void ClearSuggestions();

	/* get suggestion index based on the mouse position, works in local*/
	int32 GetSuggestionBasedOnMouse(const FVector2D& InMousePosition);

	/* Check if mouse is inside the box we draw for the suggestions*/
	bool IsMouseInsideSuggestionBox() const;

	/* Return suggestion box size to be drawn */
	FVector2D GetSuggestionBoxSize() const;

	/* Return Suggestion box position, local space*/
	FVector2D GetSuggestionBoxPosition() const;

	/* Extent right click context menu, we added some functions like find documentation*/
	void ExtentRightClickMenu(FMenuBuilder& Builder);

	/* Based on what is selected at that moment will open the documentation for that word*/
	void FindDocumentation();

	/* Bind from marshaller will receive whenever a line is modify, it is the same as OnTextChanged, but with extra info*/
	void OnLineChanged(const FString& Line, const int32& LineIndex, const int32& Offset);

	/* Return suggestion brush to draw*/
	const FSlateBrush* GetSuggestionIcon(const FSuggestion& InSuggestion) const;

public:
	// ~ File Functions
	// ~ Save file
	void SaveFile();

	void RunFile();

	bool IsFileDirty() const;

	void SetActivePythonScript(bool Status);

private:
	//~ Is Active Python Editor
	bool bActivePythonEditor = false;

	// ~ Delegate to let others know when this code is dirty and need to be saved
	FOnCodeDirty OnCodeDirty;

	//~ Whenever file is dirty
	bool bDirty = false;

	/* Hold the file we are editing, this is code editor, so we always need a file to edit*/
	FString FilePath;

	/*Hack to hold references to numbers*/
	TSharedPtr<class SCodeLinesText> Lines;

	/* Hold the last Text Location*/
	FTextLocation TextLocation;

	/* Hold Text style*/
	const FTextBlockStyle* TextStyle;

	//~ Holds line percent separation
	float LinePercent;

	/* Hold the line height, this is already define is constructor, based on text style*/
	float LineHeight;

	/* HScroll bar reference */
	TSharedPtr<SScrollBar> HScroller;

	/* VScroll bar reference */
	TSharedPtr<SScrollBar> VScroller;

	/* Font measure service we need constantly measure the text size for suggestion to be able to draw properly a container box*/
	TSharedPtr<FSlateFontMeasure> FontMeasureService;

	/* Holds marshaller - the one who made the syntax and old a references of the text but as lines (not memory copies, very efficient)*/
	TSharedPtr< FPythonHighlightMarshaller > Marshaller;

	/* Hold suggestion box position */
	FVector2D SuggestionBoxPosition;

	/* Hold Suggestion box size*/
	FVector2D SuggestionBoxSize;
	
	/* Hold all the suggestions provided for the auto complete thread*/
	TArray<FSuggestion> Suggestions;

	/* Hold index of the selected suggestions at that moment*/
	int32 SugestionBoxSelection;

	/* Hold first index to be draw*/
	int32 InitialDrawIndex;

	/* to prevent keep looking for more suggestion once we use the function CompleteWord, (it will reset next time the user writes something) */
	bool bSuggestionTaken = false;

	/* Holds whenever the mouse is inside the Suggestions box*/
	bool bIsMouseInsideSuggetions = false;

	/* Holds mouse position to compare with the next one*/
	FVector2D MousePosition;

	/*AutoComplete worker reference*/
	FAutoCompleteWorker* AutoCompleteWorker = nullptr;

	/*Auto complete bind handle to remove the reference if we close this code editor*/
	FDelegateHandle AutoCompleteHandle;

	//~ Method to find some help
	FString Help;

	//~ Hold Drawing lines at certain moment
	FIntPoint DrawLines;

	float HelpLineOffset;

	float VerticalScrollOffset;

	void ComputeDrawRange();
	FIntPoint GetDrawLines() const;
	FString GetMethodOverCursor(const FString& InLine, const FTextLocation& InTextLocation, int32& ParenthesisOffset);
};

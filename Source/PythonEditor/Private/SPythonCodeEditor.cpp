//Copyright 2019, Jorge Calleros Ramirez (Karma), All rights reserved.

#include "SPythonCodeEditor.h"
#include "Misc/FileHelper.h"
#include "PythonHighlightMarshaller.h"
#include "Widgets/Layout/SScrollBar.h"
#include "Runtime/Slate/Public/Widgets/Layout/SBox.h"
#include "Widgets/SBoxPanel.h"
#include "SCodeMultilineText.h"
#include "widgets/Docking/SDockTab.h"
#include "Editor.h"
#include "Widgets/Text/SMultiLineEditableText.h"
#include "PythonEditorToolkit.h"
#include "SCodeLinesText.h"

void SPythonCodeEditor::Construct(const FArguments& InArgs)
{
	FileEditing = InArgs._File;
	TabName = InArgs._TabName;
	CodeStyle = InArgs._CodeStyle;

	//~ file does not exist, we need a real file
	check(FPaths::FileExists(FileEditing));
	ModuleName = FPaths::GetBaseFilename(FileEditing);

	//~ Load file's content
	FString InitialCode;
	check(FFileHelper::LoadFileToString(InitialCode, *FileEditing));

	//~ if file is empty by default we add unreal module
	if (InitialCode.IsEmpty())
	{
		InitialCode = "import unreal \n";
	}

	//~ Create Python highlight marshaller
	PythonMarshaller = FPythonHighlightMarshaller::Create(FPythonHighlightMarshaller::FSyntaxTextStyle());
	
	//~ Create scroll bars
	HorizontalScrollbar =
		SNew(SScrollBar)
		.Orientation(Orient_Horizontal)
		.Thickness(FVector2D(5.0f, 5.0f));

	VerticalScrollbar =
		SNew(SScrollBar)
		.Orientation(Orient_Vertical)
		.Thickness(FVector2D(5.0f, 5.0f));


	ChildSlot[
		//~ Set Background image
		SNew(SBorder)
		.BorderImage(FPythonEditorStyle::Get().GetBrush("PythonEditor.BG"))
		.Padding(FMargin(0,3,0,0))
		[
			//~ Hack to overlay the numbers with our text editor
			SNew(SOverlay)
			+ SOverlay::Slot()
			.VAlign(VAlign_Fill)
			.HAlign(HAlign_Fill)
			.Padding(0)
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
				.VAlign(VAlign_Fill)
				.HAlign(HAlign_Fill)
				.Padding(55, 0, 0, 0)
				[
					SNew(SVerticalBox)
					+ SVerticalBox::Slot()
					.VAlign(VAlign_Fill)
					.HAlign(HAlign_Fill)
					[
						//~ Added our text editor
						SAssignNew(MultiText, SCodeMultilineText)
						.TextStyle(CodeStyle)
						.Text(FText::FromString(InitialCode))
						.Marshaller(PythonMarshaller)
						.OnCodeDirty(this, &SPythonCodeEditor::OnCodeDirty)
						.AutoWrapText(false)
						.Margin(0.0f)
						.VScrollBar(VerticalScrollbar)
						.HScrollBar(HorizontalScrollbar)
						.IsReadOnly(false)
						.AutoCompleteWorker(FPythonEditorToolKit::Get()->GetAutoCompleteWorker())
						.FileName(FileEditing)
					]
					+ SVerticalBox::Slot()
					.AutoHeight()
					[
						HorizontalScrollbar->AsShared()
					]
				]
				+SHorizontalBox::Slot()
				.VAlign(VAlign_Fill)
				.AutoWidth()
				.Padding(0)
				[
					VerticalScrollbar->AsShared()
				]
			]
			+ SOverlay::Slot()
			.HAlign(HAlign_Left)
			.VAlign(VAlign_Fill)
			.Padding(0)
			[
				SNew(SBox)
				.WidthOverride(50)
				.Padding(0)
				[
					//Added numbers background
					SNew(SBorder)
					.BorderImage(FPythonEditorStyle::Get().GetBrush("PythonEditor.Separator"))
					.Padding(0)
					[
						SNew(SHorizontalBox)
						+ SHorizontalBox::Slot()
						.VAlign(VAlign_Fill)
						.HAlign(HAlign_Fill)
						.Padding(0, 0, 16, 0)
						[
							//~ Line Numbers
							SAssignNew(NumbersText, SCodeLinesText)
							.AutoWrapText(false)
							.Margin(0.0f)
						]
					]
				]
			]
		]
	];

	//Set the actual numbers reference into our text editor, to syncronize the scrollbars
	MultiText->SetCodeLines(NumbersText);

	//Set numbers justification to the right
	NumbersText->SetJustification(ETextJustify::Right);
	
}

void SPythonCodeEditor::OnCodeDirty(const bool& Status)
{
	//~ If status is dirty file, set an asterisks before our tab name
	if (Status)
	{
		Owner->SetLabel(FText::FromString("*" + TabName));
		return;
	}
	Owner->SetLabel(FText::FromString(TabName));
}

void SPythonCodeEditor::SetOwner(TSharedPtr<SDockTab> InOwner)
{
	//~ Set Owner reference, without this we cannot name our tab when is dirty
	Owner = InOwner;
}

FString SPythonCodeEditor::GetCode() const
{
	//~ Gets code
	return MultiText->GetText().ToString();
}

bool SPythonCodeEditor::Save()
{
	//~ Calls our text editor save file
	MultiText->SaveFile();
	return true;
}

bool SPythonCodeEditor::RunScript()
{
	//~ Python module should be imported only one, next time we need to reload to catch new variables and logic, otherwise auto complete will not work properly
	if (!bIsModule)
	{
		bIsModule = ImportSelfModule();
		return bIsModule;
	}

	//~ By reloading the module it will trigger the script too. Reload module every change to update auto complete.
	return ReloadSelfModule();
}

FString SPythonCodeEditor::GetFilePath() const
{
	return FileEditing;
}

bool SPythonCodeEditor::ImportSelfModule()
{
	FString PyCode = "import " + ModuleName + "\n";
	int32 Result = -1;

	Result = PyRun_SimpleString(TCHAR_TO_UTF8(*PyCode));

	//~ Python return 0 if success otherwise return -1, weird isn't it?
	if (Result == 0)
	{
		MultiText->SetActivePythonScript(true);
		FPythonEditorToolKit::Get()->GetAutoCompleteWorker()->AddUserModule(ModuleName);
		return true;
	}
	return false;
}

bool SPythonCodeEditor::ReloadSelfModule()
{
	FString PyCode = "reload(" + ModuleName + ")\n";
	int32 Result = -1;

	Result = PyRun_SimpleString(TCHAR_TO_UTF8(*PyCode));

	//~ Python return 0 if success otherwise return -1, weird isn't it?
	return (Result == 0);
}

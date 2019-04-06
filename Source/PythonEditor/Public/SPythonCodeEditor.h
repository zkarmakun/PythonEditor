//Copyright 2019, Jorge Calleros Ramirez (Karma), All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Widgets/SCompoundWidget.h"
#include "Widgets/Layout/SBorder.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "SlateTypes.h"
#include "PythonEditorStyle.h"

class SScrollBar;
class SDockTab;
class SCodeMultilineText;

/**
 *  Python code editor, this class creates a widget that modifies any python file, it will conserve a reference to the file
 */

class SPythonCodeEditor : public SCompoundWidget
{
public:

	SLATE_BEGIN_ARGS(SPythonCodeEditor)
		: _File("")
		, _CodeStyle(&FPythonEditorStyle::Get().GetWidgetStyle<FTextBlockStyle>("PythonEditor.TextStyle"))
	{}

	//~ Set file to be editable by this widget
	SLATE_ARGUMENT(FString, File)

	//~ Set Tabs Name
	SLATE_ARGUMENT(FString, TabName)

	//~ Code Style, not supported yet, it is using the one default in our style class
	SLATE_STYLE_ARGUMENT(FTextBlockStyle, CodeStyle)

	//~ Numbers Style, not supported yet, it is using the one default in our style class
	SLATE_STYLE_ARGUMENT(FTextBlockStyle, NumberStyle)

	SLATE_END_ARGS()

	//~ Construct widget
	void Construct(const FArguments& InArgs);

private:

	//~ Hold SDockTab name to display
	FString TabName;

	//~ (Scripts/PyScripts/)File.py which we are editing, it is important to keep the file alive while editing, check function will asure that
	FString FileEditing;

	//~ Modules name is the File's name, it becomes the module
	FString ModuleName;

	//~ Widgets
	TSharedPtr<class SCodeMultilineText> MultiText;
	TSharedPtr<class SCodeLinesText> NumbersText;
	TSharedPtr<SScrollBar> HorizontalScrollbar;
	TSharedPtr<SScrollBar> VerticalScrollbar;
	TSharedPtr<SDockTab> Owner;
	//~

	//~ This marshaller is made to highlight syntax exclusively for python
	TSharedPtr<class FPythonHighlightMarshaller> PythonMarshaller;

	//~ To hold whenever the modules was initially imported
	bool bIsModule = false;

	//~ Widget style
	const FTextBlockStyle* CodeStyle;

	//~ Tries to import the module, if fails (because your py script is wrong), it will try next time you run the file
	bool ImportSelfModule();

	//~ Once your module is import you should reload with this
	bool ReloadSelfModule();


private:
	//~ Delegates that receive a status every time the code is dirty, will set the SDockTab name for a dirty version
	void OnCodeDirty(const bool& Status);
	
public:

	//~ The reference Owner is just necessary to set dirty the tab name
	void SetOwner(TSharedPtr<SDockTab> InOwner);

	//~ Retrieve the code in FString
	FString GetCode() const;

	//~ save actual code to his file, misleading this calls the one inside the SCodeMultitext class
	virtual bool Save();

	//~ runs your script, misleading this calls the one inside the SCodeMultitext class
	virtual bool RunScript();

	//~ Gets file path
	FString GetFilePath() const;
};

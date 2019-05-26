//Copyright 2019, Jorge Calleros Ramirez (Karma), All rights reserved.

#include "PythonEditorStyle.h"
#include "PythonEditor.h"
#include "Framework/Application/SlateApplication.h"
#include "Styling/SlateStyleRegistry.h"
#include "Slate/SlateGameResources.h"
#include "Interfaces/IPluginManager.h"

TSharedPtr< FSlateStyleSet > FPythonEditorStyle::StyleInstance = NULL;

void FPythonEditorStyle::Initialize()
{
	if (!StyleInstance.IsValid())
	{
		StyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*StyleInstance);
	}
}

void FPythonEditorStyle::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*StyleInstance);
	ensure(StyleInstance.IsUnique());
	StyleInstance.Reset();
}

FName FPythonEditorStyle::GetStyleSetName()
{
	static FName StyleSetName(TEXT("PythonEditorStyle"));
	return StyleSetName;
}

#define IMAGE_BRUSH( RelativePath, ... ) FSlateImageBrush( StyleSet->RootToContentDir( RelativePath, TEXT(".png") ), __VA_ARGS__ )
#define BOX_BRUSH( RelativePath, ... ) FSlateBoxBrush( StyleSet->RootToContentDir( RelativePath, TEXT(".png") ), __VA_ARGS__ )
#define BORDER_BRUSH( RelativePath, ... ) FSlateBorderBrush( StyleSet->RootToContentDir( RelativePath, TEXT(".png") ), __VA_ARGS__ )
#define TTF_FONT( RelativePath, ... ) FSlateFontInfo( StyleSet->RootToContentDir( RelativePath, TEXT(".ttf") ), __VA_ARGS__ )
#define OTF_FONT( RelativePath, ... ) FSlateFontInfo( StyleSet->RootToContentDir( RelativePath, TEXT(".otf") ), __VA_ARGS__ )
#define DEFAULT_FONT(...) FCoreStyle::GetDefaultFontStyle(__VA_ARGS__)

// Const icon sizes
static const FVector2D Icon8x8(8.0f, 8.0f);
static const FVector2D Icon9x19(9.0f, 19.0f);
static const FVector2D Icon16x16(16.0f, 16.0f);
static const FVector2D Icon20x20(20.0f, 20.0f);
static const FVector2D Icon22x22(22.0f, 22.0f);
static const FVector2D Icon24x24(24.0f, 24.0f);
static const FVector2D Icon28x28(28.0f, 28.0f);
static const FVector2D Icon27x31(27.0f, 31.0f);
static const FVector2D Icon26x26(26.0f, 26.0f);
static const FVector2D Icon32x32(32.0f, 32.0f);
static const FVector2D Icon40x40(40.0f, 40.0f);
static const FVector2D Icon48x48(48.0f, 48.0f);
static const FVector2D Icon75x82(75.0f, 82.0f);
static const FVector2D Icon360x32(360.0f, 32.0f);
static const FVector2D Icon171x39(171.0f, 39.0f);
static const FVector2D Icon170x50(170.0f, 50.0f);
static const FVector2D Icon267x140(170.0f, 50.0f);
static const FVector2D Icon128x128(128,128);
static const FVector2D Icon225x225(225, 225);

TSharedRef< FSlateStyleSet > FPythonEditorStyle::Create()
{
	TSharedRef< FSlateStyleSet > StyleSet = MakeShareable(new FSlateStyleSet("PythonEditorStyle"));
	StyleSet->SetContentRoot(IPluginManager::Get().FindPlugin("PythonEditor")->GetBaseDir() / TEXT("Resources"));

	StyleSet->Set("PythonEditor.PluginAction", new IMAGE_BRUSH(TEXT("ButtonIcon_40x"), Icon40x40));
	StyleSet->Set("PythonEditor.NoBG", new IMAGE_BRUSH(TEXT("T_NoBG_48x"), Icon40x40));

	StyleSet->Set("PythonEditor.PipPlaceHolder", new IMAGE_BRUSH(TEXT("T_PlaceHolder"), Icon128x128));

	// File Browser Icons
	StyleSet->Set("PythonEditor.FileIcon", new IMAGE_BRUSH("T_Python_48x", Icon16x16));
	StyleSet->Set("PythonEditor.Shelf", new IMAGE_BRUSH("T_Shelfs_64x", Icon16x16));
	StyleSet->Set("PythonEditor.FolderIcon", new IMAGE_BRUSH("T_Folder_48x", Icon16x16));
	StyleSet->Set("PythonEditor.BG", new IMAGE_BRUSH("T_BG_64x", Icon16x16));
	StyleSet->Set("PythonEditor.Run", new IMAGE_BRUSH("T_Run_128x", Icon32x32));
	StyleSet->Set("PythonEditor.NewFile", new IMAGE_BRUSH("T_NewFile_48x", Icon32x32));
	StyleSet->Set("PythonEditor.Pip", new IMAGE_BRUSH("T_Pip_48x", Icon32x32));

	FSlateImageBrush* barBrush = new IMAGE_BRUSH("T_Mark_128x", Icon128x128);
	barBrush->DrawAs = ESlateBrushDrawType::Box;
	barBrush->Margin = .25f;
	StyleSet->Set("PythonEditor.PipButton", barBrush);
	
	StyleSet->Set("PythonEditor.PipButtonImage", new IMAGE_BRUSH("T_PipButtonImage_48x", Icon48x48 ));
	StyleSet->Set("PythonEditor.NewFolder", new IMAGE_BRUSH("T_NewFolder_48x", Icon32x32));
	StyleSet->Set("PythonEditor.DeleteFile", new IMAGE_BRUSH("T_DeleteFile_48x", Icon32x32));
	StyleSet->Set("PythonEditor.RenameFile", new IMAGE_BRUSH("T_Rename_48x", Icon32x32));
	StyleSet->Set("PythonEditor.EditFile", new IMAGE_BRUSH("T_EditFile_48x", Icon32x32));
	StyleSet->Set("PythonEditor.Selected", new IMAGE_BRUSH("T_Selected_48x", Icon32x32));

	StyleSet->Set("PythonEditor.SuggestionBG", new BOX_BRUSH("T_SuggestionBG_128x", FMargin(3.f / 8.f)));

	// Script Editor Icons
	StyleSet->Set("PythonEditor.Separator", new IMAGE_BRUSH("T_EditorSeparator_64x", Icon16x16));
	StyleSet->Set("PythonEditor.LineSelected", new IMAGE_BRUSH("T_SelectedLine_128x", Icon48x48));
	StyleSet->Set("PythonEditor.Solid", new IMAGE_BRUSH("T_WhiteDot_16x", Icon16x16));
	StyleSet->Set("PythonEditor.OpenDocumentation", new IMAGE_BRUSH("T_OpenDocumentation_64x", Icon48x48));
	StyleSet->Set("PythonEditor.FindNext", new IMAGE_BRUSH("T_FindNext_64x", Icon48x48));
	StyleSet->Set("PythonEditor.FindPrev", new IMAGE_BRUSH("T_FindPrev_64x", Icon48x48));
	StyleSet->Set("PythonEditor.Variable", new IMAGE_BRUSH("T_Variable_64x", Icon48x48));
	StyleSet->Set("PythonEditor.Class", new IMAGE_BRUSH("T_Class_64x", Icon48x48));
	StyleSet->Set("PythonEditor.Method", new IMAGE_BRUSH("T_Method_64x", Icon48x48));
	StyleSet->Set("PythonEditor.Keyword", new IMAGE_BRUSH("T_Keyword_64x", Icon48x48));
	StyleSet->Set("PythonEditor.Tab", new IMAGE_BRUSH("T_TabArrow_32x", Icon32x32));

	//Shelf icons
	StyleSet->Set("Shelf.selected", new IMAGE_BRUSH("T_ShelfTab", Icon16x16));
	StyleSet->Set("Shelf.ScriptIcon", new IMAGE_BRUSH("T_Python_48x", Icon40x40));

	// Shelf styles
	FButtonStyle PipButtonStyle;
	PipButtonStyle.Normal = *StyleSet->GetBrush("PythonEditor.PipButton");
	PipButtonStyle.Normal.TintColor = FSlateColor(FLinearColor::White * .45f);
	PipButtonStyle.Hovered = *StyleSet->GetBrush("PythonEditor.PipButton");
	PipButtonStyle.Pressed = PipButtonStyle.Normal;
	StyleSet->Set("PythonEditor.PipButtonStyle", PipButtonStyle);


	// Shelf styles
	FButtonStyle ShelfButtonStyle;
	ShelfButtonStyle.Normal = *StyleSet->GetBrush("Shelf.ScriptIcon");
	ShelfButtonStyle.Hovered = *StyleSet->GetBrush("Shelf.ScriptIcon");
	ShelfButtonStyle.Pressed = *StyleSet->GetBrush("Shelf.ScriptIcon");
	ShelfButtonStyle.Pressed.TintColor = FLinearColor::Gray;
	StyleSet->Set("Shelf.ShelfButtonStyle", ShelfButtonStyle);

	// Shelf Tab selected style
	FButtonStyle ShelfSelecteStyle;
	StyleSet->Set("Shelf.ShelfTabBG", new IMAGE_BRUSH("T_ShelfTabBG", Icon16x16));
	ShelfSelecteStyle.Normal = *StyleSet->GetBrush("Shelf.ShelfTabBG");
	ShelfSelecteStyle.Normal.DrawAs = ESlateBrushDrawType::Image;
	ShelfSelecteStyle.Normal.ImageSize = FVector2D(100, 20);
	ShelfSelecteStyle.Hovered = *StyleSet->GetBrush("Shelf.ShelfTabBG");
	ShelfSelecteStyle.Hovered.DrawAs = ESlateBrushDrawType::Image;
	ShelfSelecteStyle.Hovered.ImageSize = FVector2D(100, 20);
	ShelfSelecteStyle.Pressed = *StyleSet->GetBrush("Shelf.ShelfTabBG");
	ShelfSelecteStyle.Pressed.DrawAs = ESlateBrushDrawType::Image;
	ShelfSelecteStyle.Pressed.ImageSize = FVector2D(100, 20);
	ShelfSelecteStyle.Pressed.TintColor = FLinearColor::Gray;
	StyleSet->Set("Shelf.ButtonStyle", ShelfSelecteStyle);

	//~ Python Editor Font
	FSlateFontInfo TTF_Hack = TTF_FONT(TEXT("Hack"), 9);

	//~ Editor text style
	const FTextBlockStyle EditorTextStyle = FTextBlockStyle()
		.SetHighlightShape(BOX_BRUSH("T_WhiteDot_16x", FMargin(3.f / 8.f)))
		.SetHighlightColor(FLinearColor(FColor(175, 255, 5, 255)))
		.SetShadowColorAndOpacity(FLinearColor::Black)
		.SetColorAndOpacity(FLinearColor(FColor(43,145,175,255))) //light blue
		.SetShadowOffset(FVector2D::ZeroVector)
		.SetFont(TTF_Hack);

	StyleSet->Set("PythonEditor.TextStyle", EditorTextStyle);

	StyleSet->Set("SyntaxHighlight.Python.Normal", FTextBlockStyle(EditorTextStyle).SetColorAndOpacity(FLinearColor::White));
	StyleSet->Set("SyntaxHighlight.Python.Operator", FTextBlockStyle(EditorTextStyle).SetColorAndOpacity(FLinearColor(FColor(217,134,34,255)))); // light blue
	StyleSet->Set("SyntaxHighlight.Python.Keyword", FTextBlockStyle(EditorTextStyle).SetColorAndOpacity(FLinearColor(.57f, .777f, .359f, 1))); // obsidian green
	StyleSet->Set("SyntaxHighlight.Python.String", FTextBlockStyle(EditorTextStyle).SetColorAndOpacity(FLinearColor(.92f, .46f, 0, 1))); //orange
	StyleSet->Set("SyntaxHighlight.Python.Number", FTextBlockStyle(EditorTextStyle).SetColorAndOpacity(FLinearColor(.87f, .7f, .13f, 1))); // light yellow
	StyleSet->Set("SyntaxHighlight.Python.Comment", FTextBlockStyle(EditorTextStyle).SetColorAndOpacity(FLinearColor(.5f, .5f, .5f, 1))); // light gray
	StyleSet->Set("SyntaxHighlight.Python.PreProcessorKeyword", FTextBlockStyle(EditorTextStyle).SetColorAndOpacity(FLinearColor::Red)); // red


	const FEditableTextBoxStyle EditableTextBoxStyle = FEditableTextBoxStyle()
		.SetBackgroundImageNormal(FSlateNoResource())
		.SetBackgroundImageHovered(FSlateNoResource())
		.SetBackgroundImageFocused(FSlateNoResource())
		.SetBackgroundImageReadOnly(FSlateNoResource());

	StyleSet->Set("TextEditor.EditableTextBox", EditableTextBoxStyle);


	return StyleSet;
}

#undef IMAGE_BRUSH
#undef BOX_BRUSH
#undef BORDER_BRUSH
#undef TTF_FONT
#undef OTF_FONT
#undef DEFAULT_FONT

void FPythonEditorStyle::ReloadTextures()
{
	if (FSlateApplication::IsInitialized())
	{
		FSlateApplication::Get().GetRenderer()->ReloadTextureResources();
	}
}

const ISlateStyle& FPythonEditorStyle::Get()
{
	return *StyleInstance;
}

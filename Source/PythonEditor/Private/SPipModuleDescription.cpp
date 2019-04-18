// Fill out your copyright notice in the Description page of Project Settings.


#include "SPipModuleDescription.h"
#include "SlateOptMacros.h"
#include "SBoxPanel.h"
#include "SScaleBox.h"
#include "SImage.h"
#include "STextBlock.h"
#include "PythonEditorStyle.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SPipModuleDescription::Construct(const FArguments& InArgs)
{
	ModuleDescription = InArgs._ModuleDescription;
	
	ChildSlot
	[
		SNew(SVerticalBox)
		+ SVerticalBox::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			.Padding(10)
			.AutoWidth()
			.HAlign(HAlign_Fill)
			[
				SNew(SScaleBox)
				[
					SNew(SImage)
				]
			]
			+ SHorizontalBox::Slot()
			.Padding(10)
			.AutoWidth()
			.HAlign(HAlign_Fill)
			[
				SNew(SVerticalBox)
				+ SVerticalBox::Slot()
				[
					CreateHeader("Author:", ModuleDescription.Author)
				]
				+ SVerticalBox::Slot()
				[
					CreateHeader("Author e-mail:", ModuleDescription.AuthorEmail)
				]
				+ SVerticalBox::Slot()
				[
					CreateHeader("Home page:", ModuleDescription.HomePage)
				]
				+ SVerticalBox::Slot()
				[
					CreateHeader("Licence:", ModuleDescription.Licence)
				]
				+ SVerticalBox::Slot()
				[
					CreateHeader("Last Version:", ModuleDescription.LastVersion)
				]
				+ SVerticalBox::Slot()
				[
					CreateHeader("Summary:", ModuleDescription.Description)
				]
			]
		]
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

TSharedRef<SWidget> SPipModuleDescription::CreateHeader(const FString& Name, const FString Value)
{
	TSharedPtr<SWidget> Widget = SNew(SHorizontalBox)
		+ SHorizontalBox::Slot()
		[
			SNew(STextBlock)
			.Text(FText::FromString(Name))
			.TextStyle(&FPythonEditorStyle::Get().GetWidgetStyle<FTextBlockStyle>("SyntaxHighlight.Python.Normal"))
		]
		+ SHorizontalBox::Slot()
		[
			SNew(STextBlock)
			.Text(FText::FromString(Value))
			.ColorAndOpacity(FSlateColor(FLinearColor::White))
		];
	return Widget->AsShared();
}

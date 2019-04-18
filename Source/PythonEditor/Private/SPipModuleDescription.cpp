// Fill out your copyright notice in the Description page of Project Settings.


#include "SPipModuleDescription.h"
#include "SlateOptMacros.h"
#include "SBoxPanel.h"
#include "SScaleBox.h"
#include "SImage.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SPipModuleDescription::Construct(const FArguments& InArgs)
{
	ModuleDescription = InArgs._ModuleDescription;
	
	ChildSlot
	[
		SNew(SVerticalBox)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			[
				SNew(SScaleBox)
				[
					SNew(SImage)
				]
			]
			+ SHorizontalBox::Slot()
			[
				SNew(SVerticalBox)
				+ SVerticalBox::Slot()
				[
					CreateHeader(ModuleDescription.Author, ModuleDescription.Au)
				]
			]
		]
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

TSharedPtr<SWidget> SPipModuleDescription::CreateHeader(const FString& Name, const FString Value)
{

}

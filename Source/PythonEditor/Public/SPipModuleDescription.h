// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class PYTHONEDITOR_API SPipModuleDescription : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SPipModuleDescription)
	{}

	SLATE_ARGUMENT(FModuleDescription, ModuleDescription)
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

private:
	FModuleDescription ModuleDescription;

	TSharedPtr<SWidget> CreateHeader(const FString& Name, const FString Value);
};

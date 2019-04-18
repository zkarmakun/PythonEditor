// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "PipWorker.h"
#include "Http.h"

DECLARE_DELEGATE_OneParam(FOnClickedModule, const FModuleDescription&)

class SPipButton : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SPipButton)
	{}

	SLATE_ARGUMENT(FModuleDescription, Module)
	SLATE_EVENT(FOnClickedModule, OnClickedModule)

	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

private:
	FReply OnClicked();


private:
	FModuleDescription Module;
	FOnClickedModule OnClickedModule;

};

/**
 * 
 */
class SPip : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SPip)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);


	~SPip();

private:
	FString LastSearch;
	TSharedPtr<SVerticalBox> Container;
	TSharedPtr<SVerticalBox> ModuleContainer;

	

private:
	void OnClickedModule(const FModuleDescription& Module);
	void OnSearchUpdate(const FText& Text, ETextCommit::Type);
	void OnModulesFound(const TArray<FModuleDescription>& Modules);
	void HandleRequest(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded);
	FModuleDescription CurrentModule;

private:
	FPipWorker* PipWorker = nullptr;
};

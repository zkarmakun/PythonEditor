// Fill out your copyright notice in the Description page of Project Settings.


#include "SPip.h"
#include "SlateOptMacros.h"
#include "SSplitter.h"
#include "SBoxPanel.h"
#include "SSearchBox.h"
#include "SBorder.h"
#include "PythonEditorStyle.h"
#include "SScrollBox.h"
#include "SButton.h"
#include "SlateTypes.h"
#include "SBox.h"
#include "SImage.h"
#include "STextBlock.h"
#include "SScaleBox.h"
#include "IHttpRequest.h"
#include "HttpModule.h"
#include "IHttpResponse.h"
#include "SPipModuleDescription.h"


BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SPipButton::Construct(const FArguments& InArgs)
{
	OnClickedModule = InArgs._OnClickedModule;
	Module = InArgs._Module;

	ChildSlot
	[
		SNew(SBox)
		.HeightOverride(50)
		[
			SNew(SButton)
			.ButtonStyle(&FPythonEditorStyle::Get().GetWidgetStyle<FButtonStyle>("PythonEditor.PipButtonStyle"))
			.ContentPadding(2)
			.OnClicked(this, &SPipButton::OnClicked)
			[
				SNew(SVerticalBox)
				+ SVerticalBox::Slot()
				.Padding(FMargin(5,5,0,0))
				[
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot()
					[
						SNew(STextBlock)
						.Text(FText::FromString(Module.Name))
						.TextStyle(&FPythonEditorStyle::Get().GetWidgetStyle<FTextBlockStyle>("SyntaxHighlight.Python.Normal"))
					]
					+ SHorizontalBox::Slot()
					.HAlign(HAlign_Right)
					.Padding(FMargin(0,0,5,0))
					[
						SNew(STextBlock)
						.Text(FText::FromString(Module.Version))
						.ColorAndOpacity(FSlateColor(FLinearColor::White))
						//.TextStyle(&FPythonEditorStyle::Get().GetWidgetStyle<FTextBlockStyle>("SyntaxHighlight.Python.Normal"))
					]
					
				]
				+ SVerticalBox::Slot()
				.Padding(FMargin(5, 0, 0, 0))
				[
					SNew(STextBlock)
					.Text(FText::FromString(Module.Description))
					.TextStyle(&FPythonEditorStyle::Get().GetWidgetStyle<FTextBlockStyle>("PythonEditor.TextStyle"))
				]
			]
		]
	];
}

FReply SPipButton::OnClicked()
{
	if (OnClickedModule.ExecuteIfBound(Module))
	{
		return FReply::Handled();
	}
	return FReply::Unhandled();
}

void SPip::Construct(const FArguments& InArgs)
{
	ChildSlot
	[
		SNew(SSplitter)
		.PhysicalSplitterHandleSize(2.0f)
		+ SSplitter::Slot()
		.Value(0.4f)
		[
			SNew(SBorder)
			.BorderImage(FPythonEditorStyle::Get().GetBrush("PythonEditor.BG"))
			[
				SNew(SVerticalBox)
				+ SVerticalBox::Slot()
				.AutoHeight()
				.Padding(5)
				[
					SNew(SSearchBox)
					.OnTextCommitted(this, &SPip::OnSearchUpdate)
				]
				+ SVerticalBox::Slot()
				.VAlign(VAlign_Fill)
				.Padding(5)
				[
					SNew(SScrollBox)
					+ SScrollBox::Slot()
					[
						SAssignNew(Container, SVerticalBox)
					]

				]
				+ SVerticalBox::Slot()
				.AutoHeight()
				.VAlign(VAlign_Bottom)
				[
					SNew(SScrollBox)
					+ SScrollBox::Slot()
					[
						SAssignNew(ModuleContainer, SVerticalBox)
					]
				]
			]
			
		]
		+ SSplitter::Slot()
		[
			SNew(SVerticalBox)
		]

	];

	PipWorker = new FPipWorker();
	PipWorker->OnModulesFound.AddRaw(this, &SPip::OnModulesFound);
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

SPip::~SPip()
{
	PipWorker->Stop();
}



void SPip::OnSearchUpdate(const FText& Text, ETextCommit::Type)
{
	check(PipWorker);
	FString Word = Text.ToString();
	if (Word.IsEmpty() || Word == LastSearch)  return;

	LastSearch = Word;
	PipWorker->SearchForModules(Word);
}

void SPip::OnModulesFound(const TArray<FModuleDescription>& Modules)
{
	Container->ClearChildren();
	for (auto& Elem : Modules)
	{
		//UE_LOG(LogTemp, Log, TEXT("Name: %s, Version: %s, Des: %s"), *Elem.Name, *Elem.Version, *Elem.Description);
		SVerticalBox::FSlot& Slot = Container->AddSlot().Padding(5);
		Slot[
			SNew(SPipButton)
				.Module(Elem)
				.OnClickedModule(this, &SPip::OnClickedModule)
		];
	}
}

void SPip::OnClickedModule(const FModuleDescription& Module)
{
	CurrentModule = Module;
	UE_LOG(LogTemp, Log, TEXT("Name: %s, Version: %s, Des: %s"), *Module.Name, *Module.Version, *Module.Description);
	FString URL = "https://pypi.org/pypi/" + Module.Name + "/json";
	TSharedRef<IHttpRequest> HttpRequest = FHttpModule::Get().CreateRequest();
	HttpRequest->OnProcessRequestComplete().BindSP(this, &SPip::HandleRequest);
	HttpRequest->SetURL(URL);
	HttpRequest->SetVerb(TEXT("GET"));
	HttpRequest->ProcessRequest();
}


void SPip::HandleRequest(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded)
{
	if (bSucceeded && HttpResponse.IsValid() && EHttpResponseCodes::IsOk(HttpResponse->GetResponseCode()))
	{
		//UE_LOG(LogTemp, Log, TEXT("%s"), *HttpResponse->GetContentAsString());
		CurrentModule.GetInfoFromJson(HttpResponse->GetContentAsString());

		//Draw UI here
		ModuleContainer->ClearChildren();
		SVerticalBox::FSlot& Slot = ModuleContainer->AddSlot().Padding(5);
		Slot[
			SNew(SPipModuleDescription)
				.ModuleDescription(CurrentModule)
		];
		UE_LOG(LogTemp, Log, TEXT("%s"), *CurrentModule.Author);
		UE_LOG(LogTemp, Log, TEXT("%s"), *CurrentModule.AuthorEmail);
		UE_LOG(LogTemp, Log, TEXT("%s"), *CurrentModule.FullDescription);
		UE_LOG(LogTemp, Log, TEXT("%s"), *CurrentModule.HomePage);
		UE_LOG(LogTemp, Log, TEXT("%s"), *CurrentModule.Licence);
		UE_LOG(LogTemp, Log, TEXT("%s"), *CurrentModule.LastVersion);
		return;
	}

	if (HttpResponse.IsValid())
	{
		//UE_LOG(LogTemp, Error, TEXT("Request Code Error: %i"), HttpResponse->GetResponseCode());
		return;
	}
}




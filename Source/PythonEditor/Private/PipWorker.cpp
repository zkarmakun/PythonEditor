// Fill out your copyright notice in the Description page of Project Settings.


#include "PipWorker.h"
#include "RunnableThread.h"
#include "Runtime/Core/Public/GenericPlatform/GenericPlatform.h"
#include "Paths.h"
#include "Runtime/Core/Public/Async/TaskGraphInterfaces.h"
#include "JsonReader.h"
#include "JsonSerializer.h"
#include "JsonObject.h"

FPipWorker::FPipWorker()
	: Stopping(false)
{
	Thread = FRunnableThread::Create(this, TEXT("FPipWorker"), 8 * 1024, TPri_Normal);
}

FPipWorker::~FPipWorker()
{
	if (Thread != nullptr)
	{
		Thread->Kill(true);
		delete Thread;
	}
}

void FPipWorker::SearchForModules(const FString& TrimWord)
{
	QueueSearch.Enqueue(TrimWord);
}

bool FPipWorker::Init()
{
	return true;
}

uint32 FPipWorker::Run()
{
	//just in case something is not inited
	FPlatformProcess::Sleep(.5f);
	while (!Stopping)
	{
		//process find better result
		if (!QueueSearch.IsEmpty())
		{
			FString NextSearch;
			QueueSearch.Dequeue(NextSearch);
			PipSearch(NextSearch);
			//ComputeAutoComplete(AutoComplete.TrimmedWord, AutoComplete.RequesterFileName);
		}

		FPlatformProcess::Sleep(.03f);
	}
	return 1;
}

void FPipWorker::Stop()
{
	Stopping = true;
}

void FPipWorker::PipSearch(const FString& Word)
{
	if (Word.IsEmpty()) return;

	FString PythonPath = FPaths::ConvertRelativePathToFull(FPaths::EngineDir()) + TEXT("Binaries/ThirdParty/Python/Win64/");
	FString ProviderPython = PythonPath + TEXT("Python.exe");
	FString CommandLine = TEXT(" -m pip search ") + Word;
	int32 ReturnCode;
	FString Output = FString();
	FString Errors = FString();
	if (FPlatformProcess::ExecProcess(*ProviderPython, *CommandLine, &ReturnCode, &Output, &Errors))
	{
		TArray<FString> Lines;
		Output.ParseIntoArrayLines(Lines, false);
		TArray<FModuleDescription> Modules;
		for (auto& line : Lines)
		{
			FString ModuleName = FString(); 
			line.Split(" (", &ModuleName, nullptr);
			FString Description = FString();
			line.Split("- ", nullptr, &Description);
			FString Version = FString();
			line.Split(" (", nullptr, &Version);
			Version.Split(")", &Version, nullptr);

			if (!ModuleName.IsEmpty() && !Description.IsEmpty())
			{
				Modules.Add(FModuleDescription(ModuleName, Version, Description));
			}
		}

		if (Modules.Num() > 0)
		{
			AsyncTask(ENamedThreads::GameThread, [this, Modules]() {
				if (OnModulesFound.IsBound())
				{
					OnModulesFound.Broadcast(Modules);
				}
			});
		}
	}
}

void FModuleDescription::GetInfoFromJson(const FString& Json)
{
	//Json example link: https://pypi.org/pypi/PySide2/json

	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject());
	TSharedRef< TJsonReader<> > JsonReader = TJsonReaderFactory<>::Create(Json);
	if (FJsonSerializer::Deserialize(JsonReader, JsonObject) && JsonObject.IsValid())
	{
		TSharedPtr<FJsonObject> Info = JsonObject->GetObjectField("info");
		Author = Info->GetStringField("author");
		AuthorEmail = Info->GetStringField("author_email");
		FullDescription = Info->GetStringField("description");
		HomePage = Info->GetStringField("home_page");
		Licence = Info->GetStringField("license");
		LastVersion = Info->GetStringField("version");
	}
}

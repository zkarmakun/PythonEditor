//Copyright 2019, Jorge Calleros Ramirez (Karma), All rights reserved.

#include "AutoCompleteWorker.h"
#include "Misc/Paths.h"
#include "Misc/FileHelper.h"
#include "Runtime/Core/Public/GenericPlatform/GenericPlatform.h"
#include "SyntaxLimits.h"
#include "HAL/FileManager.h"
#include "Runtime/Core/Public/Async/TaskGraphInterfaces.h"


const FString cPOINT = TEXT(".");

TArray<FString> FAutoCompleteWorker::PyModules;

FAutoCompleteWorker::FAutoCompleteWorker()
	: Stopping(false)
{
	Thread = FRunnableThread::Create(this, TEXT("FAutoCompleteWorker"), 8 * 1024, TPri_Normal);
}

FAutoCompleteWorker::~FAutoCompleteWorker()
{
	if (Thread != nullptr)
	{
		Thread->Kill(true);
		delete Thread;
	}
}

bool FAutoCompleteWorker::Init()
{
	return true;
}

void FAutoCompleteWorker::AddAutoCompleteToQueue(const FString& TrimWord, const FString& InRequesterFiileName)
{
	FSearchWordQueue queue;
	queue.TrimmedWord = TrimWord;
	queue.RequesterFileName = InRequesterFiileName;
	QueueFind.Enqueue(queue);
}

void FAutoCompleteWorker::AddUserModule(const FString& ModuleName)
{
	if (!UserRegisteredModules.Contains(ModuleName))
	{
		UserRegisteredModules.Add(ModuleName);
	}
}

void FAutoCompleteWorker::AddFavoriteSearch(const FString& Word)
{
	if (!Favorites.Contains(Word))
	{
		const int32 MaxFavorites = 256;
		if (Favorites.Num() > MaxFavorites)
		{
			Favorites.Insert(Word, 0);
			Favorites.RemoveAt(Favorites.Num() - 1);
			return;
		}
		Favorites.Add(Word);
	}
}

void FAutoCompleteWorker::LoadPythonInstalledModules()
{
	PyModules = UPyUnrealLib::GetPyInstalledModules();
}


uint32 FAutoCompleteWorker::Run()
{
	//just in case something is not inited
	FPlatformProcess::Sleep(.5f);

	while (!Stopping)
	{
		//process find better result
		if (!QueueFind.IsEmpty())
		{
			FSearchWordQueue AutoComplete;
			QueueFind.Dequeue(AutoComplete);
			ComputeAutoComplete(AutoComplete.TrimmedWord, AutoComplete.RequesterFileName);
		}

		FPlatformProcess::Sleep(.03f);
	}
	return 1;
}

void FAutoCompleteWorker::Stop()
{
	Stopping = true;
}

void FAutoCompleteWorker::ComputeAutoComplete(FString& TrimWord, const FString& InRequesterFileName)
{
	TArray<FSuggestion> Local_suggestions;
	FString ModuleName = FPaths::GetBaseFilename(InRequesterFileName);

	if (TrimWord.Contains(cPOINT))
	{
		TArray<FString> Tokens = GetTokensFromTrimmedCode(TrimWord);

		if (UserRegisteredModules.Contains(ModuleName))
		{
			TArray<FSuggestion> CheckSelfSuggetions;
			UPyUnrealLib::FindSuggetionFromEditable(InRequesterFileName, CheckSelfSuggetions, Favorites);

			if (CheckSelfSuggetions.Num() > 0 && Tokens.IsValidIndex(0))
			{
				for (auto& Sugges : CheckSelfSuggetions)
				{
					if (Sugges.Suggestion == Tokens[0])
					{
						Tokens.Insert(ModuleName, 0);
						break;
					}
				}
			}
		}


		if (TrimWord.EndsWith(cPOINT) && Tokens.IsValidIndex(0))
		{
			UPyUnrealLib::FindSuggetion(Tokens, Local_suggestions, Favorites, true);
		}
		else
		{
			UPyUnrealLib::FindSuggetion(Tokens, Local_suggestions, Favorites);
		}
	
		OnSendSuggestion(Local_suggestions, InRequesterFileName);
		return;
	}

	TArray<FSuggestion> FavoritesSuggestions;


	//look for keywords
	for (auto& Sugges : FSyntaxLimits::GetPyKeywords())
	{
		if (UPyUnrealLib::IsValidSuggestion(Sugges, TrimWord))
		{
			FString WordCompletation = Sugges;
			WordCompletation.RemoveFromStart(TrimWord);
			if (Favorites.Contains(Sugges))
			{
				FavoritesSuggestions.Add(FSuggestion(Sugges, EPyAttrType::Keyword, WordCompletation));
				continue;
			}
			Local_suggestions.Add(FSuggestion(Sugges, EPyAttrType::Keyword, WordCompletation));
		}
	}
	
	//look for modules
	for (auto& Module : PyModules)
	{
		if (UPyUnrealLib::IsValidSuggestion(Module,TrimWord))
		{
			FString WordCompletation = Module;
			WordCompletation.RemoveFromStart(TrimWord);
			if (Favorites.Contains(Module))
			{
				FavoritesSuggestions.Add(FSuggestion(Module, EPyAttrType::Module, WordCompletation));
				continue;
			}
			Local_suggestions.Add(FSuggestion(Module, EPyAttrType::Module, WordCompletation));
		}
	}

	//look for itself
	if (UserRegisteredModules.Contains(ModuleName))
	{
		TArray<FSuggestion> ItSelfSuggections;
		UPyUnrealLib::FindSuggetionFromEditable(InRequesterFileName, ItSelfSuggections, Favorites);
		for (auto& It : ItSelfSuggections)
		{
			if (UPyUnrealLib::IsValidSuggestion(It.Suggestion, TrimWord))
			{
				bool bFind = false;
				for (auto& lIt : Local_suggestions)
				{
					if (lIt.Suggestion == It.Suggestion)
					{
						bFind = true;
						break;
					}
				}

				if (!bFind)
				{
					FString WordCompletation = It.Suggestion;
					WordCompletation.RemoveFromStart(TrimWord);

					if (Favorites.Contains(It.Suggestion))
					{
						FavoritesSuggestions.Add(FSuggestion(It.Suggestion, EPyAttrType::Module, WordCompletation));
						continue;
					}

					Local_suggestions.Add(FSuggestion(It.Suggestion, EPyAttrType::Module, WordCompletation));
				}
			}
		}
	}

	FavoritesSuggestions.Append(Local_suggestions);

 	OnSendSuggestion(FavoritesSuggestions, InRequesterFileName);
}

TArray<FString> FAutoCompleteWorker::GetTokensFromTrimmedCode(FString& InTrimmedCode)
{
	TArray<FString> Out;
	FString Token = "";
	for (int32 i = 0; i < InTrimmedCode.Len(); i++)
	{
		if (InTrimmedCode[i] == '.')
		{
			Out.Add(Token);
			Token = "";
		}
		else
		{
			Token += InTrimmedCode[i];
		}
	}

	if (!Token.IsEmpty())
	{
		Out.Add(Token);
	}
	return Out;
}


void FAutoCompleteWorker::OnSendSuggestion(TArray<FSuggestion>& InSuggestions, const FString& InRequesterFileName)
{



	AsyncTask(ENamedThreads::GameThread, [this, InSuggestions, InRequesterFileName]() {
		if (OnAutoCompleteDone.IsBound())
		{
			OnAutoCompleteDone.Broadcast(InSuggestions, InRequesterFileName);
		}
	});	
}





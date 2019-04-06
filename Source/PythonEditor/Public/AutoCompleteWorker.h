//Copyright 2019, Jorge Calleros Ramirez (Karma), All rights reserved.

#pragma once
#include "Framework/Text/TextRange.h"
#include "Framework/Text/SyntaxTokenizer.h"
#include "CoreMinimal.h"
#include "EngineMinimal.h"
#include "Runtime/Core/Public/HAL/Runnable.h"
#include "HAL/RunnableThread.h"
#include "PyUnrealLib.h"

THIRD_PARTY_INCLUDES_START
#include "Python.h"
#include "structmember.h"
THIRD_PARTY_INCLUDES_END

//~ holds search queries
struct FSearchWordQueue
{
public:

	//~ Trimmed word, the incomplete word you are editing in a line
	FString TrimmedWord;

	//~ The file that is requesting this query
	FString RequesterFileName;

	FSearchWordQueue()
	{
		TrimmedWord = "";
		RequesterFileName = "";
	}
};



/**
 *  This should be overriden to work with another lenguages, by default works for python
 */
class FAutoCompleteWorker : public FRunnable
{
public:
	
	//~ The Modules you are in memory
	static TArray<FString> PyModules;

	//~ Delegates that fires every time we complete a query, even if is empty
	DECLARE_MULTICAST_DELEGATE_TwoParams(FOnAutoCompleteDone, TArray<FSuggestion>, FString)
	FOnAutoCompleteDone OnAutoCompleteDone;

	FAutoCompleteWorker();
	~FAutoCompleteWorker();

	//~ FRunnable
	virtual bool Init() override;
	virtual uint32 Run() override;
	virtual void Stop() override;
	virtual void Exit() override {};
	//

public:
	/*
		Adds a query to the tail
		@ TrimWord					- Trimmed word, the in complete word you are editing from an specific line
		@ InRequesterFiileName		- The file which is requesting this query
	*/
	void AddAutoCompleteToQueue(const FString& TrimWord,const FString& InRequesterFiileName);

	/*
		Adds a new python module to the queries list, this is because modules are imported only once to the editor, after that we reload modules
		@ ModuleName	- The python module name, basically the file name without extension
	*/
	void AddUserModule(const FString& ModuleName);

	/*
		Add a word to the favorites, the next we look for suggestion it will sort those using these on top
		@ Word		- add words to favorites
	*/
	void AddFavoriteSearch(const FString& Word);

	//~ Load all installed python modules at ModuleStart, it should be the first python code lines you trigger
	static void LoadPythonInstalledModules();

protected:
	//~ Perform any query
	virtual void ComputeAutoComplete(FString& TrimWord, const FString& InRequesterFileName);

private:

	//~ Queries list
	TQueue<FSearchWordQueue> QueueFind;

	/*
		Get all the tokens in trimmed word
		@ InTrimmedCode		- Trimmed word to look for, example: Module.Class.Method
	*/
	TArray<FString> GetTokensFromTrimmedCode(FString& InTrimmedCode);

	/*
		Once the query was done, it will send the info in game thread
		@InSuggestions			- InSuggestions to be send
		@InRequesterFileName	- Send back the file which requested that query
	*/
	void OnSendSuggestion(TArray<FSuggestion>& InSuggestions, const FString& InRequesterFileName);

	//~ Holds the user registered python modules
	TArray<FString> UserRegisteredModules;

	//~ Simple list with all favorites queries
	TArray<FString> Favorites;

	/** Holds the thread object. */
	FRunnableThread* Thread;
	bool Stopping;


};

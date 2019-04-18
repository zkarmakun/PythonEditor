// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HAL/RunnableThread.h"
#include "Runtime/Core/Public/HAL/Runnable.h"
#include "Queue.h"

struct FModuleDescription
{
	FString Name;
	FString Version;
	FString Description;

	//Json info
	FString Author;
	FString AuthorEmail;
	FString FullDescription;
	FString HomePage;
	FString Licence;
	FString LastVersion;

	void GetInfoFromJson(const FString& Json);

	FModuleDescription(){
		Author = AuthorEmail = FullDescription = HomePage = Licence = LastVersion = FString();
	}

	FModuleDescription(const FString& InName, const FString& InVersion, const FString& InDescription)
	{
		Name = InName;
		Version = InVersion;
		Description = InDescription;

		Author = AuthorEmail = FullDescription = HomePage = Licence = LastVersion = FString();
	}
};


DECLARE_MULTICAST_DELEGATE_OneParam(FOnModulesFound, const TArray<FModuleDescription>&)

/**
 * 
 */
class FPipWorker : public FRunnable
{
public:
	FOnModulesFound OnModulesFound;

public:
	FPipWorker();
	~FPipWorker();

	void SearchForModules(const FString& TrimWord);

	//~ FRunnable
	virtual bool Init() override;
	virtual uint32 Run() override;
	virtual void Stop() override;
	virtual void Exit() override {};
	//

private:
	TQueue<FString> QueueSearch;

	void PipSearch(const FString& Word);

private:
	

	/** Holds the thread object. */
	FRunnableThread* Thread;
	bool Stopping;
};

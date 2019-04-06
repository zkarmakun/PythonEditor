//Copyright 2019, Jorge Calleros Ramirez (Karma), All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Text/SlateTextRun.h"

class FTabTextRun : public FSlateTextRun
{
public:
	static TSharedRef< FTabTextRun > Create(const FRunInfo& InRunInfo, const TSharedRef< const FString >& InText, const FTextBlockStyle& Style, const FTextRange& InRange, int32 NumSpacesPerTab);

public:
	virtual FVector2D Measure(int32 StartIndex, int32 EndIndex, float Scale, const FRunTextContext& TextContext) const override;

protected:
	FTabTextRun(const FRunInfo& InRunInfo, const TSharedRef< const FString >& InText, const FTextBlockStyle& InStyle, const FTextRange& InRange, int32 InNumSpacesPerTab);

private:
	int32 NumSpacesPerTab;

	float TabWidth;

	float SpaceWidth;
};

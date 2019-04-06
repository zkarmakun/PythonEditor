//Copyright 2019, Jorge Calleros Ramirez (Karma), All rights reserved.

#pragma once

#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Widgets/SCompoundWidget.h"
#include "CoreMinimal.h"

class UPyMenu;
class IDetailsView;

class SPyMenu : public SCompoundWidget
{
	SLATE_BEGIN_ARGS(SPyMenu)
	{}

	SLATE_ARGUMENT(TWeakObjectPtr<UPyMenu>, PyMenu)
	SLATE_ARGUMENT(TSharedPtr<SWindow>, Window)
	SLATE_END_ARGS()

public:
	/** Widget constructor */
	void Construct(const FArguments& Args);

private:
	FReply OnRun();
	FReply OnApply();
	FReply OnCancel();


private:
	TWeakObjectPtr<UPyMenu> PyMenu;
	TSharedPtr<IDetailsView> DetailsView;
	TSharedPtr<SWindow> Window;
};

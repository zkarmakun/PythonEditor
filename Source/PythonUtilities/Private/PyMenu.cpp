//Copyright 2019, Jorge Calleros Ramirez (Karma), All rights reserved.

#include "PyMenu.h"
#include "SButton.h"
#include "SWindow.h"
#include "MultiBoxBuilder.h"
#include "SlateApplication.h"
#include "SPyMenu.h"
#include "Runtime/CoreUObject/Public/UObject/UObjectHash.h"

#define LOCTEXT_NAMESPACE "UPyMenu"


UPyMenu* UPyMenu::Get()
{
	TArray<UClass*> PythonBridgeClasses;
	GetDerivedClasses(UPyMenu::StaticClass(), PythonBridgeClasses);
	int32 NumClasses = PythonBridgeClasses.Num();
	if (NumClasses > 0)
	{
		return Cast<UPyMenu>(PythonBridgeClasses[NumClasses - 1]->GetDefaultObject());
	}
	return nullptr;
}

void UPyMenu::Run_Implementation()
{
	UE_LOG(LogTemp, Log, TEXT("override run method"));
}

void UPyMenu::Setup_Implementation()
{

}

void UPyMenu::OpenMenu(UPyMenu* Menu, FString Tittle /*= TEXT("Py Tool")*/, int32 Width /*= 320*/, int32 height /*= 200*/)
{
	if (!Menu) return;

	FString WindowTittle = Tittle;
	if (WindowTittle.IsEmpty())
	{
		WindowTittle = TEXT("PyTool");
	}

	int32 WinWidth = FMath::Clamp(Width, 100, TNumericLimits<int32>().Max());
	int32 WinHeight = FMath::Clamp(height, 100, TNumericLimits<int32>().Max());

	TSharedPtr<SWindow> Window = SNew(SWindow)
		.Title(FText::FromString(WindowTittle))
		.ClientSize(FVector2D(WinWidth, WinHeight))
		.SupportsMinimize(false)
		.SupportsMaximize(false);

	Window->SetContent(SNew(SPyMenu)
		.PyMenu(Menu)
		.Window(Window));

	FSlateApplication & SlateApp = FSlateApplication::Get();
	SlateApp.AddWindow(Window.ToSharedRef(), true);
}

#undef LOCTEXT_NAMESPACE
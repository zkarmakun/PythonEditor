//Copyright 2019, Jorge Calleros Ramirez (Karma), All rights reserved.

#include "ScriptShelfs.h"
#include "Developer/DesktopPlatform/Public/IDesktopPlatform.h"
#include "Developer/DesktopPlatform/Public/DesktopPlatformModule.h"
#include "Framework/Application/SlateApplication.h"
#include "Runtime/Core/Public/Misc/FileHelper.h"
#include "Runtime/ImageWrapper/Public/IImageWrapperModule.h"
#include "Runtime/ImageWrapper/Public/IImageWrapper.h"
#include "Runtime/Engine/Public/ImageUtils.h"
#include "PythonEditor.h"
#include "Serialization/MemoryReader.h"
#include "Serialization/ObjectAndNameAsStringProxyArchive.h"

UScriptShelfs::UScriptShelfs()
{
}

int32 UScriptShelfs::FindShelf(const FName& InID)
{
	for (int32 i = 0; i < Tabs.Num(); i++)
	{
		if (InID == Tabs[i].TabId)
		{
			return i;
		}
	}
	return -1;
}


int32 UScriptShelfs::FindButton(int32& OutShelfIndex, const FName& ShelfID, const FName& ButtonID)
{
	OutShelfIndex = FindShelf(ShelfID);
	if (Tabs.IsValidIndex(OutShelfIndex))
	{
		for (int32 i = 0; i < Tabs[OutShelfIndex].Buttons.Num(); i++)
		{
			if (ButtonID == Tabs[OutShelfIndex].Buttons[i].ID)
			{
				return i;
			}
		}
	}
	return -1;
}

bool UScriptShelfs::ContainButton(const int32& IdIndex, const FShelfButtonInfo& ButtonInfo)
{
	if (Tabs.IsValidIndex(IdIndex))
	{
		for (int32 i = 0; Tabs[IdIndex].Buttons.Num(); i++)
		{
			if (Tabs[IdIndex].Buttons[i].ID.IsEqual(ButtonInfo.ID))
			{
				return true;
			}
		}
	}
	return false;
}

FString UScriptShelfs::GetSavedShelfFilePath() const
{
	return FPythonEditorModule::GetScriptSavedDire() + TEXT("Shelf.sav");
}

void UScriptShelfs::SaveShelfs()
{
	TArray<uint8> ObjectBytes;
	FMemoryWriter MemoryWriter(ObjectBytes, true);

	FObjectAndNameAsStringProxyArchive Ar(MemoryWriter, false);
	this->Serialize(Ar);

	if (FFileHelper::SaveArrayToFile(ObjectBytes, *GetSavedShelfFilePath()))
	{
		UE_LOG(LogTemp, Warning, TEXT("Save shelfs path: %s"), *GetSavedShelfFilePath());
	}
}

void UScriptShelfs::LoadShelfs()
{
 	TArray<uint8> ObjectBytes;
	if (FFileHelper::LoadFileToArray(ObjectBytes, *GetSavedShelfFilePath()))
	{
		FMemoryReader Reader(ObjectBytes);
		FObjectAndNameAsStringProxyArchive Ar(Reader, false);
		this->Serialize(Ar);
		UE_LOG(LogTemp, Warning, TEXT("load shelfs path: %s"), *GetSavedShelfFilePath());
	}
}

bool UScriptShelfs::RemoveShelf(const FName& InID)
{
	if (Tabs.Num() == 1)
	{
		return false;
	}

	int32 Index = FindShelf(InID);
	if (Tabs.IsValidIndex(Index))
	{
		Tabs.RemoveAt(Index);
		LastSelectionID = 0;
		return true;
	}
	return false;
}

bool UScriptShelfs::ContainsShelf(const FName& InID)
{
	return FindShelf(InID) != -1;
}

bool UScriptShelfs::CreateNewShelf(const FName& NewID)
{
	if (!ContainsShelf(NewID))
	{
		FShelfTab NewShelf(NewID);
		Tabs.Add(NewShelf);
		LastSelectionID = Tabs.Num() - 1;
		return true;
	}
	return false;
}

bool UScriptShelfs::RenameShelf(const FName& OldID, const FName& NewId)
{
	if (ContainsShelf(NewId))
	{
		return false;
	}

	int32 Index = FindShelf(OldID);
	if (Tabs.IsValidIndex(Index))
	{
		Tabs[Index].TabId = NewId;
		return true;
	}
	return false;
}

bool UScriptShelfs::ShiftLeft(const FName& InID)
{
	int32 Index = FindShelf(InID);
	int32 ShiftIndex = Index - 1;
	if (Tabs.IsValidIndex(Index) && Tabs.IsValidIndex(ShiftIndex))
	{
		Tabs.Swap(Index, ShiftIndex);
		LastSelectionID = ShiftIndex;
		return true;
	}
	return false;
}

bool UScriptShelfs::ShiftRight(const FName& InID)
{
	int32 Index = FindShelf(InID);
	int32 ShiftIndex = Index + 1;
	if (Tabs.IsValidIndex(Index) && Tabs.IsValidIndex(ShiftIndex))
	{
		Tabs.Swap(Index, ShiftIndex);
		LastSelectionID = ShiftIndex;
		return true;
	}
	return false;
}

bool UScriptShelfs::AddButtonToShelf(const FName& InID, const FShelfButtonInfo& ButtonInfo)
{
	int32 Index = FindShelf(InID);
	if (Tabs.IsValidIndex(Index))
	{
		Tabs[Index].Buttons.Add(ButtonInfo);
		return true;
	}
	return false;
}

bool UScriptShelfs::RemoveButtonFromShelf(const FName& ShelfID, const FName& ButtonID)
{
	int32 ShelfIndex = -1;
	int32 ButtonIndex = FindButton(ShelfIndex, ShelfID, ButtonID);
	if (ShelfIndex != -1 && ButtonIndex != -1)
	{
		Tabs[ShelfIndex].Buttons.RemoveAt(ButtonIndex);
		return true;
	}
	return false;
}

bool UScriptShelfs::RenameButton(const FName& ShelfID, const FName& ButtonID, const FString& DisplayName)
{
	int32 ShelfIndex = -1;
	int32 ButtonIndex = FindButton(ShelfIndex, ShelfID, ButtonID);
	if (ShelfIndex != -1 && ButtonIndex != -1)
	{
		Tabs[ShelfIndex].Buttons[ButtonIndex].DisplayName = DisplayName;
		return true;
	}
	return false;
}

bool UScriptShelfs::ShiftButtonLeft(const FName& ShelfID, const FName& ButtonID)
{
	int32 ShelfIndex = -1;
	int32 ButtonIndex = FindButton(ShelfIndex, ShelfID, ButtonID);
	int32 Shift = ButtonIndex - 1;
	if (ShelfIndex != -1 && Tabs[ShelfIndex].Buttons.IsValidIndex(ButtonIndex) && Tabs[ShelfIndex].Buttons.IsValidIndex(Shift))
	{
		Tabs[ShelfIndex].Buttons.Swap(ButtonIndex, Shift);
		return true;
	}
	return false;
}

bool UScriptShelfs::ShiftButtonRight(const FName& ShelfID, const FName& ButtonID)
{
	int32 ShelfIndex = -1;
	int32 ButtonIndex = FindButton(ShelfIndex, ShelfID, ButtonID);
	int32 Shift = ButtonIndex + 1;
	if (ShelfIndex != -1 && Tabs[ShelfIndex].Buttons.IsValidIndex(ButtonIndex) && Tabs[ShelfIndex].Buttons.IsValidIndex(Shift))
	{
		Tabs[ShelfIndex].Buttons.Swap(ButtonIndex, Shift);
		return true;
	}
	return false;
}

bool UScriptShelfs::SetButtonIcon(const FName& ShelfID, const FName& ButtonID)
{
	int32 ShelfIndex = -1;
	int32 ButtonIndex = FindButton(ShelfIndex, ShelfID, ButtonID);

	if (!Tabs.IsValidIndex(ShelfIndex))
	{
		return false;
	}

	if (!Tabs[ShelfIndex].Buttons.IsValidIndex(ButtonIndex))
	{
		return false;
	}

	IDesktopPlatform* DesktopPlatform = FDesktopPlatformModule::Get();
	const void* ParentWindowWindowHandle = FSlateApplication::Get().FindBestParentWindowHandleForDialogs(nullptr);
	TArray<FString> Files;

	DesktopPlatform->OpenFileDialog(
		ParentWindowWindowHandle,
		TEXT("Choose image for icon"),
		FPaths::ProjectDir(),
		TEXT(""),
		TEXT("*.png"),
		EFileDialogFlags::None,
		Files);

	// To DO Compress here
	if (Files.IsValidIndex(0))
	{
		TArray<uint8> FileData;
		FFileHelper::LoadFileToArray(FileData, *Files[0]);
		
		IImageWrapperModule& ImageWrapperModule = FModuleManager::LoadModuleChecked<IImageWrapperModule>(FName("ImageWrapper"));

		EImageFormat ImageFormat = ImageWrapperModule.DetectImageFormat(FileData.GetData(), FileData.Num());
		if (ImageFormat == EImageFormat::Invalid)
		{
			UE_LOG(LogTemp, Error, TEXT("UScriptShelfs::SetButtonIcon Invalid Image Format"));
			return false;
		}

		// Create an image wrapper for the detected image format
		TSharedPtr<IImageWrapper> ImageWrapper = ImageWrapperModule.CreateImageWrapper(ImageFormat);
		if (!ImageWrapper.IsValid())
		{
			UE_LOG(LogTemp, Error, TEXT("UScriptShelfs::SetButtonIcon Invalid Image wrapper"));
			return false;
		}

		// Decompress the image data
		const TArray<uint8>* RawData = nullptr;
		ImageWrapper->SetCompressed(FileData.GetData(), FileData.Num());
		ImageWrapper->GetRaw(ERGBFormat::BGRA, 8, RawData);
		if (RawData == nullptr)
		{
			UE_LOG(LogTemp, Error, TEXT("UScriptShelfs::SetButtonIcon Invalid Data"));
			return false;
		}

		//get in color just to be able to resize sad but true
		TArray<FColor> Bytes;
		for (int32 i = 0; i < (ImageWrapper->GetWidth() * ImageWrapper->GetHeight()); ++i)
		{
			FColor color;
			color.R = RawData->GetData()[4 * i + 2];
			color.G = RawData->GetData()[4 * i + 1];
			color.B = RawData->GetData()[4 * i + 0];
			color.A = RawData->GetData()[4 * i + 3];
			Bytes.Add(color);
		}

		//resize to 30, icon size 
		TArray<FColor> MiniImage;
		FImageUtils::ImageResize(ImageWrapper->GetWidth(), ImageWrapper->GetHeight(), Bytes, 40, 40, MiniImage, false);

		//Added info to the real icon
		Tabs[ShelfIndex].Buttons[ButtonIndex].Icon.Empty();
		for (int32 i = 0; i < MiniImage.Num(); i++)
		{
			Tabs[ShelfIndex].Buttons[ButtonIndex].Icon.Add(MiniImage[i].B);
			Tabs[ShelfIndex].Buttons[ButtonIndex].Icon.Add(MiniImage[i].G);
			Tabs[ShelfIndex].Buttons[ButtonIndex].Icon.Add(MiniImage[i].R);
			Tabs[ShelfIndex].Buttons[ButtonIndex].Icon.Add(MiniImage[i].A);
		}
		return true;
	}
	return false;
}


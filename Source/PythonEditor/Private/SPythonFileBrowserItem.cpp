//Copyright 2019, Jorge Calleros Ramirez (Karma), All rights reserved.

#include "SPythonFileBrowserItem.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "Misc/FileHelper.h"
#include "HAL/PlatformFilemanager.h"
#include "Widgets/Images/SImage.h"
#include "PythonEditorToolKit.h"
#include "SPythonFileBrowser.h"
#include "PythonFileDragDrop.h"
#include "PythonEditorStyle.h"


FReply SPythonFileBrowserItem::OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (MouseEvent.GetEffectingButton() == EKeys::LeftMouseButton)
	{
		PythonFileBrowser->ClearSelection();
		Select(true);		
		OnSelectionChanged.ExecuteIfBound(ScriptTree);
		return FReply::Handled().DetectDrag(SharedThis(this), EKeys::LeftMouseButton).CaptureMouse(SharedThis(this));
	}
	else if (MouseEvent.GetEffectingButton() == EKeys::RightMouseButton)
	{
		PythonFileBrowser->ClearSelection();
		Select(true);
		OnSelectionChanged.ExecuteIfBound(ScriptTree);
		PythonFileBrowser->CreateContextMenuOpt(ScriptTree->Type);
		return FReply::Handled();
	}
	return FReply::Unhandled();
}

FReply SPythonFileBrowserItem::OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (MouseEvent.GetEffectingButton() == EKeys::LeftMouseButton && MyGeometry.IsUnderLocation(MouseEvent.GetScreenSpacePosition()))
	{
		return FReply::Handled().ReleaseMouseCapture();
	}
	return FReply::Handled().ReleaseMouseCapture();;
}

FReply SPythonFileBrowserItem::OnDragDetected(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (MouseEvent.IsMouseButtonDown(EKeys::LeftMouseButton))
	{
		TSharedRef<FPythonFileDragDrop> Operation = FPythonFileDragDrop::New(ScriptTree->Name, FPythonEditorToolKit::Get()->GetCode(ScriptTree));
		return FReply::Handled().BeginDragDrop(Operation);
	}
	return FReply::Unhandled();
}


void SPythonFileBrowserItem::Construct(const FArguments& Args)
{
	ScriptTree = Args._InScriptTree;
	PythonFileBrowser = Args._InOwner;
	OnSelectionChanged = Args._OnSelectionChanged;

	const FSlateBrush* Brush = ScriptTree->Type == EScriptTreeType::File ? FPythonEditorStyle::Get().GetBrush("PythonEditor.FileIcon") : FPythonEditorStyle::Get().GetBrush("PythonEditor.FolderIcon");

	ChildSlot[
		SAssignNew(SelectedBorder, SBorder)
		.BorderImage(FPythonEditorStyle::Get().GetBrush("PythonEditor.Selected"))
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			.HAlign(HAlign_Left)
			.VAlign(VAlign_Center)
			.Padding(1.0f)
			.AutoWidth()
			[
				SNew(SImage)
				.Image(Brush)
			]
			+ SHorizontalBox::Slot()
			.HAlign(HAlign_Left)
			.VAlign(VAlign_Center)
			.Padding(FMargin(5,1,1,1))
			.AutoWidth()
			.FillWidth(1.0f)
			[
				SNew(STextBlock)
				.Text(FText::FromString(ScriptTree->Name))
			]
		]
	];

	Select(false);
}

void SPythonFileBrowserItem::Select(const bool& bSelect)
{
	bIsSelected = bSelect;
	if (bSelect)
	{
		SelectedBorder->SetBorderBackgroundColor(FLinearColor::White);
	}
	else
	{
		SelectedBorder->SetBorderBackgroundColor(FLinearColor::Transparent);
	}
}

bool SPythonFileBrowserItem::IsSame(TSharedPtr<FPyScriptTree> Compare)
{
	return (Compare->Name == ScriptTree->Name && Compare->Path == ScriptTree->Path);
}

TSharedPtr<FPyScriptTree> SPythonFileBrowserItem::GetItem() const
{
	return ScriptTree;
}

//Copyright 2019, Jorge Calleros Ramirez (Karma), All rights reserved.

#include "SShelfHolder.h"
#include "Widgets/SBoxPanel.h"
#include "SShelfButton.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "Framework/Application/SlateApplication.h"
#include "Widgets/Layout/SBorder.h"
#include "PythonEditorStyle.h"
#include "PythonFileDragDrop.h"
#include "SShelfButton.h"
#include "PythonShelfToolkit.h"
#include "PythonEditor.h"

void SShelfHolder::Construct(const FArguments& InArgs)
{
	Shelf = InArgs._Shelf;

	ChildSlot[
		SNew(SBorder)
		.BorderImage(FPythonEditorStyle::Get().GetBrush("PythonEditor.BG"))
		[
			SAssignNew(Container, SHorizontalBox)
		]
	];

	UpdateButtons();
}

void SShelfHolder::OnDragEnter(const FGeometry& MyGeometry, const FDragDropEvent& DragDropEvent)
{
	// To Do
	TSharedPtr<FPythonFileDragDrop> Operation = DragDropEvent.GetOperationAs<FPythonFileDragDrop>();
	if (Operation.IsValid())
	{

	}
}

void SShelfHolder::OnDragLeave(const FDragDropEvent& DragDropEvent)
{
	// To Do
	TSharedPtr<FPythonFileDragDrop> Operation = DragDropEvent.GetOperationAs<FPythonFileDragDrop>();
	if (Operation.IsValid())
	{

	}
}

FReply SShelfHolder::OnDrop(const FGeometry& MyGeometry, const FDragDropEvent& DragDropEvent)
{
	TSharedPtr<FPythonFileDragDrop> Operation = DragDropEvent.GetOperationAs<FPythonFileDragDrop>();
	if (Operation.IsValid())
	{
		FShelfButtonInfo ButtonInfo(Operation->FileName);
		ButtonInfo.Code = Operation->Code;
		ButtonInfo.ID = FName(*FGuid::NewGuid().ToString()); // Create a guid because you can have same script names
		FPythonShelfToolkit::Get()->AddButtonToShelf(Shelf->TabId, ButtonInfo);
		return FReply::Handled();
	}
	return FReply::Unhandled();
}

void SShelfHolder::UpdateButtons()
{
	Container->ClearChildren();
	for (FShelfButtonInfo& button : Shelf->Buttons)
	{
		SHorizontalBox::FSlot& PosSlot = Container->AddSlot()
			.HAlign(HAlign_Left)
			.VAlign(VAlign_Top)
			.AutoWidth()
			.Padding(3);
		PosSlot[
			SNew(SShelfButton)
				.ShelfButton(&button)
				.ShelfOwnerID(Shelf->TabId)
		];
	}
}


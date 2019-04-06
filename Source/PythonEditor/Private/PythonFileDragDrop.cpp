//Copyright 2019, Jorge Calleros Ramirez (Karma), All rights reserved.

#include "PythonFileDragDrop.h"
#include "PythonEditorStyle.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Images/SImage.h"
#include "Widgets/SWindow.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/Text/STextBlock.h"

void FPythonFileDragDrop::OnDragged(const class FDragDropEvent& DragDropEvent)
{
	if (CursorDecoratorWindow.IsValid())
	{
		CursorDecoratorWindow->MoveWindowTo(DragDropEvent.GetScreenSpacePosition() - 20 * 0.5f);
	}
}

TSharedPtr<SWidget> FPythonFileDragDrop::GetDefaultDecorator() const
{
	return SNew(SBox)
		.WidthOverride(120)
		.HeightOverride(20)
		[
			SNew(SBorder).Cursor(EMouseCursor::GrabHandClosed)
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
				.HAlign(HAlign_Left)
				[
					SNew(SImage).Image(FPythonEditorStyle::Get().GetBrush("PythonEditor.FileIcon"))
				]
				+ SHorizontalBox::Slot()
				.HAlign(HAlign_Left)
				.AutoWidth()
				[
					SNew(STextBlock).Text(FText::FromString(FileName))
				]
			]
		];
}

TSharedRef<FPythonFileDragDrop> FPythonFileDragDrop::New(const FString& Name, const FString& InCode)
{
	TSharedRef<FPythonFileDragDrop> Operation = MakeShareable(new FPythonFileDragDrop);

	Operation->FileName = Name;
	Operation->Code = InCode;

	Operation->Construct();
	return Operation;
}

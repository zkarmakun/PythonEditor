//Copyright 2019, Jorge Calleros Ramirez (Karma), All rights reserved.

#pragma once
#include "Runtime/SlateCore/Public/Input/DragAndDrop.h"
#include "CoreMinimal.h"

/**
 * 
 */
class FPythonFileDragDrop : public FDragDropOperation
{
public:
	DRAG_DROP_OPERATOR_TYPE(FPythonFileDragDrop, FDragDropOperation)

	virtual void OnDragged(const class FDragDropEvent& DragDropEvent) override;

	/** Gets the widget that will serve as the decorator unless overridden. If you do not override, you will have no decorator */
	virtual TSharedPtr<SWidget> GetDefaultDecorator() const override;

	static TSharedRef<FPythonFileDragDrop> New(const FString& Name, const FString& InCode);


	FString FileName;
	FString Code;
};

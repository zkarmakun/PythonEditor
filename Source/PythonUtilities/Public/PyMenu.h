//Copyright 2019, Jorge Calleros Ramirez (Karma), All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "PyMenu.generated.h"


/*
 The purpose of this class is generate children in Python code, and python you can add variables to your class with the
 reflection system, it will automatically generate a menu for you with the IDetailView class
 You can access every variable in the python's way:

 #example class
 class MyMenu(unreal.PyMenu)
	
	myint = unreal.uproperty(int)

	@unreal.ufunction(Override = True)
	def run(self):
		#here goes your logic, you can access your variables like: self.myint

*/

UCLASS(Blueprintable)
class PYTHONUTILITIES_API UPyMenu : public UObject
{
	GENERATED_BODY()
public:



	//~ Boilerplate code to retrieve the first uclass generated with python
	UFUNCTION(BlueprintCallable, Category = Python, meta = (DevelopmentOnly))
		static UPyMenu* Get();
	
	//~ Empty function to be overridden in python
	UFUNCTION(BlueprintNativeEvent, Category = "Python menu", meta = (DevelopmentOnly))
		void Run();
		virtual void Run_Implementation();

	//~ Empty function to be overridden in python
	UFUNCTION(BlueprintNativeEvent, Category = "Python menu", meta = (DevelopmentOnly))
		void Setup();
		virtual void Setup_Implementation();

	//~ Open a menu passing one instance of UPyMenu object type
	UFUNCTION(BlueprintCallable, Category = "Python Menu", meta = (DevelopmentOnly))
		static void OpenMenu(UPyMenu* Menu, FString Tittle = TEXT("Py Tool"), int32 Width = 320, int32 height = 200);


};

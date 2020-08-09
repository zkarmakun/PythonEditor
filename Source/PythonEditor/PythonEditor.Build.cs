// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class PythonEditor : ModuleRules
{
	public PythonEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
				"Runtime/SlateCore/Public/Styling",
				"Runtime/SlateCore/Public/Widgets",
				"Runtime/SlateCore/Public/Widgets/Images",
				"Runtime/SlateCore/Public/Fonts",

				"Runtime/Slate/Public/Widgets",
				"Runtime/Slate/Public/Widgets/Text",
				"Runtime/Slate/Public/Widgets/Input",
				"Runtime/Slate/Public/Widgets/Layout",
				"Runtime/Slate/Public/Framework/Application",

				"Runtime/Json/Public/Dom",
				"Runtime/Core/Public/HAL",
				"Runtime/Core/Public/Misc",
				"Runtime/Core/Public/Containers",
				"Runtime/Json/Public/Serialization",
				"Runtime/Online/HTTP/Public/Interfaces",
				"Runtime/Projects/Public/Interfaces",

			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"Projects",
				"InputCore",
				"UnrealEd",
				"LevelEditor",
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
                "Kismet",
                "EditorStyle",
                "Python",
                "PythonUtilities",
                "WebBrowser",
                "HTTP",
                "Json",
				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}

// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class PythonUtilities : ModuleRules
{
	public PythonUtilities(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
				"Runtime/SlateCore/Public/Styling",
				"Runtime/SlateCore/Public/Widgets",
				"Runtime/SlateCore/Public/Widgets/Images",
				
				"Runtime/Slate/Public/Widgets",
				"Runtime/Slate/Public/Widgets/Text",
				"Runtime/Slate/Public/Widgets/Input",
				"Runtime/Slate/Public/Widgets/Layout",
				"Runtime/Slate/Public/Framework/Views",
				"Runtime/Slate/Public/Framework/MultiBox",
				"Runtime/Slate/Public/Framework/Application",

				"Runtime/Core/Public/Modules",
				"Runtime/CoreUObject/Public/UObject",
				"Editor/UnrealEd/Public/Kismet2",
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
                "Core",
				"InputCore",
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);

        if (Target.bBuildEditor)//we only want this to be included for editor builds but not packaged builds
        {
            PublicDependencyModuleNames.AddRange(
                new string[] {
                    "UnrealEd",
                    "EditorStyle",
                    "LevelEditor",
                    "PropertyEditor",
                    "ContentBrowser",
                    "BlueprintGraph",
                    "Kismet",
                    "Python",
                    "Projects",
                }
            );
        }
    }
}

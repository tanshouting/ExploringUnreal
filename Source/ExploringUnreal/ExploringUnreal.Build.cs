// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.IO;

public class ExploringUnreal : ModuleRules
{
	private string ModulePath
	{
	    get
	    {
	        return ModuleDirectory;
	    }
	}

	private string ThirdPartyPath
	{
	    get
	    {
	        return Path.GetFullPath(Path.Combine(ModulePath, "../../ThirdParty"));
	    }
	}
	public ExploringUnreal(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" ,"Slate","SlateCore"});

		PublicDependencyModuleNames.AddRange(new string[] { "AssetRegistry" });//TODO

		PrivateDependencyModuleNames.AddRange(new string[] { "UnrealEd" });

		//Delay LinkDLL Code
		//bEnableUndefinedIdentifierWarnings = false;
		//PublicIncludePaths.Add(Path.Combine(ThirdPartyPath, "include"));
		//PublicAdditionalLibraries.Add(Path.Combine(ThirdPartyPath, "lib", "DLL2.lib"));
		//PublicDelayLoadDLLs.Add("DLL2.dll");
		//PublicDelayLoadDLLs.Add(Path.Combine(ThirdPartyPath, "DLL"));
		//RuntimeDependencies.Add(new RuntimeDependency(Path.Combine(ThirdPartyPath, "lib", "DLL2.dll")));
	}
}

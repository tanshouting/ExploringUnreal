// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "EditorExtend.h"
#include "EditorExtendStyle.h"
#include "EditorExtendCommands.h"
#include "LevelEditor.h"
#include "Modules/ModuleManager.h"
#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "Engine/TextureRenderTarget2D.h"
#include "EditorExtendSlate.h"

static const FName EditorExtendTabName("EditorExtend");

#define LOCTEXT_NAMESPACE "FEditorExtendModule"

void FEditorExtendModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FEditorExtendStyle::Initialize();
	FEditorExtendStyle::ReloadTextures();

	FEditorExtendCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FEditorExtendCommands::Get().OpenPluginWindow,
		FExecuteAction::CreateRaw(this, &FEditorExtendModule::PluginButtonClicked),
		FCanExecuteAction());
		
	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	
	{
		TSharedPtr<FExtender> MenuExtender = MakeShareable(new FExtender());
		MenuExtender->AddMenuExtension("WindowLayout", EExtensionHook::After, PluginCommands, FMenuExtensionDelegate::CreateRaw(this, &FEditorExtendModule::AddMenuExtension));

		LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(MenuExtender);
	}
	
	{
		TSharedPtr<FExtender> ToolbarExtender = MakeShareable(new FExtender);
		ToolbarExtender->AddToolBarExtension("Settings", EExtensionHook::After, PluginCommands, FToolBarExtensionDelegate::CreateRaw(this, &FEditorExtendModule::AddToolbarExtension));
		
		LevelEditorModule.GetToolBarExtensibilityManager()->AddExtender(ToolbarExtender);
	}
	
	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(EditorExtendTabName, FOnSpawnTab::CreateRaw(this, &FEditorExtendModule::OnSpawnPluginTab))
		.SetDisplayName(LOCTEXT("FEditorExtendTabTitle", "EditorExtend"))
		.SetMenuType(ETabSpawnerMenuType::Hidden);
}

void FEditorExtendModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	FEditorExtendStyle::Shutdown();

	FEditorExtendCommands::Unregister();

	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(EditorExtendTabName);
}

void FEditorExtendModule::SetTextureRenderTarget2D(UTextureRenderTarget2D* inTexture2D)
{
	TextureRenderTarget2D = inTexture2D;
}

TWeakObjectPtr<UTextureRenderTarget2D> FEditorExtendModule::GetTextureRenderTarget2D()
{
	return TextureRenderTarget2D;
}

TSharedRef<SDockTab> FEditorExtendModule::OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs)
{
	FText WidgetText = FText::Format(
		LOCTEXT("WindowWidgetText", "Add code to {0} in {1} to override this window's contents"),
		FText::FromString(TEXT("FEditorExtendModule::OnSpawnPluginTab")),
		FText::FromString(TEXT("EditorExtend.cpp"))
		);

	return SNew(SDockTab)
		.TabRole(ETabRole::NomadTab)
		[
			// Put your tab content here!
			SNew(SBox)
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			[
				SNew(STextBlock)
				.Text(WidgetText)
			]
		];
}

void FEditorExtendModule::PluginButtonClicked()
{
	//FGlobalTabmanager::Get()->InvokeTab(EditorExtendTabName);
	EditorExtendSlate::Initialization();

}

void FEditorExtendModule::AddMenuExtension(FMenuBuilder& Builder)
{
	Builder.AddMenuEntry(FEditorExtendCommands::Get().OpenPluginWindow);
}


void FEditorExtendModule::AddToolbarExtension(FToolBarBuilder& Builder)
{
	Builder.AddToolBarButton(FEditorExtendCommands::Get().OpenPluginWindow);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FEditorExtendModule, EditorExtend)
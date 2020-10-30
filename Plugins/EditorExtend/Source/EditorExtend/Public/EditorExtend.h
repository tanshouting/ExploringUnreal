// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "IEditorExtend.h"

class FToolBarBuilder;
class FMenuBuilder;
class UTextureRenderTarget2D;

class FEditorExtendModule : public IEditorExtend
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	virtual void SetTextureRenderTarget2D(UTextureRenderTarget2D* inTexture2D) override;
	virtual TWeakObjectPtr<UTextureRenderTarget2D> GetTextureRenderTarget2D() override;
	
	/** This function will be bound to Command (by default it will bring up plugin window) */
	void PluginButtonClicked();
	
private:

	void AddToolbarExtension(FToolBarBuilder& Builder);
	void AddMenuExtension(FMenuBuilder& Builder);

	TSharedRef<class SDockTab> OnSpawnPluginTab(const class FSpawnTabArgs& SpawnTabArgs);

private:
	TSharedPtr<class FUICommandList> PluginCommands;
	TWeakObjectPtr<UTextureRenderTarget2D> TextureRenderTarget2D;
};
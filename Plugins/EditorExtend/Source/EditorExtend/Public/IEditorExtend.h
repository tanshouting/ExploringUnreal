#pragma once
#include "Modules/ModuleInterface.h"
#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
class UTextureRenderTarget2D;
class IEditorExtend :public IModuleInterface
{
public:
	static FORCEINLINE IEditorExtend& Get()
	{
		return FModuleManager::GetModuleChecked<IEditorExtend>("EditorExtend");
	}
public:
	virtual TWeakObjectPtr<UTextureRenderTarget2D> GetTextureRenderTarget2D() =0;
	virtual void SetTextureRenderTarget2D(UTextureRenderTarget2D* inTexture2D) = 0;

};
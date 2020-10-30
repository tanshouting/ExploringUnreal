// Fill out your copyright notice in the Description page of Project Settings.

#include "PCSceneCaptureComponent2D.h"
#include "IEditorExtend.h"




void UPCSceneCaptureComponent2D::Activate(bool bReset)
{
	Super::Activate(bReset);
	IEditorExtend::Get().SetTextureRenderTarget2D(this->TextureTarget);
}

void UPCSceneCaptureComponent2D::OnRegister()
{
	Super::OnRegister();
	IEditorExtend::Get().SetTextureRenderTarget2D(this->TextureTarget);
}

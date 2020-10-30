// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Core.h"
#include "UnrealClient.h"
#include "SCompoundWidget.h"
#include "Runtime/Slate/Public/Widgets/Input/SComboBox.h"

/**
 * 
 */
class SViewport;
class FSceneViewport;
class FViewport;
class FPlaySceneViewportClient : public FViewportClient
{
public: 
	virtual void Draw(FViewport* Viewport, FCanvas* Canvas)override;
	virtual bool InputAxis(FViewport* Viewport, int32 ControllerId, FKey Key, float Delta, float DeltaTime, int32 NumSamples = 1, bool bGamepad = false) override;
	virtual bool InputKey(FViewport* Viewport, int32 ControllerId, FKey Key, EInputEvent Event, float AmountDepressed = 1.f, bool bGamepad = false) override;
	virtual bool InputGesture(FViewport* Viewport, EGestureEvent GestureType, const FVector2D& GestureDelta, bool bIsDirectionInvertedFromDevice) override;
	virtual UWorld* GetWorld() const override { return nullptr; }
	virtual void RedrawRequested(FViewport* Viewport) override { Viewport->Draw(); }
};
class EditorExtendViewport :public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(EditorExtendViewport) { }
	SLATE_END_ARGS()
public:
	void Construct(const FArguments& InArgs);
private:
	TSharedPtr<SViewport> Viewport;
	TSharedPtr<FSceneViewport> SceneViewport;
	TSharedPtr<FPlaySceneViewportClient> EditorExtendViewportClient;
public:
	virtual void Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime) override;
};
class EDITOREXTEND_API EditorExtendSlate
{
public:
	EditorExtendSlate();
	~EditorExtendSlate();
	static void Initialization();
	static void ShutDown();
public:
	TSharedPtr<SWindow> EditorExtendWindow;
	int WindowX;
	int WindowY;
	FOnWindowClosed Indelegate;
	void OnWindowClosed(const TSharedRef<SWindow>& window);//ΪʲôTshardRef<SWindow>
	TSharedPtr<EditorExtendViewport> playSceneViewport;
	static TSharedPtr<EditorExtendSlate> editorextendSlate;

};

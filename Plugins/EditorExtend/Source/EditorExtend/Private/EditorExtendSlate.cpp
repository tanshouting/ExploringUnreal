// Fill out your copyright notice in the Description page of Project Settings.

#include "EditorExtendSlate.h"
#include "SlateApplication.h"
#include "Engine.h"
#include "Runtime/Engine/Public/Slate/SceneViewport.h"
#include "Runtime/Engine/Classes/Engine/TextureRenderTarget2D.h"
#include "SViewport.h"
#include "SToolTip.h"
#include "SWindow.h"
#include "IEditorExtend.h"


void FPlaySceneViewportClient::Draw(FViewport* Viewport, FCanvas* Canvas)
{
	Canvas->Clear(FLinearColor::Black);

	FCanvasTileItem canvasTitleItem(FVector2D(0, 0), IEditorExtend::Get().GetTextureRenderTarget2D()->Resource
		, FVector2D(Viewport->GetRenderTargetTexture()->GetSizeX(), Viewport->GetRenderTargetTexture()->GetSizeY())
		, FLinearColor::White);
	canvasTitleItem.BlendMode = ESimpleElementBlendMode::SE_BLEND_Opaque;
	Canvas->DrawItem(canvasTitleItem,Viewport->GetRenderTargetTexture()->GetSizeX(),Viewport->GetRenderTargetTexture()->GetSizeY());
}

bool FPlaySceneViewportClient::InputAxis(FViewport* Viewport, int32 ControllerId, FKey Key, float Delta, float DeltaTime, int32 NumSamples /*= 1*/, bool bGamepad /*= false*/)
{
	return false;
}

bool FPlaySceneViewportClient::InputKey(FViewport* Viewport, int32 ControllerId, FKey Key, EInputEvent Event, float AmountDepressed /*= 1.f*/, bool bGamepad /*= false*/)
{
	return false;
}

bool FPlaySceneViewportClient::InputGesture(FViewport* Viewport, EGestureEvent GestureType, const FVector2D& GestureDelta, bool bIsDirectionInvertedFromDevice)
{
	return false;
}


TSharedPtr<EditorExtendSlate>EditorExtendSlate::editorextendSlate = nullptr;
EditorExtendSlate::EditorExtendSlate():WindowX(1920),WindowY(980)
{
	EditorExtendWindow = SNew(SWindow)
		.Title(FText::FromString("EditorExtend"))
		.ScreenPosition(FVector2D(0, 0))
		.ClientSize(FVector2D(WindowX, WindowY))
		.AutoCenter(EAutoCenter::PreferredWorkArea)
		.UseOSWindowBorder(true)
		.SaneWindowPlacement(false)
		.SizingRule(ESizingRule::UserSized);
	FSlateApplication::Get().AddWindow(EditorExtendWindow.ToSharedRef());

	// Assign window events delegator
	Indelegate.BindRaw(this, &EditorExtendSlate::OnWindowClosed);
	EditorExtendWindow->SetOnWindowClosed(Indelegate);
	// Create and assign viewport to window
	playSceneViewport = SNew(EditorExtendViewport);
	EditorExtendWindow->SetContent(playSceneViewport.ToSharedRef());
}


EditorExtendSlate::~EditorExtendSlate()
{
}



void EditorExtendViewport::Construct(const FArguments& InArgs)
{
	Viewport = SNew(SViewport)
		.IsEnabled(true)
		.EnableGammaCorrection(false)
		.ShowEffectWhenDisabled(false)
		.EnableBlending(true)
		.ToolTip(SNew(SToolTip).Text(FText::FromString("SPlaySceneViewport")));
	EditorExtendViewportClient = MakeShareable(new FPlaySceneViewportClient());
	SceneViewport = MakeShareable(new FSceneViewport(EditorExtendViewportClient.Get(), Viewport));
	Viewport->SetViewportInterface(SceneViewport.ToSharedRef());
	this->ChildSlot
		[
			Viewport.ToSharedRef()
		];


}
void EditorExtendSlate::Initialization()
{
	if (editorextendSlate.IsValid())
	{
		EditorExtendSlate::editorextendSlate = MakeShareable(new EditorExtendSlate());
	}
}


void EditorExtendViewport::Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime)
{
	SceneViewport->Draw();
}

void EditorExtendSlate::ShutDown()
{
	if (!editorextendSlate.IsValid())
	{
		editorextendSlate->editorextendSlate.Reset();
		editorextendSlate->editorextendSlate = nullptr;
	}
}

void EditorExtendSlate::OnWindowClosed(const TSharedRef<SWindow>& window)
{
	ShutDown();
}


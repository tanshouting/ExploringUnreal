// Fill out your copyright notice in the Description page of Project Settings.

#include "SlateHUD.h"
#include "Engine/Engine.h"
#include "FirstSlateWidget.h"
#include "Widgets/SWeakWidget.h"
#include "Engine/GameViewportClient.h"


void ASlateHUD::BeginPlay()
{
	Super::BeginPlay();
	GEngine->GameViewport->AddViewportWidgetContent(
		SNew(SWeakWidget)
		.PossiblyNullContent(
			SAssignNew(firstSlateWidget, UFirstSlateWidget)));
}

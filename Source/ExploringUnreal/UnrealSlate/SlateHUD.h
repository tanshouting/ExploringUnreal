// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SlateHUD.generated.h"

/**
 * 
 */
UCLASS()
class EXPLORINGUNREAL_API ASlateHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	TSharedPtr<class UFirstSlateWidget> firstSlateWidget;
	virtual void BeginPlay()override;
};

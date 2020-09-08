// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"


class EXPLORINGUNREAL_API UFirstSlateWidget : public SCompoundWidget
{
public:	
	// Sets default values for this component's properties
public:
	SLATE_BEGIN_ARGS(UFirstSlateWidget)
	{}
	SLATE_END_ARGS()


	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);


};

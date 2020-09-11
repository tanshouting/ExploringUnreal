// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WrapSlateWidget.generated.h"

/**
 * 
 */
UCLASS()
class EXPLORINGUNREAL_API UWrapSlateWidget : public UUserWidget
{
	GENERATED_BODY()
		
public:
	//TSharedRef<class UFirstSlateWidget> firstSlateWidgetRef;
	//class UFirstSlateWidget*firstSlateWidgetRef;
public:
	virtual const FText GetPaletteCategory()  override;

	//ͨ��RebulidWidget ��Slate Compound ������UMG
protected:
	virtual TSharedRef<SWidget> RebuildWidget() override;
};

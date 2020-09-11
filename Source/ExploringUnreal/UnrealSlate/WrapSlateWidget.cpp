// Fill out your copyright notice in the Description page of Project Settings.

#include "WrapSlateWidget.h"
#include "FirstSlateWidget.h"
#include "Widgets/Images/SImage.h"




const FText UWrapSlateWidget::GetPaletteCategory()
{
	return NSLOCTEXT("UContenSlatetWidget", "MyCustomSlate", "CustomSlate");
}

TSharedRef<SWidget> UWrapSlateWidget::RebuildWidget()
{
	TSharedRef<class UFirstSlateWidget> slateWidget = SNew(UFirstSlateWidget);
	return slateWidget;
}

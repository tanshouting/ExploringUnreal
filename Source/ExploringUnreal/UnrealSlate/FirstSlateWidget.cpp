// Fill out your copyright notice in the Description page of Project Settings.

#include "FirstSlateWidget.h"
#include "SlateOptMacros.h"
#include "Widgets/Text/STextBlock.h"


// Sets default values for this component's properties


BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void UFirstSlateWidget::Construct(const FArguments& InArgs)
{
	ChildSlot
		[
			SNew(SButton).Content()
			[
				SNew(STextBlock).Font(FSlateFontInfo("Veranda", 100)).Text(NSLOCTEXT("font1", "font2", "First Slate Widget"))//不知道前几个参数是干嘛的
			]

		];

}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

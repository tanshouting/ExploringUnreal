// Fill out your copyright notice in the Description page of Project Settings.

#include "FirstSlateWidget.h"
#include "SlateOptMacros.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/SPanel.h"


// Sets default values for this component's properties


BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void UFirstSlateWidget::Construct(const FArguments& InArgs)
{
	ChildSlot

		// Populate a Button
		//[
		//	SNew(SButton).Content()
		//	[
		//		SNew(STextBlock).Font(FSlateFontInfo("Veranda", 100)).Text(NSLOCTEXT("font1", "font2","FirstSlate"))
		//	]
		//];
		[
			SAssignNew(verticalBox, SVerticalBox)
			+ SVerticalBox::Slot()
		.Padding(1.0).
		FillHeight(10.0f)
		.HAlign(HAlign_Fill).VAlign(VAlign_Top)
		[
			SNew(SButton).Content()
			[
				SNew(STextBlock).Font(FSlateFontInfo("Veranda", 100)).Text(NSLOCTEXT("ButtonSpace", "Button","Button"))
			]
		]
		];
	for (int ButtonNum = 0; ButtonNum < 5; ButtonNum++)
	{
		verticalBox->AddSlot().Padding(1.0)
			.FillHeight(5.0f)
				[
					SNew(SButton).Content()
					[
						SNew(STextBlock).
						Font(FSlateFontInfo("Veranda", 100))
					.Text(FText::Format(NSLOCTEXT("ButtonSpace", "Button","{0}"),ButtonNum)
					]
				];
	}
		
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

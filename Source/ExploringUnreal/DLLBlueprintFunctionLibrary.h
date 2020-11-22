// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DLLBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class EXPLORINGUNREAL_API UDLLBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
		UFUNCTION(BlueprintCallable, Category = "My DLL Library")
		static int importDLL();
public:
	UFUNCTION(BlueprintCallable, Category ="MultiThreadTest")
		static void MutliThreadDo(int32 MaxPrime);
	UFUNCTION(BlueprintCallable, Category = "MultiThreadTest")
		static void SingleThreadDo(int32 MaxPrime);
	UFUNCTION(BlueprintCallable, Category = "MultiThreadTest")
		static void Do(int32 MaxPrime);
	
	
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MeshExchangeManger.generated.h"

/**
 * 
 */
UCLASS()
class EXPLORINGUNREAL_API UMeshExchangeManger : public UObject
{
	GENERATED_BODY()


public:
		UFUNCTION(BlueprintCallable, Category = FbxImportLibrary)
		static UObject* ImportFbxFile(const FString& FbxFilePath, const FString DestinationPath);
	
};

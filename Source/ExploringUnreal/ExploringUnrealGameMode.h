// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ExploringUnrealGameMode.generated.h"

UCLASS(minimalapi)
class AExploringUnrealGameMode : public AGameModeBase
{
	GENERATED_BODY()
public:
 AExploringUnrealGameMode();
public:
	UFUNCTION(BlueprintCallable,Category ="生成FBX")
		void ExecuFbx(const FString& FbxFilePath, const FString DestinationPath);
};




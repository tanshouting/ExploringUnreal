// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "ExploringUnrealGameMode.h"
#include "ExploringUnrealCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "MeshManager/MeshExchangeManger.h"

AExploringUnrealGameMode::AExploringUnrealGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void AExploringUnrealGameMode::ExecuFbx(const FString& FbxFilePath, const FString DestinationPath)
{
	UMeshExchangeManger* meshManager = NewObject<UMeshExchangeManger>();
	meshManager->ImportFbxFile(FbxFilePath, DestinationPath);
}

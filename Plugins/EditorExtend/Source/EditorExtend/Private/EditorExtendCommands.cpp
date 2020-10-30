// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "EditorExtendCommands.h"

#define LOCTEXT_NAMESPACE "FEditorExtendModule"

void FEditorExtendCommands::RegisterCommands()
{
	UI_COMMAND(OpenPluginWindow, "EditorExtend", "Bring up EditorExtend window", EUserInterfaceActionType::Button, FInputGesture());
}

#undef LOCTEXT_NAMESPACE

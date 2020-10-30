// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "EditorExtendStyle.h"

class FEditorExtendCommands : public TCommands<FEditorExtendCommands>
{
public:

	FEditorExtendCommands()
		: TCommands<FEditorExtendCommands>(TEXT("EditorExtend"), NSLOCTEXT("Contexts", "EditorExtend", "EditorExtend Plugin"), NAME_None, FEditorExtendStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > OpenPluginWindow;
};
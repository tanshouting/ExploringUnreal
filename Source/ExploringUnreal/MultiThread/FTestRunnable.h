// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <Runnable.h>

/**
 * 
 */
class EXPLORINGUNREAL_API FTestRunnable:FRunnable
{
public:
	FTestRunnable();
	~FTestRunnable();
	virtual uint32 Run()override;


	virtual void Stop()override;


	virtual void Exit()override;

};

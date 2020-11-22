// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <Runtime/Core/Public/Async/AsyncWork.h>


/**
 * 
 */
class EXPLORINGUNREAL_API MyTaskClass :public FNonAbandonableTask
{
public:
	MyTaskClass();
	~MyTaskClass();
	FORCEINLINE TStatId GetStatId()const
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT(test, STATGROUP_ThreadPoolAsyncTasks);
	}
	void DoWork();
	int32 MaxPrime;
	MyTaskClass(int MaxPrime) { this->MaxPrime = MaxPrime; };
};

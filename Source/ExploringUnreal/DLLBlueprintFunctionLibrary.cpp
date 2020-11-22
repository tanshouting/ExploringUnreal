// Fill out your copyright notice in the Description page of Project Settings.

#include "DLLBlueprintFunctionLibrary.h"
#include "MultiThread/MyTaskClass.h"
using namespace std;


typedef int(WINAPI*_fnDll2)();
int UDLLBlueprintFunctionLibrary::importDLL()
{
	_fnDll2 datafromdll = NULL;
	//通过FPlatformProcess::GetDllHandle获取dll的句柄
	FString filePath = "D:/ExploringUnreal/Intermediate/Build/Win64/UE4Editor/Development/NetWorkClient.dll";
	void* v_dllHandle = FPlatformProcess::GetDllHandle(*filePath);//Retrieve the DLL.
	FString procName = "fnDll2";
	if (v_dllHandle)
	{
		datafromdll = (_fnDll2)FPlatformProcess::GetDllExport(v_dllHandle, *procName);
		return datafromdll();
	}
	if (v_dllHandle != NULL)

	{
	}
	return 0;
}

void UDLLBlueprintFunctionLibrary::MutliThreadDo(int32 MaxPrime)
{
	auto Task = new FAutoDeleteAsyncTask<MyTaskClass>(MaxPrime);//任务完成自动删除模板FAutoDeleteAsyncTask
	if (Task)
		Task->StartBackgroundTask();//Call BaseClass DoWork()
}

void UDLLBlueprintFunctionLibrary::SingleThreadDo(int32 MaxPrime)
{
	Do(MaxPrime);
}

void UDLLBlueprintFunctionLibrary::UDLLBlueprintFunctionLibrary::Do(int32 MaxPrime)
{
	for (int32 i = 1; i <= MaxPrime; i++)
	{
		bool isPrime = true;
		for (int32 j = 2; j <= i / 2; j++)
		{
			if (FMath::Fmod(i, j) == 0)
			{
				isPrime = false;
				break;
			}
		}
		if (isPrime)
			GLog->Log("Prime number #" + FString::FromInt(i) + ": " + FString::FromInt(i));
	}
}

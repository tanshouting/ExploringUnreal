// Fill out your copyright notice in the Description page of Project Settings.

#include "DLLBlueprintFunctionLibrary.h"
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

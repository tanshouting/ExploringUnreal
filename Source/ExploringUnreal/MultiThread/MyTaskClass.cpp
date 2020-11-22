// Fill out your copyright notice in the Description page of Project Settings.

#include "MyTaskClass.h"
#include <Runtime/Core/Public/Async/AsyncWork.h>
#include "DLLBlueprintFunctionLibrary.h"
MyTaskClass::MyTaskClass()
{
}

MyTaskClass::~MyTaskClass()
{
}

void MyTaskClass::DoWork()
{
	UDLLBlueprintFunctionLibrary::Do(MaxPrime);
}

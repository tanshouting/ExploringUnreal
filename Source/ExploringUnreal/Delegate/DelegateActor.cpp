// Fill out your copyright notice in the Description page of Project Settings.

#include "DelegateActor.h"
#include "BindActor.h"


// Sets default values
ADelegateActor::ADelegateActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//testDelegate.BindUObject(this, &ABindActor::DelegateFunc);
	
}

void ADelegateActor::CallDelegateFunc()
{
	if (testDelegate.IsBound())
	{
		testDelegate.ExecuteIfBound();
	}
	GEngine->AddOnScreenDebugMessage(-1, 30.f, FColor::Red, "Delegate Was Called");
}

// Called when the game starts or when spawned
void ADelegateActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ADelegateActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADelegateActor::CallOneParamFunc(int Num)
{
	if (testOneParamDelegate.IsBound())
		testOneParamDelegate.ExecuteIfBound(Num);
}

void ADelegateActor::CallRetvalOneParamFunc()
{
	if (testOneParamDelegate.IsBound())
		//testRetvalOneParamDelegate.ExecuteIfBound();
		testRetvalOneParamDelegate.Execute("6");
}

void ADelegateActor::CallMulticastOneParamFunc()
{
	testMulticastOneParamDelegate.Broadcast("Multicast Was Called");
}

void ADelegateActor::CallDynamicMulticastOneParamFunc(FString str)
{
	testDynamicMulticastOneParamDelegate.Broadcast("Dynamic Multicast Was Called");
}


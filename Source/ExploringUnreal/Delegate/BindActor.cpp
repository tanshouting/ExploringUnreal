// Fill out your copyright notice in the Description page of Project Settings.

#include "BindActor.h"
#include "DelegateActor.h"


// Sets default values
ABindActor::ABindActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;



}

void ABindActor::DelegateFunc()
{
	GEngine->AddOnScreenDebugMessage(-1, 30.0f, FColor::Blue, "BindFuncWasCalled");
}

void ABindActor::OneParamFunc(int Num)
{
	GEngine->AddOnScreenDebugMessage(-1, 30.0f, FColor::Blue, FString::FromInt(Num));
}

int ABindActor::RetvalOneParamFunc(FString Num)
{
	GEngine->AddOnScreenDebugMessage(-1, 30.0f, FColor::Blue, Num);
	return 5;
}

void ABindActor::MulticastOneParamFunc(FString str)
{
	GEngine->AddOnScreenDebugMessage(-1, 30.0f, FColor::Blue, str);
}

// Called when the game starts or when spawned
void ABindActor::BeginPlay()
{
	Super::BeginPlay();
	if(delegateActor)
		delegateActor->testDelegate.BindUObject(this, &ABindActor::DelegateFunc);
		delegateActor->testOneParamDelegate.BindUObject(this, &ABindActor::OneParamFunc);
		delegateActor->testRetvalOneParamDelegate.BindUObject(this, &ABindActor::RetvalOneParamFunc);
		delegateActor->testMulticastOneParamDelegate.AddUObject(this, &ABindActor::MulticastOneParamFunc);
}

// Called every frame
void ABindActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


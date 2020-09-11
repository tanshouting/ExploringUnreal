// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DelegateActor.generated.h"

////
//实际的用法为创建一个代理类 用来Call 代理
//多个绑定这个代理的class接收到Call之后调用绑定的Function
////

DECLARE_DELEGATE(FTestDelegateSignature)//无参数无返回值单播
DECLARE_DELEGATE_OneParam(FTestOneParamDelegate,int)//一个参数无返回之单播
DECLARE_DELEGATE_RetVal_OneParam(int,FRetvalOneParamDelegate,FString)//一个参数有返回值
DECLARE_MULTICAST_DELEGATE_OneParam(FMulticastOneParamDelegate, FString);//一个参数的多播代理（多播代理无法绑定带有返回值的函数）
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDynamicMulticastOneParamDelegate, FString,str);//一个参数的动态多播代理
UCLASS()
class EXPLORINGUNREAL_API ADelegateActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADelegateActor();

	//定义一个代理
	FTestDelegateSignature testDelegate;
	FTestOneParamDelegate testOneParamDelegate;
	FRetvalOneParamDelegate testRetvalOneParamDelegate;
	FMulticastOneParamDelegate testMulticastOneParamDelegate;
	UPROPERTY(BlueprintAssignable)//暴露给蓝图使用 貌似只能在Multicast时使用
	FDynamicMulticastOneParamDelegate testDynamicMulticastOneParamDelegate;

	UFUNCTION(BlueprintCallable, Category = "Delegate")
		void CallDelegateFunc();
	UFUNCTION(BlueprintCallable, Category = "Delegate")
		void CallOneParamFunc(int Num);
	UFUNCTION(BlueprintCallable, Category = "Delegate")
		void CallRetvalOneParamFunc();
	UFUNCTION(BlueprintCallable, Category = "Delegate")
		void CallMulticastOneParamFunc();
	UFUNCTION(BlueprintCallable, Category = "Delegate")
		void CallDynamicMulticastOneParamFunc(FString str);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TSet<TSubclassOf<AActor>> testActorSet;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TSet<AActor*> testActorSet2;

	
	
};

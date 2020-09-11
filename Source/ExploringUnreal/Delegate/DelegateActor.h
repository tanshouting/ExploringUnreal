// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DelegateActor.generated.h"

////
//ʵ�ʵ��÷�Ϊ����һ�������� ����Call ����
//�������������class���յ�Call֮����ð󶨵�Function
////

DECLARE_DELEGATE(FTestDelegateSignature)//�޲����޷���ֵ����
DECLARE_DELEGATE_OneParam(FTestOneParamDelegate,int)//һ�������޷���֮����
DECLARE_DELEGATE_RetVal_OneParam(int,FRetvalOneParamDelegate,FString)//һ�������з���ֵ
DECLARE_MULTICAST_DELEGATE_OneParam(FMulticastOneParamDelegate, FString);//һ�������Ķಥ�����ಥ�����޷��󶨴��з���ֵ�ĺ�����
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDynamicMulticastOneParamDelegate, FString,str);//һ�������Ķ�̬�ಥ����
UCLASS()
class EXPLORINGUNREAL_API ADelegateActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADelegateActor();

	//����һ������
	FTestDelegateSignature testDelegate;
	FTestOneParamDelegate testOneParamDelegate;
	FRetvalOneParamDelegate testRetvalOneParamDelegate;
	FMulticastOneParamDelegate testMulticastOneParamDelegate;
	UPROPERTY(BlueprintAssignable)//��¶����ͼʹ�� ò��ֻ����Multicastʱʹ��
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

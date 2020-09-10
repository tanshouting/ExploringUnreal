

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BindActor.generated.h"

UCLASS()
class EXPLORINGUNREAL_API ABindActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABindActor();
	UFUNCTION(BlueprintCallable, Category = "Delegate")
		void DelegateFunc();
	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category = "Delegate")
	class ADelegateActor* delegateActor;
	void OneParamFunc(int Num);
	int RetvalOneParamFunc(FString Num);
	void MulticastOneParamFunc(FString str);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};

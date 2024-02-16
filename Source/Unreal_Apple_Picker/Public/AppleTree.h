// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AppleTree.generated.h"

UCLASS()
class UNREAL_APPLE_PICKER_API AAppleTree : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SpawnRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AActor> AppleClassReference;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTimerHandle TimerHandle_SpawnApple;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USoundBase* DropSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Volume = 0.4f;

public:	
	// Sets default values for this actor's properties
	AAppleTree();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void SpawnApple();
};

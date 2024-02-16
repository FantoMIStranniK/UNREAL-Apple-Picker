// Fill out your copyright notice in the Description page of Project Settings.


#include "AppleTree.h"
#include "Math/UnrealMathUtility.h"
#include "Math/Transform.h"
#include "AudioSubsystem.h"

AAppleTree::AAppleTree()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AAppleTree::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorldTimerManager().SetTimer(AAppleTree::TimerHandle_SpawnApple, this, &AAppleTree::SpawnApple, AAppleTree::SpawnRate, true);
}

void AAppleTree::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAppleTree::SpawnApple()
{
	double X = FMath::RandRange(-700, 700);

	FTransform transform;

	transform.SetLocation(FVector3d(X, 0, 500));
	transform.SetRotation(FRotator3d(0, 0, 0).Quaternion());
	transform.SetScale3D(FVector3d(1, 1, 1));

	UWorld* World = GetWorld();

	FActorSpawnParameters params;

	params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	World->SpawnActor<AActor>(AAppleTree::AppleClassReference, transform, params);

	UGameInstance* GameInstance = GetGameInstance();

	UAudioSubsystem* audioSubsystem = GameInstance->GetSubsystem<UAudioSubsystem>();

	audioSubsystem->PlaySoundFromActor(this, AAppleTree::DropSound, AAppleTree::Volume);
}

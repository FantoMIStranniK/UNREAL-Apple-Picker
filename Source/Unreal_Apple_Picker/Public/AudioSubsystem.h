// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AudioSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class UNREAL_APPLE_PICKER_API UAudioSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void PlaySound(USoundBase* sound, float volume);

public:
	UFUNCTION(BlueprintCallable)
	void PlaySoundFromActor(AActor* caller, USoundBase* sound, float volume);
};

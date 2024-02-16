
#include "AudioSubsystem.h"
#include "Kismet/GameplayStatics.h"

void UAudioSubsystem::PlaySound(USoundBase* Sound, float volume)
{
	AActor* CallerActor = GetWorld()->GetFirstPlayerController()->GetPawn();

	FVector position = CallerActor->GetActorLocation();

	UGameplayStatics::PlaySoundAtLocation(this, Sound, position, volume);
}

void UAudioSubsystem::PlaySoundFromActor(AActor* Caller, USoundBase* Sound, float volume)
{
	FVector position = Caller->GetActorLocation();

	UGameplayStatics::PlaySoundAtLocation(Caller, Sound, position, volume);
}
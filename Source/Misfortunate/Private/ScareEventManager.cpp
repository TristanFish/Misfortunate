// Fill out your copyright notice in the Description page of Project Settings.


#include "ScareEventManager.h"
#include "Components/AudioComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundAttenuation.h"
#include "PlayerCharacter.h"
// Sets default values
AScareEventManager::AScareEventManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	

	scaresMaping.Add(EventZoneLevel::I, { Wind });
	scaresMaping.Add(EventZoneLevel::II, { Wind });
	scaresMaping.Add(EventZoneLevel::III, { Wind });
	scaresMaping.Add(EventZoneLevel::IV, { Wind });
	scaresMaping.Add(EventZoneLevel::V, { Wind });
	scaresMaping.Add(EventZoneLevel::VI, { Wind });
}

// Called when the game starts or when spawned
void AScareEventManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AScareEventManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



void AScareEventManager::TriggerScareEvent(APlayerCharacter* char_)
{

	selectedCharacter = char_;
	StartEvent(char_->GetCurrentZone()->ZoneLevel);
}

void AScareEventManager::StartEvent(EventZoneLevel zoneLevel)
{
	for (auto i : scaresMaping)
	{
		if (i.Key == zoneLevel)
		{
			ScareType pickedScare;
			int randomIndex = FMath::FRandRange(0,i.Value.Num());
			pickedScare = i.Value[randomIndex];
			for (auto scare : scares)
			{
				if (scare.Value == pickedScare)
				{
					UGameplayStatics::PlaySoundAtLocation(GetWorld(), scare.Key, selectedCharacter->GetActorLocation(),FRotator::ZeroRotator, 1.0f,1.0f,0.0f,ScareAttenuation,nullptr, selectedCharacter);
					GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("PLAYED SOUND")));
					break;
				}
			}
		}
	}
}
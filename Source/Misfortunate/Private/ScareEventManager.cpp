// Fill out your copyright notice in the Description page of Project Settings.


#include "ScareEventManager.h"
#include "Components/AudioComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundAttenuation.h"
#include "PlayerCharacter.h"
#include "Sound/SoundCue.h"
#include "MPlayerController.h"

// Sets default values
AScareEventManager::AScareEventManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	scaresMaping.Add(EventZoneLevel::I, { Whisper });
	scaresMaping.Add(EventZoneLevel::II, { Whisper });
	scaresMaping.Add(EventZoneLevel::III, { Whisper });
	scaresMaping.Add(EventZoneLevel::IV, { Whisper });
	scaresMaping.Add(EventZoneLevel::V, { Whisper });
	scaresMaping.Add(EventZoneLevel::VI, { Whisper });

	ScareDistanceThreshold = 100.0f;
}

// Called when the game starts or when spawned
void AScareEventManager::BeginPlay()
{
	Super::BeginPlay();

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AScarePoint::StaticClass(), scarePoints);


	
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





TMap<FScareSettings, FScareAudio> AScareEventManager::GetMapOfSameScareType(ScareType scareType)
{
	TMap<FScareSettings, FScareAudio> returnMap;


	for (auto scare : scares)
	{
		if (scare.Key.scareType == scareType)
		{
			if (!returnMap.Contains(scare.Key))
			{
				returnMap.Add(scare.Key, scare.Value);
			}
		}
	}

	return returnMap;
}

void AScareEventManager::StartEvent(EventZoneLevel zoneLevel)
{
	for (auto i : scaresMaping)
	{
		if (i.Key == zoneLevel)
		{
			AScarePoint* scarePoint = GetNearestScarePoint();

			TArray<FScareAudio> AudioArray;
			TArray<FScareSettings> SettingsArray;
			TMap<FScareSettings, FScareAudio> scaresOfType;

			int scareIndex, typeIndex, audioIndex;

			if (!scarePoint->UseScareType)
			{
				 scareIndex = FMath::RandRange(0, i.Value.Num() - 1);
				 scaresOfType = GetMapOfSameScareType(i.Value[scareIndex]);
			}
			else
			{
				scaresOfType = GetMapOfSameScareType(scarePoint->scareType);

			}


			typeIndex = FMath::RandRange(0, scaresOfType.Num() -1);
			
			scaresOfType.GenerateKeyArray(SettingsArray);
			scaresOfType.GenerateValueArray(AudioArray);


			audioIndex = FMath::RandRange(0, AudioArray[typeIndex].audioClips.Num() - 1);

			USoundCue* SoundCue = AudioArray[typeIndex].audioClips[audioIndex];


			AMPlayerController* controller = Cast<AMPlayerController>(selectedCharacter->GetController());

			if (SettingsArray[typeIndex].locationType == ScareLocationType::Positional)
			{
				controller->ClientPlaySoundAtLocation(SoundCue, scarePoint->GetActorLocation());
			}
			else
			{
				controller->ClientPlaySound(SoundCue);
			}
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, selectedCharacter->GetName());
			break;
		}
	}
}



AScarePoint* AScareEventManager::GetNearestScarePoint()
{
	float Closestindex = 0;
	if (selectedCharacter != nullptr)
	{
		FVector PlayerPos;
		float CloseestDistance = 2000000;

		for (int i = 0; i < scarePoints.Num(); i++) {

			PlayerPos =  selectedCharacter->GetActorLocation();

			float distance = (PlayerPos - scarePoints[i]->GetActorLocation()).Size();
			
			if (distance < CloseestDistance)
			{
				CloseestDistance = distance;
				Closestindex = i;
			}
		}
	}

	return Cast<AScarePoint>(scarePoints[Closestindex]);
}


float AScareEventManager::GetScareDistanceThreshold() const
{
	return ScareDistanceThreshold;
}

float AScareEventManager::GetScareTriggerDelay() const
{
	return CheckForScareTriggerDelay;
}

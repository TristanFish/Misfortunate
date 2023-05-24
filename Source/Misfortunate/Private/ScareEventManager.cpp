// Fill out your copyright notice in the Description page of Project Settings.


#include "ScareEventManager.h"
#include "Components/AudioComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundAttenuation.h"
#include "PlayerCharacter.h"
#include "MetasoundSource.h"
#include "MPlayerController.h"

// Sets default values
AScareEventManager::AScareEventManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	scaresMaping.Add(EventZoneLevel::I, { Whisper,Wind });
	scaresMaping.Add(EventZoneLevel::II, { Whisper,Wind });
	scaresMaping.Add(EventZoneLevel::III, { Whisper,Wind });
	scaresMaping.Add(EventZoneLevel::IV, { Whisper,Wind });
	scaresMaping.Add(EventZoneLevel::V, { Whisper,Wind });
	scaresMaping.Add(EventZoneLevel::VI, { Whisper,Wind });

	ScareDistanceThreshold = 100.0f;

	static ConstructorHelpers::FObjectFinder<UDataTable> DataTableClass(TEXT("/Game/Misfortuante/DataStructures/DT_ScareData.DT_ScareData"));
	ScareDataTable = DataTableClass.Object;

	for (auto RowName : ScareDataTable->GetRowNames())
	{
		FScareData* ScareData = ScareDataTable->FindRow<FScareData>(RowName,"");

		scares.Add(*ScareData);
	}

}

// Called when the game starts or when spawned
void AScareEventManager::BeginPlay()
{
	Super::BeginPlay();

	InitalizeScarePoints();

	
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
		if (scare.ScareSettings.scareType == scareType)
		{
			if (!returnMap.Contains(scare.ScareSettings))
			{
				returnMap.Add(scare.ScareSettings, scare.ScareAudio);
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
			AScarePoint* ScarePoint = GetNearestScarePoint();

			TArray<FScareAudio> AudioArray;
			TArray<FScareSettings> SettingsArray;
			TMap<FScareSettings, FScareAudio> ScaresOfType;



			int ScareIndex,TypeIndex, AudioIndex;

			if (!ScarePoint->UseScareType)
			{
				ScareIndex = FMath::RandRange(0, i.Value.Num() - 1);
				ScaresOfType = GetMapOfSameScareType(i.Value[ScareIndex]);
			}
			else
			{
				ScaresOfType = GetMapOfSameScareType(ScarePoint->scareType);

			}

			ScaresOfType.GenerateKeyArray(SettingsArray);
			ScaresOfType.GenerateValueArray(AudioArray);


			TypeIndex = FMath::RandRange(0, ScaresOfType.Num() -1);
			AudioIndex = FMath::RandRange(0, AudioArray[TypeIndex].audioClips.Num() - 1);


			UMetaSoundSource* SoundCue;
			if (ScarePoint->UseCustomCue)
			{
				SoundCue = ScarePoint->ScareCue;
			}
			else
			{
				SoundCue = AudioArray[TypeIndex].audioClips[AudioIndex];
			}



			AMPlayerController* controller = Cast<AMPlayerController>(selectedCharacter->GetController());

			if (SettingsArray[TypeIndex].locationType == EScareLocationType::Positional)
			{
				controller->ClientPlaySoundAtLocation(Cast<USoundBase>(SoundCue), ScarePoint->GetActorLocation());
				
			}
			else
			{
				controller->ClientPlaySound(Cast<USoundBase>(SoundCue));
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

void AScareEventManager::InitalizeScarePoints()
{
	if (scarePoints.Num() <= 0)
	{
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), AScarePoint::StaticClass(), scarePoints);
	}

}

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Containers/Map.h"
#include "Engine/DataTable.h"

#include "Actors/EventZone.h"
#include "Actors/ScarePoint.h"


#include "ScareEventManager.generated.h"

class UAudioComponent;


// Used to determine whether the scare will be in 3D space at a specific location or 2D sound.
UENUM()
enum EScareLocationType {

	Positional,
	NonPositional,
};


USTRUCT(BlueprintType)
struct FScareSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TEnumAsByte<ScareType> scareType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TEnumAsByte<EScareLocationType> locationType;



	FScareSettings()
		
	{}


	FScareSettings(const FScareSettings& Other)
		
	{
		scareType = Other.scareType;
		locationType = Other.locationType;
	}

	bool operator==(const FScareSettings& Other) const
	{
		return Equals(Other);
	}

	bool Equals(const FScareSettings& Other) const
	{
		return scareType == Other.scareType && locationType == Other.locationType;
	}
};
#if UE_BUILD_DEBUG
uint32 GetTypeHash(const FScareSettings& Thing);
#else // optimize by inlining in shipping and development builds
FORCEINLINE uint32 GetTypeHash(const FScareSettings& Thing)
{
	uint32 Hash = FCrc::MemCrc32(&Thing, sizeof(FScareSettings));
	return Hash;
}
#endif



USTRUCT(BlueprintType)
struct FScareAudio
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<class UMetaSoundSource*> audioClips;

};

USTRUCT(BlueprintType)
struct FScareData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FScareSettings ScareSettings;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		 FScareAudio ScareAudio;
};

UCLASS()
class MISFORTUNATE_API AScareEventManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AScareEventManager();

	


protected:

	//!CheckForScareTriggerDelay Float
	/* Holds how often that a Scare Event has a chance of triggering. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float CheckForScareTriggerDelay;

	//!ScareDistanceThreshold Float
	/* Hold's the distance the players need to go away from each other until scare event's have the possibility of happening*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float ScareDistanceThreshold;



protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//!selectedCharacter APlayerCharacter
	/*!Pointer to the character that was selected to get scared. */
	class APlayerCharacter* selectedCharacter;

	//!ScaresMaping TMap
	/*!Map's out what scares are linked to specific zone levels */
	TMap<EventZoneLevel, TArray<ScareType>> scaresMaping;
	

	//!scarePoints TArray
	/*!Hold's a pointer to all the scare points that exist in the level*/
	TArray<AActor*> scarePoints;

	//!Scares Map
	/*!Map that enables us to add Sound cue's in engine and map then to a scare type*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FScareData> scares;

	UDataTable* ScareDataTable;


	//!StartEvent Function
	/*!Starts a scare event depending on the given zoneLevel*/
	void StartEvent(EventZoneLevel zoneLevel);

	//!GetNearestScarePoint Function
	/*!Return's the scare point that is closest to the Selected Character*/
	AScarePoint* GetNearestScarePoint();

	//!GetMapOfSameScareType Function
	/*!Returns a TMap containing every scare from the scares TMap that contains that scareType*/
	TMap<FScareSettings, FScareAudio> GetMapOfSameScareType(ScareType scareType);


public:	


	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//!TriggerScareEvent Function
	/*!Trigger's a scare event with the given character*/
	void TriggerScareEvent(APlayerCharacter* char_);

	//!CheckForScareTriggerDelay Getter
	/* Returns the ScareDistanceThreshold float  */
	float GetScareDistanceThreshold() const;

	//!GetScareTriggerDelay Getter
	/* Returns the CheckForScareTriggerDelay float  */
	float GetScareTriggerDelay() const;



private:
	void InitalizeScarePoints();

};

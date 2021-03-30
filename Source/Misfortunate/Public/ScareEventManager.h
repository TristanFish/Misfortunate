// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Containers/Map.h"
#include "EventZone.h"
#include "Sound/SoundCue.h"
#include "ScareEventManager.generated.h"

class UAudioComponent;
UENUM()
enum ScareType {

	Whisper,
	Wind,
	Footsteps,
	SingingNoises,
};

UCLASS()
class MISFORTUNATE_API AScareEventManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AScareEventManager();

	//!Scares Map
	/*!Map that enables us to add Sound cue's in engine and map then to a scare type*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TMap<USoundCue*, TEnumAsByte<ScareType>> scares;

	//!ScareAttenuation USoundAttenuation
	/*!Used to determine different 3D audio settings*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class USoundAttenuation* ScareAttenuation;

protected:

	//!selectedCharacter APlayerCharacter
	/*!Pointer to the character that was selected to get scared. */
	class APlayerCharacter* selectedCharacter;

	//!ScaresMaping Map
	/*!Map's out what scares are linked to specific zone levels */
	TMap<EventZoneLevel, TArray<ScareType>> scaresMaping;


	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//!StartEvent Function
	/*!Starts a scare event depending on the given zoneLevel*/
	void StartEvent(EventZoneLevel zoneLevel);

public:	


	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//!TriggerScareEvent Function
	/*!Trigger's a scare event with the given character*/
	void TriggerScareEvent(APlayerCharacter* char_);
};

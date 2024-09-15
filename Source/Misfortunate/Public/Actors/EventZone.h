// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerVolume.h"

#include "Libraries/MisfortunateEnumLibrary.h"

#include "EventZone.generated.h"



UCLASS()
class MISFORTUNATE_API AEventZone : public ATriggerVolume
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEventZone();

	//!ZoneLevel 
	/*!The level that the current zone is. (Changeable in editor)*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TEnumAsByte<EventZoneLevel> ZoneLevel;

protected:

	//!BeginPlay Function 
	/*!Called when the game starts or when spawned*/
	virtual void BeginPlay() override;

public:	
	//!OnOverlapBegin Function 
	/*!Triggers when an actor overlaps the Trigger Volume*/
	UFUNCTION()
	void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);

	//!OnOverlapEnd Function 
	/*!Triggers when an actor exits the Trigger Volume*/
	UFUNCTION()
	void OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor);

};

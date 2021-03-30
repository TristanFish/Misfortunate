// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Engine/EngineTypes.h"
#include "MisfortunateGameMode.generated.h"

UCLASS()
class AMisfortunateGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AMisfortunateGameMode(const class FObjectInitializer& ObjectInitializer);



	virtual void PostLogin(APlayerController* NewPlayer) override;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	void CheckPlayersDistance();
	
	// Hold's the distance the players need to go away from each other until scare event's have the possibility of happening
	UPROPERTY(VisibleAnywhere)
		float DistanceThreshold;

	// The percent chance that a player will be scared by a event
	UPROPERTY(VisibleAnywhere)
		 int EventChance;


private:
	// The Character that was selected to have a scare event triggered on
	APlayerController* selectedCharacter;


	// The distance the players are away from each other In the game
	float DistanceBetweenPlayers;

	TArray<APlayerController*> ConnectedPlayers;

	FTimerHandle CheckDistTimerHandle;
	FTimerHandle TriggerEventTimerHandle;

	// Determines if a scare event will be triggered
	void CheckEventTrigger();


	// Triggers a random scare event
	void TriggerScareEvent();

};




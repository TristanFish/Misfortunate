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

	void AddLoreTabletToAllPlayers(class ALoreTablet* tablet);


public:




	// The percent chance that a player will be scared by a event
	UPROPERTY(VisibleAnywhere)
		 int EventChance;


	//!ScareManager AScareEventManager
	/*!Pointer to the games scare manager singleton*/
	class AScareEventManager* scareManager;

	//!LoreManager ALoreManager
   /*!Pointer to the games lore manager singleton(Handles initialization and collected lore)*/
	class ALoreManager* loreManager;


	void SetPlayerZone(class AEventZone* zone, class APlayerCharacter* enteredChar);


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

	void SelectCharacter();

	// Triggers a random scare event
	void TriggerScareEvent();

	//!GetScareEventManager Getter
	/*!Returns a pointer to the games scareManager*/
	AScareEventManager* GetScareEventManager() const;

	ALoreManager* GetLoreManager() const;



};




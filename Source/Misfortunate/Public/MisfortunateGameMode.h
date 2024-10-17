// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Engine/EngineTypes.h"
#include "MPlayerController.h"

#include "Libraries/MisfortunateEnumLibrary.h"

#include "MisfortunateGameMode.generated.h"


class AScareEventManager;
class AMisfortuneManager;
class ALoreManager;
class AMPlayerController;
class APlayerCharacter;
class AInteractibleObject;
class AEventZone;

UCLASS()
class AMisfortunateGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:

	// Virtual Overrides 
	virtual void PostLogin(APlayerController* NewPlayer) override;

	virtual void Logout(AController* OldPlayer) override;

	virtual void BeginPlay() override;

	virtual void EndPlay(EEndPlayReason::Type Reason) override;


	virtual void Tick(float DeltaSeconds) override;

	AMisfortunateGameMode(const class FObjectInitializer& ObjectInitializer);

	
	// Lobby Variables 
	UPROPERTY()
	TArray<AActor*> PossessableCharacters;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	TEnumAsByte<UGameState> CurrentState;



	// Gameplay Variables 

	// The percent chance that a player will be scared by a event
	UPROPERTY(VisibleAnywhere)
	int EventChance;

	//!ScareManager AScareEventManager
	/*!Pointer to the games scare manager singleton*/
	 AScareEventManager* ScareManager;

	//!LoreManager ALoreManager
   /*!Pointer to the games lore manager singleton(Handles initialization and collected lore)*/
	 ALoreManager* LoreManager;



	AMisfortuneManager* MisfortuneManager;


	UPROPERTY()
	// The Character that was selected to have a scare event triggered on
	APlayerController* selectedCharacter;

	UPROPERTY()
	FTimerHandle CheckDistTimerHandle;

	UPROPERTY()
	FTimerHandle TriggerEventTimerHandle;



	// Core Functions
	UFUNCTION(BlueprintImplementableEvent)
	void EveryoneUpdate();



	//Lobby Functions
	UFUNCTION(BlueprintImplementableEvent)
	void InitPlayerInfo(AMPlayerController* player);

	UFUNCTION()
	void UpdateReadyState(AMPlayerController* changedPlayer);

	UFUNCTION()
	void OnHostStart();

	UFUNCTION(BlueprintCallable)
	void SetGameState(TEnumAsByte<UGameState> state_);
	

	
	//Gameplay Functions
	UFUNCTION()
	void AddLoreTabletToAllPlayers(AInteractibleObject* interactibleObject);

	UFUNCTION()
	void SetPlayerZone(AEventZone* zone, APlayerCharacter* enteredChar);

	




	//Gameplay Getters

	//!GetScareEventManager Getter
	/*!Returns a pointer to the games scareManager*/
	AScareEventManager* GetScareEventManager() const;

	// Returns a pointer to the lore manager
	ALoreManager* GetLoreManager() const;

	UFUNCTION(BlueprintCallable)
	// Returns a pointer to the lore manager
	AMisfortuneManager* GetMisfortuneManager() const;


	// List of connected players
	UPROPERTY(BlueprintReadWrite)
	TArray<APlayerController*> ConnectedPlayers;

	UPROPERTY(BlueprintReadWrite)
	TArray<FMultiplayerPlayerInfo> MultiplayerPlayerInfo;

private:


	float GetDistanceBetweenPlayers();
	// Determines if a scare event will be triggered

	UFUNCTION()
	void CheckEventTrigger();

	UFUNCTION()
	void SelectCharacter();

	// Triggers a random scare event
	UFUNCTION()
	void TriggerScareEvent();


	UFUNCTION()
	void SetupGameplaySingletons();
};




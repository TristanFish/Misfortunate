// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Engine/EngineTypes.h"
#include "MPlayerController.h"
#include "MisfortunateGameMode.generated.h"


UENUM() enum UGameState {

	Lobby UMETA(DisplayName = "Lobby"),
	Exploration UMETA(DisplayName = "Exploration"),
	LobbyExploration UMETA(DisplayName = "LobbyExploration"),

};


UCLASS()
class AMisfortunateGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AMisfortunateGameMode(const class FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
		TEnumAsByte<UGameState> CurrentState;

	// The percent chance that a player will be scared by a event
	UPROPERTY(VisibleAnywhere)
		int EventChance;

#pragma region Managers

	//!ScareManager AScareEventManager
	/*!Pointer to the games scare manager singleton*/
	class AScareEventManager* scareManager;

	//!LoreManager ALoreManager
   /*!Pointer to the games lore manager singleton(Handles initialization and collected lore)*/
	class ALoreManager* loreManager;

#pragma endregion


#pragma region Overrides
	virtual void PostLogin(APlayerController* NewPlayer) override;

	virtual void Logout(AController* OldPlayer) override;

	virtual void BeginPlay() override;

	virtual void EndPlay(EEndPlayReason::Type Reason) override;


	virtual void Tick(float DeltaSeconds) override;

#pragma endregion

public:

#pragma region Lobby

	UFUNCTION(BlueprintImplementableEvent)
		void EveryoneUpdate();

	UFUNCTION(BlueprintImplementableEvent)
		void InitPlayerInfo(AMPlayerController* player);

	void UpdateReadyState(class AMPlayerController* changedPlayer);

	void OnHostStart();

#pragma endregion

	

	

	void AddLoreTabletToAllPlayers(class AInteractibleObject* interactibleObject);

	UFUNCTION(Server, Reliable, BlueprintCallable)
		void ChangeCanMisfortuneIncrease(const bool bCanMisfortuneIncrease);

	UFUNCTION(Server, Reliable, BlueprintCallable)
		void SetOtherPlayersMaxMisfortuneChange(class APlayerCharacter* PlayerNotToSet, const float NewMaxMisfortuneChange);

	UFUNCTION(Server, Reliable,BlueprintCallable)
		void SetPlayerMaxMisfortuneChange(class APlayerCharacter* PlayerToSet, const float NewMaxMisfortuneChange);

#pragma region Getters/Setters

		void SetPlayerZone(class AEventZone* zone, class APlayerCharacter* enteredChar);

		UFUNCTION(BlueprintCallable)
		void SetGameState(TEnumAsByte<UGameState> state_);

		//!GetScareEventManager Getter
	/*!Returns a pointer to the games scareManager*/
		AScareEventManager* GetScareEventManager() const;

		// Returns a pointer to the lore manager
		ALoreManager* GetLoreManager() const;
#pragma endregion
protected:

	// List of connected players
	UPROPERTY(BlueprintReadWrite)
		TArray<APlayerController*> ConnectedPlayers;

	UPROPERTY(BlueprintReadWrite)
		TArray<FPlayerInfo> ConnectedPlayerInfos;

	TArray<AActor*> PossessableCharacters;



#pragma region Scare System
	// The Character that was selected to have a scare event triggered on
	APlayerController* selectedCharacter;

	// The distance the players are away from each other In the game
	float DistanceBetweenPlayers;


	FTimerHandle CheckDistTimerHandle;
	FTimerHandle TriggerEventTimerHandle;

	void CheckPlayersDistance();

	// Determines if a scare event will be triggered
	void CheckEventTrigger();

	void SelectCharacter();

	// Triggers a random scare event
	void TriggerScareEvent();
#pragma endregion

};




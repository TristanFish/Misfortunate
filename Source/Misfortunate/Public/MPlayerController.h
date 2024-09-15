// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Libraries/MisfortunateStructLibrary.h"
#include "MPlayerController.generated.h"

class AInteractibleObject;
class UWJournal;
class UWInteraction;
class UWPlayerHUD;
class UWLobbyMenu;
class UWPlayerStatus;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FInteractClicked);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FNextPageClicked);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPrevPageClicked);




UCLASS()
class MISFORTUNATE_API AMPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	/* Virtual Overrides */

	AMPlayerController();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupInputComponent() override;

	virtual void PawnLeavingGame() override;

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual void OnPossess(APawn* InPawn) override;



	/*Widget Classes*/

	UPROPERTY()
	TSubclassOf<UWJournal> JournalWidgetClass;

	UPROPERTY()
	TSubclassOf<UWInteraction> InteractionWidgetClass;

	UPROPERTY()
	TSubclassOf<UWPlayerHUD> HUDWidgetClass;

	UPROPERTY()
	 UWInteraction* InteractionWidget;

	UPROPERTY()
	UWJournal* JournalWidget;

	UPROPERTY()
	UWPlayerHUD* HUDWidget;



	/*Lobby Variables*/

	UPROPERTY(BlueprintReadOnly)
	TSubclassOf<UWLobbyMenu> LobbyWidgetClass;

	UPROPERTY()
	TSubclassOf<UWPlayerStatus> PlayerStatusWidgetClass;

	UPROPERTY(BlueprintReadOnly)
	 UWLobbyMenu* LobbyWidget;



	/*Interactable Variables*/

	TMap<FString, TArray<AInteractibleObject*>> CollectedLore;



	/*MultiplayerPlayerInfo Variables*/

	UPROPERTY(BlueprintReadWrite, Replicated)
	FMultiplayerPlayerInfo PlayerInfo;

	UPROPERTY(BlueprintReadWrite)
	TArray<FMultiplayerPlayerInfo> AllPlayersInfo;


	UWLobbyMenu* GetLobbyWidget() const;

	bool GetIsReady() const;


	

	/*User Interface Delegates*/

	UPROPERTY()
		FInteractClicked InteractClicked;

	UPROPERTY()
		FNextPageClicked NextPageClicked;

	UPROPERTY()
		FPrevPageClicked PrevPageClicked;


	
	/*Delegate Functions*/

	void InteractionOccurred();

	void NextPageInteraction();

	void PrevPageInteraction();

	void ToggleJournal();



	/*InterActibles Functions*/

	void AddToTabletsCollected(AInteractibleObject* interactibleObject);

	void AddTabletsToAllPlayers(AInteractibleObject* interactibleObject);

	UFUNCTION(BlueprintCallable)
	void HideInteraction();

	UFUNCTION(BlueprintCallable)
	void DisplayInteraction(AInteractibleObject* tablet);

	TMap<FString, TArray<AInteractibleObject*>> GetCollectedInteractibles();


	/*RPC InterActibles Functions*/

	UFUNCTION(Client, Reliable, WithValidation)
	void Client_AddToInteractibles(AInteractibleObject* interactibleObject);

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_AddTabletsToAllPlayers(AInteractibleObject* interactibleObject);



	/*Player Lobby Functions*/

	UFUNCTION(NetMulticast, Reliable, WithValidation)
	void Multi_SwitchToGame();

	UFUNCTION(BlueprintImplementableEvent,BlueprintCallable)
	void UpdatePlayerInfo();

	UFUNCTION(BlueprintImplementableEvent)
	void AddPlayerStatusWidget(const TArray<FMultiplayerPlayerInfo>& playerInfoList);



	/*RPC Player Lobby Functions*/

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_UpdateReadyState(AMPlayerController* playerController);

	UFUNCTION(Client, Reliable, WithValidation, BlueprintCallable)
	void Client_AddPlayersToList(const TArray<FMultiplayerPlayerInfo>& playersInfo);

	UFUNCTION(Client, Reliable, WithValidation)
	void Client_UpdateReadyState(const FMultiplayerPlayerInfo& changedPlayer);

	UFUNCTION(Client, Reliable, WithValidation)
	void Client_PossesNewCharacter(ACharacter* playerCharacter);



	/*Limiting View Extent In Lobby Functions*/

	void SetViewYawExtents(float minYaw, float maxYaw);

	void SetViewPitchExtents(float minPitch, float maxPitch);

	
};

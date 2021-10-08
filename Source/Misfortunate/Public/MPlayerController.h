// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MPlayerController.generated.h"

class ALoreTablet;


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FInteractClicked);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FNextPageClicked);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPrevPageClicked);


USTRUCT(BlueprintType)
struct FPlayerInfo {

	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
		FString PlayerName;
	UPROPERTY(BlueprintReadWrite)
		UTexture2D* PlayerIcon;

	FPlayerInfo()
	{
		PlayerName = "NONE";
		PlayerIcon = nullptr;
	}

};

UCLASS()
class MISFORTUNATE_API AMPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:

	UPROPERTY()
		TSubclassOf<class UWJournal> JournalWidgetClass;

	UPROPERTY()
		TSubclassOf<class UWInteraction> InteractionWidgetClass;


	UPROPERTY()
		TSubclassOf<class UWInteraction> HUDWidgetClass;

	UPROPERTY()
		class UWInteraction* InteractionWidget;

	UPROPERTY()
		class UWJournal* JournalWidget;

	//UPROPERTY()
		//class UUserWidget* HUDWidget;

	
	/*Lobby Variables*/

	UPROPERTY()
		TSubclassOf<class UWLobbyMenu> LobbyWidgetClass;

	UPROPERTY()
		TSubclassOf<class UWPlayerStatus> PlayerStatusWidgetClass;

	UPROPERTY(BlueprintReadOnly)
		class UWLobbyMenu* LobbyWidget;

	
	UPROPERTY(BlueprintReadWrite)
		bool IsReady;

	/*Lobby Variables*/


	TArray<ALoreTablet*> CollectedTablets;

public:

	UPROPERTY(BlueprintReadWrite,Replicated)
		FPlayerInfo PlayerInfo;

	UPROPERTY(BlueprintReadWrite, Replicated)
		TArray<FPlayerInfo> AllPlayersInfo;

	AMPlayerController();


	UPROPERTY()
		FInteractClicked InteractClicked;

	UPROPERTY()
		FNextPageClicked NextPageClicked;

	UPROPERTY()
		FPrevPageClicked PrevPageClicked;
	
public:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;


	// Called to bind functionality to input
	virtual void SetupInputComponent() override;

	virtual void PawnLeavingGame() override;

	// Delegate Functions
	void InteractionOccurred();

	void NextPageInteraction();

	void PrevPageInteraction();

	void ToggleJournal();
	// Delegate Functions

	void DisplayTabletInteraction(ALoreTablet* tablet);

	void HideInteraction();

	void AddToTabletsCollected(ALoreTablet* tablet);

	void AddTabletsToAllPlayers(ALoreTablet* tablet);

	UFUNCTION(Server, Reliable, WithValidation)
		void Server_AddTabletsToAllPlayers(ALoreTablet* tablet);

	UFUNCTION(Server, Reliable, WithValidation,BlueprintCallable)
		void Server_CallUpdate(FPlayerInfo playerInfo_);

	UFUNCTION(Client, Reliable, WithValidation)
		void Client_AddToTabletsCollected(ALoreTablet* tablet);

	UFUNCTION(Client, Reliable, WithValidation)
		void Client_AddPlayersToList(const TArray<FPlayerInfo>& playersInfo);

	UFUNCTION(Client, Reliable, WithValidation)
		void Client_InitalizeLobbyInfo();

	UFUNCTION(Client, Reliable, WithValidation)
		void Client_UpdateReadyState(AMPlayerController* playerController);
	
	UFUNCTION(Client, Reliable, WithValidation)
		void Client_PossesNewCharacter(ACharacter* playerCharacter);


	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	

	UFUNCTION(BlueprintImplementableEvent,BlueprintCallable)
		void UpdatePlayerInfo();

	UFUNCTION(BlueprintImplementableEvent)
		void AddPlayerStatusWidget(const TArray<FPlayerInfo>& playerInfoList);

	UFUNCTION(BlueprintImplementableEvent)
		void UpdateReadyState(AMPlayerController* playerController);

	void SetViewYawExtents(float minYaw, float maxYaw);

	void SetViewPitchExtents(float minPitch, float maxPitch);

public:
	TArray<ALoreTablet*> GetCollectedTablets();


	
	
};

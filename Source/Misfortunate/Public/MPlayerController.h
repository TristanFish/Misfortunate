// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MPlayerController.generated.h"

class ALoreTablet;


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FInteractClicked);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FNextPageClicked);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPrevPageClicked);


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
		class UUserWidget* InteractionWidget;

	UPROPERTY()
		class UUserWidget* JournalWidget;

	TArray<ALoreTablet*> CollectedTablets;

public:

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

	UFUNCTION(Client, Reliable, WithValidation)
		void Client_AddToTabletsCollected(ALoreTablet* tablet);



public:
	TArray<ALoreTablet*> GetCollectedTablets();


	
	
};

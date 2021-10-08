// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "MPlayerController.h"
#include "BlueprintDataDefinitions.h"	

#include "WLobbyMenu.generated.h"

/**
 * 
 */
UCLASS()
class MISFORTUNATE_API UWLobbyMenu : public UUserWidget
{
	GENERATED_BODY()
	

public:

	UPROPERTY(BlueprintReadWrite)
		TArray<class UWPlayerStatus*> PlayerStatusList;

public:


	virtual void NativeConstruct() override;

	


	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		class UScaleBox* Host_Box = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		class UScaleBox* Client_Box = nullptr;


	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		class UButton* OptionsButton = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		class UButton* QuitButton = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		class UButton* ReadyButton = nullptr;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void AddNewPlayer(FPlayerInfo playerInfo);

	UFUNCTION(BlueprintCallable)
		void UpdatePlayerImage(const FBPUniqueNetId& unqiueNetID, const FString& playerName);

	UFUNCTION(BlueprintCallable)
		void AddToPlayerList(class UWPlayerStatus* playerStatus);


protected:

	UFUNCTION()
		void OnQuitButtonClicked();

	UFUNCTION()
		void OnReadyButtonClicked();

	UFUNCTION()
		void OnOptionsButtonClicked();
};

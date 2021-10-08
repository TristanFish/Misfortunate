// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WPlayOptions.generated.h"

/**
 * 
 */
UCLASS()
class MISFORTUNATE_API UWPlayOptions : public UUserWidget
{
	GENERATED_BODY()
public:

	virtual void NativeConstruct() override;



	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		class UButton* JoinButton = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		class UButton* CreateButton = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		class UWActiveGames* W_ActiveGames = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		class UWCreateGame* W_CreateGame = nullptr;


protected:

	UFUNCTION()
		void OnJoinButtonClicked();
	UFUNCTION()
		void OnCreateButtonClicked();

	UFUNCTION() 
		void OnBackFromNewMenu();
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WActiveGames.generated.h"

/**
 * 
 */
UCLASS()
class MISFORTUNATE_API UWActiveGames : public UUserWidget
{
	GENERATED_BODY()
	
public:

	virtual void NativeConstruct() override;


	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		class UButton* BackButton = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		class UButton* RefreshButton = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		class UScrollBox* GamesScrollBox = nullptr;

protected:

	class UDefaultGameInstance* GameInstance;

	UPROPERTY(EditAnywhere, Category = "Class Types")
	TSubclassOf<UUserWidget> SlotClass;

	UFUNCTION()
		void RefreshActiveGames();


	UFUNCTION(BlueprintCallable)
		void UpdateGamesScrollBox();

};

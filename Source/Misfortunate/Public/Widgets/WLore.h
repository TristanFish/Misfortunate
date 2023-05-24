// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/BackgroundBlur.h"
#include "WLore.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class MISFORTUNATE_API UWLore : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;


	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		class UTextBlock* LoreText = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		class UTextBlock* LoreTitle = nullptr;

	void SetLoreInfo(FString LoreText_, FString LoreTitle_);



	UFUNCTION()
		void DisplayLoreInfo();
};

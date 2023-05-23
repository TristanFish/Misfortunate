// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WPlayerHUD.generated.h"

/**
 * 
 */
UCLASS()
class MISFORTUNATE_API UWPlayerHUD : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		class UWMisfortune* W_Misfortune = nullptr; 

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		class UWStamina* W_Stamina = nullptr;

	virtual void NativeConstruct() override;

	
};

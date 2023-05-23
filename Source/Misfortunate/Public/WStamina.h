// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WStamina.generated.h"

/**
 * 
 */
UCLASS()
class MISFORTUNATE_API UWStamina : public UUserWidget
{
	GENERATED_BODY()


public:

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UProgressBar* Stamina = nullptr;


	virtual void NativeConstruct() override;
	
};

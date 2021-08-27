// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h"

#include "W_Battery.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class MISFORTUNATE_API UW_Battery : public UUserWidget
{
	GENERATED_BODY()

protected:


	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		UProgressBar* BatteryLevel;

public:


	void SetBatteryLevel(const float level_);
	
};

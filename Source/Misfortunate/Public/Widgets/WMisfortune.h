// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WMisfortune.generated.h"

/**
 * 
 */
UCLASS()
class MISFORTUNATE_API UWMisfortune : public UUserWidget
{
	GENERATED_BODY()


public:

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		class UProgressBar* Misfortune = nullptr;
	
public:

	virtual void NativeConstruct() override;


};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WPlayerStatus.generated.h"

/**
 * 
 */
UCLASS()
class MISFORTUNATE_API UWPlayerStatus : public UUserWidget
{
	GENERATED_BODY()
	
public:

	virtual void NativeConstruct() override;


	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UTextBlock* PlayerName = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		class UImage* IconTexture = nullptr;

};

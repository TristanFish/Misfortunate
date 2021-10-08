// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WCreateGame.generated.h"

/**
 * 
 */
UCLASS()
class MISFORTUNATE_API UWCreateGame : public UUserWidget
{
	GENERATED_BODY()
public:

	virtual void NativeConstruct() override;


	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		class UCheckBox* NetMode = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		class UTextBlock* ServerName = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		class UTextBlock* NetworkModeText = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		class UEditableTextBox* ServerNameTextBox = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		class UButton* ContinueButton = nullptr;


protected:

	UFUNCTION()
		void OnContinueButtonClicked();
};

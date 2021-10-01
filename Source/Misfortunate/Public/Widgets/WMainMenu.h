// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WMainMenu.generated.h"

/**
 * 
 */
UCLASS()
class MISFORTUNATE_API UWMainMenu : public UUserWidget
{
	GENERATED_BODY()
	

public:
	virtual void NativeConstruct() override;


	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		class UButton* PlayButton = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		class UButton* OptionsButton = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		class UButton* QuitButton = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		class UWPlayOptions* W_PlayOptions = nullptr;

protected:


	UFUNCTION()
		void OnPlayButtonClicked();

	UFUNCTION()
		void OnOptionsButtonClicked();

	UFUNCTION()
		void OnQuitButtonClicked();
};

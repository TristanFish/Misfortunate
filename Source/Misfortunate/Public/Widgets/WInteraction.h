// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "WInteraction.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class MISFORTUNATE_API UWInteraction : public UUserWidget
{
	GENERATED_BODY()
	

public:

	UPROPERTY(BlueprintReadOnly, Transient, meta = (BindWidgetAnim))
		class UWidgetAnimation* FadeOutAnim = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		 UTextBlock* InteractText = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		 UTextBlock* InteractMessageText = nullptr;

	virtual void NativeConstruct() override;

	void BindDelegate();

	void UnBindDelegate();

	UFUNCTION()
		void InteractionMessage();

	void PlayInteractionAnim();


	void SetLatestTablet(class ALoreTablet* tablet);

protected:

	class ALoreTablet* LatestTablet;

	UFUNCTION()
		void OnFadeOutAnimationFinished();
private:

	FWidgetAnimationDynamicEvent EndAnimDelegate;


};

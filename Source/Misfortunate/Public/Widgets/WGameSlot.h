// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "FindSessionsCallbackProxy.h"

#include "WGameSlot.generated.h"

/**
 * 
 */
UCLASS()
class MISFORTUNATE_API UWGameSlot : public UUserWidget
{
	GENERATED_BODY()


public:

	virtual void NativeConstruct() override;


	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* NameText = nullptr;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* PingText = nullptr;
	
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		class UButton* ServerSlotButton = nullptr;

	void SetLinkedGame(const FBlueprintSessionResult& game);
protected:

	UPROPERTY(BlueprintReadOnly)
		FBlueprintSessionResult LinkedGame;

	UFUNCTION()
		void OnServerSlotClicked();

	UFUNCTION(BlueprintImplementableEvent)
		void GetGameSettings();
};

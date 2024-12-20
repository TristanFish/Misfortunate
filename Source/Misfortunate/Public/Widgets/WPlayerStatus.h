// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "BlueprintDataDefinitions.h"	
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

	UPROPERTY(BlueprintReadOnly)
		FString CurrentPlayerName;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UTextBlock* PlayerName = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		class UImage* IconTexture = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		class UBorder* ItemBorder = nullptr;

	UFUNCTION(BlueprintImplementableEvent)
		void SetUserImage(const struct FBPUniqueNetId& unqiueNetID);


	UFUNCTION(BlueprintCallable)
		void InitPlayerStatus(FString PlayerName_, UTexture2D* IconImage);

	UFUNCTION(BlueprintCallable)
		void UpdateReadyState(bool ReadyState_);

	FString GetPlayerName() const;

	bool IsReady() const;
protected:

	

	bool ReadyState;
	


};

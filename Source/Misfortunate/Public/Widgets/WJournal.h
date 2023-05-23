// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WJournal.generated.h"

/**
 * 
 */
UCLASS()
class MISFORTUNATE_API UWJournal : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

	 bool Initialize() override;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		class UTextBlock* CurrentLoreOwner = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		class UTextBlock* LoreOwnerInfo = nullptr;

	UPROPERTY(BlueprintReadOnly, Transient, meta = (BindWidget))
		class UVerticalBox* LoreBox = nullptr;

	UPROPERTY(BlueprintReadOnly, Transient, meta = (BindWidgetAnim))
		class UWidgetAnimation* JournalOpenAnim = nullptr;


	UPROPERTY(BlueprintReadWrite)
		FString CurrentLoreOwnerViewed;
public:

	UFUNCTION()
		void ToPreviousPage();

	UFUNCTION()
		void ToNextPage();

	void BindPageDelegates();

	void UnBindPageDelegates();


private:

	bool JournalHasOpened;

private:


	void UpdatePageProperties();

};

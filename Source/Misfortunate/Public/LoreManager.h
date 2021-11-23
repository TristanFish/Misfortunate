// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Engine/DataTable.h"
#include "Actors/LoreTablet.h"
#include "LoreManager.generated.h"

USTRUCT(BlueprintType)
struct FLoreInfo : public FTableRowBase
{
	GENERATED_BODY()


	/*The text the corresponds with the lore title*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString LoreTitle;

	/*The text the corresponds with the lore*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FString LoreText;
};

UCLASS()
class MISFORTUNATE_API ALoreManager : public AActor
{

	GENERATED_BODY()

public:
	ALoreManager();
	
	

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		TArray<AActor*> LoreTablets;

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UDataTable* LoreDataTable;

private:

	void InitTablets();



};

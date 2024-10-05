// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "GameplayTagContainer.h"


#include "BasePuzzleGoal.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType,editinlinenew)
class MISFORTUNATE_API UBasePuzzleGoal : public UObject
{
	GENERATED_BODY()


public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTag GoalGameplayTag;
	

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bHasGoalBeenReached;


	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void PerformGoal();



	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void ResetPuzzleGoal();

};

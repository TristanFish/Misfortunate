// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameplayTagsManager.h"
#include "MisfortunateFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class MISFORTUNATE_API UMisfortunateFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()


	UFUNCTION(BlueprintPure, Category = "GameplayTags")
	static bool TryRequestGameplayTag(FName TagName, FGameplayTag& Tag);
	
};

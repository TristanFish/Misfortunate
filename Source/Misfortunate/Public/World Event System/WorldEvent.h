// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "Libraries/MisfortunateEnumLibrary.h"

#include "WorldEvent.generated.h"


class AActor;
/**
 * 
 */
UCLASS(Blueprintable, BlueprintType, editinlinenew, Meta = (ShowWorldContextPin))
class MISFORTUNATE_API UWorldEvent : public UObject
{
	GENERATED_BODY()



public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void InitializeWorldEvent(AActor* WorldContext);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void ActivateWorldEvent();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void PostWorldEventActivated();

	
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="World Event")
	TEnumAsByte<WorldEventOccuranceType> EventOccuranceType; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "World Event")
	TEnumAsByte<WorldEventPlayerType> EventPlayerType;
	
	UPROPERTY(BlueprintReadOnly, Category = "World Event")
	AActor* WorldContextActor;


	UPROPERTY(BlueprintReadWrite, Category = "World Event")
	int bTimesEventHasBeenActivated;


};

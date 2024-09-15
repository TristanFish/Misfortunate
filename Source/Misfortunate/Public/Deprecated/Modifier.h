// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Modifier.generated.h"

/**
 * 
 */


UENUM(BlueprintType, meta = (Bitflags, UseEnumValuesAsMaskValuesInEditor = "true"))
enum class EModifierTypes: uint8
{
	NONE = 0 UMETA(Hidden),
	POSITIVE = 1 << 0,
	NEGATIVE = 1 << 1,
	GLOBAL = 1 << 2,
	LOCAL = 1 << 3,
	TIMED = 1 << 4,
	INFINITE = 1 << 5,

};
ENUM_CLASS_FLAGS(EModifierTypes);


UCLASS(Blueprintable,BlueprintType)
class MISFORTUNATE_API UModifier : public UObject
{
	GENERATED_BODY()





public:

	UModifier();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (Bitmask, BitmaskEnum = EModifierTypes))
		int32 ModifierFlags = 0;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText ModifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float TimeTillStop;

	FTimerHandle StopTimer;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class APlayerCharacter* OwningPlayer;

	
	UFUNCTION(BlueprintNativeEvent)
		 void StartModifier();

	UFUNCTION(BlueprintNativeEvent)
		 void StopModifier();


	UFUNCTION(BlueprintCallable)
		bool HasModifiers(UPARAM(meta = (Bitmask, BitmaskEnum = EAnimDescriptorFlags)) int32 BitmaskModifiers);


	void SetModifierManager(class AModifierManager* ModiferManager);

private:
	class AModifierManager* ModiferManager;


	

};

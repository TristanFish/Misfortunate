// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/Animation/AnimInstance.h"
#include "CustomAnimInstance.generated.h"

/**
 * 
 */
UCLASS(transient,Blueprintable,hideCategories=AnimInstance,BlueprintType)
class UCustomAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UCustomAnimInstance();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class APlayerCharacter* CharPlayer;

	//!Speed float 
	/*!Handles the speed of the animation*/
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "Generic")
		float speed;

	//!Direction float 
	/*!Handles the direction of the animation*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generic")
		float direction;

	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Generic")
		float oldMovementDir;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Generic")
		float BackwardDir;

	//!IsInAir Bool 
	/*!Updated when player is/isnt in air (Used for jumping)*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generic")
		bool IsInAir;

	//!IsCrawling Bool 
	/*!Updated when player is/isnt crawling*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generic")
		bool IsCrouched;



	//!NativeUpdateAnimation Function 
	/*!Updates the current animations variables while the animation runs*/
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	//!NativeUpdateAnimation Function 
	/*!Updates the current animations variables while the animation runs*/
	virtual void NativeBeginPlay() override;
};

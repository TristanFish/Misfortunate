// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "InputAction.h"
#include "MisfortunateInputConfig.generated.h"

/**
 * 
 */
UCLASS()
class MISFORTUNATE_API UMisfortunateInputConfig : public UDataAsset
{
	GENERATED_BODY()

public:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
        UInputAction* InputMove;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
        UInputAction* InputTurn;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
        UInputAction* InputInteract;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
        UInputAction* InputSprint;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
        UInputAction* InputThrow;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
        UInputAction* InputCrouch;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
        UInputAction* InputToggleJournal;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
        UInputAction* InputToggleLight;
	
};

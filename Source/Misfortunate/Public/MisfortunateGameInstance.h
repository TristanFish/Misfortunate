// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"

#include "MisfortunateGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class MISFORTUNATE_API UMisfortunateGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	

	UMisfortunateGameInstance();

	//!Init Function
	/*!Initializes any needed variables when the game is started*/
	virtual void Init() override;

protected:

	
};

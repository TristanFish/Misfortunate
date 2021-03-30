// Fill out your copyright notice in the Description page of Project Settings.

#pragma once



#include "GameFramework/Actor.h"
#include "HeadLamp.generated.h"



UCLASS(Config = ConfigName)
class AHeadLampInfo : public AActor
{
	GENERATED_BODY()


public:
	// Sets default values for this character's properties
	AHeadLampInfo();

	

	//!TickStaminaTimerHandle FTimerHandler
	/*!Used to create a battery timer*/
	

	virtual void BeginPlay() override;

};

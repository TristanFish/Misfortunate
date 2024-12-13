// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WorldEventManager.generated.h"


class UWorldEvent;



UCLASS(Blueprintable, BlueprintType)
class MISFORTUNATE_API AWorldEventManager : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AWorldEventManager();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced, Category = "World Event Manager")
	TArray<UWorldEvent*> WorldEvents;


};

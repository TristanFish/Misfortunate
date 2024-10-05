// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BasePuzzle.generated.h"


class UBasePuzzleGoal;

UCLASS(Blueprintable, BlueprintType)
class MISFORTUNATE_API ABasePuzzle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABasePuzzle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;



	UPROPERTY(EditAnywhere,BlueprintReadWrite, Instanced, Category = "Puzzle|Goals")
	TArray<class UBasePuzzleGoal*> PuzzleGoals;

};

// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePuzzle.h"

#include "BasePuzzleGoal.h"

// Sets default values
ABasePuzzle::ABasePuzzle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABasePuzzle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABasePuzzle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


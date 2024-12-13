// Fill out your copyright notice in the Description page of Project Settings.


#include "World Event System/WorldEventManager.h"

// Sets default values
AWorldEventManager::AWorldEventManager()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWorldEventManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWorldEventManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}




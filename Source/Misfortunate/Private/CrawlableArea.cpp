// Fill out your copyright notice in the Description page of Project Settings.


#include "CrawlableArea.h"

// Sets default values
ACrawlableArea::ACrawlableArea()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACrawlableArea::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACrawlableArea::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


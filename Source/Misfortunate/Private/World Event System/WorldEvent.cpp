// Fill out your copyright notice in the Description page of Project Settings.


#include "World Event System/WorldEvent.h"
#include "GameFramework/Actor.h"

void UWorldEvent::ActivateWorldEvent_Implementation()
{
	bTimesEventHasBeenActivated += 1;
}

void UWorldEvent::InitializeWorldEvent_Implementation(AActor* WorldContext)
{
	WorldContextActor = WorldContext;
}

void UWorldEvent::PostWorldEventActivated_Implementation()
{
}

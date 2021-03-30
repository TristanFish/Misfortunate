// Fill out your copyright notice in the Description page of Project Settings.


#include "MisfortunateGameInstance.h"
#include "Kismet/GameplayStatics.h"

UMisfortunateGameInstance::UMisfortunateGameInstance()
{
	scareManager = Cast<AScareEventManager>(UGameplayStatics::GetActorOfClass(GetWorld(), AScareEventManager::StaticClass()));
}

void UMisfortunateGameInstance::Init()
{
	scareManager = Cast<AScareEventManager>(UGameplayStatics::GetActorOfClass(GetWorld(), AScareEventManager::StaticClass()));
}

AScareEventManager* UMisfortunateGameInstance::GetScareEventManager() const{

	return scareManager;
}

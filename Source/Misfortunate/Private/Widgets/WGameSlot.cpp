// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/WGameSlot.h"

#include "DefaultGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Components/Button.h"


void UWGameSlot::NativeConstruct()
{
	ServerSlotButton->OnClicked.AddDynamic(this, &UWGameSlot::OnServerSlotClicked);

	
	

}

void UWGameSlot::SetLinkedGame(const FBlueprintSessionResult& game)
{
	LinkedGame = game;
	GetGameSettings();
}

void UWGameSlot::OnServerSlotClicked()
{
	UDefaultGameInstance* gameInstance = Cast<UDefaultGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));

	gameInstance->JoinActiveSession(LinkedGame);


}

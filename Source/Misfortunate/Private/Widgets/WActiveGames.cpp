// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/WActiveGames.h"

#include "Components/Button.h"
#include "Components/ScrollBox.h"

#include "Kismet/GameplayStatics.h"
#include "DefaultGameInstance.h"

#include "Widgets/WGameSlot.h"
void UWActiveGames::NativeConstruct()
{
	RefreshButton->OnClicked.AddDynamic(this, &UWActiveGames::RefreshActiveGames);
	GameInstance = Cast<UDefaultGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));

	RefreshActiveGames();
}

void UWActiveGames::RefreshActiveGames()
{
	GameInstance->UpdateActiveSessions(this);
}

void UWActiveGames::UpdateGamesScrollBox()
{
	GamesScrollBox->ClearChildren();
	for (auto game : GameInstance->GetActiveSessions())
	{
		UWGameSlot* slot = CreateWidget<UWGameSlot>(GetWorld(), SlotClass);
		GamesScrollBox->AddChild(slot);
		slot->SetLinkedGame(game);
	}
}

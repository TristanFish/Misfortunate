// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/WLobbyMenu.h"

#include "Components/Button.h"
#include "Components/ScaleBox.h"

#include "Widgets/WPlayerStatus.h"

#include "Kismet/GameplayStatics.h"

#include "MPlayerController.h"
#include "MisfortunateGameMode.h"

void UWLobbyMenu::NativeConstruct()
{
	OptionsButton->OnClicked.AddDynamic(this, &UWLobbyMenu::OnOptionsButtonClicked);
	QuitButton->OnClicked.AddDynamic(this, &UWLobbyMenu::OnQuitButtonClicked);
	ReadyButton->OnClicked.AddDynamic(this, &UWLobbyMenu::OnReadyButtonClicked);
	StartButton->OnClicked.AddDynamic(this, &UWLobbyMenu::OnStartButtonClicked);

	if (GetOwningPlayer()->GetNetMode() != ENetMode::NM_ListenServer)
	{
		StartButton->bIsEnabled = false;
		StartButton->SetVisibility(ESlateVisibility::Hidden);
	}

}

void UWLobbyMenu::UpdatePlayerImage(const FBPUniqueNetId& unqiueNetID, const FString& playerName)
{
	for (UWPlayerStatus* status : PlayerStatusList)
	{
		if (status->GetPlayerName() == playerName)
		{
			status->SetUserImage(unqiueNetID);
		}
	}
}

void UWLobbyMenu::AddToPlayerList(UWPlayerStatus* playerStatus)
{
	PlayerStatusList.Add(playerStatus);

	if (Host_Box->HasAnyChildren())
	{
		Client_Box->AddChild(playerStatus);
	}
	else
	{
		Host_Box->AddChild(playerStatus);
	}
}

void UWLobbyMenu::ClearStatusList()
{
	PlayerStatusList.Empty();

	Client_Box->ClearChildren();
	Host_Box->ClearChildren();
}

void UWLobbyMenu::OnQuitButtonClicked()
{

}

void UWLobbyMenu::OnReadyButtonClicked()
{
	AMPlayerController* player = Cast<AMPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));


	player->Server_UpdateReadyState(player);
}

void UWLobbyMenu::OnOptionsButtonClicked()
{

}

void UWLobbyMenu::OnStartButtonClicked()
{
	int PlayersReady = 0;

	for (auto status : PlayerStatusList)
	{
		if (status->IsReady())
			PlayersReady++;
	}

	if (PlayersReady == PlayerStatusList.Num())
	{
		AMisfortunateGameMode* gameMode = Cast<AMisfortunateGameMode>(UGameplayStatics::GetGameMode(GetWorld()));

		gameMode->OnHostStart();
	}
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "MisfortuneManager.h"

#include "Net/UnrealNetwork.h"
#include "Kismet/GameplayStatics.h"

#include "GameFramework/GameStateBase.h"

#include "GameFramework/PlayerState.h"


#include "PlayerCharacter.h"


// Sets default values
AMisfortuneManager::AMisfortuneManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;
}

// Called when the game starts or when spawned
void AMisfortuneManager::BeginPlay()
{
	Super::BeginPlay();
	

	PopulatePlayerMisfortuneData();
}

// Called every frame
void AMisfortuneManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMisfortuneManager::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{

	Super::GetLifetimeReplicatedProps(OutLifetimeProps);


	DOREPLIFETIME(AMisfortuneManager, PlayerMisfortuneDataList);

}

void AMisfortuneManager::OnRep_MisfortuneData()
{
	
	APlayerCharacter* LocalPlayerChar = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn());

	FString PlayerName = LocalPlayerChar->GetPlayerState()->GetPlayerName();

	LocalPlayerChar->LocalMisfortune = GetPlayerMisfortuneData(PlayerName).Misfortune;



}

void AMisfortuneManager::PopulatePlayerMisfortuneData()
{

	for (auto PlayerState : UGameplayStatics::GetGameState(GetWorld())->PlayerArray)
	{
		FPlayerMisfortuneData PlayerData = FPlayerMisfortuneData(PlayerState->GetPlayerName());

		PlayerMisfortuneDataList.Add(PlayerData);
	}

}

FPlayerMisfortuneData AMisfortuneManager::GetPlayerMisfortuneData(const FString& PlayerName)
{
	for (auto MisfortuneData : PlayerMisfortuneDataList)
	{
		if (PlayerName == MisfortuneData.PlayerName)
		{
			return MisfortuneData;
		}
	}

	return FPlayerMisfortuneData();
}

void AMisfortuneManager::IncreaseMisfortune(const float Misfortune_, const FString& PlayerName)
{

	FPlayerMisfortuneData PlayerData = GetPlayerMisfortuneData(PlayerName);


	if (PlayerData.bCanMisfortuneIncrease)
	{
		float ModifiedMisfortune = FMath::Clamp(Misfortune_, 0.0f, PlayerData.MaxMisfortuneChange);
		SetPlayerMisfortune(FMath::Clamp(PlayerData.Misfortune + ModifiedMisfortune, 0.0f, PlayerData.MaxMisfortune), PlayerName);

		
	}
}

void AMisfortuneManager::DecreaseMisfortune(const float Misfortune_, const FString& PlayerName)
{

	FPlayerMisfortuneData PlayerData = GetPlayerMisfortuneData(PlayerName);

	float ModifiedMisfortune = FMath::Clamp(Misfortune_, 0.0f, PlayerData.MaxMisfortuneChange);
	SetPlayerMisfortune(FMath::Clamp(PlayerData.Misfortune - ModifiedMisfortune, 0.0f, PlayerData.MaxMisfortune), PlayerName);

	
}

void AMisfortuneManager::SetPlayerMisfortune(const float Misfortune_, const FString& PlayerName)
{
	if (GetNetMode() == ENetMode::NM_ListenServer)
	{
		for (auto MisfortuneData : PlayerMisfortuneDataList)
		{
			if (PlayerName == MisfortuneData.PlayerName)
			{
				MisfortuneData.Misfortune = Misfortune_;
			}
		}
	}
	else
	{
		Server_SetMisfortune(Misfortune_, PlayerName);
	}
	
}

void AMisfortuneManager::SetPlayerMaxMisfortuneChange(const float MaxMisfortuneChange_, const FString& PlayerName)
{
	if (GetNetMode() == ENetMode::NM_ListenServer)
	{
		for (auto MisfortuneData : PlayerMisfortuneDataList)
		{
			if (PlayerName == MisfortuneData.PlayerName)
			{
				MisfortuneData.MaxMisfortuneChange = FMath::Clamp(MaxMisfortuneChange_, 0.0f, 100.0f);
			}
		}
	}
	else
	{
		Server_SetMaxMisfortuneChanged(MaxMisfortuneChange_, PlayerName);
	}
}

float AMisfortuneManager::GetCombinedMisfortune()
{
	float CombinedMisfortune = 0.0f;
	for (auto MisfortuneData : PlayerMisfortuneDataList)
	{
		
		CombinedMisfortune += MisfortuneData.Misfortune;
	}

	return CombinedMisfortune;
}

float AMisfortuneManager::GetAverageMisfortune()
{
	return (GetCombinedMisfortune() / PlayerMisfortuneDataList.Num());
}

float AMisfortuneManager::GetPlayerMisfortune(const FString& PlayerName)
{
	for (auto MisfortuneData : PlayerMisfortuneDataList)
	{
		if (MisfortuneData.PlayerName == PlayerName)
		{
			return MisfortuneData.Misfortune;
		}
	}
	return 0.0f;
}

float AMisfortuneManager::GetPlayerMaxMisfortune(const FString& PlayerName)
{
	for (auto MisfortuneData : PlayerMisfortuneDataList)
	{
		if (MisfortuneData.PlayerName == PlayerName)
		{
			return MisfortuneData.MaxMisfortune;
		}
	}

	return 0.0f;
}

FString AMisfortuneManager::GetPlayerNameWithHighestMisfortune()
{
	float HighestMisfortune;
	for (int i = 0; i < PlayerMisfortuneDataList.Num(); i++)
	{
		if (PlayerMisfortuneDataList.IsValidIndex(i + 1))
		{
			HighestMisfortune = FMath::Max(PlayerMisfortuneDataList[i].Misfortune, PlayerMisfortuneDataList[i + 1].Misfortune);
		}
	}

	for (auto MisfortuneData : PlayerMisfortuneDataList)
	{
		if (MisfortuneData.Misfortune == HighestMisfortune)
		{
			return MisfortuneData.PlayerName;
		}
	}

	return FString("No Name Found");
}


void AMisfortuneManager::Server_ChangeCanMisfortuneIncrease_Implementation(const bool bCanMisfortuneIncrease, const FString& PlayerName)
{
}

void AMisfortuneManager::SetOtherPlayersMaxMisfortuneChange(const float MaxMisfortuneChange_, const FString& PlayerName)
{
	if (GetNetMode() == ENetMode::NM_ListenServer)
	{
		for (auto MisfortuneData : PlayerMisfortuneDataList)
		{

			if (MisfortuneData.PlayerName != PlayerName)
			{
				MisfortuneData.MaxMisfortuneChange = FMath::Clamp(MaxMisfortuneChange_, 0.0f, 100.0f);
			}
		}
	}
	else
	{
		Server_SetMaxMisfortuneChanged(MaxMisfortuneChange_, PlayerName);
	}
}



void AMisfortuneManager::Server_SetMaxMisfortuneChanged_Implementation(const float MaxMisfortuneChange_, const FString& PlayerName)
{
	for (auto MisfortuneData : PlayerMisfortuneDataList)
	{
		if (PlayerName == MisfortuneData.PlayerName)
		{
			MisfortuneData.MaxMisfortuneChange = FMath::Clamp(MaxMisfortuneChange_, 0.0f, 100.0f);;
		}
	}
}



void AMisfortuneManager::Server_SetMisfortune_Implementation(const float Misfortune_, const FString& PlayerName)
{
	for (auto MisfortuneData : PlayerMisfortuneDataList)
	{
		if (PlayerName == MisfortuneData.PlayerName)
		{
			MisfortuneData.Misfortune = Misfortune_;
		}
	}

	OnMisfortuneChanged.Broadcast(Misfortune_, PlayerName);

}


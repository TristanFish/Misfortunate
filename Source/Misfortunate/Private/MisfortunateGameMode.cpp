// Copyright Epic Games, Inc. All Rights Reserved.

#include "MisfortunateGameMode.h"
#include "MisfortunateHUD.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"

#include "MPlayerController.h"
#include "PlayerCharacter.h"
#include "LobbyPlayerCharacter.h"

#include "ScareEventManager.h"
#include "LoreManager.h"
#include "Actors/EventZone.h"
#include "GameFramework/PlayerState.h"
#include "Widgets/WLobbyMenu.h"

AMisfortunateGameMode::AMisfortunateGameMode(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Misfortuante/Blueprints/Actors/Player_BP"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	static ConstructorHelpers::FClassFinder<AMPlayerController> PlayerControllerClassFinder(TEXT("/Game/Misfortuante/Blueprints/M_PlayerController"));

	PlayerControllerClass = PlayerControllerClassFinder.Class;

	DistanceBetweenPlayers = 0.0f;


	EventChance = 15;
}

void AMisfortunateGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);
	ConnectedPlayers.AddUnique(NewPlayer);


	if (CurrentState == UGameState::Lobby)
	{
		for (auto possChar : PossessableCharacters)
		{
			ALobbyPlayerCharacter* lobbyChar = Cast<ALobbyPlayerCharacter>(possChar);
			if (!lobbyChar->HasBeenPossesed)
			{
				Cast<AMPlayerController>(NewPlayer)->Possess(lobbyChar);
				if (GEngine)
					GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("Player Possesed"));
			}
		}

		InitPlayerInfo(Cast<AMPlayerController>(NewPlayer));
		EveryoneUpdate();
	}


	else if (CurrentState == UGameState::Exploration)
	{
		if (PossessableCharacters.Num() == 0)
		{
			UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerCharacter::StaticClass(), PossessableCharacters);
		}

		for (auto possChar : PossessableCharacters)
		{
			APlayerCharacter* character = Cast<APlayerCharacter>(possChar);
			if (!character->HasBeenPossesed)
			{
				Cast<AMPlayerController>(NewPlayer)->Possess(character);
				character->HasBeenPossesed = true;
				character->IncreaseMisfortune(FMath::FRandRange(60.0, 85.0));
				break;
			}
		}
	}
}

void AMisfortunateGameMode::Logout(AController* OldPlayer)
{
	ConnectedPlayers.Remove(Cast<APlayerController>(OldPlayer));
	EveryoneUpdate();
}

void AMisfortunateGameMode::BeginPlay()
{

	scareManager = Cast<AScareEventManager>(UGameplayStatics::GetActorOfClass(GetWorld(), AScareEventManager::StaticClass()));
	loreManager = Cast<ALoreManager>(UGameplayStatics::GetActorOfClass(GetWorld(), ALoreManager::StaticClass()));


	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ALobbyPlayerCharacter::StaticClass(), PossessableCharacters);
	

	if (PossessableCharacters.Num() == 0)
	{
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerCharacter::StaticClass(), PossessableCharacters);
	}


	Super::BeginPlay();
}

void AMisfortunateGameMode::EndPlay(EEndPlayReason::Type Reason)
{
	if (GetWorldTimerManager().IsTimerActive(CheckDistTimerHandle))
	{
		GetWorldTimerManager().ClearTimer(CheckDistTimerHandle);
	}
}

void AMisfortunateGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);


}

#pragma region ScareEvent Functions

void AMisfortunateGameMode::CheckPlayersDistance()
{
	int closestDistance = 0;
	FVector PlayerPos_1, PlayerPos_2;

	PlayerPos_1 = ConnectedPlayers[0]->GetPawn()->GetActorLocation();
	for (int i = 1; i < ConnectedPlayers.Num(); i++) {

		PlayerPos_2 = ConnectedPlayers[i]->GetPawn()->GetActorLocation();

		DistanceBetweenPlayers = (PlayerPos_1 - PlayerPos_2).Size();
	}


}

void AMisfortunateGameMode::CheckEventTrigger()
{
	CheckPlayersDistance();
	if (DistanceBetweenPlayers > scareManager->GetScareDistanceThreshold()) {
		if(FMath::RandRange(0, 100) < EventChance){
				
			SelectCharacter();
			TriggerScareEvent();
			EventChance = 15;
		}

		else {

			EventChance += 10;
		}

	}
	
}

void AMisfortunateGameMode::SelectCharacter()
{
	float HighestMisfortune;
	APlayerCharacter* tempCharacter_1;
	APlayerCharacter* tempCharacter_2;
	for (int i = 0; i < ConnectedPlayers.Num(); i++)
	{
		tempCharacter_1 = Cast<APlayerCharacter>(ConnectedPlayers[i]->GetCharacter());
		if (i != ConnectedPlayers.Num() - 1)
		{
			tempCharacter_2 = Cast<APlayerCharacter>(ConnectedPlayers[i +1]->GetCharacter());
			HighestMisfortune = FMath::Max(tempCharacter_1->GetMisfortune(), tempCharacter_2->GetMisfortune());
		}
	}

	for (auto chars : ConnectedPlayers)
	{

		if (Cast<APlayerCharacter>(chars->GetCharacter())->GetMisfortune() == HighestMisfortune)
		{
			selectedCharacter = chars;
		}
	}
}

void AMisfortunateGameMode::TriggerScareEvent()
{

	APlayerCharacter* selectedChar = Cast<APlayerCharacter>(selectedCharacter->GetCharacter());

	if (selectedChar->GetCurrentZone() != nullptr)
	{
		scareManager->TriggerScareEvent(selectedChar);

	}
}

#pragma endregion

void AMisfortunateGameMode::UpdateReadyState(AMPlayerController* changedPlayer)
{
	for (auto player : ConnectedPlayers)
	{

		Cast<AMPlayerController>(player)->Client_UpdateReadyState(changedPlayer->PlayerInfo);
	}

}

void AMisfortunateGameMode::OnHostStart()
{
	PossessableCharacters.Empty();

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerCharacter::StaticClass(), PossessableCharacters);

	for (int i = 0; i < ConnectedPlayers.Num(); i++)
	{
		AMPlayerController* controller = Cast<AMPlayerController>(ConnectedPlayers[i]);

		controller->Multi_SwitchToGame();


		controller->UnPossess();
		controller->Possess(Cast<APlayerCharacter>(PossessableCharacters[i]));
	}

	SetGameState(LobbyExploration);
}

AScareEventManager* AMisfortunateGameMode::GetScareEventManager() const
{
	return scareManager;
}

ALoreManager* AMisfortunateGameMode::GetLoreManager() const
{
	return loreManager;
}

void AMisfortunateGameMode::AddLoreTabletToAllPlayers(class AInteractibleObject* interactibleObject)
{
	for (auto player : ConnectedPlayers)
	{
		Cast<AMPlayerController>(player)->Client_AddToInteractibles(interactibleObject);
	}
}

void AMisfortunateGameMode::ChangeCanMisfortuneIncrease_Implementation(const bool bCanMisfortuneIncrease)
{
	for (auto player : ConnectedPlayers)
	{
		APlayerCharacter* character = Cast<APlayerCharacter>(player->GetCharacter());

		character->bCanMisfortuneIncrease = bCanMisfortuneIncrease;
	}
}

void AMisfortunateGameMode::SetOtherPlayersMaxMisfortuneChange_Implementation(APlayerCharacter* PlayerNotToSet, const float NewMaxMisfortuneChange)
{
	for (auto player : ConnectedPlayers)
	{
		APlayerCharacter* character = Cast<APlayerCharacter>(player->GetCharacter());

		if (PlayerNotToSet != character)
		{
			character->MaxMisfortuneChange = FMath::Clamp(character->MaxMisfortuneChange + NewMaxMisfortuneChange,0.0f, 100.0f);
		}
	}

}

void AMisfortunateGameMode::SetPlayerMaxMisfortuneChange_Implementation(APlayerCharacter* PlayerToSet, const float NewMaxMisfortuneChange)
{
	for (auto player : ConnectedPlayers)
	{
		APlayerCharacter* character = Cast<APlayerCharacter>(player->GetCharacter());

		if (PlayerToSet == character)
		{
			character->MaxMisfortuneChange = FMath::Clamp(character->MaxMisfortuneChange + NewMaxMisfortuneChange, 0.0f, 100.0f);
		}
	}
}

void AMisfortunateGameMode::SetPlayerZone(AEventZone* zone, APlayerCharacter* enteredChar)
{
	for (auto player : ConnectedPlayers)
	{
		APlayerCharacter* character = Cast<APlayerCharacter>(player->GetCharacter());

		if (enteredChar == character)
		{
			character->SetCurrentZone(zone);
		}
	}

}

void AMisfortunateGameMode::SetGameState(TEnumAsByte<UGameState> state_)
{
	CurrentState = state_;
	if (CurrentState == UGameState::Exploration)
	{
		if (scareManager)
		{
			GetWorldTimerManager().SetTimer(CheckDistTimerHandle, this, &AMisfortunateGameMode::CheckEventTrigger, scareManager->GetScareTriggerDelay(), true);
		}
	}
}

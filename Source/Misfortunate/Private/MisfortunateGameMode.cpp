// Copyright Epic Games, Inc. All Rights Reserved.

#include "MisfortunateGameMode.h"
#include "MisfortunateHUD.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"

#include "MPlayerController.h"
#include "PlayerCharacter.h"
#include "LobbyPlayerCharacter.h"

#include "World Event System/ScareEventManager.h"
#include "Deprecated/LoreManager.h"

#include "MisfortuneManager.h"

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

	SetupGameplaySingletons();

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

float AMisfortunateGameMode::GetDistanceBetweenPlayers()
{
	int closestDistance = 0;
	FVector PlayerPos_1, PlayerPos_2;

	PlayerPos_1 = ConnectedPlayers[0]->GetPawn()->GetActorLocation();
	for (int i = 1; i < ConnectedPlayers.Num(); i++) {

		PlayerPos_2 = ConnectedPlayers[i]->GetPawn()->GetActorLocation();

		return (PlayerPos_1 - PlayerPos_2).Size();
	}

	return 0.0f;
}



void AMisfortunateGameMode::CheckEventTrigger()
{


	
	bool HasValidTimeSinceLastScare = ScareManager->HasValidTimeSinceLastScare();


	if (HasValidTimeSinceLastScare) {

		float DistanceBetweenPlayers = GetDistanceBetweenPlayers();
		float CombinedMisfortune = MisfortuneManager->GetCombinedMisfortune();

		int MisfortuneEventChanceModifier =	FMath::GetMappedRangeValueClamped(FVector2D(0, 200), FVector2D(-7, 15), CombinedMisfortune);
		int DistanceEventChanceModifer =	FMath::GetMappedRangeValueClamped(FVector2D(0, 400), FVector2D(-7, 15), DistanceBetweenPlayers);
		
		EventChance = FMath::Clamp(EventChance + MisfortuneEventChanceModifier, 0, 100);
		EventChance = FMath::Clamp(EventChance + DistanceEventChanceModifer, 0, 100);

		if(FMath::RandRange(0, 100) < EventChance){
				
			SelectCharacter();
			TriggerScareEvent();
			EventChance = 15;
		}

		else {

			EventChance += 2;
		}

	}
	
}

void AMisfortunateGameMode::SelectCharacter()
{
	FString PlayerName = MisfortuneManager->GetPlayerNameWithHighestMisfortune();

	for (auto chars : ConnectedPlayers)
	{
		if(chars->GetPlayerState<APlayerState>()->GetPlayerName() == PlayerName)
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
		ScareManager->TriggerScareEvent(selectedChar);

	}
}

void AMisfortunateGameMode::SetupGameplaySingletons()
{
	ScareManager = Cast<AScareEventManager>(UGameplayStatics::GetActorOfClass(GetWorld(), AScareEventManager::StaticClass()));


	LoreManager = Cast<ALoreManager>(UGameplayStatics::GetActorOfClass(GetWorld(), ALoreManager::StaticClass()));


	MisfortuneManager = Cast<AMisfortuneManager>(UGameplayStatics::GetActorOfClass(GetWorld(), AMisfortuneManager::StaticClass()));
	if (!MisfortuneManager)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, FString("No misfortune manager exists in the level"));

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
	return ScareManager;
}

ALoreManager* AMisfortunateGameMode::GetLoreManager() const
{
	return LoreManager;
}

AMisfortuneManager* AMisfortunateGameMode::GetMisfortuneManager() const
{
	if (MisfortuneManager)
	{
		return MisfortuneManager;
	}

	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, FString("Misfortune manager was null when trying to retrieve it"));
	return nullptr;
}

void AMisfortunateGameMode::AddLoreTabletToAllPlayers(class AInteractibleObject* interactibleObject)
{
	for (auto player : ConnectedPlayers)
	{
		Cast<AMPlayerController>(player)->Client_AddToInteractibles(interactibleObject);
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
		if (ScareManager)
		{
			GetWorldTimerManager().SetTimer(CheckDistTimerHandle, this, &AMisfortunateGameMode::CheckEventTrigger, ScareManager->GetScareTriggerDelay(), true);
		}
	}
}

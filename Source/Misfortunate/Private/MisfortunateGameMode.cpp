// Copyright Epic Games, Inc. All Rights Reserved.

#include "MisfortunateGameMode.h"
#include "MisfortunateHUD.h"
#include "MisfortunateCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "MisfortunateGameInstance.h"
#include "PlayerCharacter.h"

AMisfortunateGameMode::AMisfortunateGameMode(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Misfortuante/Blueprints/Player_BP"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AMisfortunateHUD::StaticClass();

	DistanceThreshold = 100.0f;
	DistanceBetweenPlayers = 0.0f;

	EventChance = 95;
}

void AMisfortunateGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);
	ConnectedPlayers.AddUnique(NewPlayer);
}

void AMisfortunateGameMode::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(CheckDistTimerHandle, this, &AMisfortunateGameMode::CheckEventTrigger, 10.5f, true);
}

void AMisfortunateGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);


}

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
	if (DistanceBetweenPlayers > DistanceThreshold) {
		if(FMath::RandRange(0, 100) < EventChance){
				
			selectedCharacter = ConnectedPlayers[FMath::RandRange(0, 1) ];
			TriggerScareEvent();
			EventChance = 15;
		}

		else {

			EventChance += 10;
		}

	}
	
}



void AMisfortunateGameMode::TriggerScareEvent()
{
	UMisfortunateGameInstance* gameInstance = Cast<UMisfortunateGameInstance>(GetGameInstance());

	APlayerCharacter* selectedChar = Cast<APlayerCharacter>(selectedCharacter->GetCharacter());

	if (selectedChar->GetCurrentZone() != nullptr)
	{
		gameInstance->GetScareEventManager()->TriggerScareEvent(selectedChar);

	}
}

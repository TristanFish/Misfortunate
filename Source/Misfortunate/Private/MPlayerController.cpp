// Fill out your copyright notice in the Description page of Project Settings.


#include "MPlayerController.h"
#include "Blueprint/UserWidget.h"

#include "Widgets/WJournal.h"
#include "Widgets/WInteraction.h"
#include "Widgets/WLobbyMenu.h"
#include "Widgets/WPlayerStatus.h"

#include "GameFramework/Character.h"
#include "GameFramework/GameState.h"

#include "Actors/LoreTablet.h"
#include "MisfortunateGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Net/UnrealNetwork.h"



AMPlayerController::AMPlayerController()
{
	static ConstructorHelpers::FClassFinder<UUserWidget> JournalClass(TEXT("/Game/Misfortuante/Blueprints/Widgets/W_Journal"));
	JournalWidgetClass = JournalClass.Class;

	static ConstructorHelpers::FClassFinder<UUserWidget> InteractionClass(TEXT("/Game/Misfortuante/Blueprints/Widgets/W_Interaction"));
	InteractionWidgetClass = InteractionClass.Class;

	static ConstructorHelpers::FClassFinder<UUserWidget> LobbyClass(TEXT("/Game/Misfortuante/Blueprints/Widgets/Menu/W_LobbyMenu"));
	LobbyWidgetClass = LobbyClass.Class;

	//static ConstructorHelpers::FClassFinder<UUserWidget> HUDClass(TEXT("/Game/Misfortuante/Blueprints/Widgets/W_PlayerHUD"));
	//HUDWidgetClass = HUDClass.Class;

	static ConstructorHelpers::FClassFinder<UUserWidget> PlayerStatusClass(TEXT("/Game/Misfortuante/Blueprints/Widgets/Menu/W_PlayerStatus"));
	PlayerStatusWidgetClass = PlayerStatusClass.Class;
	

	bAlwaysRelevant = true;

}

void AMPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	PlayerCameraManager->ViewPitchMin = -70.0f;
	PlayerCameraManager->ViewPitchMax = 65.0f;


	JournalWidget = CreateWidget<UWJournal>(GetWorld(), JournalWidgetClass);
	InteractionWidget = CreateWidget<UWInteraction>(GetWorld(), InteractionWidgetClass);
	//HUDWidgetClass = CreateWidget<UWJournal>(GetWorld(), JournalWidgetClass);

	if(!LobbyWidget)
		LobbyWidget = CreateWidget<UWLobbyMenu>(GetWorld(), LobbyWidgetClass);


	LobbyWidget->AddToViewport();

}

void AMPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
	

}

void AMPlayerController::SetupInputComponent()
{

	Super::SetupInputComponent();
	InputComponent->BindAction("Interact", IE_Pressed, this, &AMPlayerController::InteractionOccurred);


	InputComponent->BindAction("Journal", IE_Pressed, this, &AMPlayerController::ToggleJournal);

	InputComponent->BindAction("NextPageJournal", IE_Pressed, this, &AMPlayerController::NextPageInteraction);

	InputComponent->BindAction("PrevPageJournal", IE_Pressed, this, &AMPlayerController::PrevPageInteraction);

}

void AMPlayerController::PawnLeavingGame()
{
	UnPossess();
}

#pragma region Journal & Interaction Functions

void AMPlayerController::InteractionOccurred() 
{
	InteractClicked.Broadcast();
}

void AMPlayerController::NextPageInteraction()
{
	NextPageClicked.Broadcast();
}

void AMPlayerController::PrevPageInteraction()
{
	PrevPageClicked.Broadcast();
}

void AMPlayerController::ToggleJournal()
{
	if (JournalWidgetClass != nullptr)
	{
		if (JournalWidget->IsInViewport())
		{
			JournalWidget->RemoveFromViewport();
			SetInputMode(FInputModeGameOnly());
			JournalWidget->UnBindPageDelegates();
			bShowMouseCursor = false;

		}
		else
		{
			JournalWidget->AddToViewport();
			SetInputMode(FInputModeGameAndUI());
			JournalWidget->BindPageDelegates();
			bShowMouseCursor = true;
		}
	}
}

void AMPlayerController::DisplayTabletInteraction(ALoreTablet* tablet)
{
	if (InteractionWidgetClass != nullptr)
	{

		InteractionWidget = CreateWidget<UWInteraction>(UGameplayStatics::GetPlayerController(GetWorld(), 0), InteractionWidgetClass);

		if (InteractionWidget)
		{
			InteractionWidget->AddToViewport();
			InteractionWidget->SetLatestTablet(tablet);
			InteractionWidget->BindDelegate();
		}
		

	}
}

void AMPlayerController::HideInteraction()
{

	if (InteractionWidget->InteractText->IsVisible())
	{
		InteractionWidget->RemoveFromViewport();
		InteractionWidget->UnBindDelegate();
	}

}

void AMPlayerController::AddToTabletsCollected(ALoreTablet* tablet)
{
	if (tablet->sharedType == SharedType::Unshared)
	{
		Client_AddToTabletsCollected(tablet);
	}
	else
	{
		if (HasAuthority())
		{
			AddTabletsToAllPlayers(tablet);
		}
		else
		{
			Server_AddTabletsToAllPlayers(tablet);
		}

	}

}
void AMPlayerController::Server_AddTabletsToAllPlayers_Implementation(ALoreTablet* tablet)
{
	Cast<AMisfortunateGameMode>(UGameplayStatics::GetGameMode(GetWorld()))->AddLoreTabletToAllPlayers(tablet);

}

bool AMPlayerController::Server_AddTabletsToAllPlayers_Validate(ALoreTablet* tablet)
{
	return true;
}

void AMPlayerController::Server_UpdateReadyState_Implementation(AMPlayerController* playerController)
{
	if (playerController->GetIsReady())
	{
		playerController->PlayerInfo.IsReady = false;
	}
	else
	{
		playerController->PlayerInfo.IsReady = true;
	}


	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green,FString("Player To Change: ") + playerController->PlayerInfo.PlayerName);

	AMisfortunateGameMode* gameMode = Cast<AMisfortunateGameMode>(UGameplayStatics::GetGameMode(GetWorld()));

	gameMode->UpdateReadyState(playerController);
}

bool AMPlayerController::Server_UpdateReadyState_Validate(AMPlayerController* playerController)
{
	return true;
}

#pragma endregion





void AMPlayerController::AddTabletsToAllPlayers(ALoreTablet* tablet)
{
	Cast<AMisfortunateGameMode>(UGameplayStatics::GetGameMode(GetWorld()))->AddLoreTabletToAllPlayers(tablet);
}



void AMPlayerController::Client_AddToTabletsCollected_Implementation(ALoreTablet* tablet)
{

	
	if (!InteractionWidget->IsInViewport())
	{
		InteractionWidget->AddToViewport();
	}

	InteractionWidget->PlayInteractionAnim();
	CollectedTablets.Add(tablet);
}

bool AMPlayerController::Client_AddToTabletsCollected_Validate(ALoreTablet* tablet)
{
	return true;
}


void AMPlayerController::Client_AddPlayersToList_Implementation(const TArray<FPlayerInfo>& playersInfo)
{
	if (!LobbyWidget)
		LobbyWidget = CreateWidget<UWLobbyMenu>(GetWorld(), LobbyWidgetClass);

	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Size of players Info: %i"), playersInfo.Num()));

	AllPlayersInfo = playersInfo;

	AddPlayerStatusWidget(playersInfo);
}

bool AMPlayerController::Client_AddPlayersToList_Validate(const TArray<FPlayerInfo>& playersInfo)
{
	return true;
}




void AMPlayerController::Client_UpdateReadyState_Implementation(const FPlayerInfo& changedPlayer)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString("Client_UpdateReadyState"));

	//UpdateReadyState(playerController);

		for (auto PlayerStatus : LobbyWidget->PlayerStatusList)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString("Controller Name: ") + changedPlayer.PlayerName);
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString("Player Status Name: ") + PlayerStatus->CurrentPlayerName);

			if (changedPlayer.PlayerName == PlayerStatus->CurrentPlayerName)
			{
				PlayerStatus->UpdateReadyState(changedPlayer.IsReady);
			}
		}

	

}

bool AMPlayerController::Client_UpdateReadyState_Validate(const FPlayerInfo& changedPlayer)
{
	return true;
}


void AMPlayerController::Client_PossesNewCharacter_Implementation(ACharacter* playerCharacter)
{
	this->UnPossess();
	this->Possess(playerCharacter);
}

bool AMPlayerController::Client_PossesNewCharacter_Validate(ACharacter* playerCharacter)
{
	return true;
}

void AMPlayerController::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AMPlayerController, PlayerInfo);
}

void AMPlayerController::SetViewYawExtents(float minYaw, float maxYaw)
{

	FRotator rot = GetControlRotation();
	
	PlayerCameraManager->ViewYawMin = rot.Yaw - FMath::Abs(minYaw);
	PlayerCameraManager->ViewYawMax = rot.Yaw + maxYaw;
}

void AMPlayerController::SetViewPitchExtents(float minPitch, float maxPitch)
{
	PlayerCameraManager->ViewPitchMin = minPitch;
	PlayerCameraManager->ViewPitchMax =  maxPitch;
}



TArray<ALoreTablet*> AMPlayerController::GetCollectedTablets()
{
	return CollectedTablets;
}

UWLobbyMenu* AMPlayerController::GetLobbyWidget() const
{
	return LobbyWidget;
}

bool AMPlayerController::GetIsReady() const
{
	return PlayerInfo.IsReady;
}






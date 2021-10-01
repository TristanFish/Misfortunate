// Fill out your copyright notice in the Description page of Project Settings.


#include "MPlayerController.h"
#include "Blueprint/UserWidget.h"
#include "Widgets/WJournal.h"
#include "Actors/LoreTablet.h"
#include "Widgets/WInteraction.h"
#include "MisfortunateGameMode.h"
#include "Kismet/GameplayStatics.h"



AMPlayerController::AMPlayerController()
{
	static ConstructorHelpers::FClassFinder<UUserWidget> JournalClass(TEXT("/Game/Misfortuante/Blueprints/Widgets/W_Journal"));
	JournalWidgetClass = JournalClass.Class;

	static ConstructorHelpers::FClassFinder<UUserWidget> InteractionClass(TEXT("/Game/Misfortuante/Blueprints/Widgets/W_Interaction"));
	InteractionWidgetClass = InteractionClass.Class;


	
}

void AMPlayerController::BeginPlay()
{
	Super::BeginPlay();

	PlayerCameraManager->ViewPitchMin = -70.0f;
	PlayerCameraManager->ViewPitchMax = 65.0f;
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
		if (!JournalWidget)
		{
			JournalWidget = CreateWidget<UUserWidget>(GetWorld(), JournalWidgetClass);
		}

		if (JournalWidget->IsInViewport())
		{
			JournalWidget->RemoveFromViewport();
			SetInputMode(FInputModeGameOnly());
			Cast<UWJournal>(JournalWidget)->UnBindPageDelegates();
			bShowMouseCursor = false;

		}
		else
		{
			JournalWidget->AddToViewport();
			SetInputMode(FInputModeGameAndUI());
			Cast<UWJournal>(JournalWidget)->BindPageDelegates();
			bShowMouseCursor = true;
		}
	}
}

void AMPlayerController::DisplayTabletInteraction(ALoreTablet* tablet)
{
	if (InteractionWidgetClass != nullptr)
	{

		InteractionWidget = CreateWidget<UUserWidget>(UGameplayStatics::GetPlayerController(GetWorld(), 0), InteractionWidgetClass);

		if (InteractionWidget)
		{
			InteractionWidget->AddToViewport();
			Cast<UWInteraction>(InteractionWidget)->SetLatestTablet(tablet);
			Cast<UWInteraction>(InteractionWidget)->BindDelegate();
		}
		

	}
}

void AMPlayerController::HideInteraction()
{
	UWInteraction* InteractWidget = Cast<UWInteraction>(InteractionWidget);

	if (InteractWidget->InteractText->IsVisible())
	{
		InteractionWidget->RemoveFromViewport();
		Cast<UWInteraction>(InteractionWidget)->UnBindDelegate();
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

void AMPlayerController::AddTabletsToAllPlayers(ALoreTablet* tablet)
{
	Cast<AMisfortunateGameMode>(UGameplayStatics::GetGameMode(GetWorld()))->AddLoreTabletToAllPlayers(tablet);
}



void AMPlayerController::Client_AddToTabletsCollected_Implementation(ALoreTablet* tablet)
{

	if (InteractionWidget == nullptr)
	{
		InteractionWidget = CreateWidget<UUserWidget>(UGameplayStatics::GetPlayerController(GetWorld(), 0), InteractionWidgetClass);
	}
	if (!InteractionWidget->IsInViewport())
	{
		InteractionWidget->AddToViewport();
	}

	Cast<UWInteraction>(InteractionWidget)->PlayInteractionAnim();
	CollectedTablets.Add(tablet);
}

bool AMPlayerController::Client_AddToTabletsCollected_Validate(ALoreTablet* tablet)
{
	return true;
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








// Fill out your copyright notice in the Description page of Project Settings.


#include "HeadLamp.h"
#include "Components/SpotLightComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/SceneComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"

#include "MisfortunateGameMode.h"
#include "MisfortuneManager.h"

#include "Sound/SoundBase.h"

#include "PlayerCharacter.h"


AHeadLamp::AHeadLamp() 
{

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));

	SetRootComponent(SceneComponent);


	flashlightArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("FlashlightArm"));
	flashlightArm->SetupAttachment(RootComponent);



	lightMid = CreateDefaultSubobject<USpotLightComponent>(TEXT("LightMid"));
	lightMid->SetupAttachment(flashlightArm);


	lightLeft = CreateDefaultSubobject<USpotLightComponent>(TEXT("LightLeft"));
	lightLeft->SetupAttachment(flashlightArm);

	lightRight = CreateDefaultSubobject<USpotLightComponent>(TEXT("LightRight"));
	lightRight->SetupAttachment(flashlightArm);

	
	lightState = LightState::Off;
	lightMid->SetVisibility(false);
	lightLeft->SetVisibility(false);
	lightRight->SetVisibility(false);


	lightRight->SetIsReplicated(true);
	lightLeft->SetIsReplicated(true);
	lightMid->SetIsReplicated(true);


	MaxOutsideLightDecreaseRate = 5.0;
	MinOutsideLightDecreaseRate = 1.0;

	MaxCentreLightDecreaseRate = 10.0;
	MinCentreLightDecreaseRate = 3.0;


	MisfortuneToStartDim = 20.0f;

	bReplicates = true;

	bAreSideLightsDisabled = false;

}

void AHeadLamp::BeginPlay()
{
	Super::BeginPlay();

	OriginalCentreLightIntensity = lightMid->Intensity;

	OriginalOutsideLightIntensity = lightLeft->Intensity;
}

void AHeadLamp::ToggleHeadLamp()
{


		switch (lightState)
		{
		case LightState::Off:
			lightMid->SetVisibility(true);
			lightState = LightState::SingleBeam;
			UGameplayStatics::PlaySoundAtLocation(GetWorld(), OnOffSound, UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->GetActorLocation());
			break;
		case LightState::SingleBeam:
			if (!bAreSideLightsDisabled)
			{
				lightLeft->SetVisibility(true);
				lightRight->SetVisibility(true);
				lightState = LightState::TrippleBeam;
				UGameplayStatics::PlaySoundAtLocation(GetWorld(), OnOffSound, UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->GetActorLocation());
			}
			break;
		case LightState::TrippleBeam:
			lightMid->SetVisibility(false);
			lightLeft->SetVisibility(false);
			lightRight->SetVisibility(false);
			lightState = LightState::Off;
			UGameplayStatics::PlaySoundAtLocation(GetWorld(), OnOffSound, UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->GetActorLocation());
			break;

		default:
			break;
		}

}

void AHeadLamp::OnMisfortuneChange(float NewMisfortune,const FString& PlayerName)
{
	float CentreLightIndensity, OutsideLightIntensity;

	AMisfortunateGameMode* GameMode = Cast<AMisfortunateGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	float MaxPlayerMisfortune = GameMode->GetMisfortuneManager()->GetPlayerMaxMisfortune(PlayerName);
	if (NewMisfortune >= MisfortuneToStartDim)
	{
		CentreLightIndensity = FMath::GetMappedRangeValueClamped(FVector2D(MisfortuneToStartDim, MaxPlayerMisfortune), FVector2D(MinCentreLightDecreaseRate, MaxCentreLightDecreaseRate), NewMisfortune);

		

		lightMid->SetIntensity(CentreLightIndensity);

		if (!bAreSideLightsDisabled)
		{
			OutsideLightIntensity = FMath::GetMappedRangeValueClamped(FVector2D(MisfortuneToStartDim, MaxPlayerMisfortune), FVector2D(MinOutsideLightDecreaseRate, MaxOutsideLightDecreaseRate), NewMisfortune);
			lightLeft->SetIntensity(OutsideLightIntensity);
			lightRight->SetIntensity(OutsideLightIntensity);
		}
	}
	
}

void AHeadLamp::SetSideLightsVisibility_Client_Implementation(bool bSetSideLightsDisabled_)
{
	bAreSideLightsDisabled = bSetSideLightsDisabled_;

	lightLeft->SetVisibility(!bAreSideLightsDisabled);
	lightRight->SetVisibility(!bAreSideLightsDisabled);

	if (bAreSideLightsDisabled)
	{
		lightState = LightState::SingleBeam;
	}
	else
	{
		lightState = LightState::TrippleBeam;
	}
	
}

void AHeadLamp::SetSideLightsVisibility_Server_Implementation(bool bSetSideLightsDisabled_)
{
	SetSideLightsVisibility_Client(bSetSideLightsDisabled_);
}

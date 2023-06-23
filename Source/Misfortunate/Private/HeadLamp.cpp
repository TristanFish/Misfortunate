// Fill out your copyright notice in the Description page of Project Settings.


#include "HeadLamp.h"
#include "Components/SpotLightComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/SceneComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"

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
		break;
	case LightState::SingleBeam:
		lightLeft->SetVisibility(true);
		lightRight->SetVisibility(true);
		lightState = LightState::TrippleBeam;

		break;
	case LightState::TrippleBeam:
		lightMid->SetVisibility(false);
		lightLeft->SetVisibility(false);
		lightRight->SetVisibility(false);
		lightState = LightState::Off;
		break;

	default:
		break;
	}

	UGameplayStatics::PlaySoundAtLocation(GetWorld(), OnOffSound, UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->GetActorLocation());
}

void AHeadLamp::OnMisfortuneChange(float NewMisfortune, APlayerCharacter* Player)
{
	float CentreLightIndensity, OutsideLightIntensity;

	if (NewMisfortune >= MisfortuneToStartDim)
	{
		CentreLightIndensity = FMath::GetMappedRangeValueClamped(FVector2D(MisfortuneToStartDim, Player->MaxMisfortune), FVector2D(MinCentreLightDecreaseRate, MaxCentreLightDecreaseRate), NewMisfortune);

		OutsideLightIntensity = FMath::GetMappedRangeValueClamped(FVector2D(MisfortuneToStartDim, Player->MaxMisfortune), FVector2D(MinOutsideLightDecreaseRate, MaxOutsideLightDecreaseRate), NewMisfortune);

		lightMid->SetIntensity(CentreLightIndensity);
		lightLeft->SetIntensity(OutsideLightIntensity);
		lightRight->SetIntensity(OutsideLightIntensity);
	}
	
}



// Fill out your copyright notice in the Description page of Project Settings.


#include "HeadLamp.h"
#include "Components/SpotLightComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/SceneComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"

#include "Sound/SoundBase.h"

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

	bReplicates = true;

}

void AHeadLamp::BeginPlay()
{
	Super::BeginPlay();
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



// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Glowstick.h"
#include "Components/PointLightComponent.h"

#include "Kismet/GameplayStatics.h"


#include "MisfortunateGameMode.h"
#include "MisfortuneManager.h"

#include "PlayerCharacter.h"

// Sets default values
AGlowstick::AGlowstick()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GlowstickMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Glowstick"));
	RootComponent = GlowstickMesh;

	GlowLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("GlowstickLight"));

	GlowLight->SetupAttachment(GlowstickMesh);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> StickMesh(TEXT("StaticMesh'/Game/Misfortuante/Models/PlayerObjects/Glowstick.Glowstick'"));
	GlowstickMesh->SetStaticMesh(StickMesh.Object);

	static ConstructorHelpers::FObjectFinder<UMaterial> StickMaterial(TEXT("Material'/Game/Textures/M_Glowstick.M_Glowstick'"));
	StoredMaterial = StickMaterial.Object;


	DynamicMatInst = UMaterialInstanceDynamic::Create(StoredMaterial, GlowstickMesh);
	GlowstickMesh->SetMaterial(0, DynamicMatInst);
	GlowstickMesh->SetSimulatePhysics(true);


	FastestDimSpeed = 2.0f;
	SlowestDimSpeed = 10.0f;

	GlowLightDecreaseStep = 1.5f;


	MaterialEmmesionDecreaseStep = 1.0f;

	bReplicates = true;
}

// Called when the game starts or when spawned
void AGlowstick::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(TickLifetimeTimerHandle, this, &AGlowstick::DecreaseBrightness, 1.0f, true);

}

void AGlowstick::DecreaseBrightness()
{
	float newBrightness = 0.0f;

	DynamicMatInst->GetScalarParameterValue(FName(TEXT("Emision")), newBrightness);


	if (newBrightness > 1.0f)
	{
		newBrightness -= MaterialEmmesionDecreaseStep;
		DynamicMatInst->SetScalarParameterValue(FName("Emision"), newBrightness);
	}
	if (GlowLight->Intensity > 5.0f)
	{
		GlowLight->SetIntensity(GlowLight->Intensity - GlowLightDecreaseStep);
	}


	if (newBrightness <= 1.0f && GlowLight->Intensity <= 5.0f)
	{
		Destroy();
	}

}

// Called every frame
void AGlowstick::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

UStaticMeshComponent* AGlowstick::GetMesh() const
{
	return GlowstickMesh;
}

void AGlowstick::OnMisfortuneChange(float NewMisfortune, const FString& PlayerName)
{
	GetWorld()->GetTimerManager().ClearTimer(TickLifetimeTimerHandle);

	AMisfortunateGameMode* GameMode = Cast<AMisfortunateGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	float MaxPlayerMisfortune = GameMode->GetMisfortuneManager()->GetPlayerMaxMisfortune(PlayerName);

	float DecreaseSpeed = FMath::GetMappedRangeValueClamped(FVector2D(0.0f, MaxPlayerMisfortune), FVector2D(SlowestDimSpeed, FastestDimSpeed), NewMisfortune);

	GetWorld()->GetTimerManager().SetTimer(TickLifetimeTimerHandle, this, &AGlowstick::DecreaseBrightness, FastestDimSpeed, true);
}


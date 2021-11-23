// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Glowstick.h"

// Sets default values
AGlowstick::AGlowstick()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GlowstickMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Glowstick"));

	RootComponent = GlowstickMesh;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> StickMesh(TEXT("StaticMesh'/Game/Misfortuante/Models/PlayerObjects/Glowstick.Glowstick'"));

	GlowstickMesh->SetStaticMesh(StickMesh.Object);

	static ConstructorHelpers::FObjectFinder<UMaterial> StickMaterial(TEXT("Material'/Game/Textures/M_Glowstick.M_Glowstick'"));

	StoredMaterial = StickMaterial.Object;

	DynamicMatInst = UMaterialInstanceDynamic::Create(StoredMaterial, GlowstickMesh);

	GlowstickMesh->SetMaterial(0, DynamicMatInst);

	GlowstickMesh->SetSimulatePhysics(true);

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

	newBrightness -= 0.2;

	if (newBrightness <= 1.0f)
	{
		Destroy();
	}

	DynamicMatInst->SetScalarParameterValue(FName("Emision"), newBrightness);
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


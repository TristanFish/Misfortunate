// Fill out your copyright notice in the Description page of Project Settings.


#include "Glowstick.h"

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
}

// Called when the game starts or when spawned
void AGlowstick::BeginPlay()
{
	Super::BeginPlay();
	
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


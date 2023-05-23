// Fill out your copyright notice in the Description page of Project Settings.


#include "CrawlableArea.h"
#include "MPlayerController.h"
#include "PlayerCharacter.h"
// Sets default values
ACrawlableArea::ACrawlableArea()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
	OnActorBeginOverlap.AddDynamic(this, &ACrawlableArea::OnOverlapBegin);
	OnActorEndOverlap.AddDynamic(this, &ACrawlableArea::OnOverlapEnd);


	MaxYawView = 40.0f;
	MinYawView = -40.0f;

	MaxPitchView = 60.0f;
	MinPitchView = -60.0f;

	PrevMaxYawView = 0.0f;
	PrevMinYawView = 0.0f;

	PrevMaxPitchView = 0.0f;
	PrevMinPitchView = 0.0f;
}

// Called when the game starts or when spawned
void ACrawlableArea::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACrawlableArea::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACrawlableArea::OnOverlapBegin(class AActor* OverlappedComp, class AActor* OtherActor)
{
	APlayerCharacter* character = Cast<APlayerCharacter>(OtherActor);

	AMPlayerController* controller = Cast<AMPlayerController>(character->GetController());


	if (controller != nullptr && controller->IsLocalController())
	{
		PrevMaxYawView = controller->PlayerCameraManager->ViewYawMax;
		PrevMinYawView = controller->PlayerCameraManager->ViewYawMin;

		PrevMaxPitchView = controller->PlayerCameraManager->ViewPitchMax;
		PrevMinPitchView = controller->PlayerCameraManager->ViewPitchMin;

		controller->SetViewYawExtents(MinYawView, MaxYawView);
		controller->SetViewPitchExtents(MinPitchView, MaxPitchView);
	}
}

void ACrawlableArea::OnOverlapEnd(class AActor* OverlappedComp, class AActor* OtherActor)
{

	APlayerCharacter* character = Cast<APlayerCharacter>(OtherActor);


	if (character)
	{
		AMPlayerController* controller = Cast<AMPlayerController>(character->GetController());


		if (controller != nullptr && controller->IsLocalController())
		{
			controller->SetViewYawExtents(PrevMinYawView, PrevMaxYawView);
			controller->SetViewPitchExtents(PrevMinPitchView, PrevMaxPitchView);


		}
	}
}


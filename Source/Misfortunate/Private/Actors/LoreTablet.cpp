// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/LoreTablet.h"
#include "MPlayerController.h"
#include "PlayerCharacter.h"
#include "Widgets/WInteraction.h"
#include "Kismet/GameplayStatics.h"
// Sets default values
ALoreTablet::ALoreTablet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TabletMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Tablet"));


	TabletMesh->SetupAttachment(RootComponent);


	OnActorBeginOverlap.AddDynamic(this, &ALoreTablet::OnOverlapBegin);
	OnActorEndOverlap.AddDynamic(this, &ALoreTablet::OnOverlapEnd);



}



// Called when the game starts or when spawned
void ALoreTablet::BeginPlay()
{
	Super::BeginPlay();

	
	
}

// Called every frame
void ALoreTablet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ALoreTablet::SetText(FString& text_, FString& title_)
{
	TabletText = text_;
	TabletTitle = title_;
}

void ALoreTablet::SetText(FString text_, FString title_)
{
	TabletText = text_;
	TabletTitle = title_;
}

FString ALoreTablet::GetTabletText()
{
	return TabletText;
}

FString ALoreTablet::GetTabletTitle()
{
	return TabletTitle;
}

void ALoreTablet::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
{

	APlayerCharacter* character = Cast<APlayerCharacter>(OtherActor);

	AMPlayerController* controller = Cast<AMPlayerController>(character->GetController());


	if (controller != nullptr && controller->IsLocalController())
	{
		controller->DisplayTabletInteraction(this);

	}



	
}

void ALoreTablet::OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor)
{
	APlayerCharacter* character = Cast<APlayerCharacter>(OtherActor);

	AMPlayerController* controller = Cast<AMPlayerController>(character->GetController());


	if (controller != nullptr && controller->IsLocalController())
	{
		controller->HideInteraction();

	}
}

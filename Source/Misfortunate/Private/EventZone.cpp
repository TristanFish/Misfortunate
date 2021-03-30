// Fill out your copyright notice in the Description page of Project Settings.

#include "EventZone.h"
#include "PlayerCharacter.h"

// Sets default values
AEventZone::AEventZone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	OnActorBeginOverlap.AddDynamic(this, &AEventZone::OnOverlapBegin);
	OnActorEndOverlap.AddDynamic(this, &AEventZone::OnOverlapEnd);


}

// Called when the game starts or when spawned
void AEventZone::BeginPlay()
{
	Super::BeginPlay();
	
} 

void AEventZone::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
{
	APlayerCharacter* enteredCharacter = Cast<APlayerCharacter>(OtherActor);

	if (enteredCharacter != nullptr) {
		enteredCharacter->SetCurrentZone(*this);

	}
}

void AEventZone::OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor)
{

}


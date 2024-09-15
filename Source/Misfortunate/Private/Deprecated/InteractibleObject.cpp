// Fill out your copyright notice in the Description page of Project Settings.


#include "Deprecated/InteractibleObject.h"

#include "Components/ShapeComponent.h"
#include "Components/BillboardComponent.h"

// Sets default values
AInteractibleObject::AInteractibleObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	if (GetCollisionComponent())
	{

		GetCollisionComponent()->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);


		GetCollisionComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel2, ECollisionResponse::ECR_Block);

		GetCollisionComponent()->bHiddenInGame = true;
	}


}

// Called when the game starts or when spawned
void AInteractibleObject::BeginPlay()
{
	Super::BeginPlay();
	

}



void AInteractibleObject::OnInteracted_Implementation()
{
}

// Called every frame
void AInteractibleObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AInteractibleObject::SetLoreInfo(FString& LoreTitle_, FString& LoretOwner_, FString& LoreText_)
{
	LoreTitle = LoreTitle_;
	LoretOwner = LoretOwner_;
	LoreText = LoreText_;

}

void AInteractibleObject::SetLoreInfo(FString LoreTitle_, FString LoretOwner_, FString LoreText_)
{
	LoreTitle = LoreTitle_;
	LoretOwner = LoretOwner_;
	LoreText = LoreText_;
}

FString AInteractibleObject::GetLoreText()
{
	return LoreText;
}

FString AInteractibleObject::GetLoreTitle()
{
	return LoreTitle;
}

FString AInteractibleObject::GetLoreOwner()
{
	return LoretOwner;
}


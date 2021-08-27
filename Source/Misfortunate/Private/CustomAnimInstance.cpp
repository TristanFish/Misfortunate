// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomAnimInstance.h"
#include "PlayerCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

UCustomAnimInstance::UCustomAnimInstance()
{
	speed = 0.0f;
	direction = 0.0f;
	IsInAir = false;
}

void UCustomAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);



	if (CharPlayer != nullptr) {
		speed = CharPlayer->GetVelocity().Size();
		direction = CalculateDirection(CharPlayer->GetVelocity(), CharPlayer->GetActorRotation());



		if (CharPlayer != nullptr)
		{
			IsInAir = CharPlayer->GetCharacterMovement()->IsFalling();

			IsCrawling = CharPlayer->CrawlState == CrawlStates::Crawl;
			IsCrouched = CharPlayer->CrawlState == CrawlStates::Crouch;

		}
	}

}

void UCustomAnimInstance::NativeBeginPlay()
{
	AActor* OwningActor = GetOwningActor();

	if (OwningActor != nullptr)
	{
		APlayerCharacter* OwningCharacter = Cast<APlayerCharacter>(OwningActor);

		CharPlayer = OwningCharacter;
	}


}

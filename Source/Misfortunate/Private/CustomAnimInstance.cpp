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


	AActor* OwningActor = GetOwningActor();

	if (OwningActor != nullptr) {
		speed = OwningActor->GetVelocity().Size();
		direction = CalculateDirection(OwningActor->GetVelocity(), OwningActor->GetActorRotation());



		APlayerCharacter* OwningCharacter = Cast<APlayerCharacter>(OwningActor);

		if (OwningCharacter != nullptr)
		{
			IsInAir = OwningCharacter->GetCharacterMovement()->IsFalling();
		}
	}

}

// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomAnimInstance.h"
#include "PlayerCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

UCustomAnimInstance::UCustomAnimInstance()
{
	speed = 0.0f;
	direction = 0.0f;
	BackwardDir = 180.0f;
	IsInAir = false;

}

void UCustomAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);



	if (CharPlayer != nullptr) {
		speed = CharPlayer->GetVelocity().Size();

		float CalcDirLocal;

		CalcDirLocal = CalculateDirection(CharPlayer->GetVelocity(), CharPlayer->GetActorRotation());


		if (FMath::IsNearlyEqual(FMath::Abs(CalcDirLocal), BackwardDir, 1.0f))
		{
			if (oldMovementDir < 0.0f)
			{
				direction = BackwardDir * -1.0f;
			}
			else
			{
				direction = BackwardDir;
			}
		}
		else
		{
			direction = CalcDirLocal;
		}

		oldMovementDir = direction;


		IsInAir = CharPlayer->GetCharacterMovement()->IsFalling();

		IsCrouched = CharPlayer->CrawlState == CrawlStates::Crouch;
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

// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/WMisfortune.h"

#include "PlayerCharacter.h"

void UWMisfortune::NativeConstruct()
{
	Super::NativeConstruct();
	playerChar = Cast<APlayerCharacter>(GetOwningPlayerPawn());

	MisfortuneProgress = playerChar->GetMisfortune();
}

void UWMisfortune::NativeTick(const FGeometry& MyGeometry, float DeltaTime)
{
	Super::NativeTick(MyGeometry, DeltaTime);

	if (playerChar->GetMisfortune() != MisfortuneProgress)
	{
		MisfortuneProgress = FMath::Lerp(MisfortuneProgress, playerChar->GetMisfortune(), 0.01);
	}

}

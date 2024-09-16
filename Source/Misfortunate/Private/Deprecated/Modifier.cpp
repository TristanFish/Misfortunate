// Fill out your copyright notice in the Description page of Project Settings.


#include "Deprecated/Modifier.h"
#include "Deprecated/ModifierManager.h"
#include "PlayerCharacter.h"


UModifier::UModifier()
{
}

bool UModifier::HasModifiers(int32 BitmaskModifiers)
{
	return BitmaskModifiers && ModifierFlags == BitmaskModifiers;

}

void UModifier::StartModifier_Implementation()
{

	if (ModifierFlags & StaticCast<int32>(EModifierTypes::TIMED))
	{
		GetWorld()->GetTimerManager().SetTimer(StopTimer, this, &UModifier::StopModifier, TimeTillStop, false);
		
	}
}

void UModifier::StopModifier_Implementation()
{
	OwningPlayer->RemoveModifier(this);
}



void UModifier::SetModifierManager(AModifierManager* ModiferManager_)
{
}

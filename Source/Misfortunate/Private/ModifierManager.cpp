// Fill out your copyright notice in the Description page of Project Settings.


#include "ModifierManager.h"
#include "Modifier.h"
#include "PlayerCharacter.h"

#include "Net/UnrealNetwork.h"

#include "Kismet/GameplayStatics.h"


// Sets default values
AModifierManager::AModifierManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	bReplicates = true;
}

// Called when the game starts or when spawned
void AModifierManager::BeginPlay()
{
	Super::BeginPlay();
	
}

TSubclassOf<UModifier> AModifierManager::GetRandomModifier(const int& PlayerIndex)
{
	bool FoundModifier = false, HasModifier = false;
	while (!FoundModifier)
	{
		int RandomModiferIndex = FMath::RandRange(0, PossibleModifiers.Num() - 1);
		bool HasGlobalModifier = PossibleModifiers[RandomModiferIndex].GetDefaultObject()->HasModifiers(StaticCast<int32>(EModifierTypes::GLOBAL));
		if (HasGlobalModifier)
		{

			for (auto Modifier : CurrentGlobalModifiers)
			{
				if (PossibleModifiers[RandomModiferIndex] == Modifier->GetClass())
				{
					HasModifier = true;
				}
			}

			if (!HasModifier)
			{
				AddGlobalModifier(PossibleModifiers[RandomModiferIndex]);
				return PossibleModifiers[RandomModiferIndex];
			}
			
		}
		else
		{
			if (PlayerIndex == -1)
			{
				return PossibleModifiers[RandomModiferIndex];
			}
			else
			{
				for (auto Modifier : PlayerModifiers[PlayerIndex].Modifiers)
				{
					if (PossibleModifiers[RandomModiferIndex] == Modifier->GetClass())
					{
						HasModifier = true;
					}
				}

				if (!HasModifier)
				{
					return PossibleModifiers[RandomModiferIndex];
				}
			}
		}
	}


	return TSubclassOf<UModifier>();
}

void AModifierManager::AddPlayerModifier_Implementation(APlayerCharacter* PlayerToAdd)
{
	int index;
	bool Found = false;

	for (int i = 0; i < PlayerModifiers.Num(); i++)
	{
		if (PlayerModifiers[i].PlayerWithModifiers == PlayerToAdd)
		{
			index = i;
			Found = true;
		}
	}

	if (Found)
	{
		PlayerModifiers[index].Modifiers.AddUnique(NewObject<UModifier>(GetRandomModifier(index)->StaticClass()));

	}
	else
	{
		TArray<UModifier*> Modifiers;

		Modifiers.Add(NewObject<UModifier>(GetRandomModifier(-1)->StaticClass()));
		 
		PlayerModifiers.Emplace(PlayerToAdd, Modifiers);
	}

}

void AModifierManager::AddGlobalModifier(TSubclassOf<UModifier> ModifierType)
{
	CurrentGlobalModifiers.Add(NewObject<UModifier>(ModifierType->StaticClass()));
}

void AModifierManager::OnRep_UpdateGlobalModifiers()
{
	// Add modifier to both players
}

void AModifierManager::OnRep_UpdatePlayerModifiers()
{

	for (int i = 0; i < PlayerModifiers.Num(); i++)
	{
		if (PlayerModifiers[i].PlayerWithModifiers->GetController() == UGameplayStatics::GetGameInstance(GetWorld())->GetFirstLocalPlayerController())
		{
			PlayerModifiers[i].PlayerWithModifiers->AddNewModifier(PlayerModifiers[i].RecentlyAddedModifier);

		}
	}
}

// Called every frame
void AModifierManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AModifierManager::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AModifierManager, CurrentGlobalModifiers);
	DOREPLIFETIME(AModifierManager, PlayerModifiers);

}


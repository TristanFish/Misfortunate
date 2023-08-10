// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ModifierManager.generated.h"


class UModifier;
class APlayerCharacter;


USTRUCT()
struct FPlayerModifiers
{
	GENERATED_BODY()

	APlayerCharacter* PlayerWithModifiers;

	TArray<UModifier*> Modifiers;

	UModifier* RecentlyAddedModifier;


	
	FPlayerModifiers()
	{
		PlayerWithModifiers = nullptr;
	}

	FPlayerModifiers(APlayerCharacter* PlayerWithModifiers_, TArray<UModifier*> Modifiers_)
	{
		PlayerWithModifiers = PlayerWithModifiers_;
		Modifiers = Modifiers_;
	}
};

UCLASS()
class MISFORTUNATE_API AModifierManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AModifierManager();

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TArray<TSubclassOf<UModifier>> PossibleModifiers;

	UPROPERTY(ReplicatedUsing = OnRep_UpdateGlobalModifiers)
		TArray<UModifier*> CurrentGlobalModifiers;

	UPROPERTY(ReplicatedUsing = OnRep_UpdatePlayerModifiers)
		TArray<FPlayerModifiers> PlayerModifiers;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	TSubclassOf<UModifier> GetRandomModifier(const int& PlayerIndex);


public:	



	UFUNCTION(Server, Reliable)
		void AddPlayerModifier(APlayerCharacter* PlayerToAdd);

	UFUNCTION()
		void AddGlobalModifier(TSubclassOf<UModifier> ModifierType);

	UFUNCTION()
		void OnRep_UpdateGlobalModifiers();

	UFUNCTION()
		void OnRep_UpdatePlayerModifiers();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const override;

};

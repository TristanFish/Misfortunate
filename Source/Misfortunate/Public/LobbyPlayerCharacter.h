// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "LobbyPlayerCharacter.generated.h"

UCLASS()
class MISFORTUNATE_API ALobbyPlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ALobbyPlayerCharacter();


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		class UCameraComponent* LobbyCam;


	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Lobby Camera")
		float MinYawViewAngle;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Lobby Camera")
		float MaxYawViewAngle;

	UPROPERTY(BlueprintReadWrite, Replicated)
		bool HasBeenPossesed;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual void PossessedBy(AController* NewController) override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};

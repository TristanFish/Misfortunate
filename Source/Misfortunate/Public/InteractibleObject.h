// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/TriggerBox.h"

#include "InteractibleObject.generated.h"

UCLASS()
class MISFORTUNATE_API AInteractibleObject : public ATriggerBox
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractibleObject();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		bool bContainsLore;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FString LoreTitle;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FString LoretOwner;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FString LoreText;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;



	void SetLoreInfo(FString& LoreTitle_, FString& LoretOwner_, FString& LoreText_);
	void SetLoreInfo(FString LoreTitle_, FString LoretOwner_, FString LoreText_);

	FString GetLoreText();

	FString GetLoreTitle();

	FString GetLoreOwner();


};

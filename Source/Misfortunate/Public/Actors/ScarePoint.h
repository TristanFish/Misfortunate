// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ScarePoint.generated.h"

class UBillboardComponent;
class UTexture2D;


// Used to determine what type of scare that the player will experience
UENUM()
enum ScareType {

	Whisper,
	Wind,
	Footsteps,
	SingingNoises,
	Environment
};

UCLASS()
class MISFORTUNATE_API AScarePoint : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AScarePoint(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class USceneComponent* SceneComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool UseScareType;

	// Determines what type of scare this ScarePoint will trigger
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "UseScareType"))
		TEnumAsByte<ScareType> scareType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool UseCustomCue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "UseCustomCue"))
		class UMetaSoundSource* ScareCue;


protected:
	UBillboardComponent* ScareIconComponent;


	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

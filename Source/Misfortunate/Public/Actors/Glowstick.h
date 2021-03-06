// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/Classes/Materials/Material.h"
#include "Glowstick.generated.h"

UCLASS()
class MISFORTUNATE_API AGlowstick : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGlowstick();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//!GlowstickMesh UStaticMeshComponent
	/*!Mesh that is used to represent a glowstick*/
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* GlowstickMesh;

	//!StoredMaterial UMaterial
	/*!Material that will be applied to the GlowstickMesh*/
	UPROPERTY(VisibleAnywhere)
		UMaterial* StoredMaterial;

	//!DynamicMatInst UMaterialInstanceDynamic
	/*!Used to control and change variables of the materials shader at runtime*/
	UPROPERTY(VisibleAnywhere)
		UMaterialInstanceDynamic* DynamicMatInst;

	void DecreaseBrightness();

private:
	FTimerHandle TickLifetimeTimerHandle;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	//!GetMesh Getter
	/*!Get's pointer to the glow stick mesh*/
	UStaticMeshComponent* GetMesh() const;

};

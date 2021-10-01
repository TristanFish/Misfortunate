// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "CrawlableArea.generated.h"

UCLASS()
class MISFORTUNATE_API ACrawlableArea : public ATriggerBox
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACrawlableArea();


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = YawExtents)
		float MinYawView;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = YawExtents)
		float MaxYawView;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = YawExtents)
		float PrevMinYawView;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = YawExtents)
		float PrevMaxYawView;



	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PitchExtents)
		float MinPitchView;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PitchExtents)
		float MaxPitchView;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = PitchExtents)
		float PrevMinPitchView;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = PitchExtents)
		float PrevMaxPitchView;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	// declare overlap begin function
	UFUNCTION()
		void OnOverlapBegin(class AActor* OverlappedComp, class AActor* OtherActor);

	// declare overlap end function
	UFUNCTION()
		void OnOverlapEnd(class AActor* OverlappedComp, class AActor* OtherActor);


};

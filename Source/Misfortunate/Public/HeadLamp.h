// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "GameFramework/Actor.h"

#include "HeadLamp.generated.h"

UCLASS(Blueprintable)
class AHeadLamp : public AActor
{
	GENERATED_BODY()


public:
	// Sets default values for this character's properties
	AHeadLamp();


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class USceneComponent* SceneComponent;

	/*Head Lamp Components*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class USpotLightComponent* lightMid;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class USpotLightComponent* lightLeft;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class USpotLightComponent* lightRight;
	

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class USpringArmComponent* flashlightArm;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class USoundBase* OnOffSound;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		float MisfortuneToStartDim;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		float OriginalCentreLightIntensity;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		float OriginalOutsideLightIntensity;


	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		float MaxOutsideLightDecreaseRate;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		float MinOutsideLightDecreaseRate;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		float MaxCentreLightDecreaseRate;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		float MinCentreLightDecreaseRate;


	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		bool bAreSideLightsDisabled;

public:

	virtual void BeginPlay() override;

	//!ToggleFlashlight Function
	/*!Toggles the headlamp between modes/turns it off*/
	void ToggleHeadLamp();


	

	UFUNCTION()
	void OnMisfortuneChange(float NewMisfortune, const FString& PlayerName);


	

	UFUNCTION(Client, Reliable)
	void SetSideLightsVisibility_Client(bool bAreSideLightsDisabled_);

	UFUNCTION(BlueprintCallable, Client, Reliable)
	void SetSideLightsVisibility_Server(bool bAreSideLightsDisabled_);

protected:

	//!LightState Enum Class
	/*!Store's the different states the headlamp can be in*/
	enum class LightState { Off, SingleBeam, TrippleBeam };


	//!LightState 
	/*!Handle's what state the headlamp is currently In*/
	LightState lightState;

	
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "HeadLamp.h"
#include "PlayerCharacter.generated.h"


class UInputComponent;
class UCapsuleComponent;
class UCharacterMovementComponent;
class UInputComponent;
class USpringArmComponent;
class USpotLightComponent;
class UStaticMeshComponent;
class AEventZone;






UCLASS(BlueprintType)
class MISFORTUNATE_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

	//!Player Camera
	/*!The camera that the player will use*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* playerCamera;

	//!Stamina float
	/*!The stamina that the player uses for walking & running*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Gameplay)
		float Stamina = 100.0f;

	//!SprintMultiplier float
	/*!Allows the players to string and is used as a scaler for the MaxWalkSpeed*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Gameplay)
		float SprintMultiplier;

			/*Head Lamp Components*/
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
		class USpotLightComponent* lightMid;

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
		class USpotLightComponent* lightLeft;

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
		class USpotLightComponent* lightRight;

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
		class UStaticMeshComponent* lampMesh;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
		float BatteryLevel;
			/*Head Lamp Components*/


	//Removes stamina from our Stamina variable
	UFUNCTION()
	void TickStamina();
protected:

	//!LightState Enum Class
	/*!Store's the different states the headlamp can be in*/
	enum class LightState { Off, SingleBeam, TrippleBeam };

	//!IsPlayerRunning boolean
	/*!Stores a value for if the player is running or not*/
	bool IsPlayerRunning;

	//!TickStaminaTimerHandle FTimerHandler
	/*!Used to create a stamina timer*/
	FTimerHandle TickStaminaTimerHandle;

	//!TickBatteryTimerHandle FTimerHandler
	/*!Used to create a headlamp battery timer*/
	FTimerHandle TickBatteryTimerHandle;

	//!CurrentZone AEventZone
	/*!Pointer to the zone the player is currently In*/
	AEventZone* currentZone;

	//!LightState 
	/*!Handle's what state the headlamp is currently In*/
	LightState lightState;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//!MoveForward Function
	/*!Move's the player forward*/
	void MoveForward(float Val);

	//!MoveRight Function
	/*!Move's the player right*/
	void MoveRight(float Val);

	//!AllowSprint Function
	/*!Allow's the player to sprint*/
	void AllowSprint();

	//!StopSprinting Function
	/*!Stops the player from being able to sprint*/
	void StopSprinting();

	//!ToggleFlashlight Function
	/*!Toggles the headlamp between modes/turns it off*/
	void ToggleHeadLamp();

	//!TickBattery Function
	/*!Decreases the battery depending on the lightState*/
	void TickBattery();
	
	//!ThrowGlowstick Function
	/*!throws a glow stick in front of the player*/
	void ThrowGlowstick();


public:

	//!GetCurrentZone Getter
	/*!Returns the current zone the players is in*/
	AEventZone* GetCurrentZone() const;

	//!SetCurrentZone Function
	/*!Set's the current zone to the given parameter*/
	void SetCurrentZone(AEventZone& eventZone);


	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


};


// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"

#include "Libraries/MisfortunateEnumLibrary.h"

#include "PlayerCharacter.generated.h"


class UInputComponent;
class UCapsuleComponent;
class UCharacterMovementComponent;
class UInputComponent;
class UStaticMeshComponent;
class UInputMappingContext;

class UMisfortunateInputConfig;
class AMisfortunateGameMode;
class AEventZone;
class UCameraComponent;
class UAudioComponent;
class AGlowstick;
class AHeadLamp;
class UModifier;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMisfortuneChangedSignature, float, NewMisfortune, APlayerCharacter*, Player);


UCLASS(BlueprintType)
class MISFORTUNATE_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:

	/* Virtual Overrides */

	APlayerCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;



	/* Character Components */

	//!Player Camera
	/*!The camera that the player will use*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	UCameraComponent* playerCamera;

	//!HeartBeat Audio
	/*!The heartbeat audio component that will link to the meta sound*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Audio)
	UAudioComponent* heartbeatAudio;




	UPROPERTY()
	UMaterialInstanceDynamic* RadialBlurInstance;

	UPROPERTY()
	UMaterialInterface* BlurMaterial_Dynamic;
	


	/* Movement Variables */

	//!Stamina float
	/*!The stamina that the player uses for walking & running*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Movement)
	float Stamina = 100.0f;

	//!Max Stamina float
	/*!The max stamina that the player uses for walking & running*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Movement)
	float MaxStamina = 100.0f;

	//!SprintMultiplier float
	/*!Allows the players to string and is used as a scaler for the MaxWalkSpeed*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Movement)
	float SprintMultiplier;

	UPROPERTY(BlueprintReadWrite, Replicated)
	bool HasBeenPossesed = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovementSettings|Stand")
	float StandRadius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovementSettings|Stand")
	float StandHalfHeight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovementSettings|Stand")
	FVector StandMeshPos;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovementSettings|Crouch")
	float CrouchRadius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovementSettings|Crouch")
	float CrouchHalfHeight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovementSettings|Crouch")
	FVector CrouchMeshPos;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovementSettings|Crouch")
	bool IsCrouching;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovementSettings|Crouch")
	bool IsCrouchBlocked;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovementSettings|Crawl")
	TEnumAsByte<CrawlStates> CrawlState;


	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enhanced Input")
	UInputMappingContext* InputMapping;


	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enhanced Input")
	UMisfortunateInputConfig* InputActions;



	/* Replicated Movement Functions */

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Replicated)
	FRotator ControlRotation;



	/* Movement Functions */

	UFUNCTION()
	void TickStamina();



	/* RPC Movement Functions */

	//!AllowSprint Function
	/*!Allow's the player to sprint*/
	UFUNCTION(Server, Reliable)
	void AllowSprint_Server();

	//!AllowSprint Function
	/*!Allow's the player to sprint*/
	UFUNCTION(Server, Reliable)
	void SlowSprintSpeed_Server();

	//!StopSprinting Function
	/*!Stops the player from being able to sprint*/
	UFUNCTION(Server, Reliable)
	void StopSprinting_Server();

	UFUNCTION(Server, Reliable)
	void SetUseControllerDesiredRotation_Server(bool b);

	UFUNCTION(Server, Reliable)
	void SetUsePawnControlRotation_Server(bool b);

	UFUNCTION(NetMulticast, Unreliable)
	void Multi_UpdateLookRotation(FRotator rot);

	UFUNCTION(NetMulticast, Reliable, WithValidation)
	void Multi_UpdateMovementState(CrawlStates CrawlState_, float TargetRad, float TargetHalfHeight, FVector TargetLoc);

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_UpdateMovementState(CrawlStates CrawlState_, float TargetRad, float TargetHalfHeight, FVector TargetLoc);



	/*Modifier Variables*/

	UPROPERTY()
	TArray<UModifier*> ActiveModifiers;



	/*Modifier Functions*/

	UFUNCTION()
	void AddNewModifier(UModifier* NewModifier);

	UFUNCTION()
	void RemoveModifier(UModifier* ModifierToRemove);



	/* Player Lighting Variables */

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	int AvailableGlowsticks;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* headlampMesh;
			
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	AHeadLamp* HeadLamp;

	TSubclassOf<AGlowstick> Glowstick_Class;



	/* Player Input Functions */

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_ThrowGlowstick();

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_TriggerHeadLamp();

	void Move(const  FInputActionValue& Value);

	void Turn(const  FInputActionValue& Value);



	/* RPC Player Input Functions */

	UFUNCTION(Server, Reliable)
	void Server_SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent, class AMPlayerController* PC);

	UFUNCTION(NetMulticast, Reliable)
	void Multi_SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent, class AMPlayerController* PC);

	

	/* Misfortune Variables  */

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, Category = Gameplay)
	float Misfortune;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated)
	float MaxMisfortune;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Replicated)
	float MaxMisfortuneChange;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Replicated)
	bool bCanMisfortuneIncrease;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FOnMisfortuneChangedSignature OnMisfortuneChanged;



	/* Misfortune Functions  */

	UFUNCTION(BlueprintCallable)
	void IncreaseMisfortune(const float Misfortune_);

	UFUNCTION(BlueprintCallable)
	void DecreaseMisfortune(const float Misfortune_);

	float GetMisfortune() const;



	/* RPC Misfortune Functions  */

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_SetMisfortune(const float Misfortune_);


	UFUNCTION(Client, Reliable)
	void Local_OnMisfortuneChanged(const float NewMisfortune);

	

	/* Event Zone Variables  */

	//!CurrentZone AEventZone
	/*!Pointer to the zone the player is currently In*/
	AEventZone* currentZone;



	/* Event Zone Functions  */
	//!GetCurrentZone Getter
	/*!Returns the current zone the players is in*/
	AEventZone* GetCurrentZone() const;

	//!SetCurrentZone Function
	/*!Set's the current zone to the given parameter*/
	void SetCurrentZone(AEventZone* eventZone);



	/*Local Movement Variables*/

	FRotator LookRotation;

	//!IsPlayerRunning boolean
	/*!Stores a value for if the player is running or not*/
	bool IsPlayerRunning;

	//!TickStaminaTimerHandle FTimerHandler
	/*!Used to create a stamina timer*/
	FTimerHandle TickStaminaTimerHandle;

	float OriginalMaxWalkSpeed;

	FTimerHandle TickTraceCheckTimerHandle;



	/*Local Movement Functions*/

	void UpdateMovementState(CrawlStates CrawlState_);

	float FSelectInterpTarget(float Stand,float Crouch);

	FVector VSelectInterpTarget(FVector Stand, FVector Crouch);

	void ToggleCrawl();

	void RetrieveControlRotation();

	void TraceChecks();



	/*Extra Functions*/

	UFUNCTION(Client, Reliable)
	void Local_PrintDebugMessages();

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateHeartBeatAudio();

	//!ThrowGlowstick Function
	/*!throws a glow stick in front of the player*/
	void ThrowGlowstick();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	AMisfortunateGameMode* GetGameMode();
};


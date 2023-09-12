// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "PlayerCharacter.generated.h"


class UInputComponent;
class UCapsuleComponent;
class UCharacterMovementComponent;
class UInputComponent;
class UStaticMeshComponent;
class AEventZone;


UENUM()
enum CrawlStates
{
	Stand   UMETA(DisplayName = "Standing"),
	Crouch UMETA(DisplayName = "Crouching"),
};




DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMisfortuneChangedSignature, float, NewMisfortune, APlayerCharacter*, Player);


UCLASS(BlueprintType)
class MISFORTUNATE_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();


	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;


	//!Player Camera
	/*!The camera that the player will use*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		class UCameraComponent* playerCamera;

	//!HeartBeat Audio
	/*!The heartbeat audio component that will link to the meta sound*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Audio)
		class UAudioComponent* heartbeatAudio;

	UPROPERTY()
		UMaterialInstanceDynamic* RadialBlurInstance;

	UPROPERTY()
		UMaterialInterface* BlurMaterial_Dynamic;
	

#pragma region Movement

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
	
	// Crawl Variables
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
	// Crawl Variables

	//Removes stamina from our Stamina variable
	UFUNCTION()
		void TickStamina();


#pragma endregion



#pragma region Lighting
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		int AvailableGlowsticks;


	TSubclassOf<class AGlowstick> Glowstick_Class;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		 UStaticMeshComponent* headlampMesh;
			/*Head Lamp Components*/


	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class AHeadLamp* HeadLamp;

#pragma endregion 


	
	

#pragma region Enhanced Input
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enhanced Input")
		class UInputMappingContext* InputMapping;


	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enhanced Input")
		class UMisfortunateInputConfig* InputActions;


	UFUNCTION(Server, Reliable, WithValidation)
		void Server_ThrowGlowstick();

	UFUNCTION(Server, Reliable, WithValidation)
		void Server_TriggerHeadLamp();


	void Move(const  FInputActionValue& Value);

	void Turn(const  FInputActionValue& Value);
	// Called to bind functionality to input
	UFUNCTION(Server, Reliable)
	 void Server_SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent, class AMPlayerController* PC);

	UFUNCTION(NetMulticast, Reliable)
		void Multi_SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent, class AMPlayerController* PC);

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
#pragma endregion


#pragma region Misfortune

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


	UFUNCTION(Server, Reliable, WithValidation)
		void Server_SetMisfortune(const float Misfortune_);


	UFUNCTION(Client, Reliable)
	void Local_OnMisfortuneChanged(const float NewMisfortune);

	



	UFUNCTION(BlueprintCallable)
	void IncreaseMisfortune(const float Misfortune_);

	UFUNCTION(BlueprintCallable)
	void DecreaseMisfortune(const float Misfortune_);


	float GetMisfortune() const;


	

#pragma endregion


	//!GetCurrentZone Getter
/*!Returns the current zone the players is in*/
	AEventZone* GetCurrentZone() const;

	//!SetCurrentZone Function
	/*!Set's the current zone to the given parameter*/
	void SetCurrentZone(AEventZone* eventZone);



	UFUNCTION(Client, Reliable)
		void Local_PrintDebugMessages();

	
	UFUNCTION()
		void AddNewModifier(class UModifier* NewModifier);

	UFUNCTION()
		void RemoveModifier(class UModifier* ModifierToRemove);


	UFUNCTION(BlueprintCallable, BlueprintPure)
		class AMisfortunateGameMode* GetGameMode();
protected:



	UPROPERTY()
		TArray<class UModifier*> ActiveModifiers;



#pragma region Movement

	FRotator LookRotation;

	//!IsPlayerRunning boolean
	/*!Stores a value for if the player is running or not*/
	bool IsPlayerRunning;

	//!TickStaminaTimerHandle FTimerHandler
	/*!Used to create a stamina timer*/
	FTimerHandle TickStaminaTimerHandle;


	float OriginalMaxWalkSpeed;


	//!AllowSprint Function
	/*!Allow's the player to sprint*/
	void AllowSprint();

	//!AllowSprint Function
	/*!Allow's the player to sprint*/
	void SlowSprintSpeed();

	//!StopSprinting Function
	/*!Stops the player from being able to sprint*/
	void StopSprinting();

	float FSelectInterpTarget(float Stand,float Crouch);

	FVector VSelectInterpTarget(FVector Stand, FVector Crouch);

	void ToggleCrawl();

	void UpdateMovementState(CrawlStates CrawlState_);


	UFUNCTION(NetMulticast, Unreliable, WithValidation)
		void Multi_UpdateLookRotation(FRotator rot);

	UFUNCTION(NetMulticast, Reliable, WithValidation)

		void Multi_UpdateMovementState(CrawlStates CrawlState_, float TargetRad, float TargetHalfHeight, FVector TargetLoc);



	UFUNCTION(Server, Reliable, WithValidation)
		void Server_UpdateMovementState(CrawlStates CrawlState_, float TargetRad, float TargetHalfHeight, FVector TargetLoc);

	UFUNCTION(BlueprintImplementableEvent)
		void UpdateHeartBeatAudio();


#pragma endregion 


	void TraceChecks();

	FTimerHandle TickTraceCheckTimerHandle;

	


	//!CurrentZone AEventZone
/*!Pointer to the zone the player is currently In*/
	AEventZone* currentZone;



	//!ThrowGlowstick Function
	/*!throws a glow stick in front of the player*/
	void ThrowGlowstick();
};


// Fill out your copyright notice in the Description page of Project Settings.

#pragma

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
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
	Crawl UMETA(DisplayName = "Crawling"),
};


UCLASS(BlueprintType)
class MISFORTUNATE_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

	//!Player Camera
	/*!The camera that the player will use*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		class UCameraComponent* playerCamera;

	//!Stamina float
	/*!The stamina that the player uses for walking & running*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Movement)
		float Stamina = 100.0f;

	//!SprintMultiplier float
	/*!Allows the players to string and is used as a scaler for the MaxWalkSpeed*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement)
		float SprintMultiplier;
	
	

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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovementSettings|Crawl")
		float CrawlRadius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovementSettings|Crawl")
		float CrawlHalfHeight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovementSettings|Crawl")
		FVector CrawlMeshPos;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovementSettings|Crawl")
		bool IsCrawlBlocked;

	// Crawl Variables


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly,Replicated, Category = Gameplay)
		float Misfortune;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		int AvailableGlowsticks;



	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		 UStaticMeshComponent* headlampMesh;
			/*Head Lamp Components*/


	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class AHeadLamp* HeadLamp;

	//Removes stamina from our Stamina variable
	UFUNCTION()
	void TickStamina();
protected:

	FRotator LookRotation;

	//!IsPlayerRunning boolean
	/*!Stores a value for if the player is running or not*/
	bool IsPlayerRunning;

	//!TickStaminaTimerHandle FTimerHandler
	/*!Used to create a stamina timer*/
	FTimerHandle TickStaminaTimerHandle;

	//!CurrentZone AEventZone
	/*!Pointer to the zone the player is currently In*/
	AEventZone* currentZone;

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

	float FSelectInterpTarget(float Stand,float Crouch,float Crawl);

	FVector VSelectInterpTarget(FVector Stand, FVector Crouch, FVector Crawl);


	void HandleCrouchCrawl();

	void ToggleCrawl();

	void TraceChecks();

	FTimerHandle TickTraceCheckTimerHandle;

	void UpdateMovementState(CrawlStates CrawlState_);
	
	//!ThrowGlowstick Function
	/*!throws a glow stick in front of the player*/
	void ThrowGlowstick();

	UFUNCTION(NetMulticast,Unreliable, WithValidation)
		void Multi_UpdateLookRotation(FRotator rot);



	UFUNCTION(NetMulticast, Reliable, WithValidation)
		void Multi_UpdateMovementState(CrawlStates CrawlState_, float TargetRad, float TargetHalfHeight, FVector TargetLoc);


	UFUNCTION(Server,Reliable,WithValidation)
		void Server_ThrowGlowstick();

	UFUNCTION(Server, Reliable, WithValidation)
		void Server_TriggerHeadLamp();

	UFUNCTION(Server, Reliable, WithValidation)
		void Server_UpdateMovementState(CrawlStates CrawlState_, float TargetRad, float TargetHalfHeight, FVector TargetLoc);

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
public:

	UFUNCTION(Client, Reliable, WithValidation)
		void Client_SetMisfortune(const float Misfortune_);

	//!GetCurrentZone Getter
	/*!Returns the current zone the players is in*/
	AEventZone* GetCurrentZone() const;

	//!SetCurrentZone Function
	/*!Set's the current zone to the given parameter*/
		void SetCurrentZone(AEventZone* eventZone);

	

	float GetMisfortune() const;

	


	void SetMisfortune(const float Misfortune_);

	void IncreaseMisfortune(const float Misfortune_);

	void DecreaseMisfortune(const float Misfortune_);


	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;




};


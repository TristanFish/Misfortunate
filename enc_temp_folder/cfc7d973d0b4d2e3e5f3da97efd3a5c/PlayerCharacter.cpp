// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerCharacter.h"
#include "Runtime/Engine/Classes/Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SpotLightComponent.h"
#include "Components/AudioComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "MisfortunateGameMode.h"

#include "MPlayerController.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Math/UnrealMathUtility.h"
#include "Actors/EventZone.h"
#include "Actors/Glowstick.h"
#include "HeadLamp.h"
#include "CustomAnimInstance.h"
#include "Net/UnrealNetwork.h"


#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "EnhancedInput/Public/EnhancedInputComponent.h"
#include "MisfortunateInputConfig.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Initialize the players capsule collider
	GetCapsuleComponent()->InitCapsuleSize(55.0f, 90.0f);

	// Setup and initialize the players camera
	playerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	headlampMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("HeadLampMesh"));

	heartbeatAudio = CreateDefaultSubobject<UAudioComponent>(TEXT("HeartBeatAudio"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshOutput(TEXT("StaticMesh'/Game/Misfortuante/Models/PlayerObjects/HeadLamp.HeadLamp'"));
	headlampMesh->SetStaticMesh(MeshOutput.Object);
	
	static ConstructorHelpers::FObjectFinder<UBlueprint> GlowstickOutput(TEXT("/Script/Engine.Blueprint'/Game/Misfortuante/Blueprints/Interactibles/BP_Glowstick.BP_Glowstick'"));

	Glowstick_Class = GlowstickOutput.Object->GeneratedClass;

	playerCamera->SetupAttachment(GetMesh(),  FName("Head"));
	headlampMesh->SetupAttachment(GetMesh(), FName("Head"));

	heartbeatAudio->SetupAttachment(GetRootComponent());

	playerCamera->bUsePawnControlRotation = true;

	SetReplicates(true);

	SprintMultiplier = 1.3f;
	AvailableGlowsticks = 3;
	

	Misfortune = 0.0f;

	CrawlState = CrawlStates::Stand;

	StandRadius = 45.0f;
	StandHalfHeight = 78.0f;

	CrouchRadius = 30.0f;
	CrouchHalfHeight = 45.0f;
	IsCrouchBlocked = false;


	StandMeshPos = FVector(0.0f, 0.0f, -80.0f);
	CrouchMeshPos = FVector(0.0f, 0.0f, -80.0f);
}



// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	APawn::BeginPlay();

	OriginalMaxWalkSpeed = GetCharacterMovement()->MaxWalkSpeed;


	GetWorld()->GetTimerManager().SetTimer(TickTraceCheckTimerHandle, this, &APlayerCharacter::TraceChecks, 0.1f, true);
	GetWorld()->GetTimerManager().SetTimer(TickStaminaTimerHandle, this, &APlayerCharacter::TickStamina, 0.2f, true);


	OnMisfortuneChanged.AddDynamic(HeadLamp, &AHeadLamp::OnMisfortuneChange);


}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
	if (GetWorld()->IsServer())
	{
		Multi_UpdateLookRotation(GetControlRotation());
	}


	if (UGameplayStatics::GetPlayerPawn(GetWorld(), 0) != this)
	{
		playerCamera->bUsePawnControlRotation = false;

		playerCamera->SetWorldRotation(LookRotation);
	}
	else
	{
		playerCamera->bUsePawnControlRotation = true;

	}
}

void APlayerCharacter::TickStamina()
{
	float PlayerSpeed = Cast<UCustomAnimInstance>(GetMesh()->GetAnimInstance())->speed;



	if (GetCharacterMovement()->Velocity.Size() > 0.0)
	{

		


		if (PlayerSpeed > OriginalMaxWalkSpeed)
		{
			float StaminaDecrese = FMath::GetMappedRangeValueClamped(FVector2D(0.0f, (OriginalMaxWalkSpeed * SprintMultiplier)), FVector2D(0.0f, 4.0f), PlayerSpeed);

			Stamina -= StaminaDecrese;
			if (!heartbeatAudio->IsPlaying())
				heartbeatAudio->FadeIn(1.0f, 1.0);
		}

		else if (PlayerSpeed < OriginalMaxWalkSpeed && Stamina < MaxStamina)
		{
			float StaminaIncrease = FMath::GetMappedRangeValueClamped(FVector2D(0.0f, OriginalMaxWalkSpeed), FVector2D(5.0f, 2.5f), PlayerSpeed);

			Stamina = FMath::Clamp(Stamina + StaminaIncrease, 0.0f, MaxStamina);
		}	
	}
	else
	{
		float StaminaIncrease = FMath::GetMappedRangeValueClamped(FVector2D(0.0f, OriginalMaxWalkSpeed), FVector2D(5.0f, 2.5f), PlayerSpeed);

		Stamina = FMath::Clamp(Stamina + StaminaIncrease, 0.0f, MaxStamina);

		if (FMath::IsNearlyEqual(Stamina, MaxStamina, 5.0f))
		{
			if(heartbeatAudio->IsPlaying())
				heartbeatAudio->FadeOut(1.0f, 0.5);
		}
	}


	UpdateHeartBeatAudio();
}

void APlayerCharacter::Move(const FInputActionValue& Value)
{
	if (Controller != nullptr)
	{
		const FVector2D MoveValue = Value.Get<FVector2D>();
		const FRotator MovementRotation(0, Controller->GetControlRotation().Yaw, 0);

		// Forward/Backward direction
		if (MoveValue.Y != 0.f)
		{
			// Get forward vector
			const FVector Direction = MovementRotation.RotateVector(FVector::ForwardVector);

			AddMovementInput(Direction, MoveValue.Y);
		}

		// Right/Left direction
		if (MoveValue.X != 0.f)
		{
			// Get right vector
			const FVector Direction = MovementRotation.RotateVector(FVector::RightVector);

			AddMovementInput(Direction, MoveValue.X);
		}
	}
}

void APlayerCharacter::Turn(const FInputActionValue& Value)
{
	if (Controller != nullptr)
	{
		const FVector2D LookValue = Value.Get<FVector2D>();

		if (LookValue.X != 0.f)
		{
			AddControllerYawInput(LookValue.X);
		}

		if (LookValue.Y != 0.f)
		{
			AddControllerPitchInput(LookValue.Y);
		}
	}
}




void APlayerCharacter::AllowSprint()
{
	if (Stamina > 0.0f)
	{
		


		if (CrawlState == CrawlStates::Crouch)
		{
			if (!IsCrouchBlocked)
			{
				CrawlState = CrawlStates::Stand;
				IsCrouching = false;
				IsPlayerRunning = true;

			}
		}
		else
		{
			IsPlayerRunning = true;
		}
		GetCharacterMovement()->MaxWalkSpeed = OriginalMaxWalkSpeed * SprintMultiplier;

	}
}

void APlayerCharacter::StopSprinting()
{

	IsPlayerRunning = false;
	GetCharacterMovement()->MaxWalkSpeed /=  SprintMultiplier;
}


float APlayerCharacter::FSelectInterpTarget(float Stand, float Crouch)
{
	float targetValue = 0.0f;

	switch (CrawlState)
	{
	case CrawlStates::Stand:
		targetValue =  Stand;
		break;
	case CrawlStates::Crouch:
		targetValue = Crouch;
		break;
	default:
		break;
	}

	return targetValue;
}

FVector APlayerCharacter::VSelectInterpTarget(FVector Stand,FVector Crouch)
{
	FVector targetValue = FVector(0.0f);

	switch (CrawlState)
	{
	case CrawlStates::Stand:
		targetValue = Stand;
		break;

	case CrawlStates::Crouch:
		targetValue = Crouch;
		break;
	default:
		break;
	}

	return targetValue;
}





void APlayerCharacter::ToggleCrawl()
{
	switch (CrawlState)
	{
	case CrawlStates::Stand:
		UpdateMovementState(CrawlStates::Crouch);
		IsCrouching = true;
		break;

	case CrawlStates::Crouch:

		if (IsCrouching)
		{
			IsCrouching = false;
			UpdateMovementState(CrawlStates::Stand);
			break;
		}
		break;
	default:
		break;
	}
}

void APlayerCharacter::TraceChecks()
{
	FVector Start, End;
	FHitResult RV_Hit(ForceInit);

	TArray<FVector> VecLengths{ FVector(25.0f,0.0f,0.0f), 
								FVector(-25.0f,0.0f,0.0f), 
								FVector(0.0f,25.0f,0.0f),
								FVector(0.0f,-25.0f,0.0f) };

	for (int i = 0; i < 4; i++)
	{
		Start = GetActorLocation() + VecLengths[i];
		End = GetActorUpVector() * FSelectInterpTarget(CrouchHalfHeight * 2.3, CrouchHalfHeight * 2.3) + Start;


		bool IsHit = GetWorld()->LineTraceSingleByChannel(RV_Hit, Start, End, ECollisionChannel::ECC_Visibility);
		

		IsCrouchBlocked = IsHit;
	}

}

void APlayerCharacter::Server_TriggerHeadLamp_Implementation()
{
	HeadLamp->ToggleHeadLamp();
}

bool APlayerCharacter::Server_TriggerHeadLamp_Validate()
{
	return true;
}




void APlayerCharacter::Server_UpdateMovementState_Implementation(CrawlStates CrawlState_, float TargetRad, float TargetHalfHeight, FVector TargetLoc)
{

	Multi_UpdateMovementState(CrawlState_, TargetRad, TargetHalfHeight, TargetLoc);
}

bool APlayerCharacter::Server_UpdateMovementState_Validate(CrawlStates CrawlState_, float TargetRad, float TargetHalfHeight, FVector TargetLoc)
{
	return true;
}


void APlayerCharacter::UpdateMovementState(CrawlStates CrawlState_)
{
	CrawlState = CrawlState_;

	float TargetRad = FSelectInterpTarget(StandRadius, CrouchRadius);
	float TargetHalfHeight = FSelectInterpTarget(StandHalfHeight, CrouchHalfHeight);
	FVector TargetLoc = VSelectInterpTarget(StandMeshPos, CrouchMeshPos);


	if (GetLocalRole() < ROLE_Authority)
	{
		Server_UpdateMovementState(CrawlState_, TargetRad, TargetHalfHeight, TargetLoc);
	}
	else
	{
		Multi_UpdateMovementState(CrawlState_, TargetRad, TargetHalfHeight, TargetLoc);
	}

	
}

void APlayerCharacter::Multi_UpdateMovementState_Implementation(CrawlStates CrawlState_, float TargetRad, float TargetHalfHeight, FVector TargetLoc)
{

	CrawlState = CrawlState_;
	GetCapsuleComponent()->SetCapsuleSize(TargetRad, TargetHalfHeight);
	GetMesh()->SetRelativeLocation(TargetLoc);
	GetCharacterMovement()->MaxWalkSpeed = FSelectInterpTarget(OriginalMaxWalkSpeed, GetCharacterMovement()->MaxWalkSpeedCrouched);
}

bool APlayerCharacter::Multi_UpdateMovementState_Validate(CrawlStates CrawlState_, float TargetRad, float TargetHalfHeight, FVector TargetLoc)
{
	return true;
}




void APlayerCharacter::ThrowGlowstick()
{
	if (AvailableGlowsticks != 0)
	{
		Server_ThrowGlowstick();
		AvailableGlowsticks -= 1;
	}
}

void APlayerCharacter::Multi_UpdateLookRotation_Implementation(FRotator rot)
{
	if (UGameplayStatics::GetPlayerPawn(GetWorld(), 0) != this)
	{
		LookRotation = rot;
	}
}

bool APlayerCharacter::Multi_UpdateLookRotation_Validate(FRotator rot)
{

	return true;
}





bool APlayerCharacter::Server_ThrowGlowstick_Validate()
{
	return true;
}

void APlayerCharacter::Server_ThrowGlowstick_Implementation()
{
	AGlowstick* spawnedGlowstick = GetWorld()->SpawnActor<AGlowstick>(Glowstick_Class,(GetActorForwardVector() * 100) + GetActorLocation(), FRotator(0.0f, 0.0f, 0.0f));

	OnMisfortuneChanged.AddDynamic(spawnedGlowstick, &AGlowstick::OnMisfortuneChange);
}





void APlayerCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(APlayerCharacter, Misfortune);
	DOREPLIFETIME(APlayerCharacter, HasBeenPossesed);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);
	Super::SetupPlayerInputComponent(PlayerInputComponent);


	AMPlayerController* PC = Cast<AMPlayerController>(GetController());

	// Get the local player subsystem
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer());
	// Clear out existing mapping, and add our mapping
	Subsystem->ClearAllMappings();
	Subsystem->AddMappingContext(InputMapping, 0);

	UEnhancedInputComponent* PEI = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	PEI->BindAction(InputActions->InputMove, ETriggerEvent::Triggered, this, &APlayerCharacter::Move);
	PEI->BindAction(InputActions->InputTurn, ETriggerEvent::Triggered, this, &APlayerCharacter::Turn);


	PEI->BindAction(InputActions->InputSprint, ETriggerEvent::Triggered, this, &APlayerCharacter::AllowSprint);
	PEI->BindAction(InputActions->InputSprint, ETriggerEvent::Completed, this, &APlayerCharacter::StopSprinting);


	PEI->BindAction(InputActions->InputToggleLight, ETriggerEvent::Triggered, this, &APlayerCharacter::Server_TriggerHeadLamp);


	PEI->BindAction(InputActions->InputThrow, ETriggerEvent::Triggered, this, &APlayerCharacter::ThrowGlowstick);
	PEI->BindAction(InputActions->InputCrouch, ETriggerEvent::Triggered, this, &APlayerCharacter::ToggleCrawl);

}

void APlayerCharacter::PossessedBy(AController* NewController)
{
}

AEventZone* APlayerCharacter::GetCurrentZone() const
{
	return currentZone;
}

void APlayerCharacter::SetCurrentZone(AEventZone* eventZone)
{
	if (eventZone != nullptr)
	{
		currentZone = eventZone;

	}
}



float APlayerCharacter::GetMisfortune() const
{
	return Misfortune;
}

void APlayerCharacter::Server_SetMisfortune_Implementation(const float Misfortune_)
{
	Misfortune = Misfortune_;

	OnMisfortuneChanged.Broadcast(Misfortune, this);
}

bool APlayerCharacter::Server_SetMisfortune_Validate(const float Misfortune_)
{
	return true;
}

void APlayerCharacter::SetMisfortune(const float Misfortune_)
{
	Misfortune = Misfortune_;
}

void APlayerCharacter::IncreaseMisfortune(const float Misfortune_)
{

	Server_SetMisfortune(FMath::Clamp(Misfortune + Misfortune_,0.0f,MaxMisfortune));

}

void APlayerCharacter::DecreaseMisfortune(const float Misfortune_)
{
	Server_SetMisfortune(FMath::Clamp(Misfortune - Misfortune_, 0.0f, MaxMisfortune));
}


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
	


	playerCamera->SetupAttachment(GetMesh(),  FName("Head"));
	headlampMesh->SetupAttachment(GetMesh(), FName("Head"));

	heartbeatAudio->SetupAttachment(GetRootComponent());

	playerCamera->bUsePawnControlRotation = true;

	SetReplicates(true);

	SprintMultiplier = 1.3f;
	AvailableGlowsticks = 3;
	


	Misfortune = FMath::RandRange(10.0f, 80.0f);

	CrawlState = CrawlStates::Stand;

	StandRadius = 45.0f;
	StandHalfHeight = 78.0f;

	CrouchRadius = 30.0f;
	CrouchHalfHeight = 45.0f;

	CrawlRadius = 20.0f;
	CrawlHalfHeight = 20.0f;

	IsCrouchBlocked = false;
	IsCrawlBlocked = false;


	StandMeshPos = FVector(0.0f, 0.0f, -80.0f);
	CrouchMeshPos = FVector(-20.0f, 0.0f, -80.0f);
	CrawlMeshPos = FVector(-20.0f, 0.0f, -19.0f);
}



// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	APawn::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(TickTraceCheckTimerHandle, this, &APlayerCharacter::TraceChecks, 0.1f, true);
	GetWorld()->GetTimerManager().SetTimer(TickStaminaTimerHandle, this, &APlayerCharacter::TickStamina, 0.2f, true);
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

		if (PlayerSpeed > 451.0f)
		{
			Stamina -= 1.5f;
			if (!heartbeatAudio->IsPlaying())
				heartbeatAudio->FadeIn(1.0f, 1.0);
		}
		else if (PlayerSpeed <= 451.0f && Stamina < MaxStamina)
		{
			Stamina = FMath::Clamp(Stamina + 0.5f, 0.0f, MaxStamina);
		}	
	}
	else
	{
		Stamina = FMath::Clamp(Stamina + 1.5f, 0.0f, MaxStamina);

		if (FMath::IsNearlyEqual(Stamina, MaxStamina, 5.0f))
		{
			if(heartbeatAudio->IsPlaying())
				heartbeatAudio->FadeOut(1.0f, 0.5);
		}
	}


	UpdateHeartBeatAudio();
}

void APlayerCharacter::MoveForward(float Val)
{
	if (Val != 0)
	{

		AddMovementInput(GetActorForwardVector(), Val);

		
	}
}

void APlayerCharacter::MoveRight(float Val)
{
	if (Val != 0)
	{

		AddMovementInput(GetActorRightVector(), Val);
	
		
	}
	
}

void APlayerCharacter::AllowSprint()
{
	if (Stamina > 0.0f)
	{
		


		if (CrawlState == CrawlStates::Crouch)
		{
			if (!IsCrouchBlocked && !IsCrawlBlocked)
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
		GetCharacterMovement()->MaxWalkSpeed *= SprintMultiplier;

	}
}

void APlayerCharacter::StopSprinting()
{

	IsPlayerRunning = false;
	GetCharacterMovement()->MaxWalkSpeed /= SprintMultiplier;
}


float APlayerCharacter::FSelectInterpTarget(float Stand, float Crouch, float Crawl)
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
	case CrawlStates::Crawl:
		targetValue = Crawl;
		break;
	default:
		break;
	}

	return targetValue;
}

FVector APlayerCharacter::VSelectInterpTarget(FVector Stand,FVector Crouch, FVector Crawl)
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
	case CrawlStates::Crawl:
		targetValue = Crawl;
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
		break;

	case CrawlStates::Crouch:

		if (IsCrouching)
		{
			IsCrouching = false;
			UpdateMovementState(CrawlStates::Stand);
			break;
		}
		UpdateMovementState(CrawlStates::Crawl);
		IsCrouching = true;
		break;
	case CrawlStates::Crawl:

		UpdateMovementState(CrawlStates::Crouch);
		IsCrouching = true;
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
		End = GetActorUpVector() * FSelectInterpTarget(CrouchHalfHeight * 2.3, CrouchHalfHeight * 2.3, CrouchHalfHeight * 2.8) + Start;


		bool IsHit = GetWorld()->LineTraceSingleByChannel(RV_Hit, Start, End, ECollisionChannel::ECC_Visibility);
		

		IsCrouchBlocked = IsHit;
	}

	for (int i = 0; i < 4; i++)
	{
		Start = GetActorLocation() + (VecLengths[i] );
		End = GetActorUpVector() * 34.0f + Start;


		bool IsHit = GetWorld()->LineTraceSingleByChannel(RV_Hit, Start, End, ECollisionChannel::ECC_Visibility);

		IsCrawlBlocked = IsHit;
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

	float TargetRad = FSelectInterpTarget(StandRadius, CrouchRadius, CrawlRadius);
	float TargetHalfHeight = FSelectInterpTarget(StandHalfHeight, CrouchHalfHeight, CrawlHalfHeight);
	FVector TargetLoc = VSelectInterpTarget(StandMeshPos, CrouchMeshPos, CrawlMeshPos);


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
	GetCharacterMovement()->MaxWalkSpeed = FSelectInterpTarget(450.0f, 150.0f, 75.0f);
	

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
	AGlowstick* spawnedGlowstick = GetWorld()->SpawnActor<AGlowstick>((GetActorForwardVector() * 100) + GetActorLocation(), FRotator(0.0f, 0.0f, 0.0f));
}





void APlayerCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(APlayerCharacter, Misfortune);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &APlayerCharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &APlayerCharacter::StopJumping);
	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &APlayerCharacter::AllowSprint);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &APlayerCharacter::StopSprinting);

	PlayerInputComponent->BindAction("ToggleLight", IE_Pressed, this, &APlayerCharacter::Server_TriggerHeadLamp);

	PlayerInputComponent->BindAction("Throw", IE_Pressed, this, &APlayerCharacter::ThrowGlowstick);
	PlayerInputComponent->BindAction("Crawl", IE_Pressed, this, &APlayerCharacter::ToggleCrawl);


	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);

	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);

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
	Misfortune += Misfortune_;
}

void APlayerCharacter::DecreaseMisfortune(const float Misfortune_)
{
	Misfortune -= Misfortune_;
}


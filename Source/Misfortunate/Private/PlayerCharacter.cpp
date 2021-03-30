// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerCharacter.h"
#include "Runtime/Engine/Classes/Components/CapsuleComponent.h"
#include "Runtime/Engine/Classes/Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/SpotLightComponent.h"
#include "Components/StaticMeshComponent.h"
#include "EventZone.h"
#include "Glowstick.h"


// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Initialize the players capsule collider
	GetCapsuleComponent()->InitCapsuleSize(55.0f, 90.0f);

	// Setup and initialize the players camera
	playerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));


	lampMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("HeadLamp"));
	lightMid = CreateDefaultSubobject<USpotLightComponent>(TEXT("MiddleLight"));
	lightLeft = CreateDefaultSubobject<USpotLightComponent>(TEXT("LeftLight"));
	lightRight = CreateDefaultSubobject<USpotLightComponent>(TEXT("RightLight"));


	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshOutput(TEXT("StaticMesh'/Game/Misfortuante/Models/PlayerObjects/HeadLamp.HeadLamp'"));

	lampMesh->SetStaticMesh(MeshOutput.Object);

	lampMesh->SetupAttachment(GetMesh(), "HeadTop_End");



	// Setup Attachments
	playerCamera->SetupAttachment(GetMesh(), FName("Head"));

	
	lightMid->SetupAttachment(lampMesh);
	lightLeft->SetupAttachment(lampMesh);
	lightRight->SetupAttachment(lampMesh);

	BatteryLevel = 100.0f;

	playerCamera->bUsePawnControlRotation = true;


	SprintMultiplier = 1.3f;
}

void APlayerCharacter::TickStamina()
{
	Stamina -= 1.5f;
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("Stamina: %f"), Stamina));

}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	lightState = LightState::Off;

	lightMid->SetVisibility(false);
	lightLeft->SetVisibility(false);
	lightRight->SetVisibility(false);

	GetWorld()->GetTimerManager().SetTimer(TickBatteryTimerHandle, this, &APlayerCharacter::TickBattery, 0.1f);

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
		IsPlayerRunning = true;
		GetCharacterMovement()->MaxWalkSpeed *= SprintMultiplier;
		GetWorld()->GetTimerManager().SetTimer(TickStaminaTimerHandle, this, &APlayerCharacter::TickStamina, 0.2f,IsPlayerRunning);
	}
}

void APlayerCharacter::StopSprinting()
{
	IsPlayerRunning = false;
	GetCharacterMovement()->MaxWalkSpeed /= SprintMultiplier;
	GetWorld()->GetTimerManager().PauseTimer(TickStaminaTimerHandle);
}


void APlayerCharacter::ToggleHeadLamp()
{
	switch (lightState)
	{
	case LightState::Off:
		lightMid->SetVisibility(true);
		lightState = LightState::SingleBeam;
		break;
	case LightState::SingleBeam:
		lightLeft->SetVisibility(true);
		lightRight->SetVisibility(true);
		lightState = LightState::TrippleBeam;

		break;
	case LightState::TrippleBeam:
		lightMid->SetVisibility(false);
		lightLeft->SetVisibility(false);
		lightRight->SetVisibility(false);
		lightState = LightState::Off;
		break;

	default:
		break;
	}
}

void APlayerCharacter::TickBattery()
{
	switch (lightState)
	{
	case LightState::SingleBeam:
		BatteryLevel -= 0.2;
		break;
	case LightState::TrippleBeam:
		BatteryLevel -= 0.4;
		break;
	default:
		break;
	}
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Battery Level: %f"), BatteryLevel));

}

void APlayerCharacter::ThrowGlowstick()
{
	AGlowstick* spawnedGlowstick = GetWorld()->SpawnActor<AGlowstick>((GetActorForwardVector() * 100) + GetActorLocation(),FRotator(0.0f,0.0f,0.0f));

	spawnedGlowstick->GetMesh()->AddImpulse(GetActorForwardVector() * FVector(100.0f,100.0f,100.0f));
	spawnedGlowstick->GetMesh()->AddAngularImpulse(FVector(50.0f, 50.0f, 50.0f));
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

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

	PlayerInputComponent->BindAction("ToggleLight", IE_Pressed, this, &APlayerCharacter::ToggleHeadLamp);

	PlayerInputComponent->BindAction("Throw", IE_Pressed, this, &APlayerCharacter::ThrowGlowstick);


	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);

	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);

}

AEventZone* APlayerCharacter::GetCurrentZone() const
{
	return currentZone;
}

void APlayerCharacter::SetCurrentZone(AEventZone& eventZone)
{
	if (&eventZone != nullptr)
	{
		currentZone = &eventZone;

		FString S_Zone = UEnum::GetValueAsString(currentZone->ZoneLevel);
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, S_Zone);
	}
}


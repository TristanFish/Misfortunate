// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyPlayerCharacter.h"

#include "MPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Net/UnrealNetwork.h"

#include "Runtime/Engine/Classes/Camera/CameraComponent.h"
// Sets default values
ALobbyPlayerCharacter::ALobbyPlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	LobbyCam = CreateDefaultSubobject<UCameraComponent>(TEXT("LobbyCam"));


	LobbyCam->SetupAttachment(GetRootComponent());


	MinYawViewAngle = -80.0f;
	MaxYawViewAngle = 80.0f;
}

// Called when the game starts or when spawned

void ALobbyPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	AMPlayerController* controller = Cast<AMPlayerController>(GetController());

	if (!controller)
		return;

	controller->ClientSetRotation(GetActorRotation());
	controller->SetViewYawExtents(MinYawViewAngle, MaxYawViewAngle);
	
}






void ALobbyPlayerCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ALobbyPlayerCharacter,HasBeenPossesed);
}

void ALobbyPlayerCharacter::PossessedBy(AController* NewController)
{
	HasBeenPossesed = true;
}



// Called every frame
void ALobbyPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ALobbyPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
}


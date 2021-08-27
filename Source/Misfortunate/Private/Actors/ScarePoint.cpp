// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/ScarePoint.h"
#include "Components/SceneComponent.h"
#include "Components/BillboardComponent.h"

// Sets default values
AScarePoint::AScarePoint(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	// Structure to hold one-time initialization
	struct FConstructorStatics
	{
		// A helper class object we use to find target UTexture2D object in resource package
		ConstructorHelpers::FObjectFinderOptional<UTexture2D> NoteTextureObject;

		// Icon sprite category name
		FName ID_ScareIcon;

		// Icon sprite display name
		FText NAME_ScareIcon;

		FConstructorStatics()
			// Use helper class object to find the texture
			// "/Engine/EditorResources/S_Note" is resource path
			: NoteTextureObject(TEXT("Texture2D'/Game/Misfortuante/Art/Textures/Tools/ScareIcon.ScareIcon'"))
			, ID_ScareIcon(TEXT("ScareIcon"))
			, NAME_ScareIcon(NSLOCTEXT("SpriteCategory", "Notes", "Notes"))
		{
		}
	};
	static FConstructorStatics ConstructorStatics;

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	SetRootComponent(SceneComponent);

	RootComponent->Mobility = EComponentMobility::Static;

#if WITH_EDITORONLY_DATA
	ScareIconComponent = CreateDefaultSubobject<UBillboardComponent>(TEXT("ScareIcon"));
	if (ScareIconComponent)
	{

		ScareIconComponent->Sprite = ConstructorStatics.NoteTextureObject.Get();		// Get the sprite texture from helper class object
		ScareIconComponent->SpriteInfo.Category = ConstructorStatics.ID_ScareIcon;		// Assign sprite category name
		ScareIconComponent->SpriteInfo.DisplayName = ConstructorStatics.NAME_ScareIcon;	// Assign sprite display name
		ScareIconComponent->SetupAttachment(SceneComponent);			        // Attach sprite to scene component
		ScareIconComponent->Mobility = EComponentMobility::Static;
	}
#endif // WITH_EDITORONLY_DATA

	
	ScareIconComponent->SetEditorScale(0.5);

}

// Called when the game starts or when spawned
void AScarePoint::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AScarePoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


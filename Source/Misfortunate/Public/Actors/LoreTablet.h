// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/TriggerBox.h"
#include "LoreTablet.generated.h"



// Define's if a lore tablet is shared between players when collected or not
UENUM()
enum class SharedType : uint8
{
	Shared  UMETA(DisplayName = "Shared"),
	Unshared  UMETA(DisplayName = "Unshared")

};

UCLASS()
class MISFORTUNATE_API ALoreTablet : public ATriggerBox
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALoreTablet();

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
		UStaticMeshComponent* TabletMesh;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
		SharedType sharedType;

	UFUNCTION()
	void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);

	// declare overlap end function
	UFUNCTION()
	void OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor);
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FString TabletTitle;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FString TabletText;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	

	void SetText(FString& text_, FString& title_);
	void SetText(FString text_, FString title_);

	FString GetTabletText();

	FString GetTabletTitle();

};

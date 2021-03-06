// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MisfortunateHUD.generated.h"

UCLASS()
class AMisfortunateHUD : public AHUD
{
	GENERATED_BODY()

public:
	AMisfortunateHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;


	virtual void BeginPlay() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

	UPROPERTY(EditAnywhere)
		TSubclassOf<class UUserWidget> HUDWidgetClass;

	UPROPERTY(EditAnywhere)
		class UUserWidget* CurrentWidget;

};


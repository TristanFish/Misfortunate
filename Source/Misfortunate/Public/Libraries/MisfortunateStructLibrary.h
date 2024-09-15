// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "MisfortunateStructLibrary.generated.h"


USTRUCT(BlueprintType)
struct FMultiplayerPlayerInfo
{


	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	FString PlayerName;
	UPROPERTY(BlueprintReadWrite)
	UTexture2D* PlayerIcon;
	UPROPERTY(BlueprintReadWrite)
	FString NetID;
	UPROPERTY(BlueprintReadWrite)
	bool IsReady;

	FMultiplayerPlayerInfo()
	{
		PlayerName = "NONE";
		PlayerIcon = nullptr;
		IsReady = false;
	}

};



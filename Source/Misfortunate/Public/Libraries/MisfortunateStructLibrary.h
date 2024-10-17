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


USTRUCT(BlueprintType)
struct FPlayerMisfortuneData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	FString PlayerName;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float Misfortune;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float MaxMisfortune;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float MaxMisfortuneChange;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool bCanMisfortuneIncrease;


	FPlayerMisfortuneData()
	{
		PlayerName = "NULL";

		Misfortune = 0.0f;
		MaxMisfortune = 100.0f;

		MaxMisfortuneChange = 5.0f;
		bCanMisfortuneIncrease = true;

	}


	FPlayerMisfortuneData(const FString& PlayerName_)
	{
		PlayerName = PlayerName_;

		Misfortune = 0.0f;
		MaxMisfortune = 100.0f;

		MaxMisfortuneChange = 5.0f;
		bCanMisfortuneIncrease = true;
	}
};
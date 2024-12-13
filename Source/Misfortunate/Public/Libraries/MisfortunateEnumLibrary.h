// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

//#include "MisfortunateEnumLibrary.generated.h"

UENUM() 
enum UGameState 
{

	Lobby UMETA(DisplayName = "Lobby"),
	Exploration UMETA(DisplayName = "Exploration"),
	LobbyExploration UMETA(DisplayName = "LobbyExploration"),

};




UENUM()
enum CrawlStates
{
	Stand   UMETA(DisplayName = "Standing"),
	Crouch UMETA(DisplayName = "Crouching"),
};


UENUM()
enum EventZoneLevel {
	I,
	II,
	III,
	IV,
	V,
	VI
};

UENUM(BlueprintType)
enum WorldEventOccuranceType {
	
	Narrative,
	Random,
	Timed
};

UENUM(BlueprintType)
enum WorldEventPlayerType {

	SharedEvent,
	Single,

};
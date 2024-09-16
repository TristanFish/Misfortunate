// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AdvancedFriendsGameInstance.h"
#include "FindSessionsCallbackProxy.h"
#include "Containers/Array.h"

#include "MPlayerController.h"
#include "DefaultGameInstance.generated.h"


/**
 * 
 */
UCLASS()
class MISFORTUNATE_API UDefaultGameInstance : public UAdvancedFriendsGameInstance
{
	GENERATED_BODY()
	
public:
	
	//!HostSession Function
	/*!Implemeneted in blueprint and gets called when the player wants to host a game session via advanced sessions*/
	UFUNCTION(BlueprintImplementableEvent)
		void HostSession();

	//!JoinActiveSession Function
	/*!Implemeneted in blueprint and gets called when the player wants to join an active session via advanced sessions */
	UFUNCTION(BlueprintImplementableEvent)
		void JoinActiveSession(const FBlueprintSessionResult& Session);


	//!UpdateActiveSessions Function
	/*!Implemeneted in blueprint and is used to update the active sessions on the ActiveGames widget*/
	UFUNCTION(BlueprintImplementableEvent)
		void UpdateActiveSessions(UWActiveGames* W_ActiveGames);


	//!GetActiveSessions Getter
	/*!Implemeneted in blueprint and returns the active sessions*/
	UFUNCTION(BlueprintImplementableEvent)
		TArray<FBlueprintSessionResult> const GetActiveSessions();
protected:


	//!ActiveSessions
	/*!Stores the most up to date active sessions*/
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TArray<FBlueprintSessionResult> ActiveSessions;

	//!ServerSettings
	/*!Stores the server settings if a player chooses to host a game*/
	UPROPERTY(BlueprintReadWrite)
	TArray<FSessionPropertyKeyPair> ServerSettings;

	//!PlayerInfo
	/*!Stores the active players multiplayer information*/
	UPROPERTY(BlueprintReadWrite)
	FMultiplayerPlayerInfo PlayerInfo;



};

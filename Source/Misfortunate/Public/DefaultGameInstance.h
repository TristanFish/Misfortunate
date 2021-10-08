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
	
	UFUNCTION(BlueprintImplementableEvent)
		void HostSession();

	UFUNCTION(BlueprintImplementableEvent)
		void JoinActiveSession(const FBlueprintSessionResult& Session);


	UFUNCTION(BlueprintImplementableEvent)
		void UpdateActiveSessions(UWActiveGames* W_ActiveGames);



	UFUNCTION(BlueprintImplementableEvent)
		TArray<FBlueprintSessionResult> const GetActiveSessions();
protected:

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TArray<FBlueprintSessionResult> ActiveSessions;

	UPROPERTY(BlueprintReadWrite)
	TArray<FSessionPropertyKeyPair> ServerSettings;

	UPROPERTY(BlueprintReadWrite)
		FPlayerInfo PlayerInfo;



};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Libraries/MisfortunateStructLibrary.h"


#include "MisfortuneManager.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMisfortuneChangedSignature, float, NewMisfortune, FString, PlayerName);


UCLASS()
class MISFORTUNATE_API AMisfortuneManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMisfortuneManager();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;


	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

private:
	UPROPERTY(VisibleAnywhere, ReplicatedUsing = OnRep_MisfortuneData)
	TArray<FPlayerMisfortuneData> PlayerMisfortuneDataList;

	UFUNCTION()
	void OnRep_MisfortuneData();

	UFUNCTION()
	void PopulatePlayerMisfortuneData();

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FOnMisfortuneChangedSignature OnMisfortuneChanged;

	UFUNCTION(BlueprintCallable)
	FPlayerMisfortuneData GetPlayerMisfortuneData(const FString& PlayerName);



	UFUNCTION(BlueprintCallable)
	void SetPlayerMisfortune(const float Misfortune_, const FString& PlayerName);
	
	UFUNCTION(BlueprintCallable)
	void IncreaseMisfortune(const float Misfortune_, const FString& PlayerName);

	UFUNCTION(BlueprintCallable)
	void DecreaseMisfortune(const float Misfortune_, const FString& PlayerName);

	UFUNCTION(BlueprintCallable)
	void SetOtherPlayersMaxMisfortuneChange(const float NewMaxMisfortuneChange, const FString& PlayerName);

	UFUNCTION(BlueprintCallable)
	void SetPlayerMaxMisfortuneChange(const float NewMaxMisfortuneChange, const FString& PlayerName);



	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetCombinedMisfortune();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetAverageMisfortune();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetPlayerMisfortune(const FString& PlayerName);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetPlayerMaxMisfortune(const FString& PlayerName);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FString GetPlayerNameWithHighestMisfortune();




	// RPC Gameplay Functions
	UFUNCTION(Server, Reliable)
	void Server_ChangeCanMisfortuneIncrease(const bool bCanMisfortuneIncrease, const FString& PlayerName);

	UFUNCTION(Server, Reliable)
	void Server_SetMisfortune(const float Misfortune_, const FString& PlayerName);

	UFUNCTION(Server, Reliable)
	void Server_SetMaxMisfortuneChanged(const float MaxMisfortuneChange_, const FString& PlayerName);
};

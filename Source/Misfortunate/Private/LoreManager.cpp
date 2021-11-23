// Fill out your copyright notice in the Description page of Project Settings.


#include "LoreManager.h"
#include "Kismet/GameplayStatics.h"



ALoreManager::ALoreManager()
{
	static ConstructorHelpers::FObjectFinder<UDataTable> LoreTable(TEXT("DataTable'/Game/Misfortuante/Data/T_LoreData.T_LoreData'"));

	if(LoreTable.Succeeded())
	{
		LoreDataTable = LoreTable.Object;
	}

}

void ALoreManager::BeginPlay()
{
	Super::BeginPlay();

	InitTablets();
}



void ALoreManager::InitTablets()
{
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ALoreTablet::StaticClass(), LoreTablets);
	static const FString ContextString(TEXT("Lore Info Context"));

	FLoreInfo* nextLoreInfo;

	for (int i = 0; i < LoreTablets.Num(); i++)
	{
		FString index = "Row_" + FString::FromInt(i);
		nextLoreInfo = LoreDataTable->FindRow<FLoreInfo>(FName(index), ContextString, true);

		Cast<ALoreTablet>(LoreTablets[i])->SetText(*nextLoreInfo->LoreText,nextLoreInfo->LoreTitle);
	}
	
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/WJournal.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "Components/VerticalBox.h"

#include "Blueprint/WidgetTree.h"
#include "Kismet/GameplayStatics.h"


#include "Widgets/WJournal.h"
#include "Widgets/WLore.h"

#include "PlayerCharacter.h"
#include "MPlayerController.h"
#include "MisfortunateGameMode.h"
#include "LoreManager.h"

#include "Actors/LoreTablet.h"

void UWJournal::NativeConstruct()
{
	Super::NativeConstruct();

	AMPlayerController* player = Cast<AMPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));

	if (player->GetCollectedTablets().Num() > 0 && CurrentLoreOwnerViewed.IsEmpty())
	{

		TArray<FString> Keys;
		player->GetCollectedTablets().GenerateKeyArray(Keys);
		CurrentLoreOwnerViewed = Keys[0];
		UpdatePageProperties();
	}

}

bool UWJournal::Initialize()
{

	Super::Initialize();
	JournalHasOpened = false;

	

	return true;
}

void UWJournal::ToPreviousPage()
{
	AMPlayerController* player = Cast<AMPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	AMisfortunateGameMode* gamemode = Cast<AMisfortunateGameMode>(UGameplayStatics::GetGameMode(GetWorld()));

	
	if (player->GetCollectedTablets().Contains(CurrentLoreOwnerViewed))
	{
		int index = gamemode->GetLoreManager()->LoreOwners.Find(CurrentLoreOwnerViewed);

		TArray<FString>* LoreOwners = &gamemode->GetLoreManager()->LoreOwners;


		if (LoreOwners->IsValidIndex(index - 1))
		{
			CurrentLoreOwnerViewed = (*LoreOwners)[index - 1];
			UpdatePageProperties();
		}

		if (index == 0 && JournalHasOpened)
		{
			// Close Journal
		}

	}

}

void UWJournal::ToNextPage()
{
	AMPlayerController* player = Cast<AMPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	AMisfortunateGameMode* gamemode = Cast<AMisfortunateGameMode>(UGameplayStatics::GetGameMode(GetWorld()));


	if (!JournalHasOpened)
	{
		PlayAnimation(JournalOpenAnim);
		JournalHasOpened = true;
	}

	else 
	{
		if (player->GetCollectedTablets().Contains(CurrentLoreOwnerViewed))
		{
			int index = gamemode->GetLoreManager()->LoreOwners.Find(CurrentLoreOwnerViewed);

			TArray<FString>* LoreOwners = &gamemode->GetLoreManager()->LoreOwners;


			if (LoreOwners->IsValidIndex(index + 1))
			{
				CurrentLoreOwnerViewed = CurrentLoreOwnerViewed = (*LoreOwners)[index + 1];
				UpdatePageProperties();
			}


		}
	}

	
}

void UWJournal::BindPageDelegates()
{
	Cast<AMPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0))->NextPageClicked.AddDynamic(this, &UWJournal::ToNextPage);
	Cast<AMPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0))->PrevPageClicked.AddDynamic(this, &UWJournal::ToPreviousPage);

}

void UWJournal::UnBindPageDelegates()
{
	Cast<AMPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0))->NextPageClicked.RemoveDynamic(this, &UWJournal::ToNextPage);
	Cast<AMPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0))->PrevPageClicked.RemoveDynamic(this, &UWJournal::ToPreviousPage);
}

void UWJournal::UpdatePageProperties()
{
	for (int child = 0; child < LoreBox->GetChildrenCount(); child++)
	{
		
		LoreBox->RemoveChildAt(child);
	}


	CurrentLoreOwner->SetText(FText::FromString(CurrentLoreOwnerViewed));

	AMPlayerController* player = Cast<AMPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));


	TArray<ALoreTablet*> LoreTablets = *player->GetCollectedTablets().Find(CurrentLoreOwnerViewed);

	for (auto tablet : LoreTablets)
	{
		UWLore* NewLoreLine = CreateWidget<UWLore>(this, UWLore::StaticClass());

		NewLoreLine->SetLoreInfo(tablet->GetTabletText(), tablet->GetTabletTitle());
		LoreBox->AddChild(NewLoreLine);
	}

}

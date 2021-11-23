// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/WJournal.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "Blueprint/WidgetTree.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerCharacter.h"
#include "MPlayerController.h"
#include "Actors/LoreTablet.h"

void UWJournal::NativeConstruct()
{
	Super::NativeConstruct();

	AMPlayerController* player = Cast<AMPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));

	if (player->GetCollectedTablets().Num() > 0 && CurrentTabletViewed == nullptr)
	{
		CurrentTabletViewed = player->GetCollectedTablets()[0];
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

	
	if (player->GetCollectedTablets().Contains(CurrentTabletViewed))
	{
		int index = player->GetCollectedTablets().Find(CurrentTabletViewed);

		if (player->GetCollectedTablets().IsValidIndex(index - 1))
		{
			CurrentTabletViewed = player->GetCollectedTablets()[index - 1];
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


	if (!JournalHasOpened)
	{
		PlayAnimation(JournalOpenAnim);
		JournalHasOpened = true;
	}

	else 
	{
		if (player->GetCollectedTablets().Contains(CurrentTabletViewed))
		{
			int index = player->GetCollectedTablets().Find(CurrentTabletViewed);

			if (player->GetCollectedTablets().IsValidIndex(index + 1))
			{
				CurrentTabletViewed = player->GetCollectedTablets()[index + 1];
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
	Lore->SetText(FText::FromString(CurrentTabletViewed->GetTabletText()));

	LoreTitle->SetText(FText::FromString(CurrentTabletViewed->GetTabletTitle()));
}

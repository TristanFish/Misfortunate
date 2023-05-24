// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/WLore.h"
#include "Components/TextBlock.h"
#include "MPlayerController.h"
#include "Kismet/GameplayStatics.h"

void UWLore::NativeConstruct()
{
	Super::NativeConstruct();
}

void UWLore::SetLoreInfo(FString LoreText_, FString LoreTitle_)
{
	LoreTitle->Text.FromString(LoreTitle_);
	LoreText->Text.FromString(LoreText_);

}

void UWLore::DisplayLoreInfo()
{

	LoreText->SetVisibility(ESlateVisibility::Visible);

}

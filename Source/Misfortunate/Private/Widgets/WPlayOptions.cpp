// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/WPlayOptions.h"

#include "Components/Button.h"
#include "Widgets/WActiveGames.h"
#include "Widgets/WCreateGame.h"

void UWPlayOptions::NativeConstruct()
{
	Super::NativeConstruct();

	JoinButton->OnClicked.AddDynamic(this, &UWPlayOptions::OnJoinButtonClicked);
	CreateButton->OnClicked.AddDynamic(this, &UWPlayOptions::OnCreateButtonClicked);

	W_ActiveGames->BackButton->OnClicked.AddDynamic(this, &UWPlayOptions::OnBackFromNewMenu);
	//W_CreateGame->BackButton->OnClicked.AddDynamic(this, &UWPlayOptions::OnBackFromNewMenu);

	W_ActiveGames->SetVisibility(ESlateVisibility::Hidden);
	W_CreateGame->SetVisibility(ESlateVisibility::Hidden);

}



void UWPlayOptions::OnJoinButtonClicked()
{
	if (JoinButton->IsVisible())
	{
		JoinButton->SetVisibility(ESlateVisibility::Hidden);
		CreateButton->SetVisibility(ESlateVisibility::Hidden);
	}
	
	W_ActiveGames->SetVisibility(ESlateVisibility::Visible);
}

void UWPlayOptions::OnCreateButtonClicked()
{
	if (JoinButton->IsVisible())
	{
		JoinButton->SetVisibility(ESlateVisibility::Hidden);
		CreateButton->SetVisibility(ESlateVisibility::Hidden);
	}

	W_CreateGame->SetVisibility(ESlateVisibility::Visible);
}

void UWPlayOptions::OnBackFromNewMenu()
{

	if (W_CreateGame->IsVisible())
	{
		W_CreateGame->SetVisibility(ESlateVisibility::Hidden);

	}

	else if (W_ActiveGames->IsVisible())
	{
		W_ActiveGames->SetVisibility(ESlateVisibility::Hidden);
	}

	JoinButton->SetVisibility(ESlateVisibility::Visible);
	CreateButton->SetVisibility(ESlateVisibility::Visible);
}

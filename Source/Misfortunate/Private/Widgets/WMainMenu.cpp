// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/WMainMenu.h"

#include "Components/Button.h"
#include "Widgets/WPlayOptions.h"

#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"

void UWMainMenu::NativeConstruct()
{
	PlayButton->OnClicked.AddDynamic(this, &UWMainMenu::OnPlayButtonClicked);
	OptionsButton->OnClicked.AddDynamic(this, &UWMainMenu::OnOptionsButtonClicked);
	QuitButton->OnClicked.AddDynamic(this, &UWMainMenu::OnQuitButtonClicked);

	W_PlayOptions->SetVisibility(ESlateVisibility::Hidden);

}

void UWMainMenu::OnPlayButtonClicked()
{
	if (PlayButton->IsVisible())
	{
		PlayButton->SetVisibility(ESlateVisibility::Hidden);
		OptionsButton->SetVisibility(ESlateVisibility::Hidden);
		QuitButton->SetVisibility(ESlateVisibility::Hidden);

	}

	W_PlayOptions->SetVisibility(ESlateVisibility::Visible);

}

void UWMainMenu::OnOptionsButtonClicked()
{

}

void UWMainMenu::OnQuitButtonClicked()
{
	UKismetSystemLibrary::QuitGame(GetWorld(), UGameplayStatics::GetPlayerController(GetWorld(), 0), EQuitPreference::Quit, false);
}

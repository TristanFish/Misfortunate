// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/WCreateGame.h"

#include "Kismet/GameplayStatics.h"
#include "components/Button.h"


#include "DefaultGameInstance.h"
void UWCreateGame::NativeConstruct()
{
	ContinueButton->OnClicked.AddDynamic(this, &UWCreateGame::OnContinueButtonClicked);

}

void UWCreateGame::OnContinueButtonClicked()
{
	UDefaultGameInstance* gameInstance = Cast<UDefaultGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));

	gameInstance->HostSession();
}


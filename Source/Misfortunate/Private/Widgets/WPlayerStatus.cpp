// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/WPlayerStatus.h"

#include "Components/TextBlock.h"
#include "Components/Image.h"


void UWPlayerStatus::NativeConstruct()
{
	Super::NativeConstruct();
}

void UWPlayerStatus::InitPlayerStatus(FString PlayerName_, UTexture2D* IconImage)
{
	PlayerName->Text = FText::FromString(PlayerName_);
	IconTexture->SetBrushFromTexture(IconImage);

	ReadyState = false;
}

void UWPlayerStatus::UpdateReadyState(bool ReadyState_)
{
	ReadyState = ReadyState_;
}

FString UWPlayerStatus::GetPlayerName() const
{

	return PlayerName->Text.ToString();
}

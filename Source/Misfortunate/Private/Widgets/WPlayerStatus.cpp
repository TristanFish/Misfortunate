// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/WPlayerStatus.h"

#include "Components/TextBlock.h"
#include "Components/Image.h"
#include "Components/Border.h"

void UWPlayerStatus::NativeConstruct()
{
	Super::NativeConstruct();
}

void UWPlayerStatus::InitPlayerStatus(FString PlayerName_, UTexture2D* IconImage)
{
	PlayerName->Text = FText::FromString(PlayerName_);
	IconTexture->SetBrushFromTexture(IconImage);

	CurrentPlayerName = PlayerName_;
	ReadyState = false;
}

void UWPlayerStatus::UpdateReadyState(bool ReadyState_)
{

	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, FString("Updated Ready State In Player Status"));

	ReadyState = ReadyState_;

	if (ReadyState)
	{
		ItemBorder->SetBrushColor(FLinearColor::Green);
	}
	else
	{
		ItemBorder->SetBrushColor(FLinearColor::Red);
	}
}

FString UWPlayerStatus::GetPlayerName() const
{

	return CurrentPlayerName;
}

bool UWPlayerStatus::IsReady() const
{
	return ReadyState;
}

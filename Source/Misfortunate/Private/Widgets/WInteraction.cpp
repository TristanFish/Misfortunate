// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/WInteraction.h"
#include "MPlayerController.h"
#include "Animation/WidgetAnimation.h"
#include "Kismet/GameplayStatics.h"
#include "Actors/LoreTablet.h"



void UWInteraction::NativeConstruct()
{
	Super::NativeConstruct();

	EndAnimDelegate.BindDynamic(this, &UWInteraction::OnFadeOutAnimationFinished);

	BindToAnimationFinished(FadeOutAnim, EndAnimDelegate);
}

void UWInteraction::BindDelegate()
{
	AMPlayerController* controller = Cast<AMPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));

	if (!controller->InteractClicked.IsBound())
	{
		controller->InteractClicked.AddDynamic(this, &UWInteraction::InteractionMessage);
	}
}

void UWInteraction::UnBindDelegate()
{
	AMPlayerController* controller = Cast<AMPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));

	if (controller->InteractClicked.IsBound())
	{
		controller->InteractClicked.RemoveDynamic(this, &UWInteraction::InteractionMessage);
	}

}

void UWInteraction::InteractionMessage()
{

	Cast<AMPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0))->AddToTabletsCollected(LatestTablet);

	
	PlayInteractionAnim();
}

void UWInteraction::PlayInteractionAnim()
{
	PlayAnimation(FadeOutAnim);
}

void UWInteraction::SetLatestTablet(ALoreTablet* tablet)
{
	LatestTablet = tablet;
}

void UWInteraction::OnFadeOutAnimationFinished()
{
	RemoveFromViewport();
	UnBindDelegate();
}

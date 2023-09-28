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
		controller->InteractClicked.AddDynamic(this, &UWInteraction::OnInteractionClicked);
	}
}

void UWInteraction::UnBindDelegate()
{
	AMPlayerController* controller = Cast<AMPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));

	if (controller->InteractClicked.IsBound())
	{
		controller->InteractClicked.RemoveDynamic(this, &UWInteraction::OnInteractionClicked);
	}

}

void UWInteraction::OnInteractionClicked()
{

	Cast<AMPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0))->AddToTabletsCollected(LatestInteractible);
	//LatestInteractible->OnInteracted();
	
	PlayInteractionAnim();
}

void UWInteraction::PlayInteractionAnim()
{
	PlayAnimation(FadeOutAnim);
}

void UWInteraction::SetLatestInteractible(AInteractibleObject* interactible)
{
	LatestInteractible = interactible;
}

void UWInteraction::OnFadeOutAnimationFinished()
{
	RemoveFromViewport();
	UnBindDelegate();
}

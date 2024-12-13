// Fill out your copyright notice in the Description page of Project Settings.


#include "MisfortunateFunctionLibrary.h"

bool UMisfortunateFunctionLibrary::TryRequestGameplayTag(FName TagName, FGameplayTag& Tag)
{
	Tag = UGameplayTagsManager::Get().RequestGameplayTag(TagName, false);
	return Tag.IsValid();
}

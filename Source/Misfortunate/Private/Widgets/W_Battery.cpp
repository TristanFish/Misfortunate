// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/W_Battery.h"

void UW_Battery::SetBatteryLevel(const float level_)
{
	BatteryLevel->Percent = level_;
}

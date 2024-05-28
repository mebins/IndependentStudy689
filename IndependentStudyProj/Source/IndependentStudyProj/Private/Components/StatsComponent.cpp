// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/StatsComponent.h"


// Sets default values for this component's properties
UStatsComponent::UStatsComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	character = GetOwner();
	// ...
}


// Called when the game starts
void UStatsComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	Level = 1;
	MaxXP = MaxXPByLevel[Level - 1];
	MaxLevel = 18;
	
}


// Called every frame
void UStatsComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool UStatsComponent::AddXP(float XPAmount)
{
	if (Level < MaxLevel)
	{
		XP += XPAmount;
		if (XP >= MaxXP) {
			LevelUp();
			if (Level == 18)
			{
				XP = MaxXP;
			}
			return true;
		}
	}
	return false;
}

void UStatsComponent::LevelUp()
{
	if (MaxLevel <= Level) return;
	Level += 1;
	MaxXP = MaxXPByLevel[Level-1];
	SkillPoints++;
	AddXP(0);
}


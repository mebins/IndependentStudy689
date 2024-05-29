// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/StatsComponent.h"
#include <Net/UnrealNetwork.h>


// Sets default values for this component's properties
UStatsComponent::UStatsComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	character = GetOwner();
	UStatsComponent::SetIsReplicated(true);
	// ...
}


// Called when the game starts
void UStatsComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	ComponentInitialize_Implementation();
	
}


// Called every frame
void UStatsComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...

}

void UStatsComponent::ServerAddXP_Implementation(float XPAmount)
{
	if (Level < MaxLevel)
	{
		XP += XPAmount;
		if (XP >= MaxXP) {
			ServerLevelUp();
			if (Level == 18)
			{
				XP = MaxXP;
			}
		}
	}

}

void UStatsComponent::ServerLevelUp_Implementation()
{
	if (MaxLevel <= Level) return;
	Level += 1;
	MaxXP = MaxXPByLevel[Level - 1];
	MaxHP = StatsByLevel[Level].MaxHp;
	MaxMana = StatsByLevel[Level].MaxMana;
	SkillPoints++;
	AddXP(0);
}

void UStatsComponent::AddXP(float XPAmount)
{
	ServerAddXP(XPAmount);
}

void UStatsComponent::LevelUp()
{
	ServerLevelUp();
}

void UStatsComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	// Call the Super
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	// Add properties to replicated for the derived class
	DOREPLIFETIME(UStatsComponent, StatsByLevel);
	DOREPLIFETIME(UStatsComponent, SkillPoints);
	DOREPLIFETIME(UStatsComponent, Level);
	DOREPLIFETIME(UStatsComponent, MaxLevel);
	DOREPLIFETIME(UStatsComponent, XP);
	DOREPLIFETIME(UStatsComponent, MaxXP);
	DOREPLIFETIME(UStatsComponent, HP);
	DOREPLIFETIME(UStatsComponent, MaxHP);
	DOREPLIFETIME(UStatsComponent, MaxMana);
	DOREPLIFETIME(UStatsComponent, Mana);
	DOREPLIFETIME(UStatsComponent, MaxXPByLevel);

}

void UStatsComponent::ComponentInitialize_Implementation()
{
	Level = 1;
	MaxXP = MaxXPByLevel[Level - 1];
	MaxLevel = 18;
	MaxHP = StatsByLevel[Level].MaxHp;
	HP = MaxHP;
}


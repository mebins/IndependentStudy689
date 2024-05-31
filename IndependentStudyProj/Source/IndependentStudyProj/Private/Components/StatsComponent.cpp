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
	UStatsComponent::SetIsReplicatedByDefault(true);
	// ...
}


// Called when the game starts
void UStatsComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	ComponentInitialize();
	
}


// Called every frame
void UStatsComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...

}

void UStatsComponent::ServerAddXP_Implementation(float XPAmount)
{
	if (MaxLevel <= Level) return;

		XP += XPAmount;
		if (XP >= MaxXP) {
			ServerLevelUp();
		}

		if (Level == 18)
		{
			XP = MaxXP;
		}

}

void UStatsComponent::ServerLevelUp_Implementation()
{
	if (MaxLevel <= Level) return;
	Level += 1;
	UpdateByLevel(Level);

	
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
	DOREPLIFETIME(UStatsComponent, Armor);
	DOREPLIFETIME(UStatsComponent, Damage);
	DOREPLIFETIME(UStatsComponent, CritChance);
	DOREPLIFETIME(UStatsComponent, AttackSpeed);
	DOREPLIFETIME(UStatsComponent, AttackRange);
	DOREPLIFETIME(UStatsComponent, MovementSpeed);
	DOREPLIFETIME(UStatsComponent, HealthRegen);
	DOREPLIFETIME(UStatsComponent, ManaRegen);

}

void UStatsComponent::ComponentInitialize_Implementation()
{
	Level = 1;
	UpdateByLevel(Level);
	
	HP = MaxHP;
	Mana = MaxMana;

}

void UStatsComponent::UpdateByLevel(int32 level)
{
	verify(level > 0 && level <= MaxLevel);
	MaxXP = MaxXPByLevel[level - 1];
	MaxLevel = 18;
	FCharacterStats stat = StatsByLevel[level - 1];
	MaxHP = stat.MaxHp;
	MaxMana = stat.MaxMana;
	Armor = stat.Armor;
	Damage = stat.Damage;
	CritChance = stat.CritChance;
	AttackSpeed = stat.AttackSpeed;
	AttackRange = stat.AttackRange;
	MovementSpeed = stat.MovementSpeed;
	HealthRegen = stat.HealthRegen;
	ManaRegen = stat.ManaRegen;

}


// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/InventoryComponent.h"


// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UInventoryComponent::RecalculateInventory()
{
	BonusArmor = 0;
	BonusMaxHP = 0;
	BonusMaxMana = 0;
	BonusDamage = 0;
	BonusMovementSpeed = 0;
	BonusAttackSpeed = 0;
	BonusAttackRange = 0; 
	BonusHealthRegen = 0;
	BonusManaRegen = 0; 
	BonusCritChance = 0;
	for (int i = 0; i < MaxItems; i++)
	{
		if (!Items[i].SlotUsed) continue;
		BonusArmor += Items[i].ItemActor->ItemInfo.Armor;
		BonusMaxHP += Items[i].ItemActor->ItemInfo.HP;
		BonusMaxMana += Items[i].ItemActor->ItemInfo.Mana;
		BonusDamage += Items[i].ItemActor->ItemInfo.Damage;
		BonusMovementSpeed+= Items[i].ItemActor->ItemInfo.MovementSpeed;
		BonusAttackSpeed += Items[i].ItemActor->ItemInfo.AttackSpeed;
		BonusAttackRange += Items[i].ItemActor->ItemInfo.AttackRange;
		BonusHealthRegen += Items[i].ItemActor->ItemInfo.HealthRegen;
		BonusManaRegen += Items[i].ItemActor->ItemInfo.ManaRegen;
		BonusCritChance+= Items[i].ItemActor->ItemInfo.CritChance;
	}
}


// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

int32 UInventoryComponent::GiveUnusedItemSlot()
{
	for (int32 i = 0; i < Items.Num(); i++)
	{
		if (!Items[i].SlotUsed)
		{
			Items[i].SlotUsed = true;
			return i;
		}
	}
	return -1;
}


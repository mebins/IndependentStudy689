// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/InventoryComponent.h"
#include <Net/UnrealNetwork.h>


// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	character = GetOwner();
	UInventoryComponent::SetIsReplicatedByDefault(true);

	// ...
}

void UInventoryComponent::RecalculateInventory()
{
	ServerRecalculateInventory();
}



void UInventoryComponent::ServerRecalculateInventory_Implementation()
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
		if (!Items[i].SlotUsed || !IsValid(Items[i].ItemActor)) continue;
		BonusArmor += Items[i].ItemActor->ItemInfo.Armor;
		BonusMaxHP += Items[i].ItemActor->ItemInfo.HP;
		BonusMaxMana += Items[i].ItemActor->ItemInfo.Mana;
		BonusDamage += Items[i].ItemActor->ItemInfo.Damage;
		BonusMovementSpeed += Items[i].ItemActor->ItemInfo.MovementSpeed;
		BonusAttackSpeed += Items[i].ItemActor->ItemInfo.AttackSpeed;
		BonusAttackRange += Items[i].ItemActor->ItemInfo.AttackRange;
		BonusHealthRegen += Items[i].ItemActor->ItemInfo.HealthRegen;
		BonusManaRegen += Items[i].ItemActor->ItemInfo.ManaRegen;
		BonusCritChance += Items[i].ItemActor->ItemInfo.CritChance;
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
	if (GetOwner()->GetRemoteRole() == ROLE_AutonomousProxy)
	{
		UpdateItems();
	}


	// ...
}
void UInventoryComponent::SetItemSlot(int index, AItemBase* item)
{
	if (!IsValid(item)) return;
	Items[index].ItemActor = item;
	ServerSetItemSlot(index, item);
	
}
void UInventoryComponent::ServerSetItemSlot_Implementation(int index, AItemBase* item)
{
	if (!Items[index].SlotUsed)
	{
		Items[index].SlotUsed = true;

	}

}

int32 UInventoryComponent::GiveUnusedItemSlot()
{
	for (int32 i = 0; i < Items.Num(); i++)
	{
		if (!Items[i].SlotUsed)
		{
			return i;
		}
	}
	return -1;

}

void UInventoryComponent::UseItem(int32 index)
{
	ServerUseItem(index);
}

void UInventoryComponent::ServerUseItem_Implementation(int32 index)
{
	if (Items[index].SlotUsed && Items[index].ItemActor->ItemInfo.BHasUse)
	{
		Items[index].ItemActor->CastItem();
	}
}

void UInventoryComponent::UpdateItems()
{
	ServerUpdateItems();
}
void UInventoryComponent::ServerUpdateItems_Implementation()
{
	for (int32 i = 0; i < Items.Num(); i++)
	{
		if (!IsValid(Items[i].ItemActor)) return;
		if (Items[i].SlotUsed && Items[i].ItemActor->ItemInfo.Consumed)
		{
			DestroyItem(i);
		}
	}
}
void UInventoryComponent::DestroyItem(int32 Index)
{
	ServerDestroyItem(Index);
}

void UInventoryComponent::ServerDestroyItem_Implementation(int32 Index)
{
	Items[Index].SlotUsed = false;
	Items[Index].ItemActor = nullptr;
}

void UInventoryComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UInventoryComponent, Gold);
	DOREPLIFETIME(UInventoryComponent, Items);
	DOREPLIFETIME(UInventoryComponent, MaxItems);
	DOREPLIFETIME(UInventoryComponent, BonusMaxHP);
	DOREPLIFETIME(UInventoryComponent, BonusMaxMana);
	DOREPLIFETIME(UInventoryComponent, BonusArmor);
	DOREPLIFETIME(UInventoryComponent, BonusDamage);
	DOREPLIFETIME(UInventoryComponent, BonusMovementSpeed);
	DOREPLIFETIME(UInventoryComponent, BonusAttackSpeed);
	DOREPLIFETIME(UInventoryComponent, BonusAttackRange);
	DOREPLIFETIME(UInventoryComponent, BonusHealthRegen);
	DOREPLIFETIME(UInventoryComponent, BonusManaRegen);
	DOREPLIFETIME(UInventoryComponent, BonusCritChance);

}


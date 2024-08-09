// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/InventoryComponent.h"
#include <Net/UnrealNetwork.h>

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	UInventoryComponent::SetIsReplicatedByDefault(true);
	character = GetOwner();


	// ...
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
		
	}


	// ...
}





/*
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
*/




void UInventoryComponent::AddGold(int32 GoldAmount)
{
	Gold += GoldAmount;
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
FItemSlot UInventoryComponent::GetItemSlot(int32 index)
{
	return Items[index];
}
TArray<FItem> UInventoryComponent::GetItemInfos()
{
	TArray<FItem> iteminfos;
	for (int32 i = 0; i < Items.Num(); i++) 
	{
			if (Items[i].ItemActor)
			{
				iteminfos.EmplaceAt(i, Items[i].ItemActor->ItemInfo);
			}
			else
			{
				iteminfos.EmplaceAt(i, FItem());
			}
	}
	return iteminfos;;
}
void UInventoryComponent::SetItemSlot(int32 index, bool SlotUsed, FName FriendlyName, AItemBase* item)
{
	Items[index].SlotUsed = SlotUsed;
	Items[index].FriendlyName = FriendlyName;
	Items[index].ItemActor = item;
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


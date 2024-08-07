// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/DataTable.h"
#include "ItemBase.h"
#include "InventoryComponent.generated.h"



USTRUCT(BlueprintType)
struct FItemSlot : public FTableRowBase
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool SlotUsed = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName FriendlyName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool OnCoolDown;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bSelfTarget;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AItemBase* ItemActor;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INDEPENDENTSTUDYPROJ_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)
	int32 Gold = 0; 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)
	TArray<FItemSlot> Items;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)
	int32 MaxItems = 6; 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)
	float BonusMaxHP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)
	float BonusMaxMana;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)
	float BonusArmor; 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)
	float BonusDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)
	float BonusMovementSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)
	float BonusAttackSpeed; 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)
	float BonusAttackRange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)
	float BonusHealthRegen;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)
	float BonusManaRegen;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)
	float BonusCritChance;



protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void AddGold(int32 GoldAmount);

	UFUNCTION(BlueprintCallable)
int32 GiveUnusedItemSlot();
UFUNCTION(BlueprintCallable)
FItemSlot GetItemSlot(int32 index);

UFUNCTION(BlueprintCallable)
TArray<FItem> GetItemInfos();

UFUNCTION(BlueprintCallable)
void SetItemSlot(int32 index, bool SlotUsed, FName FriendlyName, AItemBase* item);

UFUNCTION(BlueprintCallable)
void RecalculateInventory();



virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

private:
	AActor* character;
};

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
	FName FriendlyName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool OnCoolDown;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bSelfTarget;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AItemBase> ItemActor;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INDEPENDENTSTUDYPROJ_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Gold = 0; 
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FItemSlot> Items;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MaxItems = 6; 
	UFUNCTION(BlueprintImplementableEvent)
	void RecalculateInventory();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float BonusMaxHP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float BonusMaxMana;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float BonusArmor; 
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float BonusDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float BonusMovementSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float BonusAttackSpeed; 
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float BonusAttackRange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float BonusHealthRegen;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float BonusManaRegen;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float BonusCritChance;



protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
	
};

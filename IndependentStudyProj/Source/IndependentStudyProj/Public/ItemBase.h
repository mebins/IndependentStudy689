// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemBase.generated.h"

USTRUCT(BlueprintType)
struct FItem
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category ="Health")
	float HP = 0;
	UPROPERTY(BlueprintReadWrite, Category = "Mana")
	float Mana = 0;
	UPROPERTY(BlueprintReadWrite, Category = "Armor")
	float Armor = 0;
	UPROPERTY(BlueprintReadWrite, Category = "Damage")
	float Damage = 0;
	UPROPERTY(BlueprintReadWrite, Category = "Movement")
	float MovementSpeed = 0;
	UPROPERTY(BlueprintReadWrite, Category = "Damage")
	float AttackSpeed = 0;
	UPROPERTY(BlueprintReadWrite, Category = "Damage")
	float AttackRange = 0;
	UPROPERTY(BlueprintReadWrite, Category = "Damage")
	float CritChance = 0;
	UPROPERTY(BlueprintReadWrite, Category = "Item Info")
	bool BHasUse = false;

};

UCLASS()
class INDEPENDENTSTUDYPROJ_API AItemBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItemBase();
	UPROPERTY(EditAnywhere, BlueprintReadWrite);
	FItem ItemInfo;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};

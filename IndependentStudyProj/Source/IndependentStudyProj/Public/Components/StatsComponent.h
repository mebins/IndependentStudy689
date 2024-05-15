// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StatsComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INDEPENDENTSTUDYPROJ_API UStatsComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UStatsComponent();
	UPROPERTY(BlueprintReadWrite, Category ="Health")
	float HP;
	UPROPERTY(BlueprintReadWrite, Category = "Health")
	float MaxHp; 
	UPROPERTY(BlueprintReadWrite, Category = "Mana")
	float Mana;
	UPROPERTY(BlueprintReadWrite, Category = "Mana")
	float MaxMana;
	UPROPERTY(BlueprintReadWrite, Category = "Armor")
	float Armor;
	UPROPERTY(BlueprintReadWrite, Category = "Damage")
	float Damage;
	UPROPERTY(BlueprintReadWrite, Category = "Level")
	float XP;
	UPROPERTY(BlueprintReadWrite, Category = "Level")
	float MaxXP;
	UPROPERTY(BlueprintReadWrite, Category = "Level")
	float SkillPoints;
	UPROPERTY(BlueprintReadWrite, Category = "Level")
	int32 Level;
	UPROPERTY(BlueprintReadWrite, Category = "Level")
	int32 MaxLevel;
	UPROPERTY(BlueprintReadWrite, Category = "Damage")
	float CritChance; 
	UPROPERTY(BlueprintReadWrite, Category = "Damage")
	float AttackSpeed;
	UPROPERTY(BlueprintReadWrite, Category = "Damage")
	int32 AttackRange;
	UPROPERTY(BlueprintReadWrite, Category = "Movement")
	int32 MovementSpeed;
	UPROPERTY(BlueprintReadWrite, Category = "Armor")
	float HealthRegen;
	UPROPERTY(BlueprintReadWrite, Category = "Armor")
	float ManaRegen;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	AActor* character;
	
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StatsComponent.generated.h"

USTRUCT(BlueprintType)
struct FCharacterStats
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Health")
	float MaxHp;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Mana")
	float MaxMana;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Armor")
	float Armor;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Damage")
	float Damage;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Damage")
	float CritChance;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Damage")
	float AttackSpeed;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Damage")
	int32 AttackRange;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Movement")
	int32 MovementSpeed;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Armor")
	float HealthRegen;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Armor")
	float ManaRegen;
};
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INDEPENDENTSTUDYPROJ_API UStatsComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UStatsComponent();
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Stat Info")
	TArray<FCharacterStats> StatsByLevel;
	UPROPERTY(BlueprintReadWrite, Category = "Level")
	float SkillPoints;
	UPROPERTY(BlueprintReadWrite, Category = "Level")
	int32 Level;
	UPROPERTY(BlueprintReadWrite, Category = "Level")
	int32 MaxLevel;
	UPROPERTY(BlueprintReadWrite, Category = "Level")
	float XP;
	UPROPERTY(BlueprintReadWrite, Category = "Level")
	float MaxXP;
	UPROPERTY(BlueprintReadWrite, Category = "Health")
	float HP;
	UPROPERTY(BlueprintReadWrite, Category = "Mana")
	float Mana;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category ="XP")
	TArray<float> MaxXPByLevel;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	bool AddXP(float XPAmount);
	UFUNCTION(BlueprintCallable)
	void LevelUp();
private:
	AActor* character;
	
};

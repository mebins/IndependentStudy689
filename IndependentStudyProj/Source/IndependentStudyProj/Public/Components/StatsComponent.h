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
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Category = "Stat Info")
	TArray<FCharacterStats> StatsByLevel;
	UPROPERTY(BlueprintReadWrite, Replicated, Category = "Level")
	float SkillPoints;
	UPROPERTY(BlueprintReadWrite, Replicated, Category = "Level")
	int32 Level;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Category = "Level")
	int32 MaxLevel;
	UPROPERTY(BlueprintReadWrite, Replicated, Category = "Level")
	float XP;
	UPROPERTY(BlueprintReadWrite, Replicated, Category = "Level")
	float MaxXP;
	UPROPERTY(BlueprintReadWrite, Replicated, Category = "Health")
	float HP;
	UPROPERTY(BlueprintReadWrite, Replicated, Category = "Health")
	float MaxHP;
	UPROPERTY(BlueprintReadWrite, Replicated, Category = "Mana")
	float MaxMana;
	UPROPERTY(BlueprintReadWrite, Replicated, Category = "Mana")
	float Mana;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Category ="XP")
	TArray<float> MaxXPByLevel;
	UPROPERTY(BlueprintReadWrite, Replicated, Category = "Armor")
	float Armor;
	UPROPERTY(BlueprintReadWrite, Replicated, Category = "Damage")
	float Damage;
	UPROPERTY(BlueprintReadWrite, Replicated, Category = "Damage")
	float CritChance;
	UPROPERTY(BlueprintReadWrite, Replicated, Category = "Damage")
	float AttackSpeed;
	UPROPERTY(BlueprintReadWrite, Replicated, Category = "Damage")
	int32 AttackRange;
	UPROPERTY(BlueprintReadWrite, Replicated, Category = "Movement")
	int32 MovementSpeed;
	UPROPERTY(BlueprintReadWrite, Replicated, Category = "Armor")
	float HealthRegen;
	UPROPERTY(BlueprintReadWrite, Replicated, Category = "Armor")
	float ManaRegen;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;



	UFUNCTION(Server, Reliable)
	void ServerAddXP(float XPAmount);
	UFUNCTION(Server, Reliable)
	void ServerLevelUp();

	UFUNCTION(BlueprintCallable)
	void AddXP(float XPAmount);

	UFUNCTION(BlueprintCallable)
	void LevelUp();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	void UpdateByLevel(int32 level);


private:
	AActor* character;

	UFUNCTION(Server, Reliable)
	void ComponentInitialize();
};

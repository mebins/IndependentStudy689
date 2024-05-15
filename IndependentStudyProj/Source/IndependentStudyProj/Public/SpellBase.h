// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpellBase.generated.h"

UENUM(BlueprintType)
enum class SpellType : uint8 {
	Summoner = 0 UMETA(DisplayName = "Summoner Spell"),
	Passive = 1 UMETA(DisplayName = "Passive Spell"),
	Ultimate = 2 UMETA(DisplayName = "Ultimate Spell")
};

UCLASS()
class INDEPENDENTSTUDYPROJ_API ASpellBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpellBase();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spell Scales")
	TArray<int32> DamageBases;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spell Scales")
	TArray<int32> CoolDowns;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spell Scales")
	TArray<int32> ManaCosts;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spell Scales")
	TArray<int32> SpellRanges;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spell Scales")
	TArray<float> TimeOfEffects;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spell Scales")
	TArray<float> ChannelTimes;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spell Info")
	SpellType spellType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spell Info")
	int32 MaxLevel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	bool bSelfTarget;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat")
	bool bChannelSpell;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category ="Combat")
	bool bProjectile;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category ="Combat")
	float Speed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	UParticleSystem* particle_system;


	UFUNCTION(BlueprintImplementableEvent)
	bool Cast_Spell();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};

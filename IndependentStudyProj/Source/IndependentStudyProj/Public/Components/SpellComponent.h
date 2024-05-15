// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/DataTable.h"
#include "SpellBase.h"
#include "SpellComponent.generated.h"



USTRUCT(BlueprintType)
struct FSpellSlot : public FTableRowBase
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName FriendlyName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool OnCoolDown;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Level;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bPassive;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bSelfTarget;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bUltimateSpell;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<ASpellBase> SpellActor;
};
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INDEPENDENTSTUDYPROJ_API USpellComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USpellComponent();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FSpellSlot> SpellSlots; 
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FSpellSlot> SummonerSpellSlots;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<AActor*> Targets;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
		
	
};

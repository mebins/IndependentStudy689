// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemBase.h"
#include <IndependentStudyProj/IndependentStudyProjCharacter.h>
#include "Shop.generated.h"


UCLASS()
class INDEPENDENTSTUDYPROJ_API AShop : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AShop();
	virtual void Interact(AIndependentStudyProjCharacter* Player);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Items")
	TArray<TSubclassOf<AItemBase>> ShopItems;
	
	virtual void GetItem(int index);
	virtual void BuyItem(AItemBase* item);
	virtual void SellItem(AItemBase* item);
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};

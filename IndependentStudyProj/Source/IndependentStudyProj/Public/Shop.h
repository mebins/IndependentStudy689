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
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Category = "Items")
	TArray<TSubclassOf<AItemBase>> ShopItems;
	

	virtual void GetItem(int index);
	virtual void BuyItem(AItemBase* item);
	
	UFUNCTION(BlueprintCallable)
     void SellItem(AItemBase* item);


	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	
	
};

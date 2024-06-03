// Fill out your copyright notice in the Description page of Project Settings.


#include "Shop.h"
#include <IndependentStudyProj/IndependentStudyProjPlayerController.h>
#include <Net/UnrealNetwork.h>


// Sets default values
AShop::AShop()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;

}

void AShop::Interact(AIndependentStudyProjCharacter* Player)
{
	AIndependentStudyProjPlayerController* PC = Cast<AIndependentStudyProjPlayerController>(Player->GetController());

}


// Called when the game starts or when spawned
void AShop::BeginPlay()
{
	Super::BeginPlay();
	
}

void AShop::GetItem(int index)
{
}

void AShop::BuyItem(AItemBase* item)
{
}

void AShop::SellItem(AItemBase* item)
{
}


// Called every frame
void AShop::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AShop::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AShop, ShopItems);
}


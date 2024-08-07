// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemBase.h"
#include <Net/UnrealNetwork.h>


// Sets default values
AItemBase::AItemBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;
}

// Called when the game starts or when spawned
void AItemBase::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AItemBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
UTexture2D* AItemBase::GetItemIcon()
{
	return ItemInfo.ItemIcon;
}
FName AItemBase::GetFriendlyName()
{	
	return ItemInfo.ItemName;
}

void AItemBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	// Add properties to replicated for the derived class
	DOREPLIFETIME(AItemBase, ItemInfo);
}




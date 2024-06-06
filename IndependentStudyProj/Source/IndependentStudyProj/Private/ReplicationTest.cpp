// Fill out your copyright notice in the Description page of Project Settings.


#include "ReplicationTest.h"
#include <Net/UnrealNetwork.h>


// Sets default values for this component's properties
UReplicationTest::UReplicationTest()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	// ...
}


// Called when the game starts
void UReplicationTest::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UReplicationTest::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...

}

void UReplicationTest::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UReplicationTest, TestItems);
	DOREPLIFETIME(UReplicationTest, ReachCheck);
}


void UReplicationTest::Recalculate_Multicast_Implementation()
{
	if (TestItems.Num() > 0)
	{
		if (TestItems[0].ItemActor)
		{
			FName test = TestItems[0].ItemActor->ItemInfo.ItemName;
			if (ReachCheck != -1)
			{
				int z = 3;
			}
			int y = 3; 
		}
		int x = 3; 
	}
}

void UReplicationTest::Recalculate_Client_Implementation()
{
	if (TestItems.Num() > 0)
	{

		if (TestItems[0].ItemActor)
		{
			FName test = TestItems[0].ItemActor->ItemInfo.ItemName;
			if (ReachCheck != -1)
			{
				int z = 3;
			}
			int y = 3;
		}
		int x = 3; 
	}
}

void UReplicationTest::Recalculate_Server_Implementation()
{

	Recalculate_Client();
	Recalculate_Multicast();

}


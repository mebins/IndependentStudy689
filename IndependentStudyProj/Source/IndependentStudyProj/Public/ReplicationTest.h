// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/DataTable.h"
#include "ItemBase.h"
#include "ReplicationTest.generated.h"

USTRUCT(BlueprintType)
struct FSlot : public FTableRowBase
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool SlotUsed = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName FriendlyName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool OnCoolDown;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bSelfTarget;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AItemBase* ItemActor;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INDEPENDENTSTUDYPROJ_API UReplicationTest : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UReplicationTest();

	UPROPERTY(Replicated, BlueprintReadWrite, EditAnywhere)
	TArray<FSlot> TestItems;
	UPROPERTY(Replicated, BlueprintReadWrite, EditAnywhere)
	int32 ReachCheck = -1;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION(Server, Reliable, BlueprintCallable)
	void Recalculate_Server();

	UFUNCTION(Client, Reliable, BlueprintCallable)
	void Recalculate_Client();

	UFUNCTION(NetMulticast, Reliable)
	void Recalculate_Multicast();
	
};

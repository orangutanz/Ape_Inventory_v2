// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "Engine/DataAsset.h"
#include "Item_ConsumableData.generated.h"

//define what data should consumable hold
USTRUCT(BlueprintType)
struct FConsumable
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FItemInfo ItemInfo;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FName EffectType;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int Amount;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int StackSize;
	UPROPERTY(BlueprintReadOnly, Category = ItemType)
		TEnumAsByte<ItemType> Type = ItemType::Consumable;
};

UCLASS()
class APE_INVENTORY_V2_API UItem_ConsumableData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TArray<FConsumable> ConsumableData;
	
};

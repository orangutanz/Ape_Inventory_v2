// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "Engine/DataAsset.h"
#include "Item_EquipmentData.generated.h"

//define what data should equipment hold
USTRUCT(BlueprintType)
struct FEquipment
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FItemInfo ItemInfo;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int Damage;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int Armor;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int Durability;
	UPROPERTY(BlueprintReadOnly, Category = ItemType)
		TEnumAsByte<ItemType> Type = ItemType::Equipment;
};


UCLASS(BlueprintType)
class APE_INVENTORY_V2_API UItem_EquipmentData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FEquipment> EquipmentData;
};

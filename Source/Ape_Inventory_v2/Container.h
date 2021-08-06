// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "GameFramework/Actor.h"
#include "Container.generated.h"

UCLASS()
class APE_INVENTORY_V2_API AContainer : public AActor
{
	GENERATED_BODY()

private:
	int maxSize = 0;
	bool hasEmptySlot = false;
	TArray<AItem*> Items;

public:
	AContainer();
	AContainer(int size);
	AContainer(AContainer& other);

	// Get empty slot
	bool GetHasEmptySlot() const { return hasEmptySlot; }
	bool GetIsSlotEmpty(int index) const;
	int FindEmptyIndex() const; // return index, retrun -1 if not found;	

	// Find item
	// TArray<AItem*>& Find_ItemsOfType(const AItem& const item);
	bool FindItem(AItem& item) const;
	bool FindItem_AfterIndex(AItem& item, int index) const;
	int FindItem_GetIndex(AItem& item) const; // return index, retrun -1 if not found;

	// Add item
	bool AddItem(AItem& item);
	bool AddItemAt(AItem& item, int index);

	// Swap item
	void SwapItem(int first, int second);
	void SwapItemContainer(AContainer& other, int first, int second);

	// Transfer item
	bool TransferItem(AItem item, AContainer& toOther);
	bool TransferItemAt(int index, AContainer& toOther);
	bool TransferAllItems(AContainer& toOther);

	// Get item
	AItem* GetItem(AItem item);
	AItem* GetItemAt(int index);
	TArray<AItem*> GetAllItems();

	// Remove item
	bool RemoveItems(AItem& item); // RemoveItems(Apple);
	bool RemoveItemAt(int index);
	void RemoveAllItems();

	~AContainer();

	void UpdateHasEmptySlot();
	void UpdateEmptyItems();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

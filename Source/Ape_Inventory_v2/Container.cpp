// Fill out your copyright notice in the Description page of Project Settings.


#include "Container.h"

// Sets default values
AContainer::AContainer()
{
	PrimaryActorTick.bCanEverTick = false;
}

AContainer::AContainer(int size)
{
	PrimaryActorTick.bCanEverTick = false;
	if (size > 0)
	{
		maxSize = size;
		Items.Reserve(size);
		hasEmptySlot = true;
	}

}

bool AContainer::GetIsSlotEmpty(int index) const
{
	if (index < maxSize && index >= 0)
	{
		return (Items[index] == nullptr);
	}
	return false;
}

int AContainer::FindEmptyIndex() const
{
	for (int i = 0; i < maxSize; ++i)
	{
		if (Items[i] == nullptr)
		{
			return i;
		}
	}
	return -1;
}

bool AContainer::FindItem(const AItem& const item) const
{
	for (int i = 0; i < maxSize; ++i)
	{
		if (Items[i] != nullptr)
		{
			if (Items[i]->GetID() == item.GetID())
			{
				return true;
			}
		}
	}
	return false;
}

bool AContainer::FindItem_AfterIndex(const AItem& const item, int const index) const
{
	for (int i = index + 1; i < maxSize; ++i)
	{
		if (Items[i] != nullptr)
		{
			if (Items[i]->GetID() == item.GetID())
			{
				return true;
			}
		}
	}
	return false;
}

int AContainer::FindItem_GetIndex(const AItem& const item) const
{
	for (int i = 0; i < maxSize; ++i)
	{
		if (Items[i]->GetID() == item.GetID())
		{
			return i;
		}
	}
	return -1;
}

bool AContainer::AddItem(AItem& item)
{
	int i = FindItem_GetIndex(item);
	if (i >= 0)
	{

	}
	if (hasEmptySlot)
	{

	}

	return false;
}

bool AContainer::AddItemAt(AItem& item, int index)
{
	if (index >= 0 && index < maxSize)
	{
		if (Items[index] == nullptr)
		{
			Items.EmplaceAt(index, item);
		}
	}
	return false;
}

void AContainer::SwapItem(int first, int second)
{
	if ((first >= 0 && first < maxSize) && (second >= 0 && second < maxSize))
	{
		Items.Swap(first, second);
	}
}

void AContainer::SwapItemContainer(AContainer& other, int first, int second)
{
}

bool AContainer::TransferItem(AItem item, AContainer& toOther)
{
	return false;
}

bool AContainer::TransferItemAt(int index, AContainer& toOther)
{
	return false;
}

bool AContainer::TransferAllItems(AContainer& toOther)
{
	return false;
}

AItem& AContainer::GetItem(const AItem item)
{
	int i = FindItem_GetIndex(item);
	if (i >= 0)
	{
		return *Items[i];
	}
	return AItem();
}

AItem& AContainer::GetItemAt(const int index)
{
	if (index >= 0 && index < maxSize)
	{
		if (Items[index] != nullptr)
		{
			return *Items[index];
		}
	}
	return AItem();
}

bool AContainer::RemoveItems(AItem& item)
{
	int i = FindItem_GetIndex(item);

	while ((i >= 0 && i < maxSize) && item.Quantity > 0)
	{
		if (Items[i]->Quantity > item.Quantity)
		{
			Items[i]->Quantity - item.Quantity;
			item.Quantity = 0;
		}
		else if (Items[i]->Quantity == item.Quantity)
		{
			Items[i]->Quantity - item.Quantity;
			Items[i] = nullptr;
			item.Quantity = 0;
			hasEmptySlot = true;
		}
		else
		{
			item.Quantity - Items[i]->Quantity;
			Items[i] = nullptr;
			FindItem_AfterIndex(item, i);
			hasEmptySlot = true;
		}
	}
	if (item.Quantity == 0)
	{
		return true;
	}
	return false;
}

bool AContainer::RemoveItemAt(int index)
{
	if (index >= 0 && index < maxSize)
	{
		if (Items[index] != nullptr)
		{
			Items[index] == nullptr;
		}
	}
	return false;
}

void AContainer::RemoveAllItems()
{
	Items.Empty(maxSize);
}

AContainer::~AContainer()
{
	Items.Empty();
}

void AContainer::UpdateHasEmptySlot()
{
	for (int i = 0; i < maxSize; ++i)
	{
		if (Items[i] == nullptr)
		{
			hasEmptySlot = true;
			return;
		}
	}
	hasEmptySlot = false;

}

void AContainer::UpdateEmptyItems()
{
	for (int i = 0; i < maxSize; ++i)
	{
		if (Items[i] != nullptr)
		{
			if (Items[i]->GetQuantity() <= 0)
			{
				Items[i] = nullptr;
			}
		}
	}
}

// Called when the game starts or when spawned
void AContainer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AContainer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


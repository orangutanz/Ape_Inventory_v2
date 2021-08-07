#include "Container.h"

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

AContainer::AContainer(AContainer& other)
{
	maxSize = other.maxSize;
	Items.Reserve(maxSize);
	for (int i = 0; i < maxSize; ++i)
	{
		Items[i] = other.Items[i];
	}
	hasEmptySlot = other.hasEmptySlot;
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

bool AContainer::FindItem(AItem& item) const
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

bool AContainer::FindItem_AfterIndex(AItem& item, int index) const
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

int AContainer::FindItem_GetIndex(AItem& item) const
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
	//if the item can be stacked
	if (item.maxStack > 1)
	{
		int i = FindItem_GetIndex(item);
		//find if the same item is in the container
		while ((i >= 0 && i < maxSize) && item.GetQuantity() > 0)
		{
			int p = Items[i]->GetQuantity();
			int q = item.GetQuantity();
			int m = Items[i]->GetMaxStack();
			if ((p + q) <= m)
			{
				Items[i]->SetQuantity(p + q);
				item.SetQuantity(0);
				return true;
			}
			else
			{
				Items[i]->SetQuantity(m);
				item.SetQuantity(q - (m - p));
			}
			i = FindItem_AfterIndex(item, i);
		}
	}
	//add new one if there's a spot
	if (hasEmptySlot && item.GetQuantity() > 0)
	{
		AddItemAt(item, FindEmptyIndex());
		item.SetQuantity(0);
	}
	//return true if all items are added
	if (item.GetQuantity() == 0)
	{
		return true;
	}
	//false if there are items left not added
	return false;
}

bool AContainer::AddItemAt(AItem& item, int index)
{
	if (index >= 0 && index < maxSize)
	{
		if (Items[index] == nullptr)
		{
			Items.EmplaceAt(index, &item);
			return true;
		}
		else if (item.GetID() == Items[index]->itemID)
		{
			int AddQuantity = item.GetQuantity();
			int ItemQuantity = Items[index]->GetQuantity();
			int MaxStack = Items[index]->GetMaxStack();
			if ((ItemQuantity + AddQuantity) <= MaxStack)
			{
				Items[index]->SetQuantity(ItemQuantity + AddQuantity);
				item.SetQuantity(0);
				return true;
			}
			else
			{
				Items[index]->SetQuantity(MaxStack);
				item.SetQuantity(AddQuantity - ItemQuantity);
				return true;
			}
		}
	}
	UpdateHasEmptySlot();
	return false;
}

void AContainer::SwapItem(int first, int second)
{
	if ((first >= 0 && first < maxSize) && (second >= 0 && second < maxSize))
	{
		Items.Swap(first, second);
	}
}
/*
bool AContainer::TransferItem(AItem item, AContainer& toOther)
{
	return false;
}*/

bool AContainer::TransferItemAt(int index, AContainer& toOther)
{
	if (index >= 0 && index < maxSize)
	{
		if (Items[index] == nullptr)
		{
			return false;
		}
		else
		{
			bool result = toOther.AddItem(*Items[index]);
			if (result)
			{
				Items[index] = nullptr;
			}
			return result;
		}
	}
	return false;
}

bool AContainer::TransferAllItems(AContainer& toOther)
{
	for (int i = 0; i < maxSize; ++i)
	{
		if (Items[i] != nullptr)
		{
			toOther.AddItem(*Items[i]);
		}
	}
	UpdateEmptyItems();
	UpdateHasEmptySlot();
	for (int i = 0; i < maxSize; ++i)
	{
		if (Items[i] != nullptr)
		{
			return false;
		}
	}
	return true;
}

AItem* AContainer::GetItem(AItem item)
{
	int i = FindItem_GetIndex(item);
	if (i >= 0)
	{
		return Items[i];
	}
	return nullptr;
}

AItem* AContainer::GetItemAt(int index)
{
	if (index >= 0 && index < maxSize)
	{
		if (Items[index] != nullptr)
		{
			return Items[index];
		}
	}
	return nullptr;
}

TArray<AItem*> AContainer::GetAllItems()
{
	return TArray<AItem*>();
}

bool AContainer::RemoveItems(AItem& item)
{
	int i = FindItem_GetIndex(item);
	int q = item.GetQuantity();
	while ((i >= 0 && i < maxSize) && q > 0)
	{
		int p = Items[i]->GetQuantity();
		if (p > q)
		{
			Items[i]->SetQuantity(p - q);
			q = 0;
			item.SetQuantity(0);
		}
		else if (p == q)
		{
			Items[i]->SetQuantity(0);
			Items[i] = nullptr;
			
			item.SetQuantity(0);
			hasEmptySlot = true;
		}
		else
		{
			Items[i]->SetQuantity(0);
			Items[i] = nullptr;
			q = q - p;

			item.SetQuantity(q);
			hasEmptySlot = true;

			i = FindItem_AfterIndex(item, i);
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
			Items[index] = nullptr;
			hasEmptySlot = true;
		}
	}
	return false;
}

void AContainer::RemoveAllItems()
{
	hasEmptySlot = true;
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


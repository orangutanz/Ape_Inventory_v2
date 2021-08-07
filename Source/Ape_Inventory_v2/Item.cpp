#include "Item.h"

AItem::AItem()
{
	PrimaryActorTick.bCanEverTick = false;
}

AItem::AItem(FName id, ItemType type, FString name, FText description, int MaxStack, int quantity)
{
	itemID = id;
	itemType = type;
	Name = name;
	Description = description;
	maxStack = MaxStack;
	Quantity = quantity;
	PrimaryActorTick.bCanEverTick = false;
}

AItem::AItem(AItem* other)
{
	itemID = other->itemID;
	itemType = other->itemType;
	Name = other->Name;
	Description = other->Description;
	maxStack = other->maxStack;
	Quantity = other->Quantity;
	PrimaryActorTick.bCanEverTick = false;
}

AItem::~AItem()
{
	Quantity = 0;
}
/*
AItem& AItem::operator=(const AItem& other)
{
	itemID = other.GetID();
	itemType = other.GetType();
	Name = other.GetName();
	Description = other.GetDescription();
	maxStack = other.GetMaxStack();
	Quantity = other.GetQuantity();
	return *this;
}

AItem& AItem::operator=(AItem&& other)
{
	itemID = other.GetID();
	itemType = other.GetType();
	Name = other.GetName();
	Description = other.GetDescription();
	maxStack = other.GetMaxStack();
	Quantity = other.GetQuantity();
	other.Quantity = 0;
	other = nullptr;
	return *this;
}

AItem& AItem::operator+(AItem& other)
{
	if (itemID == other.itemID)
	{
		int p = Quantity;
		int q = other.Quantity;
		int m = maxStack;
		if ((p + q) <= m)
		{			
			Quantity = p + q;
			other.Quantity = p - Quantity;
		}
		else
		{
			Quantity = m;
			other.Quantity = q - (m - p);
		}
	}
	return *this;
}
*/
// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


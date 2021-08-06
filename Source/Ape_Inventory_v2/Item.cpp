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


// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UENUM(BlueprintType)
enum ItemType
{
	Equipment        UMETA(DisplayName = "Equipment"),
	Consumable       UMETA(DisplayName = "Consumable"),
	MaterialItem     UMETA(DisplayName = "MaterialItem"),
	Container        UMETA(DisplayName = "Container"),
	Miscellaneous    UMETA(DisplayName = "Miscellaneous"),
};

UCLASS(Blueprintable)
class APE_INVENTORY_V2_API AItem : public AActor
{
	GENERATED_BODY()

public:
	FName itemID;
	FString Name;
	ItemType itemType;
	FText Description;
	int maxStack = 1;
	int Quantity = 0;

public:
	AItem();
	AItem(FName id, ItemType type, FString name, FText description, int MaxStack, int quantity);
	AItem(AItem* other);
	~AItem();

	/*
	AItem& operator=(const AItem& other) = delete; // copy assignment
	AItem& operator=(AItem&& other) = delete;// move assignment
	AItem& operator+(AItem& other) = delete; // add up (possiblely move assignment)
	*/
	void SetID(const FName id) { itemID = id; }
	void SetName(const FString name) { Name = name; }
	void SetType(const ItemType type) { itemType = type; }
	void SetDescription(const FText d) { Description = d; }
	void SetMaxStack(const int s) { maxStack = s; }
	void SetQuantity(const int v) { Quantity = v; }

	FName	    GetID()    const { return  itemID; }
	FString		GetName()  const { return  Name; }
	ItemType    GetType()  const { return  itemType; }
	FText	    GetDescription() const { return  Description; }
	bool		GetCanStack() const { return  (maxStack > 1); }
	int			GetMaxStack() const { return  maxStack; }
	int			GetQuantity() const { return  Quantity; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

//define what ItemInfo should hold in the database
USTRUCT(BlueprintType)
struct FItemInfo
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FName ItemID;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FText Description;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int MaxStack;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int Quantity;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		UTexture2D* Icon;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		UStaticMesh* mesh;
};
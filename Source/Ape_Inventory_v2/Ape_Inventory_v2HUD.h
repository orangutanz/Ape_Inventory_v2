// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Ape_Inventory_v2HUD.generated.h"

UCLASS()
class AApe_Inventory_v2HUD : public AHUD
{
	GENERATED_BODY()

public:
	AApe_Inventory_v2HUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};


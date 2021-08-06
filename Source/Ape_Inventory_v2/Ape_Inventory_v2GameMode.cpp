// Copyright Epic Games, Inc. All Rights Reserved.

#include "Ape_Inventory_v2GameMode.h"
#include "Ape_Inventory_v2HUD.h"
#include "Ape_Inventory_v2Character.h"
#include "UObject/ConstructorHelpers.h"

AApe_Inventory_v2GameMode::AApe_Inventory_v2GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AApe_Inventory_v2HUD::StaticClass();
}

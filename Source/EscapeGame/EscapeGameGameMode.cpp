// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "EscapeGameGameMode.h"
#include "EscapeGameHUD.h"
#include "EscapeGameCharacter.h"
#include "UObject/ConstructorHelpers.h"

AEscapeGameGameMode::AEscapeGameGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AEscapeGameHUD::StaticClass();
}

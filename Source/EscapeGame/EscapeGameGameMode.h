// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Blueprint/UserWidget.h"

#include "EscapeGameGameMode.generated.h"

UCLASS(minimalapi)
class AEscapeGameGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AEscapeGameGameMode();

	virtual void BeginPlay() override;

protected:

	UPROPERTY(EditAnywhere, Category = "HUD Elements")
		TSubclassOf<UUserWidget> HealthBarClass;

	UUserWidget* HealthBar;

	bool bPlayerDead;


};




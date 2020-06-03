// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"

#include "Blueprint/UserWidget.h"

#include "ER_GameMode.generated.h"

/**
 * 
 */
UCLASS()
class ESCAPEGAME_API AER_GameMode : public AGameMode
{
	GENERATED_BODY()

	AER_GameMode();

	virtual void BeginPlay() override;

public:

	bool bPlayerDead;

	UFUNCTION()
		void RestartLevel(FName LevelName);

	bool bStart;

protected:

	UWorld* ThisWorld;

	UPROPERTY(EditAnywhere, Category = "HUD Elements")
		TSubclassOf<UUserWidget> HealthWidgetClass;

	UUserWidget* HealthWidget;

	UPROPERTY(EditAnywhere, Category = "HUD Elements")
		TSubclassOf<UUserWidget> RestartWidgetClass;

	UUserWidget* RestartWidget;

	APlayerController* PC_Ref;

	
};

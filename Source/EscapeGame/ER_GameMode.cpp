// Fill out your copyright notice in the Description page of Project Settings.


#include "ER_GameMode.h"

AER_GameMode::AER_GameMode()
{
	ThisWorld = GetWorld();
}

void AER_GameMode::BeginPlay()
{
	
	Super::BeginPlay();
	
	bPlayerDead = false; 

	if (HealthWidgetClass != nullptr)
	{
		HealthWidget = CreateWidget<UUserWidget>(GetWorld(), HealthWidgetClass);
		HealthWidget->AddToViewport();
	}

	if (RestartWidgetClass != nullptr)
	{
		RestartWidget = CreateWidget<UUserWidget>(GetWorld(), RestartWidgetClass);
		RestartWidget->AddToViewport();

		RestartWidget->SetVisibility(ESlateVisibility::Hidden);

	}

	PC_Ref = GetWorld()->GetFirstPlayerController();
}

void AER_GameMode::RestartLevel(FName LevelName)
{
}

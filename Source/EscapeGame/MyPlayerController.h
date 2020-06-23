// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InventoryWidget.h"
#include "Blueprint/UserWidget.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ESCAPEGAME_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

private:

	virtual void BeginPlay() override;

	// InventoryWidget reference
	UInventoryWidget* InventoryWidgetRef;

	// true is inventory is open
	bool bIsInventoryOpen;

	FTimerHandle TimerHandle;

protected:
	// InventoryWidget Blueprint reference
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<UInventoryWidget> InventoryWidgetBP;

	UPROPERTY(EditAnywhere, Category = "HUD Elements")
		TSubclassOf<UUserWidget> HealthWidgetClass;

	UUserWidget* HealthWidget;

	UPROPERTY(EditAnywhere, Category = "HUD Elements")
		TSubclassOf<UUserWidget> RestartWidgetClass;

	UUserWidget* RestartWidget;

	UPROPERTY(EditAnywhere, Category = "HUD Elements")
		TSubclassOf<UUserWidget> UserMessageWidgetClass;

	UUserWidget* UserMessageWidget;

	UPROPERTY(EditAnywhere, Category = "HUD Elements")
		TSubclassOf<UUserWidget> WinWidgetClass;

	UUserWidget* WinWidget;

	UPROPERTY(EditAnywhere, Category = "HUD Elements")
		TSubclassOf<UUserWidget> ControlsWidgetClass;

	UUserWidget* ControlsWidget;



public:
	virtual void OnPossess(APawn* InPawn) override;

	//Opens or closes the inventory
	void HandleInventoryInput();

	virtual void Tick(float DeltaSeconds) override;

	AEscapeGameCharacter* Character;

	void ShowRestart();

	UFUNCTION()
	void DisplayMessage();

	UFUNCTION()
	void RemoveMessage();

	void UpdateInventory();

	void ShowWin();

	void ShowHideControls();
	bool bIsControlsOpen = false;

	
};

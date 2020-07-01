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
	UPROPERTY()
	UInventoryWidget* InventoryWidgetRef;

	// true is inventory is open
	UPROPERTY()
	bool bIsInventoryOpen;

	UPROPERTY()
	FTimerHandle TimerHandle;

protected:
	// InventoryWidget Blueprint reference
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<UInventoryWidget> InventoryWidgetBP;

	/// Reference to the Health bar widget
	UPROPERTY(EditAnywhere, Category = "HUD Elements")
		TSubclassOf<UUserWidget> HealthWidgetClass;

	UPROPERTY()
	UUserWidget* HealthWidget;

	/// Reference to the Restart menu widget
	UPROPERTY(EditAnywhere, Category = "HUD Elements")
		TSubclassOf<UUserWidget> RestartWidgetClass;

	UPROPERTY()
	UUserWidget* RestartWidget;

	/// Reference to the locked door message widget
	UPROPERTY(EditAnywhere, Category = "HUD Elements")
		TSubclassOf<UUserWidget> UserMessageWidgetClass;

	UPROPERTY()
	UUserWidget* UserMessageWidget;

	/// Reference to the win menu widget
	UPROPERTY(EditAnywhere, Category = "HUD Elements")
		TSubclassOf<UUserWidget> WinWidgetClass;

	UPROPERTY()
	UUserWidget* WinWidget;

	/// Reference to controls menu widget
	UPROPERTY(EditAnywhere, Category = "HUD Elements")
		TSubclassOf<UUserWidget> ControlsWidgetClass;

	UPROPERTY()
	UUserWidget* ControlsWidget;

	/// Reference to pause menu widget
	UPROPERTY(EditAnywhere, Category = "HUD Elements")
		TSubclassOf<UUserWidget> PauseWidgetClass;

	UPROPERTY()
		UUserWidget* PauseWidget;

	// Tracks whether the control menu is open or closed
	UPROPERTY()
		bool bIsControlsOpen = false;

public:
	UFUNCTION()
	virtual void OnPossess(APawn* InPawn) override;

	//Opens or closes the inventory
	UFUNCTION()
	void HandleInventoryInput();

	virtual void Tick(float DeltaSeconds) override;

	// Shows restart menu and allows use of mouse
	UFUNCTION()
	void ShowRestart();

	// Displays locked door message
	UFUNCTION()
	void DisplayMessage();

	// Removes locked door message from screen
	UFUNCTION()
	void RemoveMessage();

	// Updates the inventory when pickup is collected
	UFUNCTION()
	void UpdateInventory();

	// Shows the win menu
	UFUNCTION()
	void ShowWin();

	// Opens and closes the controls menu
	UFUNCTION()
	void ShowHideControls();

	// Displays the pause menu and allows use of mouse
	UFUNCTION()
	void PauseGame();

};

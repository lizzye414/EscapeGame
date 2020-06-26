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

	UPROPERTY(EditAnywhere, Category = "HUD Elements")
		TSubclassOf<UUserWidget> HealthWidgetClass;

	UPROPERTY()
	UUserWidget* HealthWidget;

	UPROPERTY(EditAnywhere, Category = "HUD Elements")
		TSubclassOf<UUserWidget> RestartWidgetClass;

	UPROPERTY()
	UUserWidget* RestartWidget;

	UPROPERTY(EditAnywhere, Category = "HUD Elements")
		TSubclassOf<UUserWidget> UserMessageWidgetClass;

	UPROPERTY()
	UUserWidget* UserMessageWidget;

	UPROPERTY(EditAnywhere, Category = "HUD Elements")
		TSubclassOf<UUserWidget> WinWidgetClass;

	UPROPERTY()
	UUserWidget* WinWidget;

	UPROPERTY(EditAnywhere, Category = "HUD Elements")
		TSubclassOf<UUserWidget> ControlsWidgetClass;

	UPROPERTY()
	UUserWidget* ControlsWidget;

	UPROPERTY(EditAnywhere, Category = "HUD Elements")
		TSubclassOf<UUserWidget> PauseWidgetClass;

	UPROPERTY()
		UUserWidget* PauseWidget;

public:
	UFUNCTION()
	virtual void OnPossess(APawn* InPawn) override;

	//Opens or closes the inventory
	UFUNCTION()
	void HandleInventoryInput();

	virtual void Tick(float DeltaSeconds) override;

	UFUNCTION()
	void ShowRestart();

	UFUNCTION()
	void DisplayMessage();

	UFUNCTION()
	void RemoveMessage();

	UFUNCTION()
	void UpdateInventory();

	UFUNCTION()
	void ShowWin();

	UFUNCTION()
	void ShowHideControls();

	UPROPERTY()
	bool bIsControlsOpen = false;

	UFUNCTION()
	void PauseGame();

};

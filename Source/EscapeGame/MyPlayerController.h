// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InventoryWidget.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ESCAPEGAME_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	// InventoryWidget reference
	UInventoryWidget* InventoryWidgetRef;

	// true is inventory is open
	bool bIsInventoryOpen;

protected:
	// InventoryWidget Blueprint reference
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<UInventoryWidget> InventoryWidgetBP;

public:
	virtual void OnPossess(APawn* InPawn) override;

	//Opens or closes the inventory
	void HandleInventoryInput();
	
};

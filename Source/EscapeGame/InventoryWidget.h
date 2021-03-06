// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Pickup2.h"
#include "EscapeGameCharacter.h"
#include "InventoryWidget.generated.h"

/**
 * 
 */
UCLASS()
class ESCAPEGAME_API UInventoryWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	// adds the widget into viewport and populates inventory slots
	UFUNCTION(BlueprintImplementableEvent, Category = UI)
		void Show();

	/// stores information on inventory slots
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		int32 NumCones;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		int32 NumCubes;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		int32 NumCylinders;
	
};

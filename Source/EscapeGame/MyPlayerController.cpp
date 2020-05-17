// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "EscapeGameCharacter.h"

void AMyPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if (InventoryWidgetBP)
	{
		InventoryWidgetRef = CreateWidget<UInventoryWidget>(this, InventoryWidgetBP);
	}

	// initial value
	bIsInventoryOpen = false;
}

void AMyPlayerController::HandleInventoryInput()
{

	AEscapeGameCharacter* Char = Cast<AEscapeGameCharacter>(GetPawn());
	if (InventoryWidgetRef)
	{
		if (bIsInventoryOpen)
		{
			// mark inventory as closed
			bIsInventoryOpen = false;

			// remove inventory from viewport
			InventoryWidgetRef->RemoveFromViewport();
		}
		else
		{
			// mark inventory as open
			bIsInventoryOpen = true;

			// repopulate ItemsArray
			InventoryWidgetRef->ItemsArray = Char->GetInventory();

			InventoryWidgetRef->NumCones = Char->GetNumCones();

			InventoryWidgetRef->NumCubes = Char->GetNumCubes();

			InventoryWidgetRef->NumCylinders = Char->GetNumCylinders();

			// show inventory
			InventoryWidgetRef->Show();
		}
	}

}




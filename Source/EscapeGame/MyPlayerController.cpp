// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "EscapeGameCharacter.h"

void AMyPlayerController::BeginPlay()
{
	if (HealthWidgetClass != nullptr)
	{
		HealthWidget = CreateWidget<UUserWidget>(GetWorld(), HealthWidgetClass);
		HealthWidget->AddToViewport();
	}

	if (UserMessageWidgetClass != nullptr)
	{
		UserMessageWidget = CreateWidget<UUserWidget>(GetWorld(), UserMessageWidgetClass);
	}

	if (ControlsWidgetClass != nullptr)
	{
		ControlsWidget = CreateWidget<UUserWidget>(GetWorld(), ControlsWidgetClass);
	}

}


void AMyPlayerController::Tick(float DeltaSeconds)
{
	
}

void AMyPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if (InventoryWidgetBP)
	{
		InventoryWidgetRef = CreateWidget<UInventoryWidget>(this, InventoryWidgetBP);
	}

	// initial value
	bIsInventoryOpen = false;

	//AEscapeGameCharacter* Character = Cast<AEscapeGameCharacter>(GetPawn());
}

/// Displays inventory on screen
void AMyPlayerController::HandleInventoryInput()
{

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
			UpdateInventory();
			
			// mark inventory as open
			bIsInventoryOpen = true;

			// show inventory
			InventoryWidgetRef->Show();
		}
	}

}

void AMyPlayerController::DisplayMessage()
{

	if (UserMessageWidget)
	{
		UserMessageWidget->AddToViewport();
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AMyPlayerController::RemoveMessage, 2.0f, false);
	}

}

void AMyPlayerController::RemoveMessage()
{

	if (UserMessageWidget)
	{
		UserMessageWidget->RemoveFromViewport();
	}
}

/// Update the inventory even if it is left open
void AMyPlayerController::UpdateInventory()
{

	AEscapeGameCharacter* Char = Cast<AEscapeGameCharacter>(GetPawn());

	
	InventoryWidgetRef->NumCones = Char->GetNumCones();

	InventoryWidgetRef->NumCubes = Char->GetNumCubes();

	InventoryWidgetRef->NumCylinders = Char->GetNumCylinders();

}

/// Pause the game and show the restart menu
void AMyPlayerController::ShowRestart()
{

	if (RestartWidgetClass != nullptr)
	{
		RestartWidget = CreateWidget<UUserWidget>(GetWorld(), RestartWidgetClass);
		RestartWidget->AddToViewport();
		UGameplayStatics::SetGamePaused(GetWorld(), true);
		GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;
		GetWorld()->GetFirstPlayerController()->bEnableClickEvents = true;
	}


}


/// Pause game and show win UI
void AMyPlayerController::ShowWin()
{

	if (WinWidgetClass != nullptr)
	{
		WinWidget = CreateWidget<UUserWidget>(GetWorld(), WinWidgetClass);
		WinWidget->AddToViewport();
		UGameplayStatics::SetGamePaused(GetWorld(), true);
		GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;
		GetWorld()->GetFirstPlayerController()->bEnableClickEvents = true;
	}

}

void AMyPlayerController::ShowHideControls()
{

	if (ControlsWidgetClass != nullptr)
	{
		if (!bIsControlsOpen && ControlsWidget)
		{
			ControlsWidget->AddToViewport();
			bIsControlsOpen = true;
		}
		else
		{
			ControlsWidget->RemoveFromViewport();
			bIsControlsOpen = false;
		}
	}

}












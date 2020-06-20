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

	

}


void AMyPlayerController::Tick(float DeltaSeconds)
{
	AEscapeGameCharacter* Char = Cast<AEscapeGameCharacter>(GetPawn());

	// Update the inventory even if it is left open
	InventoryWidgetRef->NumCones = Char->GetNumCones();

	InventoryWidgetRef->NumCubes = Char->GetNumCubes();

	InventoryWidgetRef->NumCylinders = Char->GetNumCylinders();
}

/// Pause the game and show the restart menu
void AMyPlayerController::ShowRestart()
{
	
	AEscapeGameCharacter* Char = Cast<AEscapeGameCharacter>(GetPawn());

	if (RestartWidgetClass != nullptr)
	{
		RestartWidget = CreateWidget<UUserWidget>(GetWorld(), RestartWidgetClass);
		RestartWidget->AddToViewport();
		UGameplayStatics::SetGamePaused(GetWorld(), true);
		GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true; 
		GetWorld()->GetFirstPlayerController()->bEnableClickEvents = true;
	}


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

	Character = Cast<AEscapeGameCharacter>(GetPawn());
}

/// Displays inventory on screen
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

			// show inventory
			InventoryWidgetRef->Show();
		}
	}

}

void AMyPlayerController::DisplayMessage()
{

	UserMessageWidget->AddToViewport();
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AMyPlayerController::RemoveMessage, 3.0f, false);

}

void AMyPlayerController::RemoveMessage()
{

	UserMessageWidget->RemoveFromViewport();

}











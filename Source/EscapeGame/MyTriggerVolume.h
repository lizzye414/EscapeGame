// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerVolume.h"
#include "EscapeGameCharacter.h"
#include "Pickup2.h"
#include "MyTriggerVolume.generated.h"

/**
 * 
 */
UCLASS()
class ESCAPEGAME_API AMyTriggerVolume : public ATriggerVolume
{
	GENERATED_BODY()

private:

	virtual void BeginPlay() override;

public:

	AMyTriggerVolume();

	UFUNCTION()
	void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);

	UFUNCTION()
	void OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor);

	UPROPERTY(EditAnywhere, Category = "Identity")
		FString Name;

	bool isPressed;


	ACharacter* CurrentCharacter;

	AEscapeGameCharacter* EGCharacter;

	UPROPERTY()
		APickup2* CurrentPickup;

};

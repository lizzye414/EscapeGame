// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/Texture2D.h"
#include "Pickup2.generated.h"

UCLASS()
class ESCAPEGAME_API APickup2 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickup2();

	/*Enables/Disables the glow effect on the pickup*/
	UFUNCTION()
		void SetGlowEffect(bool Status);

	UFUNCTION()
		FString GetItemName() { return ItemName; }

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/*The Static Mesh of the pickup*/
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* PickupSM;

	/*The name of the item*/
	UPROPERTY(EditAnywhere, Category = "PickupProperties")
		FString ItemName;

};

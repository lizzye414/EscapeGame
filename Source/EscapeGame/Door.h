// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "Components/StaticMeshComponent.h"
#include <Runtime\Engine\Classes\Components\BoxComponent.h>
#include "Door.generated.h"


/**
 * 
 */
UCLASS()
class ESCAPEGAME_API ADoor : public AStaticMeshActor
{
	GENERATED_BODY()

public:
	ADoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
		void OpenDoor(float dt);

	UFUNCTION()
		void CloseDoor(float dt);

	float DotP;
	float PosNeg;
	float AddRotation;
	float CurrentRotation;
	float MaxDegree;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UStaticMeshComponent* Door;

	UFUNCTION()
		void MoveDoor(FVector ForwardVector);

	UPROPERTY(VisibleAnywhere, Category = "BoxComp")
		UBoxComponent* BoxComp;

	UPROPERTY(EditAnywhere, Category = "Type")
		FString Type;

	bool isUnlocked;
	bool Opening;
	bool Closing;
	bool isClosed;






	
};

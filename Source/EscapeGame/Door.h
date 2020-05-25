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

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void OpenDoor(float dt);

	UFUNCTION()
		void CloseDoor(float dt);

	UFUNCTION()
		void MoveDoor(FVector ForwardVector);

	UStaticMeshComponent* Door;

	UPROPERTY(VisibleAnywhere, Category = "BoxComp")
		UBoxComponent* BoxComp;

	bool Opening;
	bool Closing;
	bool isClosed;

	float DotP;
	float PosNeg;
	float AddRotation;
	float CurrentRotation;
	float MaxDegree;




	
};

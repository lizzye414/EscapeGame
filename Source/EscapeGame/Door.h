// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
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

	UPROPERTY(VisibleAnywhere, Category = "BoxComp")
		UBoxComponent* BoxComp;

	
	bool isClosed;
	float addRotation;
	float currentRotation;




	
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/StaticMeshActor.h"
#include "Components/StaticMeshComponent.h"
#include <Engine.h>
#include "Door2.generated.h"


UCLASS()
class ESCAPEGAME_API ADoor2 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoor2();

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

	UStaticMeshComponent* Door;

	// declare sphere comp
	UPROPERTY(VisibleAnywhere, Category = "BoxComp")
		UBoxComponent* BoxComp;

	UFUNCTION()
		void MoveDoor(FVector ForwardVector);

	bool Opening;
	bool Closing;
	bool isClosed;

	float DotP;
	float MaxDegree;
	float AddRotation;
	float PosNeg;
	float DoorCurrentRotation;

};

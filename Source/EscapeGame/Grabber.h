// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/InputComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Pickup2.h"
#include "Engine/World.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPEGAME_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


private:
	// How far the character can reach
	float Reach = 150.0f;

	UPhysicsHandleComponent* PhysicsHandle = nullptr; 

	UInputComponent* InputComponent = nullptr;

	// Return hit for first physics body in reach
	const FHitResult GetFirstPhysicsBodyInReach();

	void FindPhysicsHandleComponent();
	void AttachInputComponent();

	void Grab();
	void Release();
};

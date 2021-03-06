// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "MovingPlatform.generated.h"

UCLASS()
class ESCAPEGAME_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* Platform;

	UFUNCTION()
		void MoveUp(float dt);

	UFUNCTION()
		void MoveDown(float dt);

	FVector CurrentLocation;
	float AddHeight;

	UPROPERTY()
		bool movingUp;

	UPROPERTY(EditAnywhere, Category = "Settings")
		float Speed;

	UPROPERTY(EditAnywhere, Category = "Settings")
		float MinHeight;

	UPROPERTY(EditAnywhere, Category = "Settings")
		float MaxHeight;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

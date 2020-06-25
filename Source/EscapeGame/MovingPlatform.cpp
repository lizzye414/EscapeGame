// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Actor.h"
#include "Components/SceneComponent.h"



// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	if (!RootComponent)
	{
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("MovingPlatform"));
	}

	Platform = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Platform"));
	Platform->SetupAttachment(RootComponent);

	Platform->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));

	AddHeight = 0.0f;
	movingUp = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (movingUp)
	{
		MoveUp(DeltaTime);
	}

	if (movingDown)
	{
		MoveDown(DeltaTime);
	}

}

void AMovingPlatform::MoveUp(float dt)
{
	CurrentLocation = Platform->GetRelativeLocation();

	AddHeight = dt * Speed;

	if (FMath::IsNearlyEqual(CurrentLocation.Z, MaxHeight, 1.5f))
	{
		movingUp = false;
		movingDown = true;
	}
	else if (movingUp)
	{
		
		FVector NewLocation = FVector(0.0f, 0.0f, AddHeight);
		Platform->AddRelativeLocation(NewLocation, false, 0, ETeleportType::None);
	
	}

}

void AMovingPlatform::MoveDown(float dt)
{

	CurrentLocation = Platform->GetRelativeLocation();

	AddHeight = -dt * Speed;

	// Platform stops at different height depending on whether it started at floor or not so that it doesn't 
	// fall through the floor
	if (!startDown)
	{
		if (FMath::IsNearlyEqual(CurrentLocation.Z, -MaxHeight + 100.0f, 1.5f))
		{
			movingUp = true;
			movingDown = false;
		}
		else if (movingDown)
		{

			FVector NewLocation = FVector(0.0f, 0.0f, AddHeight);
			Platform->AddRelativeLocation(NewLocation, false, 0, ETeleportType::None);

		}
	}
	else
	{
		if (FMath::IsNearlyEqual(CurrentLocation.Z, 20.0f, 1.5f))
		{
			movingUp = true;
			movingDown = false;
		}
		else if (movingDown)
		{

			FVector NewLocation = FVector(0.0f, 0.0f, AddHeight);
			Platform->AddRelativeLocation(NewLocation, false, 0, ETeleportType::None);

		}
	}

}


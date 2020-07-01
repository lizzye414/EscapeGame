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

	AddHeight = 0.0f;
	movingUp = true;
	
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	Platform->SetRelativeLocation(FVector(0.0f, 0.0f, MinHeight));
	
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (movingUp)
	{
		MoveUp(DeltaTime);
	}

	if (!movingUp)
	{
		MoveDown(DeltaTime);
	}

}

void AMovingPlatform::MoveUp(float dt)
{
	CurrentLocation = Platform->GetRelativeLocation();

	AddHeight = dt * Speed;

	if (CurrentLocation.Z >= MaxHeight)
	{
		movingUp = false;
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

	if (CurrentLocation.Z <= MinHeight)
	{
		movingUp = true;
	}
	else if (!movingUp)
	{
		FVector NewLocation = FVector(0.0f, 0.0f, AddHeight);
		Platform->AddRelativeLocation(NewLocation, false, 0, ETeleportType::None);
	}

}


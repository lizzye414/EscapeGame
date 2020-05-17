// Fill out your copyright notice in the Description page of Project Settings.


#include "Kismet/GameplayStatics.h"
#include "Door.h"


ADoor::ADoor()
{

	PrimaryActorTick.bCanEverTick = true;

	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("MyBoxComponent"));
	BoxComp->InitBoxExtent(FVector(150, 100, 100));
	BoxComp->SetCollisionProfileName("Trigger");
	RootComponent = BoxComp;

	isClosed = true;
	addRotation = 0.0f;
	currentRotation = 0.0f;

}

void ADoor::BeginPlay()
{
}

void ADoor::Tick(float DeltaTime)
{
}

void ADoor::OpenDoor(float dt)
{
}


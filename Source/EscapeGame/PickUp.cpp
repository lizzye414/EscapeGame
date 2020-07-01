// Fill out your copyright notice in the Description page of Project Settings.


#include "PickUp.h"
#include "Engine/Engine.h"

// Sets default values
APickUp::APickUp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	RootComponent = StaticMesh;

	this->BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	this->BoxCollision->SetGenerateOverlapEvents(true);
	this->BoxCollision->SetWorldScale3D(FVector(1.0f, 1.0f, 1.0f));
	this->BoxCollision->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void APickUp::BeginPlay()
{

	Super::BeginPlay();
	
}

// Called every frame
void APickUp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}




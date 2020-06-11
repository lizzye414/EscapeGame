// Fill out your copyright notice in the Description page of Project Settings.


#include "LiftPickup.h"

// Sets default values
ALiftPickup::ALiftPickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	RootComponent = StaticMesh;

	this->BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	this->BoxCollision->SetGenerateOverlapEvents(true);
	this->BoxCollision->SetWorldScale3D(FVector(1.0f, 1.0f, 1.0f));
	this->BoxCollision->AttachToComponent(this->RootComponent, FAttachmentTransformRules::SnapToTargetNotIncludingScale);

}

// Called when the game starts or when spawned
void ALiftPickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALiftPickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


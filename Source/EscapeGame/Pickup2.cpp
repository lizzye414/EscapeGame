// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickup2.h"

// Sets default values
APickup2::APickup2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PickupSM = CreateDefaultSubobject<UStaticMeshComponent>(FName("PickupSM"));
	
}

// Called when the game starts or when spawned
void APickup2::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickup2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APickup2::SetGlowEffect(bool Status)
{
	PickupSM->SetRenderCustomDepth(Status);
}







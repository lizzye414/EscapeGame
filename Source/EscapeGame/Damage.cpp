// Fill out your copyright notice in the Description page of Project Settings.

#include "EscapeGameCharacter.h"
#include "Damage.h"

// Sets default values
ADamage::ADamage()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	if (!RootComponent)
	{
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("DamageRoot"));
	}

	DamageSM = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DamageSM"));
	DamageSM->SetupAttachment(RootComponent);

	DamageSM->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));

	DamageBC = CreateDefaultSubobject<UBoxComponent>(TEXT("DamageBC"));
	DamageBC->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ADamage::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADamage::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}





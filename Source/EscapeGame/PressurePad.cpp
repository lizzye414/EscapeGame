// Fill out your copyright notice in the Description page of Project Settings.

#include "PressurePad.h"
#include "Pickup2.h"


// Sets default values
APressurePad::APressurePad()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("MyBoxComponent"));
	BoxComp->InitBoxExtent(FVector(150, 100, 100));
	BoxComp->SetCollisionProfileName("Trigger");
	RootComponent = BoxComp;

	bIsPressed = false;

}

// Called when the game starts or when spawned
void APressurePad::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APressurePad::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APressurePad::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	if (OtherActor && (OtherActor != this) && OtherComp && OtherActor->GetClass()->IsChildOf(APickup2::StaticClass()))
	{
		bIsPressed = true;
		UE_LOG(LogTemp, Warning, TEXT("Pressure pad %s was pressed"), *GetOwner()->GetName());
	}

}

void APressurePad::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		bIsPressed = false;
		UE_LOG(LogTemp, Warning, TEXT("Pressure pad %s was released"), *GetOwner()->GetName());
	}

}


// Fill out your copyright notice in the Description page of Project Settings.


#include "PickUp.h"
#include "Engine/Engine.h"

// Sets default values
APickUp::APickUp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	RootComponent = StaticMesh;

	this->BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	//this->BoxCollision->SetGenerateOverlapEvents(true);
	//this->BoxCollision->SetWorldScale3D(FVector(1.0f, 1.0f, 1.0f));
	//this->BoxCollision->AttachToComponent(this->RootComponent, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	this->BoxCollision->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void APickUp::BeginPlay()
{

	this->BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &APickUp::OnOverlapBegin);

	Super::BeginPlay();
	
}

// Called every frame
void APickUp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Handle overlaps
void APickUp::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Check if other actor is null pointer and not itself
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr)) 
	{
		//FString pickup = FString::Printf(TEXT("Picked up %s"), *GetName());
		//GEngine->AddOnScreenDebugMessage(1, 5, FColor::White, pickup);

		//Destroy();
	}
}


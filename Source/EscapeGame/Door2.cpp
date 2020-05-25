// Fill out your copyright notice in the Description page of Project Settings.


#include "Door2.h"
#include "UObject/ConstructorHelpers.h"
#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ADoor2::ADoor2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("MyBoxComponent"));
	BoxComp->InitBoxExtent(FVector(150, 100, 100));
	BoxComp->SetCollisionProfileName("Trigger");
	RootComponent = BoxComp;

	Door = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door"));
	Door->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> DoorAsset(TEXT("/Game/StarterContent/Props/SM_Door.SM_Door"));

	if (DoorAsset.Succeeded())
	{
		Door->SetStaticMesh(DoorAsset.Object);
		Door->SetRelativeLocation(FVector(0.0f, 50.0f, -100.0f));
		Door->SetWorldScale3D(FVector(1.f));
	}

	isClosed = true;

	Opening = false;
	Closing = false;

	DotP = 0.0f;
	MaxDegree = 0.0f;
	AddRotation = 0.0f;
	PosNeg = 0.0f;
	DoorCurrentRotation = 0.0f;

}

// Called when the game starts or when spawned
void ADoor2::BeginPlay()
{
	Super::BeginPlay();

	DrawDebugBox(GetWorld(), GetActorLocation(), BoxComp->GetScaledBoxExtent(), FQuat(GetActorRotation()), FColor::Turquoise, true, -1, 0, 2);
}
	

// Called every frame
void ADoor2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Opening)
	{
		OpenDoor(DeltaTime);
	}

	if (Closing)
	{
		CloseDoor(DeltaTime);
	}

}

void ADoor2::OpenDoor(float dt)
{

	DoorCurrentRotation = Door->GetRelativeRotation().Yaw;

	AddRotation = PosNeg * dt * 80;

	if (FMath::IsNearlyEqual(DoorCurrentRotation, MaxDegree, 1.5f))
	{
		Closing = false;
		Opening = false;
	}
	else if (Opening)
	{
		FRotator NewRotation = FRotator(0.0f, AddRotation, 0.0f);
		Door->AddRelativeRotation(FQuat(NewRotation), false, 0, ETeleportType::None);
	}

}

void ADoor2::CloseDoor(float dt)
{

	DoorCurrentRotation = Door->GetRelativeRotation().Yaw;

	if (DoorCurrentRotation > 0)
	{
		AddRotation = -dt * 80;
	}
	else
	{
		AddRotation = dt * 80;
	}

	if (FMath::IsNearlyEqual(DoorCurrentRotation, 0.0f, 1.5f))
	{
		Closing = false;
		Opening = false;
	}
	else if (Closing)
	{
		FRotator NewRotation = FRotator(0.0f, AddRotation, 0.0f);
		Door->AddRelativeRotation(FQuat(NewRotation), false, 0, ETeleportType::None);
	}

}

void ADoor2::MoveDoor(FVector ForwardVector)
{

	// is the chacter in front or behind the door
	DotP = FVector::DotProduct(BoxComp->GetForwardVector(), ForwardVector);

	// get 1 or -1 from the the dot product
	PosNeg = FMath::Sign(DotP);

	// degree to clamp at
	MaxDegree = PosNeg * 90.0f;

	// toggle bools
	if (isClosed) {
		isClosed = false;
		Closing = false;
		Opening = true;

	}
	else {
		Opening = false;
		isClosed = true;
		Closing = true;
	}

}


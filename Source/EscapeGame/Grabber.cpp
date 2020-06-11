// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabber.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/Actor.h"


// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	//FindPhysicsHandleComponent();

	//AttachInputComponent();
	
}



void UGrabber::FindPhysicsHandleComponent()
{
	/// Look for attached physics handle
	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();

	if (PhysicsHandle)
	{
		// Physics Handle is found
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("%s missing physics handle"), *GetOwner()->GetName());
	}
}

void UGrabber::AttachInputComponent()
{
	/// Look for attached input component
	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();

	if (InputComponent)
	{
		UE_LOG(LogTemp, Error, TEXT("%s has an input component"), *GetOwner()->GetName());

		//InputComponent->BindAction("Grab", IE_Pressed, this, &UGrabber::Grab);
		//InputComponent->BindAction("Grab", IE_Released, this, &UGrabber::Release);

	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("%s missing input component"), *GetOwner()->GetName());
	}
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//FVector PlayerViewPointLocation;
	//FRotator PlayerViewPointRotation;
	//GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(PlayerViewPointLocation, PlayerViewPointRotation);

	//FVector LineTraceEnd = PlayerViewPointLocation + PlayerViewPointRotation.Vector() * Reach;

	//if (PhysicsHandle->GrabbedComponent)
	//{

	//	PhysicsHandle->SetTargetLocation(LineTraceEnd);

	//}

}

void UGrabber::Grab()
{

	auto HitResult = GetFirstPhysicsBodyInReach();

	auto ComponentToGrab = HitResult.GetComponent();
	auto ActorHit = HitResult.GetActor();

	if (ActorHit)
	{
		PhysicsHandle->GrabComponentAtLocation(ComponentToGrab, NAME_None, ComponentToGrab->GetOwner()->GetActorLocation());
		UE_LOG(LogTemp, Warning, TEXT("Grabber is grabbing"));
	}
}

void UGrabber::Release()
{

	PhysicsHandle->ReleaseComponent();
	UE_LOG(LogTemp, Warning, TEXT("Grab released"));

}

const FHitResult UGrabber::GetFirstPhysicsBodyInReach()
{
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(PlayerViewPointLocation, PlayerViewPointRotation);


	FVector LineTraceEnd = PlayerViewPointLocation + PlayerViewPointRotation.Vector() * Reach;


	FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetOwner());
	FHitResult Hit;

	GetWorld()->LineTraceSingleByObjectType(Hit, PlayerViewPointLocation, LineTraceEnd, ECollisionChannel::ECC_PhysicsBody, TraceParameters);

	AActor* ActorHit = Hit.GetActor();

	if (ActorHit)
	{
		UE_LOG(LogTemp, Warning, TEXT("You saw %s"), *(ActorHit->GetName()));
	}

	return Hit;
}


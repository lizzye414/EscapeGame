// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "EscapeGameCharacter.h"
#include "Math/Vector.h"
#include "EscapeGameProjectile.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/InputSettings.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "MotionControllerComponent.h"
#include "MyTriggerVolume.h"
#include "MyPlayerController.h"
#include "Components/TextBlock.h"
#include "XRMotionControllerBase.h" // for FXRMotionControllerBase::RightHandSourceId

DEFINE_LOG_CATEGORY_STATIC(LogFPChar, Warning, All);

//////////////////////////////////////////////////////////////////////////
// AEscapeGameCharacter

AEscapeGameCharacter::AEscapeGameCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->SetRelativeLocation(FVector(-39.56f, 1.75f, 64.f)); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	Mesh1P->SetOnlyOwnerSee(true);
	Mesh1P->SetupAttachment(FirstPersonCameraComponent);
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->CastShadow = false;
	Mesh1P->SetRelativeRotation(FRotator(1.9f, -19.19f, 5.2f));
	Mesh1P->SetRelativeLocation(FVector(-0.5f, -4.4f, -155.7f));

	// Create a gun mesh component
	FP_Gun = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FP_Gun"));
	FP_Gun->SetOnlyOwnerSee(true);			// only the owning player will see this mesh
	FP_Gun->bCastDynamicShadow = false;
	FP_Gun->CastShadow = false;
	// FP_Gun->SetupAttachment(Mesh1P, TEXT("GripPoint"));
	FP_Gun->SetupAttachment(RootComponent);

	FP_MuzzleLocation = CreateDefaultSubobject<USceneComponent>(TEXT("MuzzleLocation"));
	FP_MuzzleLocation->SetupAttachment(FP_Gun);
	FP_MuzzleLocation->SetRelativeLocation(FVector(0.2f, 48.4f, -10.6f));

	// Default offset from the character location for projectiles to spawn
	GunOffset = FVector(100.0f, 0.0f, 10.0f);

	// Note: The ProjectileClass and the skeletal mesh/anim blueprints for Mesh1P, FP_Gun, and VR_Gun 
	// are set in the derived blueprint asset named MyCharacter to avoid direct content references in C++.

	// Create VR Controllers.
	R_MotionController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("R_MotionController"));
	R_MotionController->MotionSource = FXRMotionControllerBase::RightHandSourceId;
	R_MotionController->SetupAttachment(RootComponent);
	L_MotionController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("L_MotionController"));
	L_MotionController->SetupAttachment(RootComponent);

	// Create a gun and attach it to the right-hand VR controller.
	// Create a gun mesh component
	VR_Gun = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("VR_Gun"));
	VR_Gun->SetOnlyOwnerSee(true);			// only the owning player will see this mesh
	VR_Gun->bCastDynamicShadow = false;
	VR_Gun->CastShadow = false;
	VR_Gun->SetupAttachment(R_MotionController);
	VR_Gun->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));

	VR_MuzzleLocation = CreateDefaultSubobject<USceneComponent>(TEXT("VR_MuzzleLocation"));
	VR_MuzzleLocation->SetupAttachment(VR_Gun);
	VR_MuzzleLocation->SetRelativeLocation(FVector(0.000004, 53.999992, 10.000000));
	VR_MuzzleLocation->SetRelativeRotation(FRotator(0.0f, 90.0f, 0.0f));		// Counteract the rotation of the VR gun model.

	// Uncomment the following line to turn motion controllers on by default:
	//bUsingMotionControllers = true;

	// Set up the Trigger capsule
	TriggerCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Trigger Capsule"));
	TriggerCapsule->InitCapsuleSize(55.f, 96.0f);;
	TriggerCapsule->SetCollisionProfileName(TEXT("Trigger"));
	TriggerCapsule->SetupAttachment(RootComponent);

	// bind trigger events
	TriggerCapsule->OnComponentBeginOverlap.AddDynamic(this, &AEscapeGameCharacter::OnOverlapBegin);
	TriggerCapsule->OnComponentEndOverlap.AddDynamic(this, &AEscapeGameCharacter::OnOverlapEnd);

	CurrentDoor = NULL;
	MaxHealth = 100.0f;
	CurrentHealth = 100.0f;
	isAlive = true;

}

void AEscapeGameCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	//Attach gun mesh component to Skeleton, doing it here because the skeleton is not yet created in the constructor
	FP_Gun->AttachToComponent(Mesh1P, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), TEXT("GripPoint"));

	// Show or hide the two versions of the gun based on whether or not we're using motion controllers.
	if (bUsingMotionControllers)
	{
		VR_Gun->SetHiddenInGame(false, true);
		Mesh1P->SetHiddenInGame(true, true);
	}
	else
	{
		VR_Gun->SetHiddenInGame(true, true);
		Mesh1P->SetHiddenInGame(false, true);
	}

	//Initializing our reference to pickup2
	LastItemSeen = nullptr;

	FindPhysicsHandleComponent();
}

//////////////////////////////////////////////////////////////////////////
// Input

void AEscapeGameCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// set up gameplay key bindings
	check(PlayerInputComponent);

	// Bind jump events
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	// Bind fire event
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AEscapeGameCharacter::OnFire);

	// Enable touchscreen input
	EnableTouchscreenMovement(PlayerInputComponent);

	PlayerInputComponent->BindAction("ResetVR", IE_Pressed, this, &AEscapeGameCharacter::OnResetVR);

	// Bind movement events
	PlayerInputComponent->BindAxis("MoveForward", this, &AEscapeGameCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AEscapeGameCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AEscapeGameCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AEscapeGameCharacter::LookUpAtRate);

	//Action mapping of pickup item
	InputComponent->BindAction("Pickup", IE_Pressed, this, &AEscapeGameCharacter::PickupItem);

	// Action mapping of opening and closing inventory
	InputComponent->BindAction("Inventory", IE_Pressed, this, &AEscapeGameCharacter::HandleInventoryInput);

	// Action mapping of opening and closing the doors
	InputComponent->BindAction("OpenDoor", IE_Pressed, this, &AEscapeGameCharacter::OnAction);

	// Action mapping of grabbing and releasing an object
	InputComponent->BindAction("Grab", IE_Pressed, this, &AEscapeGameCharacter::Grab);
	InputComponent->BindAction("Grab", IE_Released, this, &AEscapeGameCharacter::Release);

	//Action mapping of showing and hiding the controls
	InputComponent->BindAction("Controls", IE_Pressed, this, &AEscapeGameCharacter::ShowHideControls);

	//Action mapping of pause menu
	InputComponent->BindAction("Pause", IE_Pressed, this, &AEscapeGameCharacter::PauseGame);

}

void AEscapeGameCharacter::OnFire()
{
	// try and fire a projectile
	if (ProjectileClass != NULL)
	{
		UWorld* const World = GetWorld();
		if (World != NULL)
		{
			if (bUsingMotionControllers)
			{
				const FRotator SpawnRotation = VR_MuzzleLocation->GetComponentRotation();
				const FVector SpawnLocation = VR_MuzzleLocation->GetComponentLocation();
				World->SpawnActor<AEscapeGameProjectile>(ProjectileClass, SpawnLocation, SpawnRotation);
			}
			else
			{
				const FRotator SpawnRotation = GetControlRotation();
				// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
				const FVector SpawnLocation = ((FP_MuzzleLocation != nullptr) ? FP_MuzzleLocation->GetComponentLocation() : GetActorLocation()) + SpawnRotation.RotateVector(GunOffset);

				//Set Spawn Collision Handling Override
				FActorSpawnParameters ActorSpawnParams;
				ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

				// spawn the projectile at the muzzle
				World->SpawnActor<AEscapeGameProjectile>(ProjectileClass, SpawnLocation, SpawnRotation, ActorSpawnParams);
			}
		}
	}

	// try and play the sound if specified
	if (FireSound != NULL)
	{
		UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
	}

	// try and play a firing animation if specified
	if (FireAnimation != NULL)
	{
		// Get the animation object for the arms mesh
		UAnimInstance* AnimInstance = Mesh1P->GetAnimInstance();
		if (AnimInstance != NULL)
		{
			AnimInstance->Montage_Play(FireAnimation, 1.f);
		}
	}
}

void AEscapeGameCharacter::OnResetVR()
{
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

void AEscapeGameCharacter::BeginTouch(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	if (TouchItem.bIsPressed == true)
	{
		return;
	}
	if ((FingerIndex == TouchItem.FingerIndex) && (TouchItem.bMoved == false))
	{
		OnFire();
	}
	TouchItem.bIsPressed = true;
	TouchItem.FingerIndex = FingerIndex;
	TouchItem.Location = Location;
	TouchItem.bMoved = false;
}

void AEscapeGameCharacter::EndTouch(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	if (TouchItem.bIsPressed == false)
	{
		return;
	}
	TouchItem.bIsPressed = false;
}

//Commenting this section out to be consistent with FPS BP template.
//This allows the user to turn without using the right virtual joystick

//void AEscapeGameCharacter::TouchUpdate(const ETouchIndex::Type FingerIndex, const FVector Location)
//{
//	if ((TouchItem.bIsPressed == true) && (TouchItem.FingerIndex == FingerIndex))
//	{
//		if (TouchItem.bIsPressed)
//		{
//			if (GetWorld() != nullptr)
//			{
//				UGameViewportClient* ViewportClient = GetWorld()->GetGameViewport();
//				if (ViewportClient != nullptr)
//				{
//					FVector MoveDelta = Location - TouchItem.Location;
//					FVector2D ScreenSize;
//					ViewportClient->GetViewportSize(ScreenSize);
//					FVector2D ScaledDelta = FVector2D(MoveDelta.X, MoveDelta.Y) / ScreenSize;
//					if (FMath::Abs(ScaledDelta.X) >= 4.0 / ScreenSize.X)
//					{
//						TouchItem.bMoved = true;
//						float Value = ScaledDelta.X * BaseTurnRate;
//						AddControllerYawInput(Value);
//					}
//					if (FMath::Abs(ScaledDelta.Y) >= 4.0 / ScreenSize.Y)
//					{
//						TouchItem.bMoved = true;
//						float Value = ScaledDelta.Y * BaseTurnRate;
//						AddControllerPitchInput(Value);
//					}
//					TouchItem.Location = Location;
//				}
//				TouchItem.Location = Location;
//			}
//		}
//	}
//}

void AEscapeGameCharacter::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void AEscapeGameCharacter::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorRightVector(), Value);
	}
}

void AEscapeGameCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AEscapeGameCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

bool AEscapeGameCharacter::EnableTouchscreenMovement(class UInputComponent* PlayerInputComponent)
{
	if (FPlatformMisc::SupportsTouchInput() || GetDefault<UInputSettings>()->bUseMouseForTouch)
	{
		PlayerInputComponent->BindTouch(EInputEvent::IE_Pressed, this, &AEscapeGameCharacter::BeginTouch);
		PlayerInputComponent->BindTouch(EInputEvent::IE_Released, this, &AEscapeGameCharacter::EndTouch);

		//Commenting this out to be more consistent with FPS BP template.
		//PlayerInputComponent->BindTouch(EInputEvent::IE_Repeat, this, &AEscapeGameCharacter::TouchUpdate);
		return true;
	}
	
	return false;
}

/// Raycast to make interactable items glow and be picked up
FHitResult AEscapeGameCharacter::Raycast()
{
	FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetOwner());
	FHitResult RaycastHit;

	GetWorld()->LineTraceSingleByObjectType(RaycastHit, GetPlayerViewPointLocation(), GetLineTraceEnd(), ECollisionChannel::ECC_PhysicsBody, TraceParameters);

	APickup2* Pickup = Cast<APickup2>(RaycastHit.GetActor());

	if (LastItemSeen && LastItemSeen != Pickup)
	{
		//If our character sees a different pickup then disable the glowing effect on the previous seen item
		LastItemSeen->SetGlowEffect(false);
	}

	if (Pickup)
	{
		//Enable the glow effect on the current item
		LastItemSeen = Pickup;
		Pickup->SetGlowEffect(true);
	}//Re-Initialize 
	else LastItemSeen = nullptr;

	return RaycastHit;

}

FVector AEscapeGameCharacter::GetLineTraceEnd()
{
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(PlayerViewPointLocation, PlayerViewPointRotation);

	FVector LineTraceEnd = PlayerViewPointLocation + PlayerViewPointRotation.Vector() * RaycastRange;

	return LineTraceEnd;
}

FVector AEscapeGameCharacter::GetPlayerViewPointLocation()
{
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(PlayerViewPointLocation, PlayerViewPointRotation);
	return PlayerViewPointLocation;
}

void AEscapeGameCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	//Raycast every frame
	Raycast();

	/// If an object has been grabbed hold it away from the camera
	if (PhysicsHandle->GrabbedComponent)
	{

		PhysicsHandle->SetTargetLocation(GetLineTraceEnd());

	}

	/// If overlapping Damage update the CurrentHealth each tick
	if (CurrentHealth > 0.0f && CurrentDamage)
	{
		CurrentHealth -= CurrentDamage->DamageAmount;

		if (CurrentHealth <= 0.0f)
		{
			CurrentHealth = 0.0f;
			isAlive = false;
			ShowRestart();
		}
	}

}

void AEscapeGameCharacter::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	/// Handle seeing a door
	if (OtherActor && (OtherActor != this) && OtherComp && OtherActor->GetClass()->IsChildOf(ADoor::StaticClass()))
	{
		CurrentDoor = Cast<ADoor>(OtherActor);
	}

	/// Handle stepping into a damage area
	if (OtherActor && (OtherActor != this) && OtherComp && OtherActor->GetClass()->IsChildOf(ADamage::StaticClass()))
	{
		CurrentDamage = Cast<ADamage>(OtherActor);

	}

	/// Handle moving over a health pack
	if (OtherActor && (OtherActor != this) && OtherComp && OtherActor->GetClass()->IsChildOf(APickUp::StaticClass()))
	{

		CurrentPickUp = Cast<APickUp>(OtherActor);

		if (CurrentPickUp)
		{
			if (CurrentHealth < 100.0f)
			{
				CurrentHealth += 20.0f;
				CurrentPickUp->Destroy();

				if (CurrentHealth > 100.0f)
				{
					CurrentHealth = 100.0f;
				}
			}
		}
	}

}

void AEscapeGameCharacter::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

	if (OtherActor && (OtherActor != this) && OtherComp && OtherActor->GetClass()->IsChildOf(ADoor::StaticClass()))
	{
		CurrentDoor = nullptr;
	}

	if (OtherActor && (OtherActor != this) && OtherComp && OtherActor->GetClass()->IsChildOf(ADamage::StaticClass()))
	{
		CurrentDamage = nullptr;
	}

	if (OtherActor && (OtherActor != this) && OtherComp && OtherActor->GetClass()->IsChildOf(APickUp::StaticClass()))
	{
		CurrentPickUp = nullptr;
	}

}

/// Picking up an item to put in inventory
void AEscapeGameCharacter::PickupItem()
{
	if (LastItemSeen)
	{

		FString ItemName = LastItemSeen->GetItemName();
		AMyPlayerController* Con = Cast<AMyPlayerController>(GetController());

		if (!ItemName.Compare("Cone"))
		{
			NumCones++;
			LastItemSeen->Destroy();
			Con->UpdateInventory();
		}
		else if (!ItemName.Compare("Cube"))
		{
			NumCubes++;
			LastItemSeen->Destroy();
			Con->UpdateInventory();
		}
		else if(!ItemName.Compare("Cylinder"))
		{
			NumCylinders++;
			LastItemSeen->Destroy();
			Con->UpdateInventory();
		}

	}
}

/// Calling the controller to show the inventory
void AEscapeGameCharacter::HandleInventoryInput()
{
	AMyPlayerController* Con = Cast<AMyPlayerController>(GetController());
	if (Con) {
		Con->HandleInventoryInput();
	}
}

/// Opening different types of door
void AEscapeGameCharacter::OnAction()
{

	FVector ForwardVector = FirstPersonCameraComponent->GetForwardVector();
	AMyPlayerController* Con = Cast<AMyPlayerController>(GetController());

	// door opens only if the player holds the correct shape, solved the puzzle or is already unlocked
	if (CurrentDoor && Con)
	{

		FString TypeNeeded = CurrentDoor->Type;

		if (!CurrentDoor->isClosed || CurrentDoor->isUnlocked) 
		{
			CurrentDoor->MoveDoor(ForwardVector);
		}
		else if (!TypeNeeded.Compare("Cone") && CurrentDoor->isClosed && NumCones > 0)
		{
				CurrentDoor->MoveDoor(ForwardVector);
				CurrentDoor->isUnlocked = true;
				NumCones--;
		}
		else if (!TypeNeeded.Compare("Cube") && CurrentDoor->isClosed && NumCubes > 0)
		{
				CurrentDoor->MoveDoor(ForwardVector);
				CurrentDoor->isUnlocked = true;
				NumCubes--;
		}
		else if (!TypeNeeded.Compare("Cylinder") && CurrentDoor->isClosed && NumCylinders > 0)
		{
				CurrentDoor->MoveDoor(ForwardVector);
				CurrentDoor->isUnlocked = true;
				NumCylinders--;
		}
		else if (!TypeNeeded.Compare("Puzzle") && CurrentDoor->isClosed && Trigger1Pressed && Trigger2Pressed && Trigger3Pressed)
		{
					Con->ShowWin();
		}
		else if (!TypeNeeded.Compare("Puzzle2") && CurrentDoor->isClosed && Trigger4Pressed)
		{
				CurrentDoor->MoveDoor(ForwardVector);
				CurrentDoor->isUnlocked = true;
		}
		else
		{
				Con->DisplayMessage();
		}

		Con->UpdateInventory();
		
	}

}

/// Picking up and carrying around an object
void AEscapeGameCharacter::Grab()
{
	
	auto HitResult = Raycast();

	auto ComponentToGrab = HitResult.GetComponent();
	auto ActorHit = HitResult.GetActor();

	if (ActorHit)
	{
		PhysicsHandle->GrabComponentAtLocation(ComponentToGrab, NAME_None, ComponentToGrab->GetOwner()->GetActorLocation());
	}

}


/// Putting down an object
void AEscapeGameCharacter::Release()
{

	PhysicsHandle->ReleaseComponent();

}


void AEscapeGameCharacter::FindPhysicsHandleComponent()
{

	PhysicsHandle = this->FindComponentByClass<UPhysicsHandleComponent>();

}

/// Showing the restart menu
void AEscapeGameCharacter::ShowRestart()
{
	AMyPlayerController* Con = Cast<AMyPlayerController>(GetController());
	if (Con) {
		Con->ShowRestart();
	}
}

/// Showing and hiding the Controls information
void AEscapeGameCharacter::ShowHideControls()
{
	AMyPlayerController* Con = Cast<AMyPlayerController>(GetController());
	if (Con) {
		Con->ShowHideControls();
	}
}

void AEscapeGameCharacter::PauseGame()
{
	AMyPlayerController* Con = Cast<AMyPlayerController>(GetController());
	if (Con) {
		Con->PauseGame();
	}
}



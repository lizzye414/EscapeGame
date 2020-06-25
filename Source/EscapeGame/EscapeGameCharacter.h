// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Pickup2.h"
#include "Door.h"
#include "Damage.h"
#include "PickUp.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "EscapeGameCharacter.generated.h"


class UInputComponent;

UCLASS(config=Game)
class AEscapeGameCharacter : public ACharacter
{
	GENERATED_BODY()

		/** Pawn mesh: 1st person view (arms; seen only by self) */
		UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USkeletalMeshComponent* Mesh1P;

	/** Gun mesh: 1st person view (seen only by self) */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USkeletalMeshComponent* FP_Gun;

	/** Location on gun mesh where projectiles should spawn. */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USceneComponent* FP_MuzzleLocation;

	/** Gun mesh: VR view (attached to the VR controller directly, no arm, just the actual gun) */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USkeletalMeshComponent* VR_Gun;

	/** Location on VR gun mesh where projectiles should spawn. */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USceneComponent* VR_MuzzleLocation;

	/** First person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FirstPersonCameraComponent;

	/** Motion controller (right hand) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UMotionControllerComponent* R_MotionController;

	/** Motion controller (left hand) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UMotionControllerComponent* L_MotionController;

public:
	AEscapeGameCharacter();

protected:
	virtual void BeginPlay();

public:
	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseLookUpRate;

	/** Gun muzzle's offset from the characters location */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		FVector GunOffset;

	/** Projectile class to spawn */
	UPROPERTY(EditDefaultsOnly, Category = Projectile)
		TSubclassOf<class AEscapeGameProjectile> ProjectileClass;

	/** Sound to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		class USoundBase* FireSound;

	/** AnimMontage to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		class UAnimMontage* FireAnimation;

	/** Whether to use motion controller location for aiming. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		uint32 bUsingMotionControllers : 1;

protected:

	/** Fires a projectile. */
	void OnFire();

	/** Resets HMD orientation and position in VR. */
	void OnResetVR();

	/** Handles moving forward/backward */
	void MoveForward(float Val);

	/** Handles stafing movement, left and right */
	void MoveRight(float Val);

	/**
	 * Called via input to turn at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	struct TouchData
	{
		TouchData() { bIsPressed = false; Location = FVector::ZeroVector; }
		bool bIsPressed;
		ETouchIndex::Type FingerIndex;
		FVector Location;
		bool bMoved;
	};
	void BeginTouch(const ETouchIndex::Type FingerIndex, const FVector Location);
	void EndTouch(const ETouchIndex::Type FingerIndex, const FVector Location);
	void TouchUpdate(const ETouchIndex::Type FingerIndex, const FVector Location);
	TouchData	TouchItem;

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;
	// End of APawn interface

	/*
	 * Configures input for touchscreen devices if there is a valid touch interface for doing so
	 *
	 * @param	InputComponent	The input component pointer to bind controls to
	 * @returns true if touch controls were enabled.
	 */
	bool EnableTouchscreenMovement(UInputComponent* InputComponent);

public:
	/** Returns Mesh1P subobject **/
	FORCEINLINE class USkeletalMeshComponent* GetMesh1P() const { return Mesh1P; }
	/** Returns FirstPersonCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }




private:
	/*Raycasts in front of the character to find usable items*/
	UFUNCTION()
	FHitResult Raycast();

	/*Reference to the last seen pickup item. Nullptr if none*/
	UPROPERTY()
	APickup2* LastItemSeen;

	UPROPERTY(VisibleAnywhere, Category = "Trigger Capsule")
		class UCapsuleComponent* TriggerCapsule;

	UPROPERTY()
	FTimerHandle TimerHandle;

	UFUNCTION()
		FVector GetLineTraceEnd();

public:

	virtual void Tick(float DeltaSeconds) override;

	FORCEINLINE int32 GetNumCones() { return NumCones; }

	FORCEINLINE int32 GetNumCubes() { return NumCubes; }

	FORCEINLINE int32 GetNumCylinders() { return NumCylinders; }

	// declare overlap begin function for door
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// declare overlap end function for door
	UFUNCTION()
		void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UPROPERTY()
	class ADoor* CurrentDoor;

	UPROPERTY()
	class ADamage* CurrentDamage;

	UPROPERTY()
	class APickUp* CurrentPickUp;

	UPROPERTY(BlueprintReadOnly)
		float MaxHealth;

	UPROPERTY(BlueprintReadOnly)
		float CurrentHealth;
	
	UPROPERTY()
	bool isAlive;

	UPROPERTY()
	bool Trigger1Pressed = false;

	UPROPERTY()
	bool Trigger2Pressed = false;

	UPROPERTY()
	bool Trigger3Pressed = false;

	UPROPERTY()
	bool Trigger4Pressed = false;



protected:
	/*The range of the raycast*/
	UPROPERTY(EditAnywhere)
		float RaycastRange = 300.f;

	/*Handles the Pickup Input*/
	UFUNCTION()
		void PickupItem();

	// handle the inventory by sending information to controller
	UFUNCTION()
		void HandleInventoryInput();

	UPROPERTY(EditAnywhere)
		TSubclassOf<APickup2> PickupBPRef;

	UPROPERTY(EditAnywhere)
		int32 NumCones = 0;

	UPROPERTY(EditAnywhere)
		int32 NumCubes = 0;

	UPROPERTY(EditAnywhere)
		int32 NumCylinders = 0;

	UFUNCTION()
	void OnAction();

	UFUNCTION()
	void Grab();

	UFUNCTION()
	void Release();

	UFUNCTION()
	void FindPhysicsHandleComponent();

	UPROPERTY()
	UPhysicsHandleComponent* PhysicsHandle = nullptr;

	// Display restart option
	UFUNCTION()
		void ShowRestart();

	UFUNCTION()
		void ShowHideControls();


};
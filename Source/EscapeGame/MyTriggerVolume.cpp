// Fill out your copyright notice in the Description page of Project Settings.

#include "MyTriggerVolume.h"
#include "Kismet/GameplayStatics.h"
#include "MyPlayerController.h"
#include "GameFramework/PlayerController.h"

AMyTriggerVolume::AMyTriggerVolume()
{
    //Register Events
    OnActorBeginOverlap.AddDynamic(this, &AMyTriggerVolume::OnOverlapBegin);
    OnActorEndOverlap.AddDynamic(this, &AMyTriggerVolume::OnOverlapEnd);

    isPressed = false;
    CurrentPickup = nullptr;
}

// Called when the game starts or when spawned
void AMyTriggerVolume::BeginPlay()
{
    Super::BeginPlay();

    CurrentCharacter = GetWorld()->GetFirstPlayerController()->GetCharacter();

    if (CurrentCharacter)
    {
        EGCharacter = Cast<AEscapeGameCharacter>(CurrentCharacter);
    }

}


/// Triggers volume if not yet pressed and sets Trigger press on character to open puzzle doors
void AMyTriggerVolume::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
{
    if (OtherActor && (OtherActor != this) && OtherActor->GetClass()->IsChildOf(APickup2::StaticClass()) && !isPressed) {
        
        isPressed = true;
        CurrentPickup = Cast<APickup2>(OtherActor);

        if (EGCharacter && !Name.Compare("Trigger1"))
        {
            EGCharacter->Trigger1Pressed = true;
        }
        else if (EGCharacter && !Name.Compare("Trigger2"))
        {
            EGCharacter->Trigger2Pressed = true;
        }
        else if (EGCharacter && !Name.Compare("Trigger3"))
        {
            EGCharacter->Trigger3Pressed = true;
        }
        else if (EGCharacter && !Name.Compare("Trigger4"))
        {
            EGCharacter->Trigger4Pressed = true;
        }

    }
}

/// Removes trigger from volume only if the current pickup leaves volume, preventing false negatives from other pickups leaving area
void AMyTriggerVolume::OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor)
{
    if (OtherActor && (OtherActor != this) && OtherActor->GetClass()->IsChildOf(APickup2::StaticClass()) && (OtherActor == CurrentPickup)) {
        
        isPressed = false;
        CurrentPickup = nullptr;

        if (EGCharacter && !Name.Compare("Trigger1"))
        {
            EGCharacter->Trigger1Pressed = false;
        }
        else if (EGCharacter && !Name.Compare("Trigger2"))
        {
            EGCharacter->Trigger2Pressed = false;
        }
        else if (EGCharacter && !Name.Compare("Trigger3"))
        {
            EGCharacter->Trigger3Pressed = false;
        }

    }
}




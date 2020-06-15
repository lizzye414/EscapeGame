// Fill out your copyright notice in the Description page of Project Settings.

#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green,text)
#define printFString(text, fstring) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT(text), fstring))

#include "Pickup2.h"
#include "MyTriggerVolume.h"
#include "Kismet/GameplayStatics.h"
#include "MyPlayerController.h"
#include "GameFramework/PlayerController.h"
// include draw debug helpers header file
#include "DrawDebugHelpers.h"

AMyTriggerVolume::AMyTriggerVolume()
{
    //Register Events
    OnActorBeginOverlap.AddDynamic(this, &AMyTriggerVolume::OnOverlapBegin);
    OnActorEndOverlap.AddDynamic(this, &AMyTriggerVolume::OnOverlapEnd);

    isPressed = false;

}

// Called when the game starts or when spawned
void AMyTriggerVolume::BeginPlay()
{
    Super::BeginPlay();

    DrawDebugBox(GetWorld(), GetActorLocation(), GetActorScale() * 100, FColor::Cyan, true, -1, 0, 5);

    CurrentCharacter = GetWorld()->GetFirstPlayerController()->GetCharacter();

    if (CurrentCharacter)
    {
        EGCharacter = Cast<AEscapeGameCharacter>(CurrentCharacter);
    }

}

void AMyTriggerVolume::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
{
    if (OtherActor && (OtherActor != this) && OtherActor->GetClass()->IsChildOf(APickup2::StaticClass())) {
        
        isPressed = true;

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

    }
}

void AMyTriggerVolume::OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor)
{
    if (OtherActor && (OtherActor != this) && OtherActor->GetClass()->IsChildOf(APickup2::StaticClass())) {
        
        isPressed = false;

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




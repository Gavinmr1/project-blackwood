#include "BlackwoodInteractionComponent.h"
#include "BlackwoodInteractable.h"

UBlackwoodInteractionComponent::UBlackwoodInteractionComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UBlackwoodInteractionComponent::BeginPlay()
{
    Super::BeginPlay();
}

void UBlackwoodInteractionComponent::TryInteract()
{
    AActor* Owner = GetOwner();

    if (!Owner)
    {
        return;
    }

    FVector Start;
    FRotator Rotation;

    Owner->GetActorEyesViewPoint(Start, Rotation);

    const FVector End = Start + (Rotation.Vector() * InteractionDistance);

    FHitResult HitResult;
    FCollisionQueryParams QueryParams;
    QueryParams.AddIgnoredActor(Owner);

    const bool bHit = GetWorld()->LineTraceSingleByChannel(
        HitResult,
        Start,
        End,
        ECC_Visibility,
        QueryParams
    );

    if (!bHit)
    {
        UE_LOG(LogTemp, Warning, TEXT("Looking at: Nothing"));
        return;
    }

    AActor* HitActor = HitResult.GetActor();

    if (!HitActor)
    {
        return;
    }

    UE_LOG(LogTemp, Warning, TEXT("Looking at: %s"), *HitActor->GetName());

    if (HitActor->GetClass()->ImplementsInterface(UBlackwoodInteractable::StaticClass()))
    {
        IBlackwoodInteractable::Execute_Interact(HitActor, Owner);
    }
}
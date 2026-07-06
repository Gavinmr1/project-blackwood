#include "BlackwoodStaminaComponent.h"

UBlackwoodStaminaComponent::UBlackwoodStaminaComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
}

void UBlackwoodStaminaComponent::BeginPlay()
{
    Super::BeginPlay();

    CurrentStamina = MaxStamina;

}

void UBlackwoodStaminaComponent::TickComponent(
    float DeltaTime,
    ELevelTick TickType,
    FActorComponentTickFunction* ThisTickFunction
)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if (bIsSprinting && CanSprint())
    {
        CurrentStamina = FMath::Clamp(CurrentStamina - (DrainRate * DeltaTime), 0.f, MaxStamina);

        if (CurrentStamina <= 0.f)
        {
            bIsSprinting = false;
        }
    }
    else
    {
        CurrentStamina = FMath::Clamp(CurrentStamina + (RegenRate * DeltaTime), 0.f, MaxStamina);
    }
}

void UBlackwoodStaminaComponent::SetSprinting(bool bNewSprinting)
{
    bIsSprinting = bNewSprinting && CanSprint();
}

bool UBlackwoodStaminaComponent::CanSprint() const
{
    return CurrentStamina > 0.f;
}

float UBlackwoodStaminaComponent::GetStaminaPercent() const
{
    return MaxStamina > 0.f ? CurrentStamina / MaxStamina : 0.f;
}

bool UBlackwoodStaminaComponent::IsSprinting() const
{
    return bIsSprinting;
}
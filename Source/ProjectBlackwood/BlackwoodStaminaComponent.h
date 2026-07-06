#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BlackwoodStaminaComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PROJECTBLACKWOOD_API UBlackwoodStaminaComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UBlackwoodStaminaComponent();

    UFUNCTION(BlueprintCallable, Category = "Blackwood|Stamina")
    void SetSprinting(bool bNewSprinting);

    UFUNCTION(BlueprintPure, Category = "Blackwood|Stamina")
    bool IsSprinting() const;

    UFUNCTION(BlueprintPure, Category = "Blackwood|Stamina")
    bool CanSprint() const;

    UFUNCTION(BlueprintPure, Category = "Blackwood|Stamina")
    float GetStaminaPercent() const;

protected:
    virtual void BeginPlay() override;

    virtual void TickComponent(
        float DeltaTime,
        ELevelTick TickType,
        FActorComponentTickFunction* ThisTickFunction
    ) override;

private:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Blackwood|Stamina", meta = (AllowPrivateAccess = "true"))
    float MaxStamina = 100.f;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Blackwood|Stamina", meta = (AllowPrivateAccess = "true"))
    float CurrentStamina = 100.f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Blackwood|Stamina", meta = (AllowPrivateAccess = "true"))
    float DrainRate = 20.f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Blackwood|Stamina", meta = (AllowPrivateAccess = "true"))
    float RegenRate = 15.f;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Blackwood|Stamina", meta = (AllowPrivateAccess = "true"))
    bool bIsSprinting = false;
};
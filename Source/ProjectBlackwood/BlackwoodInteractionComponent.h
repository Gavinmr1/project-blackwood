#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BlackwoodInteractionComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PROJECTBLACKWOOD_API UBlackwoodInteractionComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UBlackwoodInteractionComponent();

    UFUNCTION(BlueprintCallable, Category = "Blackwood|Interaction")
    void TryInteract();

protected:
    virtual void BeginPlay() override;

private:
    UPROPERTY(EditAnywhere, BlueprintReadOnly,
        Category = "Blackwood|Interaction",
        meta = (AllowPrivateAccess = "true"))
    float InteractionDistance = 300.0f;
};
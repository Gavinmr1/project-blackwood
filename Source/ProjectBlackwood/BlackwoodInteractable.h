#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "BlackwoodInteractable.generated.h"

UINTERFACE(Blueprintable)
class PROJECTBLACKWOOD_API UBlackwoodInteractable : public UInterface
{
    GENERATED_BODY()
};

class PROJECTBLACKWOOD_API IBlackwoodInteractable
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Blackwood|Interaction")
    void Interact(AActor* InteractingActor);
};
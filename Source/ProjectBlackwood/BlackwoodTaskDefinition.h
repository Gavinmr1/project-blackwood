#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "BlackwoodTaskDefinition.generated.h"

UCLASS(BlueprintType)
class PROJECTBLACKWOOD_API UBlackwoodTaskDefinition : public UPrimaryDataAsset
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Blackwood|Task")
    FName TaskID;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Blackwood|Task")
    FText Title;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Blackwood|Task")
    FText Description;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Blackwood|Task")
    int32 TargetProgress = 1;
};
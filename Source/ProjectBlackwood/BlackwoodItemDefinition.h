#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "BlackwoodItemDefinition.generated.h"

UENUM(BlueprintType)
enum class EBlackwoodItemType : uint8
{
    Tool,
    Resource,
    Consumable,
    Key,
    Evidence,
    Story
};

UCLASS(BlueprintType)
class PROJECTBLACKWOOD_API UBlackwoodItemDefinition : public UPrimaryDataAsset
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Blackwood|Item")
    FName ItemID;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Blackwood|Item")
    FText DisplayName;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Blackwood|Item")
    FText Description;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Blackwood|Item")
    EBlackwoodItemType ItemType = EBlackwoodItemType::Resource;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Blackwood|Item")
    bool bCanEquip = false;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Blackwood|Item")
    int32 MaxStackSize = 1;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Blackwood|Item")
    float Weight = 0.f;
};
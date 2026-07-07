#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BlackwoodItemDefinition.h"
#include "BlackwoodInventoryComponent.generated.h"

USTRUCT(BlueprintType)
struct FBlackwoodInventoryItem
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blackwood|Inventory")
    TObjectPtr<UBlackwoodItemDefinition> ItemDefinition = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blackwood|Inventory")
    int32 Quantity = 0;
};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PROJECTBLACKWOOD_API UBlackwoodInventoryComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UBlackwoodInventoryComponent();

    UFUNCTION(BlueprintCallable, Category = "Blackwood|Inventory")
    void AddItem(UBlackwoodItemDefinition* ItemDefinition, int32 Quantity);

    UFUNCTION(BlueprintCallable, Category = "Blackwood|Inventory")
    bool RemoveItem(UBlackwoodItemDefinition* ItemDefinition, int32 Quantity);

    UFUNCTION(BlueprintPure, Category = "Blackwood|Inventory")
    bool HasItem(UBlackwoodItemDefinition* ItemDefinition, int32 Quantity) const;

    UFUNCTION(BlueprintPure, Category = "Blackwood|Inventory")
    int32 GetItemQuantity(UBlackwoodItemDefinition* ItemDefinition) const;

protected:
    virtual void BeginPlay() override;

private:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Blackwood|Inventory", meta = (AllowPrivateAccess = "true"))
    TArray<FBlackwoodInventoryItem> Items;
};
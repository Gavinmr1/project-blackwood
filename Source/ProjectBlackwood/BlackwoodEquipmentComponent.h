#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BlackwoodItemDefinition.h"
#include "BlackwoodInventoryComponent.h"
#include "BlackwoodEquipmentComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PROJECTBLACKWOOD_API UBlackwoodEquipmentComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UBlackwoodEquipmentComponent();

    UFUNCTION(BlueprintCallable, Category = "Blackwood|Equipment")
    void EquipItem(UBlackwoodItemDefinition* ItemDefinition);

    UFUNCTION(BlueprintCallable, Category = "Blackwood|Equipment")
    void UnequipItem();

    UFUNCTION(BlueprintPure, Category = "Blackwood|Equipment")
    UBlackwoodItemDefinition* GetEquippedItem() const;

    UFUNCTION(BlueprintPure, Category = "Blackwood|Equipment")
    UStaticMesh* GetEquippedMesh() const;

    UFUNCTION(BlueprintCallable, Category = "Blackwood|Equipment")
    void EquipPrimaryTool(const FBlackwoodInventoryItem& Item);

    UFUNCTION(BlueprintPure, Category = "Blackwood|Equipment")
    FBlackwoodInventoryItem GetEquippedPrimaryTool() const;

protected:
    virtual void BeginPlay() override;

private:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Blackwood|Equipment", meta = (AllowPrivateAccess = "true"))
    TObjectPtr<UBlackwoodItemDefinition> EquippedItem = nullptr;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Blackwood|Equipment", meta = (AllowPrivateAccess = "true"))
    FBlackwoodInventoryItem EquippedPrimaryTool;
};
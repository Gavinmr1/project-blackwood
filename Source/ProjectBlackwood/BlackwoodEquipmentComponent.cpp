#include "BlackwoodEquipmentComponent.h"

UBlackwoodEquipmentComponent::UBlackwoodEquipmentComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UBlackwoodEquipmentComponent::BeginPlay()
{
    Super::BeginPlay();
}

void UBlackwoodEquipmentComponent::EquipItem(UBlackwoodItemDefinition* ItemDefinition)
{
    if (!ItemDefinition || !ItemDefinition->bCanEquip)
    {
        return;
    }

    EquippedItem = ItemDefinition;
}

void UBlackwoodEquipmentComponent::UnequipItem()
{
    EquippedItem = nullptr;
}

UBlackwoodItemDefinition* UBlackwoodEquipmentComponent::GetEquippedItem() const
{
    return EquippedItem;
}

UStaticMesh* UBlackwoodEquipmentComponent::GetEquippedMesh() const
{
    if (!EquippedItem)
    {
        return nullptr;
    }

    return EquippedItem->EquippedMesh;
}
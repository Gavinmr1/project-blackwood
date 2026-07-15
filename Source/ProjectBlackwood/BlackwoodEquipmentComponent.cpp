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
    EquippedPrimaryTool = FBlackwoodInventoryItem();
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

void UBlackwoodEquipmentComponent::EquipPrimaryTool(const FBlackwoodInventoryItem& Item)
{
    if (!Item.ItemDefinition || Item.Quantity <= 0 || !Item.ItemDefinition->bCanEquip)
    {
        return;
    }

    EquippedPrimaryTool = Item;
    EquipItem(Item.ItemDefinition);
}

FBlackwoodInventoryItem UBlackwoodEquipmentComponent::GetEquippedPrimaryTool() const
{
    return EquippedPrimaryTool;
}
#include "BlackwoodInventoryComponent.h"

UBlackwoodInventoryComponent::UBlackwoodInventoryComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UBlackwoodInventoryComponent::BeginPlay()
{
    Super::BeginPlay();
}

void UBlackwoodInventoryComponent::AddItem(UBlackwoodItemDefinition* ItemDefinition, int32 Quantity)
{
    if (!ItemDefinition || Quantity <= 0)
    {
        return;
    }

    for (FBlackwoodInventoryItem& Item : Items)
    {
        if (Item.ItemDefinition == ItemDefinition)
        {
            Item.Quantity += Quantity;
            return;
        }
    }

    FBlackwoodInventoryItem NewItem;
    NewItem.ItemDefinition = ItemDefinition;
    NewItem.Quantity = Quantity;
    Items.Add(NewItem);
}

bool UBlackwoodInventoryComponent::RemoveItem(UBlackwoodItemDefinition* ItemDefinition, int32 Quantity)
{
    if (!ItemDefinition || Quantity <= 0)
    {
        return false;
    }

    for (int32 Index = 0; Index < Items.Num(); Index++)
    {
        if (Items[Index].ItemDefinition == ItemDefinition)
        {
            if (Items[Index].Quantity < Quantity)
            {
                return false;
            }

            Items[Index].Quantity -= Quantity;

            if (Items[Index].Quantity <= 0)
            {
                Items.RemoveAt(Index);
            }

            return true;
        }
    }

    return false;
}

bool UBlackwoodInventoryComponent::HasItem(UBlackwoodItemDefinition* ItemDefinition, int32 Quantity) const
{
    return GetItemQuantity(ItemDefinition) >= Quantity;
}

int32 UBlackwoodInventoryComponent::GetItemQuantity(UBlackwoodItemDefinition* ItemDefinition) const
{
    if (!ItemDefinition)
    {
        return 0;
    }

    for (const FBlackwoodInventoryItem& Item : Items)
    {
        if (Item.ItemDefinition == ItemDefinition)
        {
            return Item.Quantity;
        }
    }

    return 0;
}
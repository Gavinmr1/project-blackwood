#include "BlackwoodInventoryComponent.h"

UBlackwoodInventoryComponent::UBlackwoodInventoryComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UBlackwoodInventoryComponent::BeginPlay()
{
    Super::BeginPlay();
}

void UBlackwoodInventoryComponent::AddItem(FName ItemID, int32 Quantity)
{
    if (ItemID.IsNone() || Quantity <= 0)
    {
        return;
    }

    for (FBlackwoodInventoryItem& Item : Items)
    {
        if (Item.ItemID == ItemID)
        {
            Item.Quantity += Quantity;
            return;
        }
    }

    FBlackwoodInventoryItem NewItem;
    NewItem.ItemID = ItemID;
    NewItem.Quantity = Quantity;
    Items.Add(NewItem);
}

bool UBlackwoodInventoryComponent::RemoveItem(FName ItemID, int32 Quantity)
{
    if (ItemID.IsNone() || Quantity <= 0)
    {
        return false;
    }

    for (int32 Index = 0; Index < Items.Num(); Index++)
    {
        if (Items[Index].ItemID == ItemID)
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

bool UBlackwoodInventoryComponent::HasItem(FName ItemID, int32 Quantity) const
{
    return GetItemQuantity(ItemID) >= Quantity;
}

int32 UBlackwoodInventoryComponent::GetItemQuantity(FName ItemID) const
{
    for (const FBlackwoodInventoryItem& Item : Items)
    {
        if (Item.ItemID == ItemID)
        {
            return Item.Quantity;
        }
    }

    return 0;
}
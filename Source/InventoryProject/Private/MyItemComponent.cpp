#include "MyItemComponent.h"


UMyItemComponent::UMyItemComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UMyItemComponent::BeginPlay()
{
    Super::BeginPlay();

	for (const auto& Item : InventoryData)
	{
		DataDescription.Add(Item.ItemName, Item.Description);
		DataTitle.Add(Item.ItemName, Item.RequiredTitle);
	}
}

bool UMyItemComponent::CanUseItem(FName ItemName)
{
    if (!DataDescription.Contains(ItemName)) return false;

    if (!DataTitle.Contains(ItemName)) return false;
    
	if (AcquiredTitle.Contains(DataTitle[ItemName]))
	{
		return true;
	}

	return false;
}

bool UMyItemComponent::UseItem(FName ItemName)
{
    if (!CanUseItem(ItemName))
    {
        UE_LOG(LogTemp, Warning, TEXT("Requirements not met"));
        return false;
    }

    for (int32 i = 0; i < InventoryData.Num(); ++i)
    {
        if (InventoryData[i].ItemName == ItemName)
        {
            InventoryData[i].Quantity--;

            if (InventoryData[i].Quantity <= 0)
            {
                InventoryData.RemoveAt(i);
            }
            UE_LOG(LogTemp, Warning, TEXT("%s Quantity: %d"), *InventoryData[i].ItemName.ToString(), InventoryData[i].Quantity);
            return true;
        } 
    }
    return false;
}

FString UMyItemComponent::GetDataDescription(FName ItemName) const
{
    if (DataDescription.Contains(ItemName))
    {
        return DataDescription[ItemName];
    }
    return FString(TEXT("No Description"));
}

FName UMyItemComponent::GetDataTitle(FName ItemName) const
{
    if (DataTitle.Contains(ItemName))
    {
        return DataTitle[ItemName];
    }
    return NAME_None;
}
#include "MyUserWidgetInventory.h"
#include "Components/UniformGridPanel.h"
#include "MyUserWidget.h"
#include "MyItemComponent.h"

void UMyUserWidgetInventory::RefreshInventory(const TArray<FItemData>& Items)
{
	if (!GridInventory || !SlotWidgetClass) return;

    int32 ExistingChildren = GridInventory->GetChildrenCount();

    for (int32 i = 0; i < Items.Num(); ++i)
    {
        UMyUserWidget* TargetSlot = nullptr;

        if (i < ExistingChildren)
        {
            TargetSlot = Cast<UMyUserWidget>(GridInventory->GetChildAt(i));
        }
        else
        {
            TargetSlot = CreateWidget<UMyUserWidget>(this, SlotWidgetClass);
            if (TargetSlot)
            {
                int32 Row = i / ColumnCount;
                int32 Column = i % ColumnCount;
                GridInventory->AddChildToUniformGrid(TargetSlot, Row, Column);
            }
        }

        if (TargetSlot)
        {
            TargetSlot->UpdateSlot(Items[i]);
        }
    }

    while (GridInventory->GetChildrenCount() > Items.Num())
    {
        GridInventory->RemoveChildAt(GridInventory->GetChildrenCount() - 1);
    }

}

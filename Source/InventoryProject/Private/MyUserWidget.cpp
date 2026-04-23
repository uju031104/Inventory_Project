#include "MyUserWidget.h"
#include "MyUserWidgetInventory.h"
#include "MyItemComponent.h"
#include "MyCharacter.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/WidgetBlueprintLibrary.h"

void UMyUserWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (SlotButton)
	{
		SlotButton->OnClicked.AddDynamic(this, &UMyUserWidget::OnSlotClicked);
	}
}

void UMyUserWidget::OnSlotClicked()
{
    UE_LOG(LogTemp, Warning, TEXT("Slot Clicked: %s"), *CurrentItemName.ToString());

    AMyCharacter* MyChar = Cast<AMyCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
    if (MyChar && MyChar->InventoryComponent)
    {
        if (MyChar->InventoryComponent->UseItem(CurrentItemName))
        {
            if (MyChar->InventoryUI)
            {
                MyChar->InventoryUI->RefreshInventory(MyChar->InventoryComponent->InventoryData);
            }
        }
    }
}

void UMyUserWidget::UpdateSlot(FItemData NewData)
{
	if (ItemImage && NewData.Icon)
	{
		ItemImage->SetBrushFromTexture(NewData.Icon);
	}

	if (ItemText)
	{
		ItemText->SetText(FText::AsNumber(NewData.Quantity));
	}

    CurrentItemName = NewData.ItemName;
	ItemDescription = NewData.Description;
}


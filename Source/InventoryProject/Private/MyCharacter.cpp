#include "MyCharacter.h"
#include "MyItemComponent.h"
#include "MyUserWidgetInventory.h"
#include "Blueprint/UserWidget.h"

AMyCharacter::AMyCharacter()
{
 	
	PrimaryActorTick.bCanEverTick = false;
	InventoryComponent = CreateDefaultSubobject<UMyItemComponent>(TEXT("InventoryComponent"));
}

void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
    APlayerController* PC = Cast<APlayerController>(GetController());

    if (PC && InventoryWidgetClass)
    {
        InventoryUI = CreateWidget<UMyUserWidgetInventory>(PC, InventoryWidgetClass);

        if (InventoryUI)
        {
            InventoryUI->AddToViewport();

            if (InventoryComponent)
            {
                InventoryUI->RefreshInventory(InventoryComponent->InventoryData);
            }

            FInputModeGameAndUI InputMode;
            PC->SetInputMode(InputMode);
            PC->bShowMouseCursor = true;
        }
    }
}



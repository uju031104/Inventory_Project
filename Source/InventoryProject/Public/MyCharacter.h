#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

class UMyItemComponent;
class UMyUserWidgetInventory;

UCLASS()
class INVENTORYPROJECT_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AMyCharacter();

	virtual void BeginPlay() override;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory")
    TObjectPtr<UMyItemComponent> InventoryComponent;

    UPROPERTY(EditDefaultsOnly, Category = "UI")
    TSubclassOf<UMyUserWidgetInventory> InventoryWidgetClass;

    UPROPERTY()
    TObjectPtr<UMyUserWidgetInventory> InventoryUI;
};

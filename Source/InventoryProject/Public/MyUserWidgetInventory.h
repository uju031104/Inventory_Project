#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyUserWidgetInventory.generated.h"

class UUniformGridPanel;
class UMyUserWidget;
struct FItemData;

UCLASS()
class INVENTORYPROJECT_API UMyUserWidgetInventory : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UUniformGridPanel> GridInventory;

	UPROPERTY(EditDefaultsOnly, Category = "Inventory")
	TSubclassOf<UUserWidget> SlotWidgetClass;

	UPROPERTY(EditDefaultsOnly, Category = "Inventory")
	int32 ColumnCount = 5;

public:
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void RefreshInventory(const TArray<FItemData>& Items);
};

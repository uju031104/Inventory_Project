#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyUserWidget.generated.h"

class UImage;
class UTextBlock;
class UButton;
struct FItemData;

UCLASS()
class INVENTORYPROJECT_API UMyUserWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UImage> ItemImage;
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> ItemText;
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> SlotButton;
	UPROPERTY(BlueprintReadOnly, Category = "Inventory")
	FName CurrentItemName;
	UPROPERTY(BlueprintReadOnly, Category = "Inventory")
	FString ItemDescription;

	UFUNCTION()
	void OnSlotClicked();

	virtual void NativeConstruct() override;

public:
	void UpdateSlot(FItemData NewData);
};

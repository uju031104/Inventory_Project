#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MyItemComponent.generated.h"

USTRUCT(BlueprintType)
struct FItemData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite) 
	FName ItemName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) 
	UTexture2D* Icon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) 
	int32 Quantity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Description;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName RequiredTitle;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INVENTORYPROJECT_API UMyItemComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UMyItemComponent();

	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	TArray<FItemData> InventoryData;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	TMap<FName, FString> DataDescription;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	TMap<FName, FName> DataTitle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	TSet<FName> AcquiredTitle;

	UFUNCTION(BlueprintCallable)
	bool CanUseItem(FName ItemName);
	UFUNCTION(BlueprintCallable)
	bool UseItem(FName ItemName);
	UFUNCTION(BlueprintPure)
	FString GetDataDescription(FName ItemName) const;
	UFUNCTION(BlueprintPure)
	FName GetDataTitle(FName ItemName) const;
};

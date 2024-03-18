// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaginationDot.h"
#include "PaintingGridCard.h"
#include "Blueprint/UserWidget.h"
#include "Components/HorizontalBox.h"
#include "Components/UniformGridPanel.h"
#include "PaintingGrid.generated.h"

/**
 * 
 */
UCLASS()
class VRWIDGETSUI_API UPaintingGrid : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void AddPainting(int32 PaintingIndex, FString PaintingName);
	UFUNCTION()
	void ClearPaintings();
	void AddPaginationDot(bool Active);

	int32 GetNumberOfSlots();

	void ClearPaginationDots();


protected:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget))
	UUniformGridPanel* PaintingGrid;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget))
	UHorizontalBox* PaginationDots;

private:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UPaintingGridCard> GridCardClass;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UPaginationDot> PaginationDotClass;
	
};

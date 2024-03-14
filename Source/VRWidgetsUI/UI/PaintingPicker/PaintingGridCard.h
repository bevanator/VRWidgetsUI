// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "PaintingGridCard.generated.h"

/**
 * 
 */
UCLASS()
class VRWIDGETSUI_API UPaintingGridCard : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void CardButtonClicked();
	void SetPaintingName(FString NewPaintingName);

protected:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BIndWidget))
	UTextBlock* SlotNameText;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BIndWidget))
	UButton* CardButton;
	
	FString PaintingName;
};

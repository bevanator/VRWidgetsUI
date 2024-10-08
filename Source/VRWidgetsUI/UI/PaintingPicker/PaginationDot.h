// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "PaginationDot.generated.h"

/**
 * 
 */
UCLASS()
class VRWIDGETSUI_API UPaginationDot : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetActive(bool Active);

protected:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget))
	UImage* DotImage;
	
};

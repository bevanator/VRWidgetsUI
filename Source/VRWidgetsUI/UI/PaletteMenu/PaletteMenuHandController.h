// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "VRWidgetsUI/HandControllerBase.h"
#include "PaletteMenuHandController.generated.h"

/**
 * 
 */
UCLASS()
class VRWIDGETSUI_API APaletteMenuHandController : public AHandControllerBase
{
	GENERATED_BODY()
	APaletteMenuHandController();

	UPROPERTY(VisibleAnywhere)
	UWidgetComponent* PaletteMenu;
	
};

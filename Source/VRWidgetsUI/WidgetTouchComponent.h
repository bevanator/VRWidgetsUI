// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetInteractionComponent.h"
#include "WidgetTouchComponent.generated.h"

/**
 * 
 */
UCLASS(meta=(BlueprintSpawnableComponent))
class VRWIDGETSUI_API UWidgetTouchComponent : public UWidgetInteractionComponent
{
	GENERATED_BODY()

public:
	void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	//State
	bool bIsClicked = false;
};

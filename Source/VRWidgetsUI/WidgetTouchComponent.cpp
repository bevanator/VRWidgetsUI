// Fill out your copyright notice in the Description page of Project Settings.


#include "WidgetTouchComponent.h"

#include "Utilities/Logger.h"

void UWidgetTouchComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if(IsOverInteractableWidget() && !bIsClicked)
	{
		PressPointerKey(EKeys::LeftMouseButton);
		Logger::Log("Pressed over");
		bIsClicked = true;
	}
	if(!IsOverInteractableWidget() || bIsClicked)
	{
		ReleasePointerKey(EKeys::LeftMouseButton);
		Logger::Log("Released");
		bIsClicked = false;
	}
}

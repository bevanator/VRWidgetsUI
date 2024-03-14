// Fill out your copyright notice in the Description page of Project Settings.


#include "UIPointerHandController.h"

AUIPointerHandController::AUIPointerHandController()
{
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	Root->SetupAttachment(GetRootComponent());
	
	Pointer = CreateDefaultSubobject<UWidgetInteractionComponent>(TEXT("Pointer"));
	Pointer->SetupAttachment(Root);

	FRotator CurrentRotation = Root->GetComponentRotation();
	CurrentRotation.Pitch -= 80.0f;

	Root->SetWorldRotation(CurrentRotation);
	
}

void AUIPointerHandController::TriggerPressed()
{
	UE_LOG(LogTemp, Warning, TEXT("Pressed!"));
	Pointer->PressPointerKey(EKeys::LeftMouseButton);
}

void AUIPointerHandController::TriggerReleased()
{
	Pointer->ReleasePointerKey(EKeys::LeftMouseButton);
}

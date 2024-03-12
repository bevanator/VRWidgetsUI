// Fill out your copyright notice in the Description page of Project Settings.


#include "PaintBrushHandController.h"

#include "Stroke.h"

APaintBrushHandController::APaintBrushHandController()
{
	PrimaryActorTick.bCanEverTick = true;
}

void APaintBrushHandController::TriggerPressed()
{
	CurrentStroke = GetWorld()->SpawnActor<AStroke>(StrokeClass);
	CurrentStroke->SetActorLocation(GetActorLocation());
}

void APaintBrushHandController::TriggerReleased()
{
	CurrentStroke = nullptr;
}

void APaintBrushHandController::BeginPlay()
{
	Super::BeginPlay();
	
}

void APaintBrushHandController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(CurrentStroke)
	{
		CurrentStroke->Update(GetActorLocation());
	}
	
}


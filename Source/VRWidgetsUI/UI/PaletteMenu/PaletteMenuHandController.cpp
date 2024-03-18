// Fill out your copyright notice in the Description page of Project Settings.


#include "VRWidgetsUI/UI/PaletteMenu/PaletteMenuHandController.h"

APaletteMenuHandController::APaletteMenuHandController()
{
	PaletteMenu = CreateDefaultSubobject<UWidgetComponent>(TEXT("PaletteMenu"));
	PaletteMenu->SetupAttachment(GetRootComponent());
}

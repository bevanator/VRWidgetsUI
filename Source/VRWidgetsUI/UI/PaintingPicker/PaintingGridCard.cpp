// Fill out your copyright notice in the Description page of Project Settings.


#include "VRWidgetsUI/UI/PaintingPicker/PaintingGridCard.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/StereoLayerFunctionLibrary.h"


void UPaintingGridCard::SetPaintingName(FString NewPaintingName)
{
	PaintingName = NewPaintingName;
	// SlotNameText->SetText(FText::FromString(PaintingName));
	SlotNameText->SetText(FText::FromString("Untitled"));

	CardButton->OnClicked.AddDynamic(this, &UPaintingGridCard::CardButtonClicked);
}


void UPaintingGridCard::CardButtonClicked()
{
	// UStereoLayerFunctionLibrary::ShowSplashScreen();
	UGameplayStatics::OpenLevel(GetWorld(), TEXT("MainMap"), true, "SlotName=" + PaintingName);
}


// Fill out your copyright notice in the Description page of Project Settings.


#include "VRGameMode.h"

#include "Kismet/GameplayStatics.h"
#include "Saving/VRSaveGame.h"

void AVRGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
	SlotName = UGameplayStatics::ParseOption(Options, "SlotName");

	UE_LOG(LogTemp, Warning, TEXT("SlotName: %s"), *SlotName);
}

void AVRGameMode::BeginPlay()
{
	Super::BeginPlay();
	Load();
}

void AVRGameMode::Save()
{
	UVRSaveGame* Painting = UVRSaveGame::Load(SlotName);
	if(Painting)
	{
		Painting->SerializeFromWorld(GetWorld());
		Painting->Save();
	}
}

void AVRGameMode::Load()
{
	UVRSaveGame* Painting = UVRSaveGame::Load(SlotName);
	if(Painting)
	{
		Painting->DeserializeToWorld(GetWorld());
	}
	else UE_LOG(LogTemp, Warning, TEXT("Game slot not found! %s"), *SlotName);
}

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VRSaveGame.h"
#include "GameFramework/SaveGame.h"
#include "PainterSaveGameIndex.generated.h"

/**
 * 
 */
UCLASS()
class VRWIDGETSUI_API UPainterSaveGameIndex : public USaveGame
{
	GENERATED_BODY()

public:
	static UPainterSaveGameIndex* Load();
	bool Save();
	void AddSaveGame(UVRSaveGame* SaveGame);
	TArray<FString> GetSlotNameList() const { return SlotNames; }

private:
	static const FString SLOT_NAME;

	UPROPERTY()
	TArray<FString> SlotNames;
};

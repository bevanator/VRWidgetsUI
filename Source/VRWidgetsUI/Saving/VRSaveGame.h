
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "VRSaveGame.generated.h"


USTRUCT()
struct FStrokeState
{
	GENERATED_BODY()
	UPROPERTY()
	TSubclassOf<class AStroke> Class;

	UPROPERTY()
	TArray<FVector> ControlPoints;
};

UCLASS()
class VRWIDGETSUI_API UVRSaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	static UVRSaveGame* Create();
	bool Save();
	static UVRSaveGame* Load(FString SlotName);
	
	void SetState(FString NewState) { State = NewState;}
	FString GetState() const { return State;}

	void SerializeFromWorld(const UWorld* World);
	void DeserializeToWorld(UWorld* World);
	void ClearWorld(UWorld* World);

	FString GetSlotName() const { return SlotName; }

private:
	//State
	UPROPERTY()
	FString State;

	UPROPERTY()
	FString SlotName;

	UPROPERTY()
	TArray<FStrokeState> Strokes;
};



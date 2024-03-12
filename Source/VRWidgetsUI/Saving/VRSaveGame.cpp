

#include "VRSaveGame.h"
#include "EngineUtils.h"
#include "Kismet/GameplayStatics.h"
#include "VRWidgetsUI/Stroke.h"

UVRSaveGame* UVRSaveGame::Create()
{
	USaveGame* NewSaveGame = UGameplayStatics::CreateSaveGameObject(StaticClass());
	return Cast<UVRSaveGame>(NewSaveGame);
}

bool UVRSaveGame::Save()
{
	return UGameplayStatics::SaveGameToSlot(this, TEXT("Test"), 0);
}

UVRSaveGame* UVRSaveGame::Load()
{
	return Cast<UVRSaveGame>(UGameplayStatics::LoadGameFromSlot(TEXT("Test"), 0));
}

void UVRSaveGame::SerializeFromWorld(const UWorld* World)
{
	Strokes.Empty();
	for(TActorIterator<AStroke> StrokeItr(World); StrokeItr; ++StrokeItr) //TODO: Experiment with TActorIterator Type
	{
		Strokes.Add(StrokeItr->SerializeToStruct());
	}
}

void UVRSaveGame::ClearWorld(UWorld* World)
{
	for(TActorIterator<AStroke> StrokeItr(World); StrokeItr; ++StrokeItr)
	{
		StrokeItr->Destroy();	
	}
}

void UVRSaveGame::DeserializeToWorld(UWorld* World)
{
	ClearWorld(World);
	for (FStrokeState StrokeState : Strokes)
	{
		AStroke::DeserializeFromStruct(World, StrokeState);
	}
}


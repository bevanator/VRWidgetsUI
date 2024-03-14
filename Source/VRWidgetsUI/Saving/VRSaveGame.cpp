

#include "VRSaveGame.h"
#include "EngineUtils.h"
#include "PainterSaveGameIndex.h"
#include "Kismet/GameplayStatics.h"
#include "VRWidgetsUI/Stroke.h"

UVRSaveGame* UVRSaveGame::Create()
{
	//create a save game using "UGameplayStatics::CreateSaveGameObject(StaticClass())"
	//cast to self, generate a unique identifier (guid) and return
	USaveGame* NewSaveGame = UGameplayStatics::CreateSaveGameObject(StaticClass());
	UVRSaveGame* NewVRSaveGame = Cast<UVRSaveGame>(NewSaveGame);
	NewVRSaveGame->SlotName = FGuid::NewGuid().ToString();
	if(!NewVRSaveGame->Save()) return nullptr;

	UPainterSaveGameIndex* Index = UPainterSaveGameIndex::Load();
	Index->AddSaveGame(NewVRSaveGame);
	Index->Save();
	return NewVRSaveGame;
}

bool UVRSaveGame::Save()
{
	return UGameplayStatics::SaveGameToSlot(this, SlotName, 0);
}

UVRSaveGame* UVRSaveGame::Load(FString SlotName)
{
	return Cast<UVRSaveGame>(UGameplayStatics::LoadGameFromSlot(SlotName, 0));
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


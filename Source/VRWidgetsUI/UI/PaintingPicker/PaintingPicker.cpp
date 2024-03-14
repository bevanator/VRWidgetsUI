#include "PaintingPicker.h"

#include "PaintingGrid.h"
#include "VRWidgetsUI/Saving/PainterSaveGameIndex.h"

APaintingPicker::APaintingPicker()
{
	PrimaryActorTick.bCanEverTick = true;
	
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);
	
	PaintingGrid = CreateDefaultSubobject<UWidgetComponent>(TEXT("PaintingGrid"));
	PaintingGrid->SetupAttachment(GetRootComponent());

	ActionBar = CreateDefaultSubobject<UWidgetComponent>(TEXT("ActionBar"));
	ActionBar->SetupAttachment(GetRootComponent());

}

void APaintingPicker::BeginPlay()
{
	Super::BeginPlay();

	UPaintingGrid* PaintingGridWidget = Cast<UPaintingGrid>(PaintingGrid->GetUserWidgetObject());
	if(!PaintingGridWidget) return;

	int32 Index = 0;
	for (FString SlotName : UPainterSaveGameIndex::Load()->GetSlotNameList())
	{
		PaintingGridWidget->AddPainting(Index, SlotName);
		++Index;
	}
	
}

void APaintingPicker::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// for (FString Slot : UPainterSaveGameIndex::Load()->GetSlotNameList())
	// {
	// 	UE_LOG(LogTemp, Warning, TEXT("Painting name: %s"), *Slot);
	// }

}


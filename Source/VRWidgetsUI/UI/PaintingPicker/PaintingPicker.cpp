#include "PaintingPicker.h"

#include "PaintingGrid.h"
#include "VRWidgetsUI/ActionBar.h"
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

void APaintingPicker::AddPainting()
{
	// UVRSaveGame* Painting = UVRSaveGame::Create();
	UVRSaveGame::Create();
	Refresh();
}

void APaintingPicker::ToggleDeleteMode()
{
	UPaintingGrid* PaintingGridWidget = Cast<UPaintingGrid>(PaintingGrid->GetUserWidgetObject());
	if(!PaintingGridWidget) return;
	PaintingGridWidget->ClearPaintings();
}


void APaintingPicker::RefreshSlots()
{
	UPaintingGrid* PaintingGridWidget = Cast<UPaintingGrid>(PaintingGrid->GetUserWidgetObject());
	if(!PaintingGridWidget) return;
	
	PaintingGridWidget->AddPaginationDot(true);
	PaintingGridWidget->AddPaginationDot(false);
	PaintingGridWidget->AddPaginationDot(false);
	
	PaintingGridWidget->ClearPaintings();

	int32 Index = 0;
	for (FString SlotName : UPainterSaveGameIndex::Load()->GetSlotNameList())
	{
		PaintingGridWidget->AddPainting(Index, SlotName);
		++Index;
	}
}


void APaintingPicker::RefreshDots()
{
	if(!GetPaintingGrid()) return;
	GetPaintingGrid()->ClearPaginationDots();
	for (int32 i = 0; i < GetNumberOfPages(); ++i)
	{
		GetPaintingGrid()->AddPaginationDot(CurrentPage == i);
	}
}

int32 APaintingPicker::GetNumberOfPages() const
{
	if(!GetPaintingGrid()) return 0;
	
	int32 TotalNumberOfSlots = UPainterSaveGameIndex::Load()->GetSlotNameList().Num();
	int32 SlotsPerPage = GetPaintingGrid()->GetNumberOfSlots();

	return FMath::CeilToInt((float) TotalNumberOfSlots / SlotsPerPage);
}

void APaintingPicker::BeginPlay()
{
	Super::BeginPlay();

	UActionBar* ActionBarWidget = Cast<UActionBar>(ActionBar->GetUserWidgetObject());
	if(ActionBarWidget)
	{
		ActionBarWidget->SetParentPicker(this);
	}
	Refresh();
	
}

void APaintingPicker::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// for (FString Slot : UPainterSaveGameIndex::Load()->GetSlotNameList())
	// {
	// 	UE_LOG(LogTemp, Warning, TEXT("Painting name: %s"), *Slot);
	// }

}


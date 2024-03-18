// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaintingGrid.h"
#include "Components/WidgetComponent.h"
#include "GameFramework/Actor.h"
#include "PaintingPicker.generated.h"

UCLASS()
class VRWIDGETSUI_API APaintingPicker : public AActor
{
	GENERATED_BODY()
	
public:	
	APaintingPicker();
	void AddPainting();
	void ToggleDeleteMode();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

private:
	void Refresh() { RefreshSlots(); RefreshDots();}
	void RefreshSlots();
	UPaintingGrid* GetPaintingGrid() const {return Cast<UPaintingGrid>(PaintingGrid->GetUserWidgetObject());}
	void RefreshDots();
	int32 GetNumberOfPages() const;
	
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;
	
	UPROPERTY(VisibleAnywhere)
	UWidgetComponent* ActionBar;

	UPROPERTY(VisibleAnywhere)
	UWidgetComponent* PaintingGrid;

	UPROPERTY(EditAnywhere)
	int32 CurrentPage = 0;

};

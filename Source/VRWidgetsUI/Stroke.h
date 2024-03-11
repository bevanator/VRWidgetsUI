// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SplineMeshComponent.h"
#include "GameFramework/Actor.h"
#include "Stroke.generated.h"

UCLASS()
class VRWIDGETSUI_API AStroke : public AActor
{
	GENERATED_BODY()
	
public:	
	AStroke();
	void Update(FVector CursorLocation);
	void UpdateInstanced(FVector CursorLocation);

private:
	FTransform GetNextSegmentTransform(FVector CurrentLocation) const;
	FVector GetNextSegmentScale(FVector CurrentLocation) const;
	FQuat GetNextSegmentRotation(FVector CurrentLocation) const;
	FVector GetNextSegmentLocation(FVector CurrentLocation) const;

	//Component
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;



	UPROPERTY(VisibleAnywhere)
	UInstancedStaticMeshComponent* StrokeMeshes;

	//State
	FVector PreviousCursorLocation;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SplineMeshComponent.h"
#include "GameFramework/Actor.h"
#include "Saving/VRSaveGame.h"
#include "Stroke.generated.h"

UCLASS()
class VRWIDGETSUI_API AStroke : public AActor
{
	GENERATED_BODY()
	
public:	
	AStroke();
	void Update(FVector CursorLocation);
	FStrokeState SerializeToStruct() const;
	static AStroke* DeserializeFromStruct(UWorld* World, const FStrokeState& StrokeState);

	
private:
	FTransform GetNextSegmentTransform(FVector CurrentLocation) const;
	FTransform GetNextJointTransform(FVector CurrentLocation) const;
	FVector GetNextSegmentScale(FVector CurrentLocation) const;
	FQuat GetNextSegmentRotation(FVector CurrentLocation) const;
	FVector GetNextSegmentLocation(FVector CurrentLocation) const;

	//Component
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
	UInstancedStaticMeshComponent* JointMeshes;

	UPROPERTY(VisibleAnywhere)
	UInstancedStaticMeshComponent* StrokeMeshes;

	//State
	FVector PreviousCursorLocation;
	TArray<FVector> ControlPoints;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};

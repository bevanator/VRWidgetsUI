
#pragma once

#include "CoreMinimal.h"
#include "MotionControllerComponent.h"
#include "Stroke.h"
#include "GameFramework/Actor.h"
#include "HandController.generated.h"

UCLASS()
class VRWIDGETSUI_API AHandController : public AActor
{
	GENERATED_BODY()
	
public:	
	AHandController();
	void TriggerPressed();
	void TriggerReleased();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

private:
	//Components

	UPROPERTY(EditAnywhere)
	TSubclassOf<AStroke> StrokeClass;
	
	UPROPERTY(VisibleAnywhere)
	UMotionControllerComponent* MotionController;

	AStroke* CurrentStroke;
	
};

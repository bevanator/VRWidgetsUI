
#pragma once

#include "CoreMinimal.h"
#include "HandControllerBase.h"
#include "MotionControllerComponent.h"
#include "Stroke.h"
#include "GameFramework/Actor.h"
#include "PaintBrushHandController.generated.h"

UCLASS()
class VRWIDGETSUI_API APaintBrushHandController : public AHandControllerBase
{
	GENERATED_BODY()
	
public:	
	APaintBrushHandController();
	void TriggerPressed() override;
	void TriggerReleased() override;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

private:
	//Components

	UPROPERTY(EditAnywhere)
	TSubclassOf<AStroke> StrokeClass;

	AStroke* CurrentStroke;
	
};

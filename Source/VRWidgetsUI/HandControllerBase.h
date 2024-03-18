
#pragma once

#include "CoreMinimal.h"
#include "MotionControllerComponent.h"
#include "GameFramework/Actor.h"
#include "HandControllerBase.generated.h"

UCLASS()
class VRWIDGETSUI_API AHandControllerBase : public AActor
{
	GENERATED_BODY()

	
public:	
	AHandControllerBase();

	void SetHand(EControllerHand Hand);
	virtual void TriggerPressed() {}
	virtual void TriggerReleased() {}

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

protected:
	
	UPROPERTY
	//Components
	(VisibleAnywhere)
	UMotionControllerComponent* MotionController;
};

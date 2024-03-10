
#pragma once

#include "CoreMinimal.h"
#include "MotionControllerComponent.h"
#include "GameFramework/Actor.h"
#include "HandController.generated.h"

UCLASS()
class VRWIDGETSUI_API AHandController : public AActor
{
	GENERATED_BODY()
	
public:	
	AHandController();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

private:
	//Components

	UPROPERTY(VisibleAnywhere)
	UMotionControllerComponent* MotionController;
	
};

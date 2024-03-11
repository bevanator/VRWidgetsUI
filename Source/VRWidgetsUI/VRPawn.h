
#pragma once

#include "CoreMinimal.h"
#include "HandController.h"
#include "Stroke.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Pawn.h"
#include "VRPawn.generated.h"
class UInputAction;
class UInputMappingContext;
UCLASS()
class VRWIDGETSUI_API AVRPawn : public APawn
{
	GENERATED_BODY()

public:
	AVRPawn();

protected:
	virtual void BeginPlay() override;
	void RightTriggerPressed() { if (RightHandController) RightHandController->TriggerPressed();};
	void RightTriggerReleased() { if (RightHandController) RightHandController->TriggerReleased();};
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

private:

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AHandController> HandControllerClass;
	
	UPROPERTY(VisibleAnywhere)
	USceneComponent* VRRoot;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* Camera;

	UPROPERTY()
	AHandController* RightHandController;




public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UInputAction* Action1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UInputMappingContext* MappingContext;
};


#pragma once

#include "CoreMinimal.h"
#include "HandControllerBase.h"
#include "InputActionValue.h"
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
	void ScrollAxisInput(const FInputActionValue& Value);
	void HandleAxisInput(float AxisValue);
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	// void Load();
	void Save();

private:

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AHandControllerBase> HandControllerClass; //Exposed property in blueprint;
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AHandControllerBase> LeftHandControllerClass; //Usually points to BP of the class
	
	UPROPERTY(VisibleAnywhere)
	USceneComponent* VRRoot;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* Camera;

	UPROPERTY()
	AHandControllerBase* RightHandController; //Used for storing spawned Reference

	UPROPERTY()
	AHandControllerBase* LeftHandController;
	
	int32 LastPaginationOffset = 0;

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UInputAction* DrawAction;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UInputAction* SaveAction;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UInputAction* LoadAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UInputAction* ScrollAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UInputMappingContext* MappingContext;
};

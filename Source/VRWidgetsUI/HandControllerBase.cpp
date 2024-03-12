

#include "HandControllerBase.h"


AHandControllerBase::AHandControllerBase()
{
	PrimaryActorTick.bCanEverTick = false;
	MotionController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("MotionController"));
	SetRootComponent(MotionController);
	MotionController->SetTrackingSource(EControllerHand::Right);
	MotionController->SetShowDeviceModel(true);

}

void AHandControllerBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AHandControllerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


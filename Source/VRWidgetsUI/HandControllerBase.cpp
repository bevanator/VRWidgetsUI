

#include "HandControllerBase.h"


AHandControllerBase::AHandControllerBase()
{
	PrimaryActorTick.bCanEverTick = false;
	MotionController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("MotionController"));
	SetRootComponent(MotionController);
	MotionController->SetShowDeviceModel(true);
	// MotionController->SetTrackingSource(EControllerHand::Right);
}

void AHandControllerBase::SetHand(EControllerHand Hand)
{
	MotionController->SetTrackingSource(Hand);
}

void AHandControllerBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AHandControllerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


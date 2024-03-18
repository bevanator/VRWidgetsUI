

#include "VRPawn.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "VRGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Utilities/Logger.h"

AVRPawn::AVRPawn()
{
	PrimaryActorTick.bCanEverTick = true;

	VRRoot = CreateDefaultSubobject<USceneComponent>(TEXT("VRRoot"));
	SetRootComponent(VRRoot);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(VRRoot);
}

void AVRPawn::BeginPlay()
{
	Super::BeginPlay();
	
	// UVRSaveGame* Painting = UVRSaveGame::Create();
	// if(Painting && Painting->Save())
	// {
	// 	CurrentSlotName = Painting->GetSlotName();
	// }

	if(APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());
		if(Subsystem)
		{
			Subsystem->AddMappingContext(MappingContext, 0);
		}
	}
	
	if(HandControllerClass)
	{
		RightHandController = GetWorld()->SpawnActor<AHandControllerBase>(HandControllerClass);
		RightHandController->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::SnapToTargetIncludingScale);
		RightHandController->SetOwner(this);
		RightHandController->SetHand(EControllerHand::Right);
	}

	if(LeftHandControllerClass)
	{
		LeftHandController = GetWorld()->SpawnActor<AHandControllerBase>(LeftHandControllerClass);
		LeftHandController->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::SnapToTargetNotIncludingScale);
		LeftHandController->SetOwner(this);
		LeftHandController->SetHand(EControllerHand::Left);

	}


}

void AVRPawn::ScrollAxisInput(const FInputActionValue& Value)
{
	float AxisValue = Value.Get<float>();
	int32 PaginationOffset = 0;
	PaginationOffset += AxisValue > 0.9 ? 1 : 0;
	PaginationOffset += AxisValue < -0.9 ? -1 : 0;

	if (PaginationOffset != LastPaginationOffset && PaginationOffset != 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Paginate %d"), PaginationOffset);
	}

	LastPaginationOffset = PaginationOffset;
}

void AVRPawn::HandleAxisInput(float AxisValue)
{
	
}


void AVRPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if(UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(DrawAction, ETriggerEvent::Started, this, &AVRPawn::RightTriggerPressed);
		EnhancedInputComponent->BindAction(DrawAction, ETriggerEvent::Completed, this, &AVRPawn::RightTriggerReleased);
		EnhancedInputComponent->BindAction(ScrollAction, ETriggerEvent::Started, this, &AVRPawn::ScrollAxisInput);
		// EnhancedInputComponent->BindAction(SaveAction, ETriggerEvent::Started, this, &AVRPawn::Save);
		// EnhancedInputComponent->BindAction(LoadAction, ETriggerEvent::Started, this, &AVRPawn::Load);
	}
}


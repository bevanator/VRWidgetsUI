

#include "VRPawn.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Saving/VRSaveGame.h"

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
		RightHandController = GetWorld()->SpawnActor<AHandController>(HandControllerClass);
		RightHandController->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::SnapToTargetIncludingScale);
		RightHandController->SetOwner(this);
	}


}

void AVRPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if(UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(DrawAction, ETriggerEvent::Started, this, &AVRPawn::RightTriggerPressed);
		EnhancedInputComponent->BindAction(DrawAction, ETriggerEvent::Completed, this, &AVRPawn::RightTriggerReleased);
		EnhancedInputComponent->BindAction(SaveAction, ETriggerEvent::Started, this, &AVRPawn::Save);
		EnhancedInputComponent->BindAction(LoadAction, ETriggerEvent::Started, this, &AVRPawn::Load);
	}
}

void AVRPawn::Save()
{
	UVRSaveGame* Painting = UVRSaveGame::Create();
	Painting->SetState(TEXT("Hello!"));
	Painting->SerializeFromWorld(GetWorld());
	Painting->Save();
}

void AVRPawn::Load()
{
	UVRSaveGame* Painting = UVRSaveGame::Load();
	if(Painting)
	{
		Painting->DeserializeToWorld(GetWorld());
		UE_LOG(LogTemp, Warning, TEXT("Painting State %s"), *Painting->GetState());
	}
	else UE_LOG(LogTemp, Warning, TEXT("Not found!"));
}
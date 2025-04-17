// Copyright Uncertain Studios (c). All Rights Reserved.


#include "MainCharacter/MainCharacterComponents/TP_MainCharInteractionController.h"
#include "EnhancedInputComponent.h"
#include "Camera/CameraComponent.h"
#include "Framework/SignalBus.h"
#include "InteractableComponents/BaseInteractableComponent.h"
#include "InteractableComponents/Interactable.h"
#include "MainCharacter/MainCharacterComponents/Interaction/InteractionCaseController.h"

UTP_MainCharInteractionController::UTP_MainCharInteractionController()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTP_MainCharInteractionController::Inject(UDependencyContainer* Container)
{
	SignalBus = Container->Resolve<USignalBus>();
}

void UTP_MainCharInteractionController::Init(UCameraComponent* camera)
{
	Owner = Cast<AMainCharacter>(GetOwner());
	MainCamera = camera;
	check(MainCamera);
	
	InteractionController = NewObject<UInteractionCaseController>(this);

	// !!! SignalBus->GetCharacterEventsContainer()->OnCharacterCameraReturnedToCharacter.AddDynamic(this, &UTP_MainCharInteractionController::ResetCurrentInteractable);
}

void UTP_MainCharInteractionController::SetupInput(UEnhancedInputComponent* input)
{
	UEnhancedInputComponent* enhancedInputComponent = Cast<UEnhancedInputComponent>(input);	
	check(enhancedInputComponent);
	
	enhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Triggered, this, &UTP_MainCharInteractionController::PerformInteract);
}

void UTP_MainCharInteractionController::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if(!bIsServiceStoped)
	{
		PerformInteractableCheck();	
	}
}

void UTP_MainCharInteractionController::PerformInteractableCheck()
{
	FHitResult InfoCastHit;
	FCollisionQueryParams CollisionParams;
    CollisionParams.AddIgnoredActor(Owner);

	FVector TraceStart = MainCamera->GetComponentLocation();
	FVector TraceEnd = TraceStart + (MainCamera->GetComponentRotation().Vector() * InfoCastLength);
	
	if (GetWorld()->LineTraceSingleByChannel(InfoCastHit, TraceStart, TraceEnd, ECC_Visibility, CollisionParams))
	{
		if (AActor* HitActor = InfoCastHit.GetActor())
		{
			if (IInteractable* Interactable = Cast<IInteractable>(HitActor->FindComponentByInterface(UInteractable::StaticClass())))
			{
				InteractionController->InteractableFound(Interactable);
				return;    
			}
		}
	}

	InteractionController->InteractableNotFound();
}

void UTP_MainCharInteractionController::PerformInteract()
{
	if(!bIsServiceStoped)
	{
		InteractionController->InteractionCalled();	
	}
}

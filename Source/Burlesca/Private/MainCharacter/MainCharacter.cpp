// Copyright Uncertain Studios (c). All Rights Reserved.

#include "MainCharacter/MainCharacter.h"

#include "BurlescaPlayerController.h"
#include "EnhancedInputComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/WidgetInteractionComponent.h"
#include "MainCharacter/MainCharacterAnimInstance.h"
#include "MainCharacter/MainCharacterComponents/TP_MainCharacterCameraController.h"
#include "MainCharacter/MainCharacterComponents/TP_MainCharMovementComponent.h"
#include "MainCharacter/MainCharacterComponents/TP_MainCharInteractionController.h"

class ABurlescaPlayerController;

AMainCharacter::AMainCharacter()
{
	ComponentsConstruction();
}

void AMainCharacter::Inject(UDependencyContainer* Container)
{
	ABurlescaPlayerController* PlayerController = Container->Resolve<ABurlescaPlayerController>();
	PlayerController->SetViewTarget(this);
	MainCamera->Activate();
}

void AMainCharacter::SetupInput(UEnhancedInputComponent* input)
{	
	input->BindAction(MousePressedInputAction, ETriggerEvent::Triggered, this, &AMainCharacter::MousePressed);
	input->BindAction(MouseReleasedInputAction, ETriggerEvent::Triggered, this, &AMainCharacter::MouseReleased);
}

void AMainCharacter::ComponentsConstruction()
{
	MainCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Main Camera"));
	MainCamera->SetupAttachment(RootComponent);
	MainCamera->bUsePawnControlRotation = true;

	WidgetInteraction = CreateDefaultSubobject<UWidgetInteractionComponent>(TEXT("Widget Interaction"));
	WidgetInteraction->SetupAttachment(RootComponent);
	WidgetInteraction->InteractionSource = EWidgetInteractionSource::Mouse;
	
	CharacterMesh = FindComponentByClass<USkeletalMeshComponent>();
	check(CharacterMesh);
	CharacterMesh->bCastDynamicShadow = false;
	CharacterMesh->CastShadow = false;

	CameraController = CreateDefaultSubobject<UTP_MainCharacterCameraController>(TEXT("Camera Movement Controller"));
	MovementController = CreateDefaultSubobject<UTP_MainCharMovementComponent>(TEXT("Player Movement Controller"));
	InteractionController = CreateDefaultSubobject<UTP_MainCharInteractionController>(TEXT("Interaction Controller"));
	
	check(CameraController);
	check(MovementController);
	check(InteractionController);
	check(WidgetInteraction);
}

void AMainCharacter::MousePressed()
{
	if (WidgetInteraction)
		WidgetInteraction->PressPointerKey(EKeys::LeftMouseButton);
}

void AMainCharacter::MouseReleased()
{
	if (WidgetInteraction)
		WidgetInteraction->ReleasePointerKey(EKeys::LeftMouseButton);
}

void AMainCharacter::ComponentsInitialization()
{
	//MainCamera->AttachToComponent(CharacterMesh, FAttachmentTransformRules::KeepWorldTransform, TEXT("camera_socket"));
	InteractionController->Init(MainCamera);
	MovementController->Init();
	CameraController->Init(MainCamera);
}

void AMainCharacter::PlayAllPlayerServicies()
{
	InteractionController->PlayService();
	MovementController->PlayService();
	CameraController->PlayService();
}

void AMainCharacter::StopAllPlayerServicies()
{
	InteractionController->StopService();
	MovementController->StopService();
	CameraController->StopService();
}

UMainCharacterAnimInstance* AMainCharacter::CreateAnimInstance(UClass* AnimInstanceClass)
{
	CharacterMesh->SetAnimClass(AnimInstanceClass);
	return Cast<UMainCharacterAnimInstance>(CharacterMesh->GetAnimInstance());
}

void AMainCharacter::AttachActorToSocket(AActor* actor, FName socketName)
{
	actor->AttachToComponent(CharacterMesh, FAttachmentTransformRules::SnapToTargetNotIncludingScale, socketName);
}

/*
void AMainCharacter::DetachPhoneFromSocket()
{
	MobilePhone->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
}*/


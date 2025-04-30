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

	CameraComponent = CreateDefaultSubobject<UTP_MainCharacterCameraController>(TEXT("Camera Movement Controller"));
	MovementComponent = CreateDefaultSubobject<UTP_MainCharMovementComponent>(TEXT("Player Movement Controller"));
	InteractionComponent = CreateDefaultSubobject<UTP_MainCharInteractionController>(TEXT("Interaction Controller"));
	
	check(CameraComponent);
	check(MovementComponent);
	check(InteractionComponent);
	check(WidgetInteraction);
}

void AMainCharacter::ComponentsInitialization()
{
	//MainCamera->AttachToComponent(CharacterMesh, FAttachmentTransformRules::KeepWorldTransform, TEXT("camera_socket"));
	InteractionComponent->Init(MainCamera);
	MovementComponent->Init();
	CameraComponent->Init(MainCamera);
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

void AMainCharacter::PlayAllPlayerServicies()
{
	InteractionComponent->PlayService();
	MovementComponent->PlayService();
	CameraComponent->PlayService();
}

void AMainCharacter::StopAllPlayerServicies()
{
	InteractionComponent->StopService();
	MovementComponent->StopService();
	CameraComponent->StopService();
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


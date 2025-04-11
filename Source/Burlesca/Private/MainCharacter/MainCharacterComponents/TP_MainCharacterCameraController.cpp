// Copyright Uncertain Studios (c). All Rights Reserved.


#include "MainCharacter/MainCharacterComponents/TP_MainCharacterCameraController.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
#include "Camera/CameraComponent.h"
#include "Framework/SignalBus.h"
#include "MainCharacter/MainCharacter.h"
#include "Settings/InputSettingsContainer.h"
#include "Settings/SettingsContainer.h"
#include "Tween/Tween.h"
#include "TweenFunctions/TransformTweenFunctions.h"

void UTP_MainCharacterCameraController::Init(UCameraComponent* camera)
{
	MainCamera = camera;
	cameraOffset = MainCamera->GetRelativeLocation();
}

void UTP_MainCharacterCameraController::Inject(UDependencyContainer* Container)
{
	SignalBus = Container->Resolve<USignalBus>();
	InputSettingsContainer = Container->Resolve<USettingsContainer>()->GetInputSettingsContainer();
}

void UTP_MainCharacterCameraController::SetupInput(UEnhancedInputComponent* input)
{
	Owner = Cast<AMainCharacter>(GetOwner());
	check(Owner);
	
	input->BindAction(LookXAction, ETriggerEvent::Triggered, this, &UTP_MainCharacterCameraController::LookX);
	input->BindAction(LookYAction, ETriggerEvent::Triggered, this, &UTP_MainCharacterCameraController::LookY);
}

UTween* UTP_MainCharacterCameraController::MoveCameraTo(FVector targetWorldPosition, float duration)
{
	bIsCameraControlEnabled = false;
	return DOLocalMoveComponent(MainCamera, targetWorldPosition - MainCamera->GetRelativeLocation(), duration);
}

UTween* UTP_MainCharacterCameraController::ReturnCameraToCharacter()
{
	UTween* t = DOLocalMoveComponent(MainCamera, cameraOffset, 0.5f);
	t->OnComplete.AddDynamic(this, &UTP_MainCharacterCameraController::AllowCameraControl);
	return t;
}

void UTP_MainCharacterCameraController::LookY(const FInputActionValue& Value)
{
	if(bIsServiceStoped || !bIsCameraControlEnabled)
		return;

	int32 invertValue = InputSettingsContainer->bIsMouseInvertedY == false ? 1 : -1;
	float pitch = Value.Get<float>() * InputSettingsContainer->GetMouseSensitivity() * invertValue;
	
	if(MainCamera->GetRelativeRotation().Pitch + pitch > topLookBound)
		MainCamera->SetRelativeRotation(FRotator(topLookBound, 0, 0));
	else if(MainCamera->GetRelativeRotation().Pitch + pitch < bottomLookBound)
		MainCamera->SetRelativeRotation(FRotator(bottomLookBound, 0, 0));
	else
		MainCamera->AddRelativeRotation(FRotator(pitch, 0, 0));
}

void UTP_MainCharacterCameraController::LookX(const FInputActionValue& Value)
{
	if(bIsServiceStoped || !bIsCameraControlEnabled)
		return;

	int32 invertValue = InputSettingsContainer->bIsMouseInvertedX == false ? 1 : -1;
	float yaw = Value.Get<float>() * InputSettingsContainer->GetMouseSensitivity() * invertValue;
	
	Owner->AddActorWorldRotation(FRotator(0, yaw, 0));
}

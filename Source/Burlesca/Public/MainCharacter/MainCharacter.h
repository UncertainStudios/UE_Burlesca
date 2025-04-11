// Copyright Uncertain Studios (c). All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "InputSetupable.h"
#include "Framework/DependencyInjection/Inject.h"
#include "GameFramework/Character.h"
#include "MainCharacter.generated.h"

class UInputAction;
class UMainCharacterAnimInstance;
class UTP_MainCharInteractionController;
class UTP_MainCharMovementComponent;
class UTP_MainCharacterCameraController;
class UWidgetInteractionComponent;
class UCameraComponent;

UCLASS()
class BURLESCA_API AMainCharacter : public ACharacter, public IInject, public IInputSetupable
{
	GENERATED_BODY()

public:
	AMainCharacter();
	virtual void Inject(UDependencyContainer* Container) override;
	virtual void SetupInput(UEnhancedInputComponent* input) override;
	void ComponentsInitialization();
	
	UFUNCTION(BlueprintCallable)
	virtual void StopAllPlayerServicies();

	UFUNCTION(BlueprintCallable)
	virtual void PlayAllPlayerServicies();

	UFUNCTION(BlueprintCallable)
	virtual UTP_MainCharMovementComponent* GetCharacterMovementComponent() { return MovementController; }

	UFUNCTION(BlueprintCallable)
	virtual UTP_MainCharacterCameraController* GetCharacterCameraComponent() { return CameraController; }

	UFUNCTION(BlueprintCallable)
	virtual UTP_MainCharInteractionController* GetCharacterInteractionComponent()  { return InteractionController; }

	UFUNCTION()
	UMainCharacterAnimInstance* CreateAnimInstance(UClass* AnimInstanceClass);

	UFUNCTION()
	void AttachActorToSocket(AActor* actor, FName socketName);

protected:
	void ComponentsConstruction();

	void MousePressed(); 
	void MouseReleased();
	
	UPROPERTY(EditAnywhere, Category = CameraController)
	UCameraComponent* MainCamera;

	UPROPERTY(EditAnywhere, Category = WidgetInteraction)
	UWidgetInteractionComponent* WidgetInteraction;

	UPROPERTY(EditAnywhere, Category = Mesh)
	USkeletalMeshComponent* CharacterMesh;

	UPROPERTY(EditAnywhere, Category = CameraController)
	UTP_MainCharacterCameraController* CameraController;

	UPROPERTY(EditAnywhere, Category = MovementController)
	UTP_MainCharMovementComponent* MovementController;

	UPROPERTY(EditAnywhere, Category = MovementController)
	UTP_MainCharInteractionController* InteractionController;

	UPROPERTY(EditAnywhere, Category = WidgetInteraction)
	UInputAction* MousePressedInputAction;

	UPROPERTY(EditAnywhere, Category = WidgetInteraction)
	UInputAction* MouseReleasedInputAction;
	
	/*
	
	UFUNCTION(BlueprintCallable)
	float GetForwardMovementSpeedRelativeToMax() const { return MovementController->GetForwardMovementSpeedRelativeToMax(); }

	UFUNCTION(BlueprintCallable)
	float GetRightMovementSpeedRelativeToMax() const { return MovementController->GetRightMovementSpeedRelativeToMax(); }
	
	void MoveCameraTo(AActor* PositionActor, float MovementDuration, bool bIsMovingFromCharacter, bool bIsMovingToCharacter = false) const;
	void MoveCameraTo(FVector PositionVector, FRotator RotationVector, float MovementDuration, bool bIsMovingFromCharacter, bool bIsMovingToCharacter = false) const;
	void ReturnCameraToCharacter(float MovementDuration) const;

	void AttachPhoneToSocket();
	void DetachPhoneFromSocket();
	
protected:	
	UPROPERTY(EditDefaultsOnly, Category = Input)
	UInputAction* MousePressInputAction;

	UPROPERTY(EditDefaultsOnly, Category = Input)
	UInputAction* MouseReleaseInputAction;
	
	UPROPERTY(VisibleAnywhere)
	AMobilePhone* MobilePhone;
	
	UPROPERTY(VisibleAnywhere, Category = HUD)
	AGameplayHUD* HUD;

	UPROPERTY()
	USignalBus* SignalBus;
	
	void ComponentsConstruction();
	void SubscribeEvents();

	UFUNCTION()
	void ActivateStaticMesh() { ArmsMesh->SetVisibility(true); }
	
	UFUNCTION()
	void DeactivateStaticMesh() { ArmsMesh->SetVisibility(false); }

	UFUNCTION()
	void OnLMBPressed() { WidgetInteraction->PressPointerKey(EKeys::LeftMouseButton); }

	UFUNCTION()
	void OnLMBReleased() { WidgetInteraction->ReleasePointerKey(EKeys::LeftMouseButton); }*/
};

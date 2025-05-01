// Copyright Uncertain Studios (c). All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MainCharacter.generated.h"

class UMobilePhone;
class UInputAction;
class UMainCharacterAnimInstance;
class UTP_MainCharInteractionController;
class UTP_MainCharMovementComponent;
class UTP_MainCharacterCameraController;
class UWidgetInteractionComponent;
class UCameraComponent;

UCLASS()
class BURLESCA_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AMainCharacter();
	virtual void BeginPlay() override;
	void ComponentsInitialization();
	
	UFUNCTION(BlueprintCallable)
	virtual void StopAllPlayerServicies();

	UFUNCTION(BlueprintCallable)
	virtual void PlayAllPlayerServicies();

	UFUNCTION(BlueprintCallable)
	virtual UTP_MainCharMovementComponent* GetCharacterMovementComponent() { return MovementComponent; }

	UFUNCTION(BlueprintCallable)
	virtual UTP_MainCharacterCameraController* GetCharacterCameraComponent() { return CameraComponent; }

	UFUNCTION(BlueprintCallable)
	virtual UTP_MainCharInteractionController* GetCharacterInteractionComponent()  { return InteractionComponent; }

	UFUNCTION(BlueprintCallable)
	virtual UMobilePhone* GetPhoneComponent()  { return PhoneComponent; }
	
	UFUNCTION()
	UMainCharacterAnimInstance* CreateAnimInstance(UClass* AnimInstanceClass);

	UFUNCTION()
	void AttachActorToSocket(AActor* actor, FName socketName);

protected:
	void MousePressed(); 
	void MouseReleased();

	UPROPERTY(EditAnywhere, Category="Components|CameraComponent")
	UCameraComponent* MainCamera;
	
	UPROPERTY(EditAnywhere, Category="Components|WidgetInteractionComponent")
	UWidgetInteractionComponent* WidgetInteraction;

	UPROPERTY(EditAnywhere, Category="Components|SKMeshComponent")
	USkeletalMeshComponent* CharacterMesh;

	UPROPERTY(EditAnywhere, Category="Components|CameraComponent")
	UTP_MainCharacterCameraController* CameraComponent;

	UPROPERTY(EditAnywhere, Category ="Components|MovementComponent")
	UTP_MainCharMovementComponent* MovementComponent;

	UPROPERTY(EditAnywhere, Category="Components|InteractionComponent")
	UTP_MainCharInteractionController* InteractionComponent;

	UPROPERTY(EditAnywhere, Category="Components|PhoneComponent")
	UMobilePhone* PhoneComponent;
	
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

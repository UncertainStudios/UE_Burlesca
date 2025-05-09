// Copyright Uncertain Studios (c). All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "InputSetupable.h"
#include "MainCharacterComponent.h"
#include "Components/ActorComponent.h"
#include "Framework/DependencyInjection/Inject.h"
#include "TP_MainCharMovementComponent.generated.h"

struct FInputActionValue;

class AMainCharacter;
class UEnhancedInputComponent;
class UInputAction;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BURLESCA_API UTP_MainCharMovementComponent : public UMainCharacterComponent, public IInject, public IInputSetupable
{
	GENERATED_BODY()

public:	
	UTP_MainCharMovementComponent();
	virtual void Init();
	virtual void Inject(UDependencyContainer* Container) override;
	virtual void SetupInput(UEnhancedInputComponent* input) override;
	
	float GetForwardMovementSpeedRelativeToMax() const { return CurrentForwardMovementSpeed / MaxCharacterMovementSpeed * 100.0f; }
	float GetRightMovementSpeedRelativeToMax() const { return CurrentRightMovementSpeed / MaxCharacterMovementSpeed * 100.0f; }
	
	void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
protected:
	uint8 CurrentForwardMovementDirection = 0;
	uint8 CurrentRightMovementDirection = 0;
	
	UFUNCTION()
	void StartAcceleratingForward(const FInputActionValue& Value);

	UFUNCTION()
	void StartAcceleratingRight(const FInputActionValue& Value);

	UFUNCTION()
	void StartDeacceleratingForward();

	UFUNCTION()
	void StartDeacceleratingRight();

	UFUNCTION()
	void StartRunning();

	UFUNCTION()
	void StopRunning();
	
	FTimerHandle ChangingForwardMovementSpeedTimer;
	FTimerHandle ChangingRightMovementSpeedTimer;

	void UpdateForwardVelocity(float DeltaTime);
	void UpdateRightVelocity(float DeltaTime);

protected:
	UPROPERTY()
	AActor* Owner = nullptr;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveForwardAction = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveRightAction = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* RunAction = nullptr;
	
	float CurrentForwardMovementSpeed = 0;
	float CurrentRightMovementSpeed = 0;

	UPROPERTY(EditDefaultsOnly, DisplayName = "Max Character Movement Speed", Category = "Movement Settings")
	float  MaxCharacterMovementSpeed;
	
	UPROPERTY(EditDefaultsOnly, DisplayName = "Acceleration Speed", Category = "Movement Settings")
	float AccelerationChangeSpeed;

	UPROPERTY(EditDefaultsOnly, DisplayName = "Run Speed", Category = "Movement Settings")
	float RunSpeed;
};

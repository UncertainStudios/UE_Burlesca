// Copyright Uncertain Studios (c). All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "InputSetupable.h"
#include "MainCharacterComponent.h"
#include "Components/ActorComponent.h"
#include "Framework/DependencyInjection/Inject.h"
#include "TP_MainCharacterCameraController.generated.h"

class UTween;
class AMainCharacter;
class UDependencyContainer;
class USignalBus;
class UCameraComponent;
class UEnhancedInputComponent;
class UInputMappingContext;
class UInputAction;
class UInputSettingsContainer;

struct FInputActionValue;

UENUM(BlueprintType)
enum class ECameraViewMode : uint8
{
	FirstPerson,
	ThirdPerson
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BURLESCA_API UTP_MainCharacterCameraController : public UMainCharacterComponent, public IInject, public IInputSetupable
{
	GENERATED_BODY()

public:	
	void Init(UCameraComponent* camera);
	virtual void Inject(UDependencyContainer* Container) override;
	virtual void SetupInput(UEnhancedInputComponent* input) override;

	UTween* MoveCameraTo(FVector targetWorldPosition, float duration);
	UTween* ReturnCameraToCharacter();
	
protected:
	void LookX(const FInputActionValue& Value);
	void LookY(const FInputActionValue& Value);

	UFUNCTION()
	void AllowCameraControl() { bIsCameraControlEnabled = true; } 
	
	UPROPERTY()
	UCameraComponent* MainCamera;

	UPROPERTY()
	AMainCharacter* Owner;

	UPROPERTY()
	USignalBus* SignalBus;

	UPROPERTY()
	UInputSettingsContainer* InputSettingsContainer;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* LookXAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* LookYAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	float topLookBound = 90.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	float bottomLookBound = -80.0f; 
	
	bool bIsCameraControlEnabled = true;
	FVector cameraOffset;
};

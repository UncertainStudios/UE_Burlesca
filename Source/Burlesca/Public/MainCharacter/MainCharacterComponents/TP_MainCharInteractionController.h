// Copyright Uncertain Studios (c). All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "InputSetupable.h"
#include "MainCharacter/MainCharacter.h"
#include "Components/ActorComponent.h"
#include "MainCharacter/MainCharacterComponents/MainCharacterComponent.h"
#include "TP_MainCharInteractionController.generated.h"

class USignalBus;
class UInteractionCaseController;
class IInteractable;
class UCameraComponent;
class UEnhancedInputComponent;
class UInputAction;
struct FHitResult;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BURLESCA_API UTP_MainCharInteractionController : public UMainCharacterComponent, public IInputSetupable
{
	GENERATED_BODY()

public:	
	UTP_MainCharInteractionController();
	void Init(UCameraComponent* camera);
	virtual void SetupInput(UEnhancedInputComponent* input) override;
	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY()
	UCameraComponent* MainCamera;

	UPROPERTY()
	AMainCharacter* Owner;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* InteractAction;

	UPROPERTY(EditAnywhere, Category = "InteractionSettings")
	uint16 InfoCastLength;

	UPROPERTY()
	UInteractionCaseController* InteractionController;
	
	void PerformInteractableCheck();
	void PerformInteract();
};

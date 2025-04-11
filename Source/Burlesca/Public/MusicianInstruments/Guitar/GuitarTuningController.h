#pragma once

#include "CoreMinimal.h"
#include "InputSetupable.h"
#include "Framework/DependencyInjection/Inject.h"
#include "UObject/Object.h"
#include "GuitarTuningController.generated.h"

class AGuitar;
class AMainCharacter;
struct FInputActionValue;

BURLESCA_API DECLARE_LOG_CATEGORY_EXTERN(MusicianInstruments, All, All);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnGuitarSetupComplete);

UCLASS()
class BURLESCA_API UGuitarTuningController : public UObject, public IInject, public IInputSetupable
{
	GENERATED_BODY()

public:
	void Init(AGuitar* guitar);
	virtual void Inject(UDependencyContainer* Container) override;
	virtual void SetupInput(UEnhancedInputComponent* InputComponent) override;
	
	UFUNCTION(BlueprintCallable)
	void StartGuitarTuning();

	UFUNCTION(BlueprintCallable)
	void StopGuitarTuning();
	
protected:
	UPROPERTY()
	AMainCharacter* MainCharacter;

	UPROPERTY()
	AGuitar* Guitar;

	/*
	void InitGuitarSetup(AActor* guitarSetupViewPlaceholder, APointLight* leftLight, APointLight* rightLight, TArray<ATuningPegs*> tuningPegs);
	void InitAudio(UAudioComponent* audioSource, USoundBase* successSound, TArray<USoundBase*> stringSounds);
	void InitInputActions(UInputAction* switchPegAction, UInputAction* rotatePegAction, UInputAction* playStringAction);

	bool GetIsGuitarSetsUp() const { return bIsGuitarSetsUp; }
	bool GetIsGuitarSetupCompleted() const { return bIsGuitarSetupCompleted; }
	
	FOnGuitarSetupComplete OnGuitarSetupComplete;
	
protected:
	bool bIsGuitarSetsUp = false;
	bool bIsGuitarSetupCompleted = false;
    bool bIsTimerSucceed = false;
	bool bIsGuitarPlayStringReloaded = true;
	
	uint8 CurrentSelectedTuningPeg = 0;
	
	FTimerHandle GuitarSetupDelay;
	FTimerHandle StringPlayReload;

	UPROPERTY()
	USignalBus* SignalBus;

	UPROPERTY()
	APointLight* LeftLight;

	UPROPERTY()
	APointLight* RightLight;
	
	UPROPERTY(EditInstanceOnly)
	AActor* GuitarSetupViewPlaceholder;

	UPROPERTY()
	TArray<ATuningPegs*> TuningPegs;

	UPROPERTY()
	UInputAction* SwitchPegAction;
	UPROPERTY()
	UInputAction* RotatePegAction;
	UPROPERTY()
	UInputAction* PlayStringAction;

	UPROPERTY()
    UAudioComponent* AudioSource;
	UPROPERTY()
	USoundBase* SuccessSound;
	UPROPERTY()
	TArray<USoundBase*> StringSound;
	
	float CalculatePitchFromRotation(float RotationValue) const;
	
	void ChangeLightActivityState(bool bActivitySate) const;

	UFUNCTION()
	void OnDelayTimerEnds();

	UFUNCTION()
	void OnGuitarPlayStringReloaded() { bIsGuitarPlayStringReloaded = true; }
	
	UFUNCTION()
	void SwitchPeg(const FInputActionValue& Value);
	
	UFUNCTION()
	void RotatePeg(const FInputActionValue& Value);
	
	UFUNCTION()
	void PlayGuitarString(const FInputActionValue& Value);*/
};

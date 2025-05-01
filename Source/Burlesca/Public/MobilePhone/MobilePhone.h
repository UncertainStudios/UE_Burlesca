// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MobilePhone.generated.h"

class UMainCharacterAnimInstance;
class UInputAction;
class ABurlescaPlayerController;
class AMainCharacter;
class UPhoneApplicationContainer;
class UWidgetComponent;
enum class EPhoneApplication : uint8;
class UPhoneApplication;

UCLASS()
class BURLESCA_API UMobilePhone : public USceneComponent
{
	GENERATED_BODY()

public:
	UMobilePhone();
	void Init();
	void TogglePower() const;
	void TogglePower(bool bPowerOn) const;
	void ToggleVisibility() const;
	void ToggleVisibility(bool bIsVisible) const;
	UPhoneApplicationContainer* GetUIView() const { return ApplicationsContainer; }
	
protected:
	UPROPERTY(EditDefaultsOnly, Category="Components")
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditDefaultsOnly, Category="Components")
	UWidgetComponent* MobilePhoneScreenWidgetComponent;
	
	UPROPERTY(EditDefaultsOnly, Category="Components")
	UAudioComponent* AudioComponent;
	
	UPROPERTY(EditDefaultsOnly, Category="Audio")
	USoundWave* NotificationSound;
	
	UPROPERTY(EditDefaultsOnly, Category="UI")
	TSubclassOf<UPhoneApplicationContainer> ApplicationsContainerClass;

	UPROPERTY(EditDefaultsOnly, Category="Input")
	UInputAction* FocusPhoneAction;

	UPROPERTY(EditDefaultsOnly, Category="Input")
	UInputAction* PullPhoneAction;
	
	UPROPERTY()
	UPhoneApplicationContainer* ApplicationsContainer;

	UPROPERTY()
	AMainCharacter* Owner;

	UPROPERTY()
	ABurlescaPlayerController* PlayerController;

	UPROPERTY()
	UMainCharacterAnimInstance* AnimInstance;
	
	UFUNCTION(BlueprintCallable)
	void PlayNotificationSound();

	UFUNCTION(BlueprintCallable)
	void OnFocusPhoneTriggered();
	
	UFUNCTION(BlueprintCallable)
	void OnPullPhoneTriggered();
};

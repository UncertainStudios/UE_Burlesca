// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MainCharacter/Animation/MainCharacterAnimInstance.h"
#include "UObject/Object.h"
#include "MobilePhoneController.generated.h"

enum class EPhoneState : uint8;
enum class EPhoneApplication : uint8;
class UMainCharacterAnimInstance;
class AMainCharacter;
class UInputAction;
class UMobilePhoneScreen;
class UMobilePhone;

/**
 * 
 */
UCLASS()
class BURLESCA_API UMobilePhoneController : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	void PutPhoneInTheWorld(AActor* situationActor);
	void TakePhoneFromTheWorld();
	void SelectViewedApplication(EPhoneApplication PhoneApplication);
};

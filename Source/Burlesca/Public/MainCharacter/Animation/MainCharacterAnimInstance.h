// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MobilePhone/MobilePhoneEnums.h"
#include "MainCharacterAnimInstance.generated.h"

// DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPhoneIsInHands);
// DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPhoneIsInPocket);
// DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPhoneFocusStateChanged, bool, bIsFocused);
// DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHandIsOutOfFOV);

UENUM(Blueprintable)
enum class EPhoneAnimState : uint8
{
	None,
	PickUp_Pocket,
	PullOut,
	PickUp_Place,
	PutDown_Place,
};

class AMainCharacter;

UCLASS()
class BURLESCA_API UMainCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	
	UFUNCTION()
	void SetPhoneAnimState(EPhoneAnimState AnimState);
protected:
	UPROPERTY(BlueprintReadOnly)
	AMainCharacter* MainCharacter;
	
	UPROPERTY(BlueprintReadOnly)
	float CharacterForwardMovingSpeed;
	
	UPROPERTY(BlueprintReadOnly)
	float CharacterRightMovingSpeed;

	UPROPERTY(BlueprintReadOnly)
	bool bIsCharacterMoving;

	UPROPERTY(BlueprintReadWrite)
	float RightArmAnimationWeight;

	UPROPERTY(BlueprintReadWrite)
	bool bCanChangePhoneState = true;

	UPROPERTY(BlueprintReadWrite)
	EPhoneState PhoneState = EPhoneState::Placed;
};

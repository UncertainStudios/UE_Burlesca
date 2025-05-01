// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter/Animation/MainCharacterAnimInstance.h"
#include "MainCharacter/MainCharacter.h"
#include "MainCharacter/MainCharacterComponents/TP_MainCharMovementComponent.h"

void UMainCharacterAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	MainCharacter = Cast<AMainCharacter>(TryGetPawnOwner());
}

void UMainCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if(MainCharacter == nullptr)
	{
		return;
	}

	CharacterForwardMovingSpeed = MainCharacter->GetCharacterMovementComponent()->GetForwardMovementSpeedRelativeToMax();
	CharacterRightMovingSpeed = MainCharacter->GetCharacterMovementComponent()->GetRightMovementSpeedRelativeToMax();

	if(CharacterForwardMovingSpeed == 0 && CharacterRightMovingSpeed == 0)
	{
		bIsCharacterMoving = false;
	}
	else
	{
		bIsCharacterMoving = true;
	}
}

void UMainCharacterAnimInstance::SetPhoneAnimState(EPhoneAnimState AnimState)
{
	
}

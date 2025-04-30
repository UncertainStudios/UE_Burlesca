// Fill out your copyright notice in the Description page of Project Settings.

#include "MobilePhone/MobilePhoneController.h"
#include "MobilePhone/MobilePhoneEnums.h"

/*AnimInstance->OnPhoneIsInHands.AddDynamic(this, &UMobilePhoneController::OnPhonePickedUpFromPocket);
	AnimInstance->OnPhoneIsInPocket.AddDynamic(this, &UMobilePhoneController::OnPhonePutDownToPocket);
	AnimInstance->OnPhoneFocusStateChanged.AddDynamic(this, &UMobilePhoneController::OnPhoneFocusStateChanged);
	AnimInstance->OnHandIsOutOfFOV.AddDynamic(this, &UMobilePhoneController::SwitchPhoneVisibility);*/

/* !!! void UMobilePhoneController::OnPhoneFocusStateChanged(bool bIsFocused)
{
	UE_LOG(LogTemp, Display, TEXT("OnPhoneFocusStateChanged , isFocused = %d"), bIsFocused);
	
	bIsPhoneFocused = bIsFocused;
	bCanChangePhoneFocusState = true;
	bCanChangePhoneSituation = true;

	if(!bIsFocused)
	{
		MainCharacter->PlayAllPlayerServicies();
		PlayerController->HideCursor();
	}
	else
	{
		MobilePhone->OnPhoneFocused();
		PlayerController->ShowCursor();
	}
} !!! */

void UMobilePhoneController::PutPhoneInTheWorld(AActor* situationActor)
{
}

void UMobilePhoneController::TakePhoneFromTheWorld()
{
}

void UMobilePhoneController::SelectViewedApplication(EPhoneApplication phoneApplication)
{
}
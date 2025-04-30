// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter/Animation/AnimNotifies/AnimNotify_TogglePhonePowerState.h"

#include "Kismet/GameplayStatics.h"
#include "MainCharacter/MainCharacter.h"
#include "MobilePhone/MobilePhone.h"

void UAnimNotify_TogglePhonePowerState::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
                                               const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);
	if(AMainCharacter* MainCharacter = Cast<AMainCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(),0)))
	{
		if(UMobilePhone* MobilePhone = MainCharacter->GetPhoneComponent())
		{
			MobilePhone->TogglePower();
		}
	}
}

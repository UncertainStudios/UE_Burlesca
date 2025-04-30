// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter/Animation/AnimNotifies/AnimNotify_TogglePhoneVisibility.h"
#include "Kismet/GameplayStatics.h"
#include "MainCharacter/MainCharacter.h"
#include "MobilePhone/MobilePhone.h"

class AMainCharacter;

void UAnimNotify_TogglePhoneVisibility::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
                                               const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);
	if(AMainCharacter* MainCharacter = Cast<AMainCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(),0)))
	{
		if(UMobilePhone* MobilePhone = MainCharacter->GetPhoneComponent())
		{
			MobilePhone->ToggleVisibility();
		}
	}
}

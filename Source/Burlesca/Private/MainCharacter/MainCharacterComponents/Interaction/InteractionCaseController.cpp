// Fill out your copyright notice in the Description page of Project Settings.

#include "MainCharacter/MainCharacterComponents/Interaction/InteractionCaseController.h"
#include "HUD/GameplayHUD.h"
#include "HUD/InteractionView.h"
#include "InteractableComponents/Interactable.h"

void UInteractionCaseController::Init()
{
	InteractionView = Cast<AGameplayHUD>(GetWorld()->GetFirstPlayerController()->GetHUD())->GetInteractionView();
}

void UInteractionCaseController::InteractableFound(IInteractable* Interactable)
{
	if(CurrentInteractable)
	{
		if(CurrentInteractable == Interactable)
		{
			return;
		}
		
		CurrentInteractable->EndFocus();
		InteractionView->ClearWidget();
	}

	CurrentInteractable = Interactable;
	switch(CurrentInteractable->GetInteractionActivityState())
	{
		case EInteractionActivityState::Active:
			CurrentInteractable->StartFocus(4);
			InteractionView->ShowItemName(CurrentInteractable->GetObjectName());
			InteractionView->ShowInteracableAimBullet();
			break;
		
		case EInteractionActivityState::LockedActive:
			CurrentInteractable->StartFocus(5);
			InteractionView->ShowItemName(CurrentInteractable->GetObjectName());
			InteractionView->ShowLockedItemTooltip(CurrentInteractable->GetLockedTooltip());
			InteractionView->ShowLockedAimBullet();
			break;

		case EInteractionActivityState::Disabled:
			InteractableNotFound();		
			break;
	}
}

void UInteractionCaseController::InteractableNotFound()
{
	if(CurrentInteractable)
	{
		CurrentInteractable->EndFocus();
		InteractionView->ClearWidget();
	}
	
	CurrentInteractable = nullptr;
}

void UInteractionCaseController::InteractionCalled()
{
	if(CurrentInteractable)
	{
		switch(CurrentInteractable->GetInteractionActivityState())
		{
			case EInteractionActivityState::Active:
				CurrentInteractable->Interact();
				break;
			
			case EInteractionActivityState::LockedActive:
				InteractionView->PlayInteractionLockedAnimation();
				break;
		}
	}
}

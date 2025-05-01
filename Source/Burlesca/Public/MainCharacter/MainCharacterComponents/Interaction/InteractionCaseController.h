// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractionCaseController.generated.h"

class UInteractionView;
class UTP_BaseInteractionComponent;
class IInteractable;
class AGameplayHUD;

UCLASS()
class BURLESCA_API UInteractionCaseController : public UObject
{
	GENERATED_BODY()

public:
	void Init();
	void InteractableFound(IInteractable* Interactable);
	void InteractableNotFound();
	void InteractionCalled();

private:
	UPROPERTY()
	UInteractionView* InteractionView;
	
	IInteractable* CurrentInteractable;
};

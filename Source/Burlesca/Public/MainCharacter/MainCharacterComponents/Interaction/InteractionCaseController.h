// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Framework/DependencyInjection/Inject.h"
#include "InteractionCaseController.generated.h"

class UInteractionView;
class UTP_BaseInteractableObject;
class IInteractable;
class AGameplayHUD;

UCLASS()
class BURLESCA_API UInteractionCaseController : public UObject, public IInject
{
	GENERATED_BODY()

public:
	virtual void Inject(UDependencyContainer* Container) override;
	
	void InteractableFound(IInteractable* Interactable);
	void InteractableNotFound();

	void InteractionCalled();

private:

	UPROPERTY()
	UInteractionView* InteractionView;
	
	IInteractable* CurrentInteractable;
};

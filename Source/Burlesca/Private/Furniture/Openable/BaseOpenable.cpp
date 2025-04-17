// Fill out your copyright notice in the Description page of Project Settings.

#include "Furniture/OPenable/BaseOpenable.h"
#include "InteractableComponents/BaseInteractableComponent.h"

ABaseOpenable::ABaseOpenable()
{
	InteractableComponent = CreateDefaultSubobject<UTP_BaseInteractableComponent>(TEXT("InteractableComponent"));
}

void ABaseOpenable::BeginPlay()
{
	Super::BeginPlay();

	InteractableComponent->OnInteract.AddDynamic(this, &ABaseOpenable::OnInteract);
}

void ABaseOpenable::OnInteract()
{
	if(bIsOpened)
		Close();
	else
		Open();
}

void ABaseOpenable::Open()
{
	OnOpenStarted.Broadcast();
}

void ABaseOpenable::Close()
{
	OnCloseStarted.Broadcast();
}

void ABaseOpenable::OpenFinished()
{
	OnOpened.Broadcast();
}

void ABaseOpenable::CloseFinished()
{
	OnClosed.Broadcast();
}

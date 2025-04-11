// Fill out your copyright notice in the Description page of Project Settings.

#include "MainCharacter/MainCharacterComponents/Interaction/BaseInteractableObject.h"

void UTP_BaseInteractableObject::Inject_Implementation(UDependencyContainer* container)
{
	
}


void UTP_BaseInteractableObject::BeginPlay()
{
	Super::BeginPlay();
	
	if(!bUseCustomOutlineMesh)
	{
		OutlineMesh = GetOwner()->FindComponentByClass<UStaticMeshComponent>();
	}	
}

void UTP_BaseInteractableObject::StartFocus_Implementation(int stencilValue)
{
	if(!OutlineMesh)
		return;
	
	OutlineMesh->SetRenderCustomDepth(true);
	OutlineMesh->SetCustomDepthStencilValue(stencilValue);		
}

void UTP_BaseInteractableObject::EndFocus_Implementation()
{
	if(!OutlineMesh)
		return;
	
	OutlineMesh->SetRenderCustomDepth(false);
}

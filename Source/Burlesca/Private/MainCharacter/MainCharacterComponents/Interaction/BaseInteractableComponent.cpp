// Fill out your copyright notice in the Description page of Project Settings.

#include "MainCharacter/MainCharacterComponents/Interaction/BaseInteractableComponent.h"

void UTP_BaseInteractableComponent::Inject_Implementation(UDependencyContainer* container)
{
	
}

void UTP_BaseInteractableComponent::BeginPlay()
{
	Super::BeginPlay();

	TArray<UActorComponent*>targetMeshComponents = GetOwner()->GetComponentsByTag(UStaticMeshComponent::StaticClass(), TEXT("OutlineTarget"));
	if(targetMeshComponents.IsEmpty())
	{
		if(UStaticMeshComponent* defaultMesh = GetOwner()->GetComponentByClass<UStaticMeshComponent>())
			OutlineTargetMeshes.Add(defaultMesh);
		else
			bIsOutlineEnabled = false;
	}
	else
	{
		for(UActorComponent* actorComponent : targetMeshComponents)
		{
			OutlineTargetMeshes.Add(Cast<UStaticMeshComponent>(actorComponent));
		}
	}
}

void UTP_BaseInteractableComponent::Interact_Implementation()
{
	OnInteract.Broadcast();
}

void UTP_BaseInteractableComponent::StartFocus_Implementation(int stencilValue)
{
	OnFocus.Broadcast();
	
	if(!bIsOutlineEnabled && !OutlineTargetMeshes.IsEmpty())
		return;

	for(UStaticMeshComponent* mesh : OutlineTargetMeshes)
	{
		mesh->SetRenderCustomDepth(true);
		mesh->SetCustomDepthStencilValue(stencilValue);	
	}
}

void UTP_BaseInteractableComponent::EndFocus_Implementation()
{
	OnUnfocus.Broadcast();
	
	if(!OutlineTargetMeshes.IsEmpty())
		return;
	
	for(UStaticMeshComponent* mesh : OutlineTargetMeshes)
	{
		mesh->SetRenderCustomDepth(false);
	}
}

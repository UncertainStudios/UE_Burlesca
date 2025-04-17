// Copyright UncertainStudios (c). All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "Framework/DependencyInjection/Inject.h"
#include "UObject/Object.h"
#include "BaseInteractableComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInteractEvent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFocusEvent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnUnfocusEvent);

UCLASS(meta = (BlueprintSpawnableComponent), ClassGroup=("Interactable|BaseInteractableComponent"), Blueprintable, BlueprintType, EditInlineNew)
class BURLESCA_API UTP_BaseInteractableComponent : public UActorComponent, public IInteractable, public IInject
{
	GENERATED_BODY()
	
public:
	UTP_BaseInteractableComponent() { PrimaryComponentTick.bCanEverTick = false; bWantsInitializeComponent = true; }
	
	UFUNCTION(BlueprintNativeEvent)
	void Inject(UDependencyContainer* Container) override;
	virtual void BeginPlay() override;
	
	UFUNCTION(BlueprintNativeEvent)
	void StartFocus(int stencilValue) override;
	
	UFUNCTION(BlueprintNativeEvent)
	void EndFocus() override;

	UFUNCTION(BlueprintNativeEvent)
	void Interact() override;

	UFUNCTION(BlueprintCallable)
	virtual EInteractionActivityState GetInteractionActivityState() override { return InteractionActivityState; }

	UFUNCTION(BlueprintCallable)
	virtual FText GetObjectName() override { return ObjectName; }

	UFUNCTION(BlueprintCallable)
	virtual FText GetLockedTooltip() override { return LockedTooltip; }

	UFUNCTION(BlueprintCallable)
	void SetOutlineTargetMeshes(TArray<UStaticMeshComponent*> meshes) { OutlineTargetMeshes = meshes; }

	UPROPERTY(BlueprintAssignable, Category="Events")
	FOnInteractEvent OnInteract;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FOnFocusEvent OnFocus;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FOnUnfocusEvent OnUnfocus;
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction Info")
	EInteractionActivityState InteractionActivityState = EInteractionActivityState::Active;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction Info")
	FText ObjectName = FText::FromString("InteractableObject");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction Info")
	FText LockedTooltip = FText::GetEmpty();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction Info")
	bool bIsOutlineEnabled = true;
	
	UPROPERTY(BlueprintReadWrite)
	TArray<UStaticMeshComponent*> OutlineTargetMeshes;
};

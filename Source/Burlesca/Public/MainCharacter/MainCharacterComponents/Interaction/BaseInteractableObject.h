// Copyright UncertainStudios (c). All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "Framework/DependencyInjection/Inject.h"
#include "UObject/Object.h"
#include "BaseInteractableObject.generated.h"

UCLASS(Blueprintable)
class BURLESCA_API UTP_BaseInteractableObject : public UActorComponent, public IInteractable, public IInject
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintNativeEvent)
	void Inject(UDependencyContainer* Container) override;
	
	UFUNCTION(BlueprintNativeEvent)
	void StartFocus(int stencilValue) override;
	
	UFUNCTION(BlueprintNativeEvent)
	void EndFocus() override;

	UFUNCTION(BlueprintImplementableEvent)
	void Interact() override;

	UFUNCTION(BlueprintCallable)
	virtual void UseCustomOutlineMesh(UStaticMeshComponent* mesh) { bUseCustomOutlineMesh = true; OutlineMesh = mesh; }
	
	virtual EInteractionActivityState GetInteractionActivityState() override { return InteractionActivityState; }
	virtual FText GetObjectName() override { return ObjectName; }
	virtual FText GetLockedTooltip() override { return LockedTooltip; }
	virtual void BeginPlay() override;

protected:
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, DisplayName = "Initial Interaction Activity State", Category = "Interaction Info")
	EInteractionActivityState InteractionActivityState = EInteractionActivityState::Active;

	UPROPERTY(BlueprintReadWrite)
	UStaticMeshComponent* OutlineMesh;
	
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName = "Use Custom Mesh For Outline", Category = "Interaction Info")
	UPROPERTY(BlueprintReadWrite)
	bool bUseCustomOutlineMesh = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName = "Diaplay Name", Category = "Interaction Info")
	FText ObjectName;
	FText LockedTooltip = FText::GetEmpty();
};

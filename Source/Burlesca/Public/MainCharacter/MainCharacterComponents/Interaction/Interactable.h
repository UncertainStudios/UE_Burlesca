// Copyright Uncertain Studios (c). All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Interactable.generated.h"

UENUM(BlueprintType)
enum class EInteractionActivityState : uint8
{
	None = 0,
	Active = 1,
	LockedActive = 2 UMETA(DisplayName = "Locked"),
	Disabled = 3,
};

UINTERFACE(MinimalAPI)
class UInteractable : public UInterface
{
	GENERATED_BODY()
};

class BURLESCA_API IInteractable
{
	GENERATED_BODY()
	
public:	
	virtual void StartFocus(int stencilValue) = 0;
	virtual void EndFocus() = 0;
	virtual void Interact() = 0;
	virtual FText GetObjectName() = 0;
	virtual FText GetLockedTooltip() = 0;
	virtual EInteractionActivityState GetInteractionActivityState() = 0;
};

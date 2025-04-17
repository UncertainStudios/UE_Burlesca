// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DialogueInvocationInfo_Base.h"
#include "InteractableComponents/Interactable.h"
#include "UObject/Object.h"
#include "ChangeObjectInteractionActivityStateDialogueInvocationInfo.generated.h"

enum class EInteractionActivityState : uint8;
enum class EInteractableObjectActivityState : uint8;

UENUM(BlueprintType)
enum class EObjectToChange : uint8
{
	None,
	Guitar,
	Xylophone,
	Metronome
};

UCLASS()
class BURLESCA_API UChangeObjectInteractionActivityStateDialogueInvocationInfo : public UDialogueInvocationInfo_Base
{
	GENERATED_BODY()

public:
	virtual FDialogueInvocationParams GetInvocationParams() override
	{
		return FDialogueInvocationParams(FVariant(static_cast<uint8>(ObjectToChange)), FVariant(static_cast<uint8>(TargetActivityState)));
	}

protected:
	UPROPERTY(EditAnywhere)
	EObjectToChange ObjectToChange = EObjectToChange::None;

	UPROPERTY(EditAnywhere)
	EInteractionActivityState TargetActivityState = EInteractionActivityState::Active;
};

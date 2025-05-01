// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "DialogueInvocationRegistry.generated.h"


struct FDialogueInvocationParams;
enum class EDialogueInvocationType : uint16;

UCLASS()
class BURLESCA_API UDialogueInvocationRegistry : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Invoke(EDialogueInvocationType conditionType, FDialogueInvocationParams params);
	
	UPROPERTY()
	TMap<EDialogueInvocationType, UObject*> Invocations;
};

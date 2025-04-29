// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/WorldSettings.h"
#include "BurlescaWorldSettings.generated.h"

class UDialogueGraphAsset;
class UConditionSetAsset;
class ASceneContext;
class UDependencyContainer;
/**
 * 
 */
UCLASS()
class BURLESCA_API ABurlescaWorldSettings : public AWorldSettings
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, Category="Condition Registry")
	UConditionSetAsset* ConditionSetAsset;

	UPROPERTY(EditAnywhere, Category="Dialogues")
	TArray<UDialogueGraphAsset*> WorldDialogues;
};

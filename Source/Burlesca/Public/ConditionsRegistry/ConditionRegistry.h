// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ConditionParams.h"
#include "ConditionType.h"
#include "Tween/Tween.h"
#include "UObject/Object.h"
#include "ConditionRegistry.generated.h"

/**
 * 
 */
UCLASS()
class BURLESCA_API UConditionRegistry : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	bool CheckCondition(EConditionType conditionType, FConditionParams params);
	
	UPROPERTY()
	TMap<EConditionType, UObject*> Conditions;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ConditionAssetConfig.h"
#include "ConditionSetAsset.generated.h"

UCLASS(BlueprintType)
class BURLESCA_API UConditionSetAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FConditionAssetConfig Config;
};

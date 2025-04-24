// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

USTRUCT(BlueprintType)
struct FConditionAssetConfig
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bEnable_HasItem = false;
};

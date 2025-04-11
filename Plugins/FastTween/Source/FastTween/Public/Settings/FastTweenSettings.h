// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FastTweenEnumerable.h"
#include "UObject/Object.h"
#include "FastTweenSettings.generated.h"

UCLASS(Blueprintable, BlueprintType)
class FASTTWEEN_API UFastTweenSettings : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tween Settings")
	EAutoPLay DefaultAutoPlay = EAutoPLay::All;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tween Settings")
	EEaseType DefaultEaseType = EEaseType::Linear;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tween Settings")
	bool DefaultAutoKill = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tween Settings")
	ELoopType DefaultLoopType = ELoopType::Restart;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tween Settings")
	int32 MaxActiveTweeners = 200;
};

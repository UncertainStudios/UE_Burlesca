// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tween.h"
#include "MarginTween.generated.h"

/**
 * 
 */
UCLASS()
class FASTTWEEN_API UMarginTween : public UTween
{
	GENERATED_BODY()

public:
	TTweenGetter<FMargin> Getter;
	TTweenSetter<FMargin> Setter;

	FMargin StartValue;
	FMargin EndValue;

	void Setup(TTweenGetter<FMargin> getter, TTweenSetter<FMargin>& setter, FMargin endValue, float duration)
	{
		Super::Setup();
		
		Getter = getter;
		Setter = setter;
		StartValue = Getter();
		EndValue = endValue;
		Duration = duration;
		FullDuration = duration;
	}

	void ApplyPosition(float position) override;
};

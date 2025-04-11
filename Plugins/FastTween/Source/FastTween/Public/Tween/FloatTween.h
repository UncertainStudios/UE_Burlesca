// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tween.h"
#include "FloatTween.generated.h"

/**
 * 
 */
UCLASS()
class FASTTWEEN_API UFloatTween : public UTween
{
	GENERATED_BODY()
	
public:	
	TTweenGetter<float> Getter;
	TTweenSetter<float> Setter;

	float StartValue;
	float EndValue;

	void Setup(TTweenGetter<float> getter, TTweenSetter<float>& setter, float endValue, float duration)
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

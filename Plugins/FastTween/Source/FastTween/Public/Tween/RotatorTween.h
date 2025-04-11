// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tween.h"
#include "RotatorTween.generated.h"

/**
 * 
 */
UCLASS()
class FASTTWEEN_API URotatorTween : public UTween
{
	GENERATED_BODY()

public:	
	TTweenGetter<FRotator> Getter;
	TTweenSetter<FRotator> Setter;

	FRotator StartValue;
	FRotator EndValue;

	void Setup(TTweenGetter<FRotator> getter, TTweenSetter<FRotator>& setter, FRotator endValue, float duration)
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

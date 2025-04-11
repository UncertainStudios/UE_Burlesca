// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tween.h"
#include "VectorTween.generated.h"

/**
 * 
 */
UCLASS()
class FASTTWEEN_API UVectorTween : public UTween
{
	GENERATED_BODY()

public:	
	TTweenGetter<FVector> Getter;
	TTweenSetter<FVector> Setter;

	FVector StartValue;
	FVector EndValue;
	
	void Setup(TTweenGetter<FVector> getter, TTweenSetter<FVector>& setter, FVector endValue, float duration)
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

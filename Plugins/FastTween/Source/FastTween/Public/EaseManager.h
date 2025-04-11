// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

enum class EEaseType : uint8;
class UTween;
/**
 * 
 */
class FASTTWEEN_API FEaseManager
{
public:
	static float Evaluate(UTween* t, float time, float duration, float overshootOrAmplitude, float period);
	static float Evaluate(EEaseType easeType, float time, float duration, float overshootOrAmplitude, float period, bool isReversed);
	
private:
	static float pi;
	static float piOverTwo;
	static float twoPi;
};

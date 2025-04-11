// Fill out your copyright notice in the Description page of Project Settings.


#include "Tween/FloatTween.h"

void UFloatTween::ApplyPosition(float position)
{
	Setter(StartValue + (EndValue - StartValue) * position);
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "Tween/MarginTween.h"

void UMarginTween::ApplyPosition(float position)
{
	Setter(StartValue + (EndValue - StartValue) * position);
}
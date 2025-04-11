// Fill out your copyright notice in the Description page of Project Settings.


#include "Tween/VectorTween.h"

void UVectorTween::ApplyPosition(float position)
{
	Setter(StartValue + (EndValue - StartValue) * position);
}

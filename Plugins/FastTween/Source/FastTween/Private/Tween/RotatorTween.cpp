// Fill out your copyright notice in the Description page of Project Settings.


#include "Tween/RotatorTween.h"

void URotatorTween::ApplyPosition(float position)
{
    Setter(StartValue + (EndValue - StartValue) * position);
}
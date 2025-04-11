// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SlotTweenFunctions.generated.h"

class UWidget;
class UTween;

#define DOPadding(target, endValue, duration) USlotTweenFunctions::DoPadding(target, endValue, duration)
#define DOPaddingLeft(target, endValue, duration) USlotTweenFunctions::DoPaddingLeft(target, endValue, duration)
#define DOPaddingTop(target, endValue, duration) USlotTweenFunctions::DoPaddingTop(target, endValue, duration)
#define DOPaddingRight(target, endValue, duration) USlotTweenFunctions::DoPaddingRight(target, endValue, duration)
#define DOPaddingBottom(target, endValue, duration) USlotTweenFunctions::DoPaddingBottom(target, endValue, duration)

UCLASS()
class FASTTWEEN_API USlotTweenFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Tweening|ShortcutMethods")
	static UTween* DoPadding(UWidget* target, const FMargin& endValue, float duration);

	UFUNCTION(BlueprintCallable, Category = "Tweening|ShortcutMethods")
	static UTween* DoPaddingLeft(UWidget* target, const float endValue, float duration);

	UFUNCTION(BlueprintCallable, Category = "Tweening|ShortcutMethods")
	static UTween* DoPaddingTop(UWidget* target, const float endValue, float duration);

	UFUNCTION(BlueprintCallable, Category = "Tweening|ShortcutMethods")
	static UTween* DoPaddingRight(UWidget* target, const float endValue, float duration);

	UFUNCTION(BlueprintCallable, Category = "Tweening|ShortcutMethods")
	static UTween* DoPaddingBottom(UWidget* target, const float endValue, float duration);
};

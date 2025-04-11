// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FastTweenComponent.h"
#include "UObject/Object.h"
#include "FastTweenManager.generated.h"

class AFastTweenComponent;
class UTween;

UCLASS()
class FASTTWEEN_API UFastTweenManager : public UObject
{
	GENERATED_BODY()

public:
	template <typename T, typename = std::enable_if_t<std::is_base_of_v<UTween, T>>> 
	static T* GetTween()
	{
		T* t = NewObject<T>(AFastTweenComponent::Instance());
		check(t);
		AddActiveTween(Cast<UTween>(t));
		return t;
	}
	
	static void Update(float deltaSeconds);
	static void ClearTweens();
	static void KillTween(UTween* tween);

	static TArray<UTween*> activeTweens;
	static TArray<UTween*> activationQueue;
	static TArray<UTween*> killQueue;
private:
	static bool hasActiveTweens;
	static bool isClearingTweens;
	
	static void AddActiveTween(UTween* tween);
	static void DestroyTween(UTween* tween);
};

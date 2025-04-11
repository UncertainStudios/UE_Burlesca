#pragma once

#include "CoreMinimal.h"
#include "FastTweenEnumerable.h"
#include "FastTweenManager.h"

class UTween;
class UFastTweenSettings;

DECLARE_LOG_CATEGORY_EXTERN(FastTween, Log, All);

template <typename T>
using TTweenGetter = TFunction<T()>;

template <typename T>
using TTweenSetter = TFunction<void(T)>;

class FFastTweenCore
{
public:
	static UTween* To(TTweenGetter<float> getter, TTweenSetter<float> setter, float endValue, float duration);
	static UTween* To(TTweenGetter<FVector> getter, TTweenSetter<FVector> setter, FVector endValue, float duration);
	static UTween* To(TTweenGetter<FRotator> getter, TTweenSetter<FRotator> setter, FRotator endValue, float duration);
	static UTween* To(TTweenGetter<FMargin> getter, TTweenSetter<FMargin> setter, FMargin endValue, float duration);

	static void OnWorldInitialized(UWorld* world, FWorldInitializationValues initValues)
	{
		if(world->IsGameWorld())
			Init(world);
	}

	static void OnWorldPreDestroy(UWorld* world)
	{
		if(world->IsGameWorld())
			Destroy(world);
	}

	static EAutoPLay defaultAutoPlay;
	static EEaseType defaultEaseType;
	static ELoopType defaultLoopType;
	static float defaultOvershootOrAmplitude;
	static float defaultPeriod;
	static bool defaultAutoKill;
	static int32 maxActiveTweeners;
	
private:
	static bool bIsInitialized;
	
	static void Init(UWorld* world);
	static void Destroy(UWorld* world);
	static bool InitCheck() { return bIsInitialized; }
};









/*
static bool IsApplicationPlaying()
{
if(GEngine)
{
UWorld* world = GEngine->GetWorldContexts()[0].World();
return world && world->IsGameWorld();
}
return false;
}
*/
#include "FastTweenCore.h"
#include "FastTweenComponent.h"
#include "Settings/FastTweenSettings.h"
#include "Tween/FloatTween.h"
#include "Tween/MarginTween.h"
#include "Tween/RotatorTween.h"
#include "Tween/VectorTween.h"

DEFINE_LOG_CATEGORY(FastTween)

bool FFastTweenCore::bIsInitialized = false;

EAutoPLay FFastTweenCore::defaultAutoPlay = EAutoPLay::All;
EEaseType FFastTweenCore::defaultEaseType = EEaseType::Linear;
ELoopType FFastTweenCore::defaultLoopType = ELoopType::Restart;
bool FFastTweenCore::defaultAutoKill = true;
float FFastTweenCore::defaultOvershootOrAmplitude = 1.70158f;
float FFastTweenCore::defaultPeriod = 0.5f;
int32 FFastTweenCore::maxActiveTweeners = 0;

void FFastTweenCore::Init(UWorld* world)
{
	if(bIsInitialized)
		return;
	
	UFastTweenSettings* settings = Cast<UFastTweenSettings>(StaticLoadObject(UFastTweenSettings::StaticClass(), nullptr, TEXT("/Game/FastTween/FastTweenSettings")));
	if(settings)
	{
		AFastTweenComponent::Create(world);
		bIsInitialized = true;
		defaultAutoPlay = settings->DefaultAutoPlay;
		defaultEaseType = settings->DefaultEaseType;
		defaultLoopType = settings->DefaultLoopType;
		defaultAutoKill = settings->DefaultAutoKill;
		maxActiveTweeners = settings->MaxActiveTweeners;
	}
}

void FFastTweenCore::Destroy(UWorld* world)
{
	UFastTweenManager::ClearTweens();
	bIsInitialized = false;
}

UTween* FFastTweenCore::To(TTweenGetter<float> getter, TTweenSetter<float> setter, float endValue, float duration)
{
	InitCheck();
	UFloatTween* t = UFastTweenManager::GetTween<UFloatTween>();
	check(t);
	t->Setup(getter, setter, endValue, duration);
	return t;
}

UTween* FFastTweenCore::To(TTweenGetter<FVector> getter, TTweenSetter<FVector> setter, FVector endValue, float duration)
{
	InitCheck();
	UVectorTween* t = UFastTweenManager::GetTween<UVectorTween>();
	check(t);
	t->Setup(getter, setter, endValue, duration);
	return t;
}

UTween* FFastTweenCore::To(TTweenGetter<FRotator> getter, TTweenSetter<FRotator> setter, FRotator endValue, float duration)
{
	InitCheck();
	URotatorTween* t = UFastTweenManager::GetTween<URotatorTween>();
	t->Setup(getter, setter, endValue, duration);
	return t;
}

UTween* FFastTweenCore::To(TTweenGetter<FMargin> getter, TTweenSetter<FMargin> setter, FMargin endValue, float duration)
{
	InitCheck();
	UMarginTween* t = UFastTweenManager::GetTween<UMarginTween>();
	t->Setup(getter, setter, endValue, duration);
	return t;
}

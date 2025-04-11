// Fill out your copyright notice in the Description page of Project Settings.

#include "FastTweenManager.h"
#include "Tween/Tween.h"

bool UFastTweenManager::hasActiveTweens = false;
TArray<UTween*> UFastTweenManager::activeTweens;
TArray<UTween*> UFastTweenManager::activationQueue;
TArray<UTween*> UFastTweenManager::killQueue;
bool UFastTweenManager::isClearingTweens = false;

void UFastTweenManager::AddActiveTween(UTween* tween)
{
	tween->bIsActive = true;
	hasActiveTweens = true;
	activationQueue.Add(tween);
}

void UFastTweenManager::KillTween(UTween* tween)
{
	tween->bIsActive = false;
	killQueue.Add(tween);
}

void UFastTweenManager::DestroyTween(UTween* tween)
{
	tween->bIsActive = false;
	tween->bIsPlaying = false;
	activeTweens.RemoveSingle(tween);
	if(tween)
		tween->ConditionalBeginDestroy();
}

void UFastTweenManager::Update(float deltaSeconds)
{
	if(isClearingTweens)
		return;

	for(UTween* tween : activationQueue)
	{
		activeTweens.Add(tween);
	}
	activationQueue.Empty();
	
	for(UTween* tween : killQueue)
	{
		DestroyTween(tween);
	}
	killQueue.Empty();
	
	for(UTween* tween : activeTweens)
	{
		float elapsed = deltaSeconds;
		
		if(tween)
		{
			if(!tween->bIsPlaying)
				return;

			if(!tween->bIsActive)
				KillTween(tween);

			if(!tween->bIsDelayCompleted)
			{
				float delayOvershoot = tween->UpdateDelay(deltaSeconds);
				
				if(!tween->bIsDelayCompleted)
					return;

				elapsed = delayOvershoot;
			}

			if(tween)
			{
				tween->UpdatePosition(elapsed);
			}
		}
	}
}

void UFastTweenManager::ClearTweens()
{
	isClearingTweens = true;
	for(UTween* tween : activationQueue)
	{
		tween->bIsActive = false;
		tween->bIsPlaying = false;
		tween->ConditionalBeginDestroy();
	}
	activationQueue.Empty();

	for(UTween* tween : killQueue)
	{
		tween->bIsActive = false;
		tween->bIsPlaying = false;
		tween->ConditionalBeginDestroy();
	}
	killQueue.Empty();

	for(UTween* tween : activeTweens)
	{
		tween->bIsActive = false;
		tween->bIsPlaying = false;
		tween->ConditionalBeginDestroy();
	}
	activeTweens.Empty();

	hasActiveTweens = false;
	isClearingTweens = false;
}

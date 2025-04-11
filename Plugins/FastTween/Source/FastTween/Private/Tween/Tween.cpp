// Copyright Uncertain Studios (c). All Rights Reserved.

#include "Tween/Tween.h"
#include "EaseManager.h"

void UTween::Setup()
{
	bAutoKill = FFastTweenCore::defaultAutoKill;
	OvershootOrAmplitude = FFastTweenCore::defaultOvershootOrAmplitude;
	Period = FFastTweenCore::defaultPeriod;
	bIsPlaying = FFastTweenCore::defaultAutoPlay == EAutoPLay::All;
	LoopType = FFastTweenCore::defaultLoopType;
	EaseType = FFastTweenCore::defaultEaseType;

	OnStart.Broadcast();
}

float UTween::UpdateDelay(float deltaTime)
{
	if (deltaTime > Delay)
	{
		bIsDelayCompleted = true;
		return deltaTime - Delay;
	}

	Delay -= deltaTime;
	return 0.0f;
}

void UTween::UpdatePosition(float deltaTime)
{
	Elapsed += deltaTime;;
	
	ApplyPosition(FEaseManager::Evaluate(this, Elapsed, Duration, OvershootOrAmplitude, Period));
	if(Elapsed >= Duration)
	{
		Elapsed = Duration;
		TargetPositionReached();
	}
}

UTween* UTween::Flip()
{
	bIsReversed = !bIsReversed;
	Elapsed = Duration - Elapsed;
	return this;
}

UTween* UTween::Play()
{
	OnPlay.Broadcast();
	bIsPlaying = true;
	return this;
}

UTween* UTween::Stop()
{
	OnStop.Broadcast();
	TargetPositionReached();
	return this;
}

UTween* UTween::Pause()
{
	OnPause.Broadcast();
	bIsPlaying = true;
	return this;
}

UTween* UTween::SetAutoKill(bool autoKill)
{
	bAutoKill = autoKill;
	return this;
}

UTween* UTween::SetEaseType(EEaseType easeType)
{
	EaseType = easeType;
	return this;
}

void UTween::TargetPositionReached()
{
	bIsPlaying = false;
	OnComplete.Broadcast();
	if(bAutoKill)
	{
		OnKill.Broadcast();
		UFastTweenManager::KillTween(this);
	}
}

/*void UTween::Reset()
{
	TimeScale = 1.0f;
	bIsBackwards = false;
	ID = -999;
	OnStart.Clear();
	OnPlay.Clear();
	OnPause.Clear();
	OnRewind.Clear();
	OnUpdate.Clear();
	OnStepComplete.Clear();
	OnComplete.Clear();
	OnKill.Clear();
	OnWaypointChanged.Clear();
	Target = nullptr;
	Duration = Position = FullDuration = Delay = ElapsedDelay = 0.0f;
	Loops = 1;
	bIsRelative = false;
	bIsCreationLocked = bIsStartupDone = bPlayedOnce = false;
	bIsPlaying = bIsCompleted = false;
	bIsDelayCompleted = true;
}

bool UTween::DoGoto(UTween t, float toPosition, int32 toCompletedLoops)
{
	if(!t.bIsStartupDone && !t.Startup())
		return true;
	if(!t.bPlayedOnce)
	{
		t.bPlayedOnce = true;
		t.OnStart.Broadcast();
		if(!t.bIsActive)
			return true;

		
	}
}*/

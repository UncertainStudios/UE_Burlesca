// Copyright Uncertain Studios (c). All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FastTweenCore.h"
#include "FastTweenEnumerable.h"
#include "UObject/Object.h"
#include "Tween.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTweenCallback);

UCLASS(BlueprintType, Abstract)
class FASTTWEEN_API UTween : public UObject
{
	GENERATED_BODY()

public:
	void Setup();
	
	UPROPERTY()
	UClass* TweenClass;
	UStruct* TweenStruct;
	
	bool bIsActive = false;
	bool bIsPlaying = false;
	bool bAutoKill = true;
	bool bIsReversed = false;
	bool bIsDelayCompleted = true;

	float UpdateDelay(float deltaTime);
	void UpdatePosition(float deltaTime);

	EEaseType EaseType;
	ELoopType LoopType;
	float OvershootOrAmplitude;
	float Period;
	float Elapsed = 0;
	float Duration;
	float FullDuration;
	float Delay = 0;

	FTweenCallback OnStart;
	FTweenCallback OnPlay;
	FTweenCallback OnPause;
	FTweenCallback OnStop;
	FTweenCallback OnUpdate;
	FTweenCallback OnStepComplete;
	FTweenCallback OnComplete;
	FTweenCallback OnKill;
	
	// Customization functions
	UFUNCTION(BlueprintCallable)
	UTween* Play();

	UFUNCTION(BlueprintCallable)
	UTween* Stop();

	UFUNCTION(BlueprintCallable)
	UTween* Pause();

	UFUNCTION(BlueprintCallable)
	UTween* Flip();
	
	UFUNCTION(BlueprintCallable)
	UTween* SetAutoKill(bool autoKill);

	UFUNCTION(BlueprintCallable)
	UTween* SetEaseType(EEaseType easeType);
protected:
	virtual void ApplyPosition(float position) {}
	void TargetPositionReached();
/*
public:
	UPROPERTY()
	UObject* Target;
	float TimeScale;
	bool bIsBackwards;
	int32 ID;
	FTweenCallback_int OnWaypointChanged;	
	
	//getters
	bool GetIsRelative() const { return bIsRelative; }
	bool GetIsActive() const { return bIsRelative; }
	bool HasLoops() const { return Loops == -1 || Loops > 1; }
	bool GetPlayedOnce() const { return bPlayedOnce; }
	float GetPosition() const { return Position; }	
	
protected:
	float Duration;
	float FullDuration;
	int32 Loops;
	ELoopType LoopType;
	float Delay;
	UClass* T1Class;
	UClass* T2Class;
	bool bIsCreationLocked;
	bool bIsStartupDone;
	int32 CompletedLoops;
	bool bIsPlaying;
	bool bIsCompleted;
	float ElapsedDelay;
	bool bIsDelayCompleted;
	bool bIsRelative;
	bool bPlayedOnce;
	float Position;

	virtual void Reset();
	virtual bool Validate() PURE_VIRTUAL(UTween::Validate, return false; );
	virtual bool Startup() PURE_VIRTUAL(UTween::Startup, return false; );
	virtual float UpdateDelay(float elapsedTime) { return 0.0f; }

	virtual bool ApplyTween (
		float prevPosition,
		int32 prevCompletedLoops,
		int32 newCompletedSteps,
		bool useInversePosition
	) PURE_VIRTUAL(UTween::ApplyTween, return false; );

	static bool DoGoto(UTween t, float toPosition, int32 toCompletedLoops);
*/
};

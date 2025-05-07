// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "FuncLibrary/RhythmGameTypes.h"
#include "InputAction.h"
#include "MelatoninRhythmGamePresenter.generated.h"


class UMelatoninLikeRhythmGameAsset;
class UMelatoninRhythmGameUI;
class UInputMappingContext;

UCLASS(Blueprintable)
class BURLESCA_API UMelatoninRhythmGamePresenter : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	   
public:

    UFUNCTION(BlueprintCallable, Category = "Rhythm Game")
    void StartRhythmGame(UMelatoninLikeRhythmGameAsset* AssetToPlay);

    UFUNCTION(BlueprintCallable, Category = "Rhythm Game")
    void StopRhythmGame();

    UFUNCTION(BlueprintCallable, Category = "Rhythm Game")
    void HandleInput(ENoteSide Side);

    //GameUI
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Melatonin Rythm Game UI")
    TSubclassOf<UMelatoninRhythmGameUI> MelatoninRhythmGameUIClass;
    UPROPERTY()
    UMelatoninRhythmGameUI* MelatoninRhythmGameUI;


    //Asset
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Asset to play")
    UMelatoninLikeRhythmGameAsset* CurrentAsset;

    //InputContext
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
    UInputMappingContext* RhythmGameInputContext;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
    UInputMappingContext* BaseInputContext;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interval Between Note Spawn")
    float IntervalBetweenNoteSpawn = 0.3f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Threshold Note HitTime")
    float ThresholdNoteHitTime = 0.2f;

    UFUNCTION(BlueprintCallable, Category = "Rhythm Game")
    void RestartGame();

    //Inputs Escape/Restart
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
    UInputAction* EscapeRhythmGame;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
    UInputAction* RestartRhythmGame;
protected:
    void SpawnNextNote();

    void ProcessNoteHit(ENoteSide Side, float HitTime);

    //Game Win/Over
    void GameOver();
    void GameWin();

    //InputActions
    void BindInputActions();
    void UnbindInputActions();
    void OnStartDelayFinished();

    FTimerHandle NoteSpawnTimer;
    FTimerHandle SuccessDelayTimer;

    int32 CurrentNoteIndex = 0;
    bool bIsGameActive = false;
    bool bIsGameOver = false;

    bool bIsGameWin = false;

private:
    TArray<uint32> InputBindingHandles;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FuncLibrary/RhythmGameTypes.h"
#include "MelatoninRhythmGameUI.generated.h"

class UMelatoninRhythmNoteWidget;

UCLASS()
class BURLESCA_API UMelatoninRhythmGameUI : public UUserWidget
{
	GENERATED_BODY()

public:

    UFUNCTION(BlueprintImplementableEvent)
    void PlayNoteAnimation(ENoteSide Side);

    UFUNCTION(BlueprintImplementableEvent, Category = "Rhythm UI Anim")
    float StopNoteAnimation(ENoteSide Side);

    UFUNCTION(BlueprintImplementableEvent, Category = "Rhythm Game")
    void ShowGameOver();
    UFUNCTION(BlueprintImplementableEvent, Category = "Rhythm Game")
    void HideGameOver();

    UFUNCTION(BlueprintImplementableEvent, Category = "Rhythm Game")
    void ShowGameWin();
    UFUNCTION(BlueprintImplementableEvent, Category = "Rhythm Game")
    void HideGameWin();

    UFUNCTION(BlueprintImplementableEvent, Category = "Rhythm Game")
    void ShowStartDelayTimer();
    UFUNCTION(BlueprintImplementableEvent, Category = "Rhythm Game")
    void HideStartDelayTimer();

    UFUNCTION(BlueprintImplementableEvent, Category = "Rhythm Game")
    void ShowHitFeedback(ENoteSide Side, bool bSuccess);

};

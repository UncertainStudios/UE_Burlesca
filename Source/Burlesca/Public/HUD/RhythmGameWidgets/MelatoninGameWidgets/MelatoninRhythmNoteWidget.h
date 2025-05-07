// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FuncLibrary/RhythmGameTypes.h"
#include "MelatoninRhythmNoteWidget.generated.h"

/**
 * 
 */
UCLASS()
class BURLESCA_API UMelatoninRhythmNoteWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:


    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void ShowHitEffect(bool bSuccess);
};

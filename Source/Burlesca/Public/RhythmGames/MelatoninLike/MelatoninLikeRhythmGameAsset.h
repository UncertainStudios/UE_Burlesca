// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FuncLibrary/RhythmGameTypes.h"
#include "MelatoninLikeRhythmGameAsset.generated.h"


UCLASS(Blueprintable)
class BURLESCA_API UMelatoninLikeRhythmGameAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
    //Rhythm Notes Array
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rhythm")
    TArray<FRhythmNoteData> MelatoningRythmGameNotes;

    // Note Side InputActions 
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Melatonin Rythm Game Input")
    UInputAction* LeftNoteInput;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Melatonin Rythm Game Input")
    UInputAction* DownNoteInput;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Melatonin Rythm Game Input")
    UInputAction* RightNoteInput;

    //Delay before RythmGame start
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Timing Melatonin Game", meta = (ClampMin = "0.0"))
    float MelatoninRythmGameStartDelay = 1.0f;

};

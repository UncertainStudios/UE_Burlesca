// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "InputAction.h"
#include "RhythmGameTypes.generated.h"

class UMelatoninRhythmNoteWidget;

UENUM(BlueprintType)
enum class ENoteSide : uint8
{
    Left,
    Right,
    Down
};

USTRUCT(BlueprintType)
struct FRhythmNoteData : public FTableRowBase
{
    GENERATED_BODY()

    /*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MelatoninRhythmGame")
    float TargetTime;*/

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MelatoninRhythmGame")
    ENoteSide SideOfNote;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MelatoninRhythmGame", meta = (ClampMin = "0.1")) //not shure bout ClampMin, but should test
    float TravelDuration = 1.0f;

};

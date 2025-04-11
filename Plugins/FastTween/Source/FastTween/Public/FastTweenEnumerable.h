#pragma once

#include "CoreMinimal.h"
#include "FastTweenEnumerable.generated.h"

UENUM(BlueprintType)
enum class ELoopType : uint8
{
	Restart,
	Yoyo
};

UENUM(BlueprintType)
enum class EAutoPLay : uint8
{
	None,
	All,
};

UENUM(BlueprintType)
enum class EEaseType : uint8
{
	Linear,
	InSine,
	OutSine,
	InOutSine,
	InQuad,
	OutQuad,
	InOutQuad,
	InCubic,
	OutCubic,
	InOutCubic,
	InQuart,
	OutQuart,
	InOutQuart,
	InQuint,
	OutQuint,
	InOutQuint,
	InExpo,
	OutExpo,
	InOutExpo,
	InCirc,
	OutCirc,
	InOutCirc,
	InElastic,
	OutElastic,
	InOutElastic,
	InBack,
	OutBack,
	InOutBack,
	InBounce,
	OutBounce,
	InOutBounce,
	Flash,
	InFlash,
	OutFlash,
	InOutFlash,
	INTERNAL_Zero,
	INTERNAL_Custom
};
#include "TweenFunctions/TransformTweenFunctions.h"
#include "FastTweenCore.h"

UTween* UTransformTweenFunctions::DoMove(AActor* target, const FVector endValue, float duration)
{
	UTween* t = FFastTweenCore::To([target] { return target->GetActorLocation(); }, [target](const FVector& value){ target->SetActorLocation(value); }, endValue, duration);
	return t;
}

UTween* UTransformTweenFunctions::DoLocalMoveActor(AActor* target, const FVector endValue, float duration)
{
	UTween* t = FFastTweenCore::To([target] { return target->GetRootComponent()->GetRelativeLocation(); }, [target](const FVector& value){ target->GetRootComponent()->SetRelativeLocation(value); }, endValue, duration);
	return t;
}

UTween* UTransformTweenFunctions::DoLocalMoveComponent(USceneComponent* target, const FVector endValue, float duration)
{
	UTween* t = FFastTweenCore::To([target] { return target->GetRelativeLocation(); }, [target](const FVector& value){ target->SetRelativeLocation(value); }, endValue, duration);
	return t;
}

UTween* UTransformTweenFunctions::DoRotate(AActor* target, const FRotator endValue, float duration)
{
	UTween* t = FFastTweenCore::To([target] { return target->GetActorRotation(); }, [target](const FRotator& value){ target->SetActorRotation(value); }, endValue, duration);
	return t;
}

UTween* UTransformTweenFunctions::DoLocalRotateActor(AActor* target, const FRotator endValue, float duration)
{
	UTween* t = FFastTweenCore::To([target] { return target->GetRootComponent()->GetRelativeRotation(); }, [target](const FRotator& value){ target->GetRootComponent()->SetRelativeRotation(value); }, endValue, duration);
	return t;
}

UTween* UTransformTweenFunctions::DoLocalRotateComponent(USceneComponent* target, const FRotator endValue, float duration)
{
	UTween* t = FFastTweenCore::To([target] { return target->GetRelativeRotation(); }, [target](const FRotator& value){ target->SetRelativeRotation(value); }, endValue, duration);
	return t;
}

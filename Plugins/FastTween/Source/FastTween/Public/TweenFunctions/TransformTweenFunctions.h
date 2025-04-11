#pragma once

#include "CoreMinimal.h"
#include "TransformTweenFunctions.generated.h"

class UTween;

#define DOMove(target, endValue, duration) UTransformTweenFunctions::DoMove(target, endValue, duration)
#define DOLocalMoveActor(target, endValue, duration) UTransformTweenFunctions::DoLocalMoveActor(target, endValue, duration)
#define DOLocalMoveComponent(target, endValue, duration) UTransformTweenFunctions::DoLocalMoveComponent(target, endValue, duration)
#define DORotate(target, endValue, duration) UTransformTweenFunctions::DoRotate(target, endValue, duration)
#define DOLocalRotateActor(target, endValue, duration) UTransformTweenFunctions::DoLocalRotateActor(target, endValue, duration)
#define DOLocalRotateComponent(target, endValue, duration) UTransformTweenFunctions::DoLocalRotateComponent(target, endValue, duration)

UCLASS()
class FASTTWEEN_API UTransformTweenFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Tweening|ShortcutMethods")	
	static UTween* DoMove(AActor* target, const FVector endValue, float duration);

	UFUNCTION(BlueprintCallable, Category = "Tweening|ShortcutMethods")	
	static UTween* DoLocalMoveActor(AActor* target, const FVector endValue, float duration);

	UFUNCTION(BlueprintCallable, Category = "Tweening|ShortcutMethods")	
	static UTween* DoLocalMoveComponent(USceneComponent* target, const FVector endValue, float duration);
	
	UFUNCTION(BlueprintCallable, Category = "Tweening|ShortcutMethods")	
	static UTween* DoRotate(AActor* target, const FRotator endValue, float duration);

	UFUNCTION(BlueprintCallable, Category = "Tweening|ShortcutMethods")	
	static UTween* DoLocalRotateActor(AActor* target, const FRotator endValue, float duration);

	UFUNCTION(BlueprintCallable, Category = "Tweening|ShortcutMethods")	
	static UTween* DoLocalRotateComponent(USceneComponent* target, const FRotator endValue, float duration);
};
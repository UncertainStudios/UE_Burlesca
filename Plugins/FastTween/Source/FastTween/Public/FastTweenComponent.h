// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FastTweenComponent.generated.h"

UCLASS(meta = (DisplayThumbnail = "true"))
class FASTTWEEN_API AFastTweenComponent : public AActor
{
	GENERATED_BODY()

public:
	AFastTweenComponent();
	
	static void Create(UWorld* world);

	static AFastTweenComponent* Instance();

	virtual void Tick(float DeltaSeconds) override;

private:
	static AFastTweenComponent* instance;
};

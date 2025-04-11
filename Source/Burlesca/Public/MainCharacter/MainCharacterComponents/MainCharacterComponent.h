// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MainCharacterComponent.generated.h"

UCLASS()
class UMainCharacterComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	bool IsServiceStoped() const { return bIsServiceStoped; }
	
	virtual void PlayService() { bIsServiceStoped = false; }
	virtual void StopService() { bIsServiceStoped = true; }

protected:
	bool bIsServiceStoped = false;
};

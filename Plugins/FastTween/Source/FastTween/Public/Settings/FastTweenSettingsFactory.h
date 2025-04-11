// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "FastTweenSettingsFactory.generated.h"

/**
 * 
 */
UCLASS()
class FASTTWEEN_API UFastTweenSettingsFactory : public UFactory
{
	GENERATED_BODY()

public:
	UFastTweenSettingsFactory(const FObjectInitializer& ObjectInitializer);

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
};

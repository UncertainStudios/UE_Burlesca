// Fill out your copyright notice in the Description page of Project Settings.

#include "Settings/FastTweenSettingsFactory.h"
#include "Settings/FastTweenSettings.h"

UFastTweenSettingsFactory::UFastTweenSettingsFactory(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SupportedClass = UFastTweenSettings::StaticClass();
	bCreateNew = true;
	bEditAfterNew = true;
}

UObject* UFastTweenSettingsFactory::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName,
	EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	if (InClass != UFastTweenSettings::StaticClass())
	{
		return nullptr;
	}

	return NewObject<UFastTweenSettings>(InParent, InClass, InName, Flags);
}

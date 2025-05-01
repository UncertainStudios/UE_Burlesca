// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ConditionsRegistry/Condition.h"
#include "MusicianInstruments/Guitar/GuitarTuningController.h"
#include "UObject/Object.h"
#include "GuitarSetupCondition.generated.h"

class UGuitarTuningController;
/**
 * 
 */
UCLASS()
class BURLESCA_API UGuitarSetupCondition : public UObject, public ICondition
{
	GENERATED_BODY()

public:
	virtual void Init() override
	{
		/*GuitarSetupController = container->Resolve<UGuitarTuningController>();

		if(GuitarSetupController == nullptr)
		{
			UE_LOG(LogTemp, Error, TEXT("UGuitarSetupResponseCondition::InitDependenciesFromDIContainer - GuitarSetupController is null"));
		}*/
	}
	
	virtual bool CheckCondition(FConditionParams params) override
	{
		return true;//GuitarSetupController->GetIsGuitarSetupCompleted();
	}

protected:
	UPROPERTY()
	UGuitarTuningController* GuitarSetupController = nullptr;
};

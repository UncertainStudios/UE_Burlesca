// Fill out your copyright notice in the Description page of Project Settings.


#include "ConditionsRegistry/ConditionAssetConfig.h"
#include "ConditionsRegistry/ConditionRegistry.h"
#include "ConditionsRegistry/ConditionSetAsset.h"
#include "ConditionsRegistry/Conditions/GuitarSetupCondition.h"
#include "Dialogue/DialogueSystemManager.h"
#include "Core/BurlescaWorldSettings.h"

void UConditionRegistry::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	FConditionAssetConfig& config = Cast<ABurlescaWorldSettings>(GetWorld()->GetWorldSettings())->ConditionSetAsset->Config;

	/* !!! if(config.bEnable_HasItem)
	{
		
	} !!! */
	
	/* !!! UGuitarSetupCondition* guitarSetupResponseCondition = NewObject<UGuitarSetupCondition>(this);
	guitarSetupResponseCondition->InitDependenciesFromDIContainer(Container);
	Conditions.Add(EConditionType::IsGuitarSetUp, guitarSetupResponseCondition); !!! */
}

bool UConditionRegistry::CheckCondition(EConditionType conditionType, FConditionParams params)
{
	UObject** objPtr = Conditions.Find(conditionType);
	if(objPtr)
	{
		UObject* obj = *objPtr;
		if(obj)
		{
			ICondition* condition = Cast<ICondition>(obj);
			return condition->CheckCondition(params);
		}
	}
    
	UE_LOG(DialogueGraphRuntime, Error, TEXT("No condition with name: %d was found"), conditionType);
	return false;
}

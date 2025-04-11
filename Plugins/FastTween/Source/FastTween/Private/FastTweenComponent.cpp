#include "FastTweenComponent.h"
#include "FastTweenCore.h"

AFastTweenComponent* AFastTweenComponent::instance = nullptr;

AFastTweenComponent::AFastTweenComponent() { PrimaryActorTick.bCanEverTick = true; }

void AFastTweenComponent::Create(UWorld* world)
{
	if (instance && instance->IsValidLowLevel())
		return;
		
	instance = world->SpawnActor<AFastTweenComponent>();

	if (instance)
	{
		instance->SetActorLabel(TEXT("[FastTweenComponent]"));
	}
	else
	{
		UE_LOG(FastTween, Error, TEXT("Failed to spawn FastTweenComponent."));
	}
}

AFastTweenComponent* AFastTweenComponent::Instance()
{
	return instance;
}

void AFastTweenComponent::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	UFastTweenManager::Update(DeltaSeconds);
}

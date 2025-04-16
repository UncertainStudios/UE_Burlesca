// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseOpenable.generated.h"

UCLASS()
class BURLESCA_API ABaseOpenable : public AActor
{
	GENERATED_BODY()

public:
	ABaseOpenable();

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Settings|Audio")
	UAudioComponent* AudioComponent;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Furniture/Openable/BaseOpenable.h"
#include "SingleLeafOpenable.generated.h"

UCLASS()
class BURLESCA_API ASingleLeafOpenable : public ABaseOpenable
{
	GENERATED_BODY()

public:
	ASingleLeafOpenable();

protected:
	UPROPERTY(BlueprintReadWrite, Category="Components")
	UStaticMeshComponent* MeshComponent;
};

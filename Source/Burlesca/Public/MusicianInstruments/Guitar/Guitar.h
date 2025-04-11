// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Guitar.generated.h"

UCLASS()
class BURLESCA_API AGuitar : public AActor
{
	GENERATED_BODY()

public:
	AGuitar();
	
protected:
	UFUNCTION(BlueprintCallable)
	void PlayStringSound(int32 stringIndex, int32 fret);

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UStaticMeshComponent* GuitarMesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* GuitarTuningViewPlaceholder;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UStaticMeshComponent* GuitarPegsPlaceholder;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TArray<UStaticMeshComponent*> GuitarPegs;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UAudioComponent* GuitarTuningAudioComponent;
};

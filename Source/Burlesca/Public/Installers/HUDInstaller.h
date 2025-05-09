﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Framework/DependencyInjection/InjectionInstaller.h"
#include "HUDInstaller.generated.h"

class AGameplayHUD;

UCLASS()
class BURLESCA_API AHUDInstaller : public AInjectionInstaller
{
	GENERATED_BODY()

public:
	AHUDInstaller();

	virtual void InstallBindings(UDependencyContainer* Container) override;

protected:
	UPROPERTY(EditInstanceOnly)
	TSubclassOf<AGameplayHUD> HUDClass;

	UPROPERTY(VisibleAnywhere)
	AGameplayHUD* HUD;
};

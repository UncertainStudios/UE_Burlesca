// Fill out your copyright notice in the Description page of Project Settings.


#include "Installers/HUDInstaller.h"
#include "Framework/DependencyInjection/DependencyContainer.h"
#include "HUD/GameplayHUD.h"
#include "HUD/InteractionView.h"

AHUDInstaller::AHUDInstaller()
{
}

void AHUDInstaller::InstallBindings(UDependencyContainer* Container)
{
	HUD = GetWorld()->SpawnActor<AGameplayHUD>(HUDClass);
	check(HUD);
	HUD->InitWidgets();
	
	Container->Bind<AGameplayHUD>()->FromInstance(HUD);
	Container->Bind<UInteractionView>()->FromInstance(HUD->GetInteractionView());
}

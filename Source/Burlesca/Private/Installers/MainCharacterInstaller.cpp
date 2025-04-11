// Fill out your copyright notice in the Description page of Project Settings.


#include "Installers/MainCharacterInstaller.h"
#include "Framework/SignalBus.h"
#include "Framework/DependencyInjection/DependencyContainer.h"
#include "Framework/DependencyInjection/DIHelpersClasses.h"
#include "MainCharacter/MainCharacter.h"
#include "MainCharacter/MainCharacterAnimInstance.h"

void AMainCharacterInstaller::InstallBindings(UDependencyContainer* Container)
{
	if (CharacterClass)
	{
		UWorld* World = GetWorld();
		if (World)
		{
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = GetInstigator();

			MainCharacter = World->SpawnActor<AMainCharacter>(CharacterClass, CharacterSpawnPosition, CharacterSpawnRotation, SpawnParams);
		}	
	}

	MainCharacter->ComponentsInitialization();
	MainCharacterAnimInstance = MainCharacter->CreateAnimInstance(AnimInstanceClass);

	Container->Bind<AMainCharacter>()->FromInstance(MainCharacter);
	Container->Bind<UMainCharacterAnimInstance>()->FromInstance(MainCharacterAnimInstance);
}

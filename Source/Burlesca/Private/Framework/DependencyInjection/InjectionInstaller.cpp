// Fill out your copyright notice in the Description page of Project Settings.

#include "Framework/DependencyInjection/InjectionInstaller.h"

AInjectionInstaller::AInjectionInstaller()
{
	UStaticMeshComponent* staticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Root"));
	SetRootComponent(staticMesh);
}

void AInjectionInstaller::InstallBindings(UDependencyContainer* Container)
{
	
}

void AInjectionInstaller::Start(UDependencyContainer* Container)
{
	
}

// Fill out your copyright notice in the Description page of Project Settings.

#include "MusicianInstruments/Guitar/Guitar.h"
#include "Components/AudioComponent.h"

AGuitar::AGuitar()
{
	GuitarMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GuitarMesh"));
	SetRootComponent(GuitarMesh);
	
	GuitarTuningViewPlaceholder = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GuitarTuningViewPlaceholder"));
	GuitarTuningViewPlaceholder->SetupAttachment(RootComponent);
	GuitarTuningViewPlaceholder->bCastDynamicShadow = false;
	GuitarTuningViewPlaceholder->CastShadow = false;

	GuitarPegsPlaceholder = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GuitarPegsPlaceholder"));
	GuitarPegsPlaceholder->SetupAttachment(RootComponent);

	GuitarPegs.SetNum(6);
	for (int32 i = 5; i >= 0; i--)
	{
		GuitarPegs[i] = CreateDefaultSubobject<UStaticMeshComponent>(FName(*FString::Printf(TEXT("GuitarPeg%i"), i + 1)));
		GuitarPegs[i]->SetupAttachment(GuitarPegsPlaceholder);
	}
	
	GuitarTuningAudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("GuitarTuningAudioComponent"));
	GuitarTuningAudioComponent->SetupAttachment(RootComponent);
}

void AGuitar::PlayStringSound(int32 stringIndex, int32 fret)
{
	/*GuitarTuningAudioComponent->SetParameter(FAudioParameter(TEXT("StringIndex"), stringIndex));
	GuitarTuningAudioComponent->SetParameter(FAudioParameter(TEXT("Pitch"), pitch));
	GuitarTuningAudioComponent->Play();*/
}

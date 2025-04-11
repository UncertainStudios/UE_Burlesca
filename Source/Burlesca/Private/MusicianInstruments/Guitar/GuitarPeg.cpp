// Fill out your copyright notice in the Description page of Project Settings.

#include "MusicianInstruments/Guitar/GuitarPeg.h"

UTP_GuitarPeg::UTP_GuitarPeg()
{
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	//SetRootComponent(StaticMeshComponent);
}

void UTP_GuitarPeg::Select()
{
	StaticMeshComponent->SetRenderCustomDepth(true);
	StaticMeshComponent->SetCustomDepthStencilValue(2);
}

void UTP_GuitarPeg::Deselect()
{
	StaticMeshComponent->SetCustomDepthStencilValue(0);
	StaticMeshComponent->SetRenderCustomDepth(false);
}

void UTP_GuitarPeg::Rotate(ERotationDirection RotationDirection)
{
	if(!bIsRotating && !bIsTuned)
	{
		bIsRotating = true;
		//GetWorldTimerManager().SetTimer(RotationReload, this, &AGuitarPeg::SetIsNotRotating, 0.01f);
		
		switch(RotationDirection)
		{
			case ERotationDirection::Left:
				if(CurrentRotation - 0.02f > MinRotation)
					CurrentRotation -= 0.02f;
			break;
			
			case ERotationDirection::Right:
				if(CurrentRotation + 0.02f < MaxRotation)
					CurrentRotation += 0.02f;
			break;
		}

		UpdateRelativeRotationViaCurrentRotationValue();

		if(CurrentRotation >= 4.98f && CurrentRotation <= 5.02f)
		{
			bIsTuned = true;
			SetComplete();
		}
	}
}

void UTP_GuitarPeg::SetComplete()
{
	StaticMeshComponent->SetRenderCustomDepth(true);
	StaticMeshComponent->SetCustomDepthStencilValue(1);
}

float UTP_GuitarPeg::GetCurrentRotation() const
{
	return CurrentRotation;
}

void UTP_GuitarPeg::InitializeRotationRange()
{
	if (FMath::RandBool()) {
		CurrentRotation = FMath::RandRange(1.5f, 3.5f);
	} else {
		CurrentRotation = FMath::RandRange(6.5f, 8.5f);
	}

	UpdateRelativeRotationViaCurrentRotationValue();
}

void UTP_GuitarPeg::BeginPlay()
{
	Super::BeginPlay();

	InitializeRotationRange();
}

void UTP_GuitarPeg::UpdateRelativeRotationViaCurrentRotationValue()
{
	//SetActorRelativeRotation(FRotator(CurrentRotation * 30, 0.0f, 0.0f));
}

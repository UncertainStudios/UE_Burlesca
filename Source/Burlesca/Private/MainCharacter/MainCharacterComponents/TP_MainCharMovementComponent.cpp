// Copyright Uncertain Studios (c). All Rights Reserved.

#include "MainCharacter/MainCharacterComponents/TP_MainCharMovementComponent.h"
#include "EnhancedInputComponent.h"

UTP_MainCharMovementComponent::UTP_MainCharMovementComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTP_MainCharMovementComponent::Init()
{
}

void UTP_MainCharMovementComponent::SetupInput(UEnhancedInputComponent* input)
{
	Owner = GetOwner();
	check(Owner);
	
	input->BindAction(MoveForwardAction, ETriggerEvent::Triggered, this, &UTP_MainCharMovementComponent::StartAcceleratingForward);
	input->BindAction(MoveRightAction, ETriggerEvent::Triggered, this, &UTP_MainCharMovementComponent::StartAcceleratingRight);
	
	input->BindAction(MoveForwardAction, ETriggerEvent::Completed, this, &UTP_MainCharMovementComponent::StartDeacceleratingForward);
	input->BindAction(MoveRightAction, ETriggerEvent::Completed, this, &UTP_MainCharMovementComponent::StartDeacceleratingRight);

	input->BindAction(RunAction, ETriggerEvent::Started, this, &UTP_MainCharMovementComponent::StartRunning);
	input->BindAction(RunAction, ETriggerEvent::Completed, this, &UTP_MainCharMovementComponent::StopRunning);
}

void UTP_MainCharMovementComponent::StartAcceleratingForward(const FInputActionValue& Value)
{
	if(bIsServiceStoped)
	{
		CurrentForwardMovementDirection = 0;
		return;	
	}
	
	if(Value.Get<float>() == -1)
	{
		CurrentForwardMovementDirection = 2;
	}
	else if(Value.Get<float>() == 1)
	{
		CurrentForwardMovementDirection = 1;
	}
}

void UTP_MainCharMovementComponent::StartAcceleratingRight(const FInputActionValue& Value)
{
	if(bIsServiceStoped)
	{
		CurrentRightMovementDirection = 0;
		return;	
	}
	
	if(Value.Get<float>() == -1)
	{
		CurrentRightMovementDirection = 2;
	}
	else if(Value.Get<float>() == 1)
	{
		CurrentRightMovementDirection = 1;
	}
}

void UTP_MainCharMovementComponent::StartDeacceleratingForward()
{
	CurrentForwardMovementDirection = 0;
}

void UTP_MainCharMovementComponent::StartDeacceleratingRight()
{
	CurrentRightMovementDirection = 0;
}

void UTP_MainCharMovementComponent::StartRunning()
{
	float PreviousSpeed = MaxCharacterMovementSpeed;
	MaxCharacterMovementSpeed = RunSpeed;
	RunSpeed = PreviousSpeed;
}

void UTP_MainCharMovementComponent::StopRunning()
{
	float PreviousSpeed = RunSpeed;
	RunSpeed = MaxCharacterMovementSpeed;
	MaxCharacterMovementSpeed = PreviousSpeed;
}

void UTP_MainCharMovementComponent::UpdateForwardVelocity(float DeltaTime)
{
	float TargetSpeed;

	switch (CurrentForwardMovementDirection)
	{
	case 1: TargetSpeed = MaxCharacterMovementSpeed; break;
	case 2: TargetSpeed = -MaxCharacterMovementSpeed; break;
	default: TargetSpeed = 0.0f; break;
	}

	CurrentForwardMovementSpeed = FMath::FInterpTo(
		CurrentForwardMovementSpeed,
		TargetSpeed,
		DeltaTime,
		AccelerationChangeSpeed
	);
}

void UTP_MainCharMovementComponent::UpdateRightVelocity(float DeltaTime)
{
	float TargetSpeed;

	switch (CurrentRightMovementDirection)
	{
	case 1: TargetSpeed = MaxCharacterMovementSpeed; break;
	case 2: TargetSpeed = -MaxCharacterMovementSpeed; break;
	default: TargetSpeed = 0.0f; break;
	}

	CurrentRightMovementSpeed = FMath::FInterpTo(
		CurrentRightMovementSpeed,
		TargetSpeed,
		DeltaTime,
		AccelerationChangeSpeed
	);
}

void UTP_MainCharMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	check(Owner);

	if(bIsServiceStoped)
	{
		CurrentForwardMovementSpeed = 0;
		CurrentRightMovementSpeed = 0;
	}
	
	UpdateForwardVelocity(DeltaTime);
	UpdateRightVelocity(DeltaTime);
	
	FVector TotalMovement = FVector::ZeroVector;
	if (!FMath::IsNearlyZero(CurrentForwardMovementSpeed))
		TotalMovement += Owner->GetActorForwardVector() * CurrentForwardMovementSpeed * DeltaTime;
		
	if (!FMath::IsNearlyZero(CurrentRightMovementSpeed))
		TotalMovement += Owner->GetActorRightVector() * CurrentRightMovementSpeed * DeltaTime;

	if (!TotalMovement.IsNearlyZero())
	{
		FHitResult Hit;
		FVector DesiredMovement = TotalMovement;
		
		GetOwner()->GetRootComponent()->MoveComponent(DesiredMovement, Owner->GetActorRotation(), true, &Hit);
		
		if (Hit.IsValidBlockingHit())
		{
			FVector SlideDirection = FVector::VectorPlaneProject(DesiredMovement, Hit.Normal);
			GetOwner()->GetRootComponent()->MoveComponent(SlideDirection, Owner->GetActorRotation(), true);
		}
	}
}


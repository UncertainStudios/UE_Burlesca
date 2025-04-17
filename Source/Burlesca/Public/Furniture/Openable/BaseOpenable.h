// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseOpenable.generated.h"

class UTween;
class UTP_BaseInteractableComponent;
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnOpenStartedEvent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCloseStartedEvent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnOpenedEvent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnClosedEvent);

UCLASS()
class BURLESCA_API ABaseOpenable : public AActor
{
	GENERATED_BODY()

public:
	ABaseOpenable();
	
	
protected:
	UFUNCTION()
	virtual void OnInteract();
	virtual void BeginPlay() override;

	virtual void Open();
	virtual void OpenFinished();
	virtual void Close();
	virtual void CloseFinished();
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
	UTP_BaseInteractableComponent* InteractableComponent;
		
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
	UAudioComponent* AudioComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings|Audio")
	USoundCue* DoorOpenSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings|Audio")
	USoundCue* DoorCloseSound;

	UPROPERTY(BlueprintAssignable)
	FOnOpenStartedEvent OnOpenStarted;
	
	UPROPERTY(BlueprintAssignable)
	FOnCloseStartedEvent OnCloseStarted;

	UPROPERTY(BlueprintAssignable)
	FOnOpenedEvent OnOpened;

	UPROPERTY(BlueprintAssignable)
	FOnClosedEvent OnClosed;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings|Initial")
	bool bIsOpened;
};

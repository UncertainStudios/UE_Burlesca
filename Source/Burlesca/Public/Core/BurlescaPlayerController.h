// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BurlescaPlayerController.generated.h"

class AGameplayHUD;

UCLASS()
class BURLESCA_API ABurlescaPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	void Init();
	void PauseGame();
	void UnpauseGame();

	void ShowCursor();
	void HideCursor();
	
	FORCEINLINE bool GetIsGamePaused() const { return bIsGamePaused; }

protected:
	bool bIsGamePaused;
};

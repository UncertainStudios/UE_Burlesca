// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/BurlescaPlayerController.h"

void ABurlescaPlayerController::Init()
{
}

void ABurlescaPlayerController::PauseGame()
{
	bIsGamePaused = true;
	ShowCursor();
	
	SetPause(true);
}

void ABurlescaPlayerController::UnpauseGame()
{
	bIsGamePaused = false;

	HideCursor();
	SetPause(false);
}

void ABurlescaPlayerController::ShowCursor()
{
	bShowMouseCursor = true;
}

void ABurlescaPlayerController::HideCursor()
{
	bShowMouseCursor = false;
}

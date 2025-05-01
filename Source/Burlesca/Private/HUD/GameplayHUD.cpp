// Copyright Uncertain Studios (c). All Rights Reserved.


#include "HUD/GameplayHUD.h"
#include "HUD/InteractionView.h"
#include "HUD/PauseMenu.h"

void AGameplayHUD::InitWidgets()
{
	if(PauseMenuClass)
	{
		PauseMenuWidget = CreateWidget<UPauseMenu>(GetWorld(),PauseMenuClass);
		PauseMenuWidget->AddToViewport(5);
		PauseMenuWidget->SetVisibility(ESlateVisibility::Collapsed);
	}

	if(InteractionWidgetClass)
	{
		InteractionInfoWidget = CreateWidget<UInteractionView>(GetWorld(),InteractionWidgetClass);
		InteractionInfoWidget->AddToViewport(-1);
		InteractionInfoWidget->ShowWidget();
		InteractionInfoWidget->ClearWidget();
	}

	check(InteractionInfoWidget);
	check(PauseMenuWidget);
}

void AGameplayHUD::DisplayPauseMenu()
{
	if(PauseMenuWidget)
	{
		bIsPauseMenuVisible = true;
		PauseMenuWidget->SetVisibility(ESlateVisibility::Visible);
	}
}

void AGameplayHUD::HidePauseMenu()
{
	if(PauseMenuWidget)
	{
		bIsPauseMenuVisible = false;
		PauseMenuWidget->SetVisibility(ESlateVisibility::Collapsed);
	}
}

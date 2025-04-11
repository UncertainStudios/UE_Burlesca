// Copyright Uncertain Studios (c). All Rights Reserved.


#include "HUD/GameplayHUD.h"

#include "Framework/SignalBus.h"
#include "HUD/InteractionView.h"
#include "HUD/PauseMenu.h"

AGameplayHUD::AGameplayHUD()
{
}

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

void AGameplayHUD::Inject(UDependencyContainer* Container)
{
	SignalBus = Container->Resolve<USignalBus>();

	SubscribeEvents();
}



void AGameplayHUD::SubscribeEvents()
{
	SignalBus->GetCharacterEventsContainer()->OnCharacterCameraReturnedToCharacter.AddDynamic(InteractionInfoWidget, &UInteractionView::ShowWidget);
	SignalBus->GetCharacterEventsContainer()->OnCharacterCameraMovedOutFromCharacter.AddDynamic(InteractionInfoWidget, &UInteractionView::ClearWidget);
	SignalBus->GetCharacterEventsContainer()->OnCharacterCameraMovedOutFromCharacter.AddDynamic(InteractionInfoWidget, &UInteractionView::HideWidget);
	
	SignalBus->GetGlobalGameEventsContainer()->OnGamePaused.AddDynamic(this, &AGameplayHUD::DisplayPauseMenu);
	SignalBus->GetGlobalGameEventsContainer()->OnGameUnpaused.AddDynamic(this, &AGameplayHUD::HidePauseMenu);
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

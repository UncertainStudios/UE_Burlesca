// Copyright Uncertain Studios (c). All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/DependencyInjection/Inject.h"
#include "GameFramework/HUD.h"
#include "GameplayHUD.generated.h"

class USignalBus;
class UPauseMenu;
class UInteractionView;

UCLASS()
class BURLESCA_API AGameplayHUD : public AHUD, public IInject
{
protected:

private:
	GENERATED_BODY()

public:
	AGameplayHUD();
	void InitWidgets();
	virtual void Inject(UDependencyContainer* Container) override;
	
	bool bIsPauseMenuVisible;

	UFUNCTION()
	void DisplayPauseMenu();

	UFUNCTION()
	void HidePauseMenu();

	UInteractionView* GetInteractionView() { return InteractionInfoWidget; }

protected:
	// classes
	UPROPERTY(EditDefaultsOnly, Category = "User Widgets")
	TSubclassOf<UPauseMenu> PauseMenuClass;

	UPROPERTY(EditDefaultsOnly, Category = "User Widgets")
	TSubclassOf<UInteractionView> InteractionWidgetClass;

	//widgets
	UPROPERTY()
	UPauseMenu* PauseMenuWidget;

	UPROPERTY()
	UInteractionView* InteractionInfoWidget;

	UPROPERTY()
	USignalBus* SignalBus;
	
	void SubscribeEvents();
};

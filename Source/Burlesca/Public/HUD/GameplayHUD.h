// Copyright Uncertain Studios (c). All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GameplayHUD.generated.h"

class UPauseMenu;
class UInteractionView;

UCLASS()
class BURLESCA_API AGameplayHUD : public AHUD
{
protected:

private:
	GENERATED_BODY()

public:
	void InitWidgets();
	
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
};

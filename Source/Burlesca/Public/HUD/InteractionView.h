// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InteractionView.generated.h"

class UInputAction;
class UImage;
class UCircularProgressBar;
class UProgressBar;
class UTextBlock;
class AMainCharacter;

UCLASS()
class BURLESCA_API UInteractionView : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;
	
	UPROPERTY(VisibleAnywhere, Category = "Interaction Widget|Owner Character")
	AMainCharacter* MainCharacter;

	UFUNCTION(BlueprintCallable)
	void ShowWidget();

	UFUNCTION(BlueprintCallable)
	void HideWidget();

	UFUNCTION(BlueprintCallable)
	void ClearWidget();

	void ShowNotInteracableAimBullet();
	void ShowInteracableAimBullet();
	void ShowLockedAimBullet();

	void ShowItemName(FText itemName);
	void HideItemName();
	
	void ShowLockedItemTooltip(FText tooltip);
	void HideLockedItemTooltip();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void PlayInteractionLockedAnimation();
	
protected:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* ItemNameText;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* LockedItemTooltipText;
	
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UImage* LockedBulletImage;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UImage* AimBulletImage;

	UPROPERTY(BlueprintReadOnly)
	UTexture2D* InteractableNotFoundAimBulletBrush;

	UPROPERTY(BlueprintReadOnly)
	UTexture2D* InteractableFoundAimBulletBrush;
	
	void ResetAimBullet();
};

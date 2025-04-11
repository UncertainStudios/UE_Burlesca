// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/InteractionView.h"

#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "HUD/CircularProgressBar.h"

void UInteractionView::NativeConstruct()
{
	Super::NativeConstruct();
	check(ItemNameText);
	check(LockedItemTooltipText);
	check(AimBulletImage);
}

void UInteractionView::ShowWidget()
{
	SetVisibility(ESlateVisibility::Visible);
}

void UInteractionView::HideWidget()
{
	ClearWidget();
	SetVisibility(ESlateVisibility::Collapsed);
}

void UInteractionView::ClearWidget()
{
	ItemNameText->SetText(FText::GetEmpty());
	LockedItemTooltipText->SetText(FText::GetEmpty());
	ResetAimBullet();
}

void UInteractionView::ResetAimBullet()
{
	LockedBulletImage->SetVisibility(ESlateVisibility::Collapsed);
	AimBulletImage->SetVisibility(ESlateVisibility::Visible);
	AimBulletImage->SetBrushFromTexture(InteractableNotFoundAimBulletBrush);
}

void UInteractionView::ShowNotInteracableAimBullet()
{
	ResetAimBullet();
}

void UInteractionView::ShowInteracableAimBullet()
{
	ResetAimBullet();
	AimBulletImage->SetBrushFromTexture(InteractableFoundAimBulletBrush);
}

void UInteractionView::ShowLockedAimBullet()
{
	ResetAimBullet();
	AimBulletImage->SetVisibility(ESlateVisibility::Collapsed);
	LockedBulletImage->SetVisibility(ESlateVisibility::Visible);
}

void UInteractionView::ShowItemName(FText itemName)
{
	if(!itemName.IsEmpty())
	{
		ItemNameText->SetVisibility(ESlateVisibility::Visible);
		ItemNameText->SetText(itemName);
	}
}

void UInteractionView::HideItemName()
{
	ItemNameText->SetVisibility(ESlateVisibility::Collapsed);
	ItemNameText->SetText(FText::GetEmpty());
}

void UInteractionView::ShowLockedItemTooltip(FText tooltip)
{
	LockedItemTooltipText->SetVisibility(ESlateVisibility::Visible);
	LockedItemTooltipText->SetText(tooltip);
}

void UInteractionView::HideLockedItemTooltip()
{
	ItemNameText->SetVisibility(ESlateVisibility::Collapsed);
	ItemNameText->SetText(FText::GetEmpty());
}

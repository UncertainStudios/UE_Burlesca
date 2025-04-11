// Fill out your copyright notice in the Description page of Project Settings.

#include "TweenFunctions/SlotTweenFunctions.h"

#include "FastTweenCore.h"
#include "Components/BorderSlot.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/GridSlot.h"
#include "Components/HorizontalBoxSlot.h"
#include "Components/OverlaySlot.h"
#include "Components/SizeBoxSlot.h"
#include "Components/VerticalBoxSlot.h"
#include "Components/Widget.h"
#include "Components/WidgetSwitcherSlot.h"

UTween* USlotTweenFunctions::DoPadding(UWidget* target, const FMargin& endValue, float duration)
{
	if (!target || !target->Slot)
		return nullptr;

	UPanelSlot* panelSlot = target->Slot;

	TTweenGetter<FMargin> getter = [panelSlot]() -> FMargin {
		if (const UBorderSlot* borderSlot = Cast<UBorderSlot>(panelSlot)) return borderSlot->GetPadding();
		if (const UHorizontalBoxSlot* horizontalSlot = Cast<UHorizontalBoxSlot>(panelSlot)) return horizontalSlot->GetPadding();
		if (const UVerticalBoxSlot* verticalSlot = Cast<UVerticalBoxSlot>(panelSlot)) return verticalSlot->GetPadding();
		if (const UOverlaySlot* overlaySlot = Cast<UOverlaySlot>(panelSlot)) return overlaySlot->GetPadding();
		if (const UGridSlot* gridSlot = Cast<UGridSlot>(panelSlot)) return gridSlot->GetPadding();
		if (const USizeBoxSlot* sizeBoxSlot = Cast<USizeBoxSlot>(panelSlot)) return sizeBoxSlot->GetPadding();
		if (const UWidgetSwitcherSlot* widgetSwitcherSlot = Cast<UWidgetSwitcherSlot>(panelSlot)) return widgetSwitcherSlot->GetPadding();
		return FMargin();
	};

	TTweenSetter<FMargin> setter = [panelSlot](const FMargin& value) -> void {
		if (UBorderSlot* borderSlot = Cast<UBorderSlot>(panelSlot)) borderSlot->SetPadding(value);
		else if (UHorizontalBoxSlot* horizontalSlot = Cast<UHorizontalBoxSlot>(panelSlot)) horizontalSlot->SetPadding(value);
		else if (UVerticalBoxSlot* verticalSlot = Cast<UVerticalBoxSlot>(panelSlot)) verticalSlot->SetPadding(value);
		else if (UOverlaySlot* overlaySlot = Cast<UOverlaySlot>(panelSlot)) overlaySlot->SetPadding(value);
		else if (UGridSlot* gridSlot = Cast<UGridSlot>(panelSlot)) gridSlot->SetPadding(value);
		else if (USizeBoxSlot* sizeBoxSlot = Cast<USizeBoxSlot>(panelSlot)) sizeBoxSlot->SetPadding(value);
		else if (UWidgetSwitcherSlot* widgetSwitcherSlot = Cast<UWidgetSwitcherSlot>(panelSlot)) widgetSwitcherSlot->SetPadding(value);
		else UE_LOG(FastTween, Error, TEXT("Unsupportable slot type!"));
	};
	
	UTween* t = FFastTweenCore::To(getter, setter, endValue, duration);
	return t;
}

UTween* USlotTweenFunctions::DoPaddingLeft(UWidget* target, const float endValue, float duration)
{	
	if (!target || !target->Slot)
		return nullptr;

	UPanelSlot* panelSlot = target->Slot;

	TTweenGetter<float> getter = [panelSlot]() -> float {
		if (UBorderSlot* borderSlot = Cast<UBorderSlot>(panelSlot)) return borderSlot->GetPadding().Left;
		if (UHorizontalBoxSlot* horizontalSlot = Cast<UHorizontalBoxSlot>(panelSlot)) return horizontalSlot->GetPadding().Left;
		if (UVerticalBoxSlot* verticalSlot = Cast<UVerticalBoxSlot>(panelSlot)) return verticalSlot->GetPadding().Left;
		if (UOverlaySlot* overlaySlot = Cast<UOverlaySlot>(panelSlot)) return overlaySlot->GetPadding().Left;
		if (UGridSlot* gridSlot = Cast<UGridSlot>(panelSlot)) return gridSlot->GetPadding().Left;
		if (USizeBoxSlot* sizeBoxSlot = Cast<USizeBoxSlot>(panelSlot)) return sizeBoxSlot->GetPadding().Left;
		if (UWidgetSwitcherSlot* widgetSwitcherSlot = Cast<UWidgetSwitcherSlot>(panelSlot)) return widgetSwitcherSlot->GetPadding().Left;
		return 0.0f;
	};

	TTweenSetter<float> setter = [panelSlot](const float value) {
		if (UBorderSlot* borderSlot = Cast<UBorderSlot>(panelSlot)) 
		{
			FMargin padding = borderSlot->GetPadding();
			padding.Left = value;
			borderSlot->SetPadding(padding);
		}
		else if (UHorizontalBoxSlot* horizontalSlot = Cast<UHorizontalBoxSlot>(panelSlot)) 
		{
			FMargin padding = horizontalSlot->GetPadding();
			padding.Left = value;
			horizontalSlot->SetPadding(padding);
		}
		else if (UVerticalBoxSlot* verticalSlot = Cast<UVerticalBoxSlot>(panelSlot)) 
		{
			FMargin padding = verticalSlot->GetPadding();
			padding.Left = value;
			verticalSlot->SetPadding(padding);
		}
		else if (UOverlaySlot* overlaySlot = Cast<UOverlaySlot>(panelSlot)) 
		{
			FMargin padding = overlaySlot->GetPadding();
			padding.Left = value;
			overlaySlot->SetPadding(padding);
		}
		else if (UGridSlot* gridSlot = Cast<UGridSlot>(panelSlot)) 
		{
			FMargin padding = gridSlot->GetPadding();
			padding.Left = value;
			gridSlot->SetPadding(padding);
		}
		else if (USizeBoxSlot* sizeBoxSlot = Cast<USizeBoxSlot>(panelSlot)) 
		{
			FMargin padding = sizeBoxSlot->GetPadding();
			padding.Left = value;
			sizeBoxSlot->SetPadding(padding);
		}
		else if (UWidgetSwitcherSlot* widgetSwitcherSlot = Cast<UWidgetSwitcherSlot>(panelSlot)) 
		{
			FMargin padding = widgetSwitcherSlot->GetPadding();
			padding.Left = value;
			widgetSwitcherSlot->SetPadding(padding);
		}
		else UE_LOG(FastTween, Error, TEXT("Unsupportable slot type!"));
	};

	return FFastTweenCore::To(getter, setter, endValue, duration);
}

UTween* USlotTweenFunctions::DoPaddingTop(UWidget* target, const float endValue, float duration)
{
	if (!target || !target->Slot)
		return nullptr;

	UPanelSlot* panelSlot = target->Slot;

	TTweenGetter<float> getter = [panelSlot]() -> float {
		if (UBorderSlot* borderSlot = Cast<UBorderSlot>(panelSlot)) return borderSlot->GetPadding().Top;
		if (UHorizontalBoxSlot* horizontalSlot = Cast<UHorizontalBoxSlot>(panelSlot)) return horizontalSlot->GetPadding().Top;
		if (UVerticalBoxSlot* verticalSlot = Cast<UVerticalBoxSlot>(panelSlot)) return verticalSlot->GetPadding().Top;
		if (UOverlaySlot* overlaySlot = Cast<UOverlaySlot>(panelSlot)) return overlaySlot->GetPadding().Top;
		if (UGridSlot* gridSlot = Cast<UGridSlot>(panelSlot)) return gridSlot->GetPadding().Top;
		if (USizeBoxSlot* sizeBoxSlot = Cast<USizeBoxSlot>(panelSlot)) return sizeBoxSlot->GetPadding().Top;
		if (UWidgetSwitcherSlot* widgetSwitcherSlot = Cast<UWidgetSwitcherSlot>(panelSlot)) return widgetSwitcherSlot->GetPadding().Top;
		return 0.0f;
	};

	TTweenSetter<float> setter = [panelSlot](const float value) {
		if (UBorderSlot* borderSlot = Cast<UBorderSlot>(panelSlot)) 
		{
			FMargin padding = borderSlot->GetPadding();
			padding.Top = value;
			borderSlot->SetPadding(padding);
		}
		else if (UHorizontalBoxSlot* horizontalSlot = Cast<UHorizontalBoxSlot>(panelSlot)) 
		{
			FMargin padding = horizontalSlot->GetPadding();
			padding.Top = value;
			horizontalSlot->SetPadding(padding);
		}
		else if (UVerticalBoxSlot* verticalSlot = Cast<UVerticalBoxSlot>(panelSlot)) 
		{
			FMargin padding = verticalSlot->GetPadding();
			padding.Top = value;
			verticalSlot->SetPadding(padding);
		}
		else if (UOverlaySlot* overlaySlot = Cast<UOverlaySlot>(panelSlot)) 
		{
			FMargin padding = overlaySlot->GetPadding();
			padding.Top = value;
			overlaySlot->SetPadding(padding);
		}
		else if (UGridSlot* gridSlot = Cast<UGridSlot>(panelSlot)) 
		{
			FMargin padding = gridSlot->GetPadding();
			padding.Top = value;
			gridSlot->SetPadding(padding);
		}
		else if (USizeBoxSlot* sizeBoxSlot = Cast<USizeBoxSlot>(panelSlot)) 
		{
			FMargin padding = sizeBoxSlot->GetPadding();
			padding.Top = value;
			sizeBoxSlot->SetPadding(padding);
		}
		else if (UWidgetSwitcherSlot* widgetSwitcherSlot = Cast<UWidgetSwitcherSlot>(panelSlot)) 
		{
			FMargin padding = widgetSwitcherSlot->GetPadding();
			padding.Top = value;
			widgetSwitcherSlot->SetPadding(padding);
		}
		else UE_LOG(FastTween, Error, TEXT("Unsupportable slot type!"));
	};

	return FFastTweenCore::To(getter, setter, endValue, duration);
}

UTween* USlotTweenFunctions::DoPaddingRight(UWidget* target, const float endValue, float duration)
{
	if (!target || !target->Slot)
		return nullptr;

	UPanelSlot* panelSlot = target->Slot;

	TTweenGetter<float> getter = [panelSlot]() -> float {
		if (UBorderSlot* borderSlot = Cast<UBorderSlot>(panelSlot)) return borderSlot->GetPadding().Right;
		if (UHorizontalBoxSlot* horizontalSlot = Cast<UHorizontalBoxSlot>(panelSlot)) return horizontalSlot->GetPadding().Right;
		if (UVerticalBoxSlot* verticalSlot = Cast<UVerticalBoxSlot>(panelSlot)) return verticalSlot->GetPadding().Right;
		if (UOverlaySlot* overlaySlot = Cast<UOverlaySlot>(panelSlot)) return overlaySlot->GetPadding().Right;
		if (UGridSlot* gridSlot = Cast<UGridSlot>(panelSlot)) return gridSlot->GetPadding().Right;
		if (USizeBoxSlot* sizeBoxSlot = Cast<USizeBoxSlot>(panelSlot)) return sizeBoxSlot->GetPadding().Right;
		if (UWidgetSwitcherSlot* widgetSwitcherSlot = Cast<UWidgetSwitcherSlot>(panelSlot)) return widgetSwitcherSlot->GetPadding().Right;
		return 0.0f;
	};

	TTweenSetter<float> setter = [panelSlot](const float value) {
		if (UBorderSlot* borderSlot = Cast<UBorderSlot>(panelSlot)) 
		{
			FMargin padding = borderSlot->GetPadding();
			padding.Right = value;
			borderSlot->SetPadding(padding);
		}
		else if (UHorizontalBoxSlot* horizontalSlot = Cast<UHorizontalBoxSlot>(panelSlot)) 
		{
			FMargin padding = horizontalSlot->GetPadding();
			padding.Right = value;
			horizontalSlot->SetPadding(padding);
		}
		else if (UVerticalBoxSlot* verticalSlot = Cast<UVerticalBoxSlot>(panelSlot)) 
		{
			FMargin padding = verticalSlot->GetPadding();
			padding.Right = value;
			verticalSlot->SetPadding(padding);
		}
		else if (UOverlaySlot* overlaySlot = Cast<UOverlaySlot>(panelSlot)) 
		{
			FMargin padding = overlaySlot->GetPadding();
			padding.Right = value;
			overlaySlot->SetPadding(padding);
		}
		else if (UGridSlot* gridSlot = Cast<UGridSlot>(panelSlot)) 
		{
			FMargin padding = gridSlot->GetPadding();
			padding.Right = value;
			gridSlot->SetPadding(padding);
		}
		else if (USizeBoxSlot* sizeBoxSlot = Cast<USizeBoxSlot>(panelSlot)) 
		{
			FMargin padding = sizeBoxSlot->GetPadding();
			padding.Right = value;
			sizeBoxSlot->SetPadding(padding);
		}
		else if (UWidgetSwitcherSlot* widgetSwitcherSlot = Cast<UWidgetSwitcherSlot>(panelSlot)) 
		{
			FMargin padding = widgetSwitcherSlot->GetPadding();
			padding.Right = value;
			widgetSwitcherSlot->SetPadding(padding);
		}
		else UE_LOG(FastTween, Error, TEXT("Unsupportable slot type!"));
	};

	return FFastTweenCore::To(getter, setter, endValue, duration);
}

UTween* USlotTweenFunctions::DoPaddingBottom(UWidget* target, const float endValue, float duration)
{
	if (!target || !target->Slot)
		return nullptr;

	UPanelSlot* panelSlot = target->Slot;

	TTweenGetter<float> getter = [panelSlot]() -> float {
		if (UBorderSlot* borderSlot = Cast<UBorderSlot>(panelSlot)) return borderSlot->GetPadding().Bottom;
		if (UHorizontalBoxSlot* horizontalSlot = Cast<UHorizontalBoxSlot>(panelSlot)) return horizontalSlot->GetPadding().Bottom;
		if (UVerticalBoxSlot* verticalSlot = Cast<UVerticalBoxSlot>(panelSlot)) return verticalSlot->GetPadding().Bottom;
		if (UOverlaySlot* overlaySlot = Cast<UOverlaySlot>(panelSlot)) return overlaySlot->GetPadding().Bottom;
		if (UGridSlot* gridSlot = Cast<UGridSlot>(panelSlot)) return gridSlot->GetPadding().Bottom;
		if (USizeBoxSlot* sizeBoxSlot = Cast<USizeBoxSlot>(panelSlot)) return sizeBoxSlot->GetPadding().Bottom;
		if (UWidgetSwitcherSlot* widgetSwitcherSlot = Cast<UWidgetSwitcherSlot>(panelSlot)) return widgetSwitcherSlot->GetPadding().Bottom;
		return 0.0f;
	};

	TTweenSetter<float> setter = [panelSlot](const float value) {
		if (UBorderSlot* borderSlot = Cast<UBorderSlot>(panelSlot)) 
		{
			FMargin padding = borderSlot->GetPadding();
			padding.Bottom = value;
			borderSlot->SetPadding(padding);
		}
		else if (UHorizontalBoxSlot* horizontalSlot = Cast<UHorizontalBoxSlot>(panelSlot)) 
		{
			FMargin padding = horizontalSlot->GetPadding();
			padding.Bottom = value;
			horizontalSlot->SetPadding(padding);
		}
		else if (UVerticalBoxSlot* verticalSlot = Cast<UVerticalBoxSlot>(panelSlot)) 
		{
			FMargin padding = verticalSlot->GetPadding();
			padding.Bottom = value;
			verticalSlot->SetPadding(padding);
		}
		else if (UOverlaySlot* overlaySlot = Cast<UOverlaySlot>(panelSlot)) 
		{
			FMargin padding = overlaySlot->GetPadding();
			padding.Bottom = value;
			overlaySlot->SetPadding(padding);
		}
		else if (UGridSlot* gridSlot = Cast<UGridSlot>(panelSlot)) 
		{
			FMargin padding = gridSlot->GetPadding();
			padding.Bottom = value;
			gridSlot->SetPadding(padding);
		}
		else if (USizeBoxSlot* sizeBoxSlot = Cast<USizeBoxSlot>(panelSlot)) 
		{
			FMargin padding = sizeBoxSlot->GetPadding();
			padding.Bottom = value;
			sizeBoxSlot->SetPadding(padding);
		}
		else if (UWidgetSwitcherSlot* widgetSwitcherSlot = Cast<UWidgetSwitcherSlot>(panelSlot)) 
		{
			FMargin currentPadding = widgetSwitcherSlot->GetPadding();
			currentPadding.Bottom = value;
			widgetSwitcherSlot->SetPadding(currentPadding);
		}
		else UE_LOG(FastTween, Error, TEXT("Unsupportable slot type!"));
	};

	return FFastTweenCore::To(getter, setter, endValue, duration);
}

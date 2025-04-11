// Fill out your copyright notice in the Description page of Project Settings.


#include "MobilePhone/ApplicationWidgets/GuitarTuner/GuitarTunerScreen.h"
#include "Blueprint/WidgetTree.h"
#include "Components/Border.h"
#include "Components/HorizontalBoxSlot.h"
#include "Components/TextBlock.h"
#include "TweenFunctions/SlotTweenFunctions.h"

void UGuitarTunerScreen::NativeConstruct()
{
	Super::NativeOnInitialized();

	TArray<UWidget*> widgets;
	WidgetTree->GetAllWidgets(widgets);
	
	pegImages.SetNum(6);
	pegNoteImages.SetNum(6);
	pegNoteTexts.SetNum(6);
	
	for(UWidget* widget : widgets)
	{
		if(UImage* image = Cast<UImage>(widget))
		{
			FString widgetName = widget->GetName();
			if(widgetName.StartsWith(TEXT("GuitarPeg")))
			{
				int32 index = FCString::Atoi(*widgetName.RightChop(9).LeftChop(5));
				pegImages[index - 1] = image;
			}
		}
		
		if(UBorder* border = Cast<UBorder>(widget))
		{
			FString widgetName = widget->GetName();
			if(widgetName.StartsWith(TEXT("PegNote")))
			{
				int32 index = FCString::Atoi(*widgetName.RightChop(7).LeftChop(5));
				pegNoteImages[index - 1] = border;
			}
		}

		if(UTextBlock* text = Cast<UTextBlock>(widget))
		{
			FString widgetName = widget->GetName();
			if(widgetName.StartsWith(TEXT("PegNote")))
			{
				int32 index = FCString::Atoi(*widgetName.RightChop(7).LeftChop(4));
				pegNoteTexts[index - 1] = text;
			}
		}
	}

	UE_LOG(LogTemp, Log, TEXT("Guitar Tuner App Initialized"));
}

void UGuitarTunerScreen::SelectPeg(int32 pegIndex)
{
	pegImages[pegIndex]->SetBrushFromTexture(selectedPegSprites[pegIndex]);
	pegNoteImages[pegIndex]->SetBrushFromTexture(selectedPegNoteSprite);
	pegNoteTexts[pegIndex]->SetColorAndOpacity(FSlateColor(FLinearColor(0.25f, 0.25f, 0.25f, 1.0f)));

	GetWorld()->GetTimerManager().SetTimer(deselectAllPegsTimerHandle, this, &UGuitarTunerScreen::DeselectAllPegs, 1.5f);
}

void UGuitarTunerScreen::DeselectAllPegs()
{
	for(int32 i = 0; i < 6; i++)
	{
		pegImages[i]->SetBrushFromTexture(deselectedPegSprites[i]);
		pegNoteImages[i]->SetBrushFromTexture(deselectedPegNoteSprite);
		pegNoteTexts[i]->SetColorAndOpacity(FSlateColor(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f)));
	}
}

void UGuitarTunerScreen::OpenApplication()
{
	Super::OpenApplication();

	SelectPeg(3);
}

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Image.h"
#include "Components/SizeBox.h"
#include "MobilePhone/ApplicationWidgets/PhoneApplication.h"
#include "GuitarTunerScreen.generated.h"

class UBorder;
class UTextBlock;
class UImage;
/**
 * 
 */
UCLASS()
class BURLESCA_API UGuitarTunerScreen : public UPhoneApplication
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

	UFUNCTION()
	void SelectPeg(int32 pegIndex);

	UFUNCTION()
	void DeselectAllPegs();
	virtual void OpenApplication() override;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(BindWidget))
	USizeBox* GuitarSetupIndicator;
	
	UPROPERTY()
	TArray<UImage*> pegImages;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Pegs")
	TArray<UTexture2D*> selectedPegSprites;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Pegs")
	TArray<UTexture2D*> deselectedPegSprites;

	UPROPERTY()
	TArray<UBorder*> pegNoteImages;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Peg Notes")
	UTexture2D* selectedPegNoteSprite;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Peg Notes")
	UTexture2D* deselectedPegNoteSprite;

	UPROPERTY()
	TArray<UTextBlock*> pegNoteTexts;
	
	FTimerHandle deselectAllPegsTimerHandle;
};

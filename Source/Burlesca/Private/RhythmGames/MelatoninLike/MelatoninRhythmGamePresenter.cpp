// Fill out your copyright notice in the Description page of Project Settings.


#include "RhythmGames/MelatoninLike/MelatoninRhythmGamePresenter.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "RhythmGames/MelatoninLike/MelatoninLikeRhythmGameAsset.h"
#include "HUD/RhythmGameWidgets/MelatoninGameWidgets/MelatoninRhythmGameUI.h"
#include "HUD/RhythmGameWidgets/MelatoninGameWidgets/MelatoninRhythmNoteWidget.h"
#include "Kismet/GameplayStatics.h" 


void UMelatoninRhythmGamePresenter::StartRhythmGame(UMelatoninLikeRhythmGameAsset* AssetToPlay)
{
    if (!AssetToPlay)
    {
        AssetToPlay = CurrentAsset;
    }

    if (!AssetToPlay || bIsGameActive) return;

    CurrentAsset = AssetToPlay;
    CurrentNoteIndex = 0;
    bIsGameOver = false;
    bIsGameWin = false;

    // Create UI
    if (MelatoninRhythmGameUIClass)
    {
        MelatoninRhythmGameUI = CreateWidget<UMelatoninRhythmGameUI>(GetWorld(), MelatoninRhythmGameUIClass);
        if (MelatoninRhythmGameUI)
        {
            MelatoninRhythmGameUI->AddToViewport();
            if (CurrentAsset->MelatoninRythmGameStartDelay > 0.f)
            {
                // Show delay timer if needed
                MelatoninRhythmGameUI->ShowStartDelayTimer();

                // Start actual game after delay
                GetWorld()->GetTimerManager().SetTimer(
                    NoteSpawnTimer,
                    this,
                    &UMelatoninRhythmGamePresenter::OnStartDelayFinished,
                    CurrentAsset->MelatoninRythmGameStartDelay,
                    false
                );
                return; 
            }
        }
    }

}

void UMelatoninRhythmGamePresenter::OnStartDelayFinished()
{
    if (MelatoninRhythmGameUI)
    {
        MelatoninRhythmGameUI->HideStartDelayTimer();
    }
   
    BindInputActions();
    bIsGameActive = true;
    SpawnNextNote();
}

void UMelatoninRhythmGamePresenter::StopRhythmGame()
{
    GetWorld()->GetTimerManager().ClearAllTimersForObject(this);


    // Unbind inputs
    UnbindInputActions();

    // Clean up UI
    if (MelatoninRhythmGameUI)
    {
        if (bIsGameWin)
        {
            MelatoninRhythmGameUI->HideGameWin();
        }
        else
        {
            MelatoninRhythmGameUI->HideGameOver();
        }
        MelatoninRhythmGameUI->RemoveFromParent();
        MelatoninRhythmGameUI = nullptr;
    }

    bIsGameActive = false;
    CurrentAsset = nullptr; 
    bIsGameOver = true;
}

void UMelatoninRhythmGamePresenter::HandleInput(ENoteSide Side)
{
    if (!bIsGameActive || bIsGameOver || !MelatoninRhythmGameUI) return;

    float HitTime = MelatoninRhythmGameUI->StopNoteAnimation(Side);
    ProcessNoteHit(Side, HitTime);
}


void UMelatoninRhythmGamePresenter::BindInputActions()
{
    
    if (!CurrentAsset || !CurrentAsset->LeftNoteInput || !CurrentAsset->RightNoteInput || !CurrentAsset->DownNoteInput)
        return;

    APlayerController* PC = GetWorld()->GetFirstPlayerController();
    if (!PC) return;

    if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PC->InputComponent))
    {
        // Remove base input 
        if (ULocalPlayer* LocalPlayer = PC->GetLocalPlayer())
        {
            if (UEnhancedInputLocalPlayerSubsystem* InputSystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
            {
                if (BaseInputContext)
                {
                    InputSystem->RemoveMappingContext(BaseInputContext);
                }

                // Add rhythm game input 
                InputSystem->AddMappingContext(RhythmGameInputContext, 1);
            }
        }

        // Clear existing bindings
        for (uint32 Handle : InputBindingHandles)
        {
            EnhancedInput->RemoveBindingByHandle(Handle);
        }
        InputBindingHandles.Empty();

        // Bind new actions
        if (CurrentAsset->LeftNoteInput)
        {
            InputBindingHandles.Add(EnhancedInput->BindAction(
                CurrentAsset->LeftNoteInput,
                ETriggerEvent::Triggered,
                this,
                &UMelatoninRhythmGamePresenter::HandleInput, ENoteSide::Left).GetHandle());
        }

        if (CurrentAsset->RightNoteInput)
        {
            InputBindingHandles.Add(EnhancedInput->BindAction(
                CurrentAsset->RightNoteInput,
                ETriggerEvent::Triggered,
                this,
                &UMelatoninRhythmGamePresenter::HandleInput, ENoteSide::Right).GetHandle());
        }

        if (CurrentAsset->DownNoteInput)
        {
            InputBindingHandles.Add(EnhancedInput->BindAction(
                CurrentAsset->DownNoteInput,
                ETriggerEvent::Triggered,
                this,
                &UMelatoninRhythmGamePresenter::HandleInput, ENoteSide::Down).GetHandle());
        }
        if (EscapeRhythmGame)
        {
            InputBindingHandles.Add(EnhancedInput->BindAction(
                EscapeRhythmGame,
                ETriggerEvent::Triggered,
                this,
                &UMelatoninRhythmGamePresenter::StopRhythmGame).GetHandle());
        }
        if (RestartRhythmGame)
        {
            InputBindingHandles.Add(EnhancedInput->BindAction(
                RestartRhythmGame,
                ETriggerEvent::Triggered,
                this,
                &UMelatoninRhythmGamePresenter::RestartGame).GetHandle());
        }
    }
}

void UMelatoninRhythmGamePresenter::UnbindInputActions()
{
    if (!CurrentAsset) return;

    APlayerController* PC = GetWorld()->GetFirstPlayerController();
    if (!PC) return;

    // Remove rhythm game input
    if (ULocalPlayer* LocalPlayer = PC->GetLocalPlayer())
    {
        if (UEnhancedInputLocalPlayerSubsystem* InputSystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
        {
            if (RhythmGameInputContext)
            {
                InputSystem->RemoveMappingContext(RhythmGameInputContext);
            }

            // Reset base inputs
            if (BaseInputContext)
            {
                InputSystem->AddMappingContext(BaseInputContext, 0);
            }
        }
    }

    // Clear action bindings
    if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PC->InputComponent))
    {
        for (uint32 Handle : InputBindingHandles)
        {
            EnhancedInput->RemoveBindingByHandle(Handle);
        }
    }
    InputBindingHandles.Empty();
}


void UMelatoninRhythmGamePresenter::SpawnNextNote()
{

    if (!CurrentAsset || !MelatoninRhythmGameUI || !bIsGameActive) return;

    // Clear timers
    GetWorld()->GetTimerManager().ClearTimer(NoteSpawnTimer);
    GetWorld()->GetTimerManager().ClearTimer(SuccessDelayTimer);

    if (CurrentNoteIndex >= CurrentAsset->MelatoningRythmGameNotes.Num())
    {
        return;
    }

    const FRhythmNoteData& NextNote = CurrentAsset->MelatoningRythmGameNotes[CurrentNoteIndex];
    MelatoninRhythmGameUI->PlayNoteAnimation(NextNote.SideOfNote);

}


void UMelatoninRhythmGamePresenter::ProcessNoteHit(ENoteSide Side, float HitTime)
{
    if (!IsValid(MelatoninRhythmGameUI)) return;
    if (!CurrentAsset || CurrentNoteIndex >= CurrentAsset->MelatoningRythmGameNotes.Num()) return;
    if (bIsGameOver) return;

    const FRhythmNoteData& CurrentNote = CurrentAsset->MelatoningRythmGameNotes[CurrentNoteIndex];

    // CheckNoteSide
    if (CurrentNote.SideOfNote == Side)
    {
        //Check HitTime
        float MinHitTime = CurrentNote.TravelDuration - ThresholdNoteHitTime;
        float MaxHitTime = CurrentNote.TravelDuration + ThresholdNoteHitTime;
        bool bSuccess = FMath::IsWithinInclusive(HitTime, MinHitTime, MaxHitTime);

        MelatoninRhythmGameUI->ShowHitFeedback(Side, bSuccess);
        MelatoninRhythmGameUI->StopAllAnimations();

        if (bSuccess)
        {
            CurrentNoteIndex++;

            if (CurrentNoteIndex >= CurrentAsset->MelatoningRythmGameNotes.Num())
            {
                GameWin();
            }
            else
            {
                GetWorld()->GetTimerManager().SetTimer(
                    SuccessDelayTimer,
                    this,
                    &UMelatoninRhythmGamePresenter::SpawnNextNote,
                    IntervalBetweenNoteSpawn,
                    false
                );
            }
            return; 
        }
        else
        {

            GameOver();
            return;
        }
    }

}

void UMelatoninRhythmGamePresenter::GameOver()
{
    if (bIsGameOver) return;
    bIsGameActive = false;
    bIsGameOver = true;

    bIsGameWin = false;

    GetWorld()->GetTimerManager().ClearAllTimersForObject(this);
    if (MelatoninRhythmGameUI)
    {
        MelatoninRhythmGameUI->ShowGameOver();
    }
}

void UMelatoninRhythmGamePresenter::RestartGame()
{
    if (MelatoninRhythmGameUI)
    {
        if (bIsGameWin)
        {
            MelatoninRhythmGameUI->HideGameWin();
        }
        else
        {
            MelatoninRhythmGameUI->HideGameOver();
        }
    }
    GetWorld()->GetTimerManager().ClearAllTimersForObject(this);

    // Clean up UI
    if (MelatoninRhythmGameUI)
    {
        MelatoninRhythmGameUI->RemoveFromParent();
    }

    bIsGameActive = false;
    bIsGameOver = true;
    StartRhythmGame(CurrentAsset);

}

void UMelatoninRhythmGamePresenter::GameWin()
{
    bIsGameActive = false;
    bIsGameOver = true;

    bIsGameWin = true;

    GetWorld()->GetTimerManager().ClearAllTimersForObject(this);

    if (MelatoninRhythmGameUI)
    {
        MelatoninRhythmGameUI->ShowGameWin();
    }
}




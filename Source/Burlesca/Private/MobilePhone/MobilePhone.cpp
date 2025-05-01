// Fill out your copyright notice in the Description page of Project Settings.

#include "MobilePhone/MobilePhone.h"
#include "EnhancedInputComponent.h"
#include "Components/AudioComponent.h"
#include "Components/WidgetComponent.h"
#include "Core/BurlescaPlayerController.h"
#include "MainCharacter/MainCharacter.h"
#include "MainCharacter/Animation/MainCharacterAnimInstance.h"
#include "MobilePhone/MobilePhoneEnums.h"
#include "MobilePhone/ApplicationWidgets/PhoneApplicationContainer.h"
#include "MobilePhone/ApplicationWidgets/Chat/ChatScreen.h"

UMobilePhone::UMobilePhone()
{
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("PhoneMesh");
	StaticMesh->SetSimulatePhysics(false);
	StaticMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	StaticMesh->CastShadow = false;
	StaticMesh->SetupAttachment(this);

	AudioComponent = CreateDefaultSubobject<UAudioComponent>("AudioSource");
	AudioComponent->SetupAttachment(this);
	
	MobilePhoneScreenWidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("Mobile Screen Widget"));
	MobilePhoneScreenWidgetComponent->SetupAttachment(this);
	MobilePhoneScreenWidgetComponent->SetWidgetSpace(EWidgetSpace::World);
}

void UMobilePhone::Init()
{
	Owner = Cast<AMainCharacter>(GetOwner());
	PlayerController = Cast<ABurlescaPlayerController>(Owner->GetController());
	
	AudioComponent->SetSound(NotificationSound);
	ApplicationsContainer = Cast<UPhoneApplicationContainer>(CreateWidget(GetWorld(), ApplicationsContainerClass));
	MobilePhoneScreenWidgetComponent->SetWidget(ApplicationsContainer);
	ApplicationsContainer->SetVisibility(ESlateVisibility::Collapsed);

	Cast<UChatScreen>(ApplicationsContainer->GetApplicationWidget(EPhoneApplication::Chat))->OnNotificationRecived.AddDynamic(this, &UMobilePhone::PlayNotificationSound);
	if (UEnhancedInputComponent* inputConponent = Cast<UEnhancedInputComponent>(PlayerController->InputComponent))
	{
		inputConponent->BindAction(FocusPhoneAction, ETriggerEvent::Triggered, this, &UMobilePhone::OnFocusPhoneTriggered);
		inputConponent->BindAction(PullPhoneAction, ETriggerEvent::Triggered, this, &UMobilePhone::OnPullPhoneTriggered);
	}
}

void UMobilePhone::TogglePower() const
{
	TogglePower(ApplicationsContainer->GetVisibility() == ESlateVisibility::Collapsed);
}

void UMobilePhone::ToggleVisibility() const
{
	ToggleVisibility(!StaticMesh->IsVisible());
}

void UMobilePhone::TogglePower(bool bPowerOn) const
{
	if(bPowerOn)
		ApplicationsContainer->OpenApplication(EPhoneApplication::HomePage);
	
	ESlateVisibility visibility = bPowerOn ? ESlateVisibility::Visible : ESlateVisibility::Hidden;
	ApplicationsContainer->SetVisibility(visibility);
}

void UMobilePhone::ToggleVisibility(bool bIsVisible) const
{
	StaticMesh->SetVisibility(bIsVisible);
	MobilePhoneScreenWidgetComponent->SetVisibility(bIsVisible);
}

void UMobilePhone::PlayNotificationSound()
{
	AudioComponent->SetSound(NotificationSound);
	AudioComponent->Play();
}

void UMobilePhone::OnFocusPhoneTriggered()
{
	AnimInstance->SetPhoneAnimState(EPhoneAnimState::PickUp_Pocket);
}

void UMobilePhone::OnPullPhoneTriggered()
{
	AnimInstance->SetPhoneAnimState(EPhoneAnimState::PullOut);
}

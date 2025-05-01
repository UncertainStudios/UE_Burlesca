#pragma once

#include "CoreMinimal.h"
#include "InputSetupable.h"
#include "Components/ChatMessage.h"
#include "Components/ConditionTooltip.h"
#include "Components/DialogueCompanionButton.h"
#include "Components/DialogueResponseButton.h"
#include "Components/ScrollBox.h"
#include "Components/VerticalBox.h"
#include "Dialogue/DialogueCompanion.h"
#include "Dialogue/DialogueMessage.h"
#include "MobilePhone/ApplicationWidgets/PhoneApplication.h"
#include "NodeInfo/DialogueGraphResponseNodeInfo.h"
#include "ChatScreen.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCompanionSelected, EDialogueCompanion, companion);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnNotificationRecivecedEvent);

UCLASS(Blueprintable)
class BURLESCA_API UChatScreen : public UPhoneApplication, public IInputSetupable
{
	GENERATED_BODY()

public:
	virtual void SetupInput(UEnhancedInputComponent* InputComponent) override;
	void NativeConstruct() override;
	virtual void CloseApplication() override;
	
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Animation")
	void ShowDialogueWindow();
	void LoadDialogue(TArray<FDialogueMessage> messageHistory);
	void ClearDialogue();
	void CreateChatMessageWidget(FDialogueMessage message);
	void IncreaseUnreadMessagesQuantity(EDialogueCompanion companion);
	bool GetIsDialogueWindowShown() { return bIsDialogueWindowShown; }
	void ShowRequest(TArray<UDialogueGraphResponseNodeInfo*> info);
	void ClearRequest();

	UPROPERTY(BlueprintAssignable)
	FOnCompanionSelected OnCompanionSelected;

	UPROPERTY(BlueprintAssignable)
	FOnResponseSelected OnResponseSelected;

	UPROPERTY(BlueprintAssignable)
	FOnNotificationRecivecedEvent OnNotificationRecived;
	
protected:
	UFUNCTION()
	void ProcessOnCompanionSelected(EDialogueCompanion companion) { OnCompanionSelected.Broadcast(companion); }

	UFUNCTION()
	void ProcessOnResponseSelected(int responseId);
	
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Animation")
	void HideDialogueWindow();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)	
	void ShowConditionTooltip(const FText& TextInput);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void HideConditionTooltip();

	UPROPERTY(meta=(BindWidget), BlueprintReadWrite, EditDefaultsOnly)
	UConditionTooltip* ConditionTooltip;
	
	UPROPERTY(meta=(BindWidget))
	UDialogueCompanionButton* FriendButton;
	
	UPROPERTY(meta=(BindWidget))
	UDialogueCompanionButton* PayerButton;

	UPROPERTY(meta=(BindWidget))
	UDialogueCompanionButton* MonsterButton;

	UPROPERTY()
	TMap<EDialogueCompanion, UDialogueCompanionButton*> CompanionToButtonMap;
	
	UPROPERTY(meta=(BindWidget))
	UScrollBox* MessagePlaceholder;

	UPROPERTY(meta=(BindWidget))
	UVerticalBox* ResponsePlaceholder;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UChatMessage> ChatMessageClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UDialogueResponseButton> DialogueResponseButtonClass;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsDialogueWindowShown = false;

	UPROPERTY(EditAnywhere)
	UTexture2D* CompanionMessageTexture;
	
	UPROPERTY(EditAnywhere)
	UTexture2D* CompanionLastMessageTexture;

	UPROPERTY(EditAnywhere)
	UTexture2D* PlayerMessageTexture;
	
	UPROPERTY(EditAnywhere)
	UTexture2D* PlayerLastMessageTexture;
};

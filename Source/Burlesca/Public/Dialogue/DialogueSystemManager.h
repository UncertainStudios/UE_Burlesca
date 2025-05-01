#pragma once

#include "CoreMinimal.h"
#include "DialogueCompanion.h"
#include "MessageHistoryData.h"
#include "MobilePhone/MobilePhone.h"
#include "MobilePhone/ApplicationWidgets/Chat/ChatScreen.h"
#include "ConditionsRegistry/ConditionRegistry.h"
#include "DialogueSystemManager.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(DialogueGraphRuntime, Log, All)

class UConditionTooltip;
class UDialogueGraphQuoteNodeInfo;
class UDialoguePlayer;

UCLASS()
class BURLESCA_API UDialogueSystemManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

protected:
	UFUNCTION()
	void HandleMessageRecieved(EDialogueCompanion companion, UDialogueGraphQuoteNodeInfo* info);

	UFUNCTION()
	void HandleRequestRecieved(EDialogueCompanion companion, TArray<UDialogueGraphResponseNodeInfo*> info);
	void ModifyInfoWithConditionCheck(TArray<UDialogueGraphResponseNodeInfo*> info);

	UFUNCTION()
	void HandleResponseSelected(int responseId);

	UFUNCTION()
	void HandleCompanionSelected(EDialogueCompanion companion);

protected:
	UPROPERTY()
	UDialoguePlayer* DialoguePlayer = nullptr;

	UPROPERTY()
	UMobilePhone* MobilePhone = nullptr;
	
	UPROPERTY()
	UChatScreen* ChatScreen = nullptr;

	UPROPERTY()
	UConditionRegistry* ConditionRegistry = nullptr;
	
	UPROPERTY()
	EDialogueCompanion SelectedCompanion = EDialogueCompanion::None;
	
	// message history
	UPROPERTY()
	UMessageHistoryData* FriendMessageHistory = nullptr;

	UPROPERTY()
	UMessageHistoryData* PayerMessageHistory = nullptr;

	UPROPERTY()
	UMessageHistoryData* MonsterMessageHistory = nullptr;

	UPROPERTY()
	TMap<EDialogueCompanion, UMessageHistoryData*> CompanionToHistoryMap;
};
#pragma once

#include "CoreMinimal.h"
#include "DialogueGraphNodeInfo_Base.h"
#include "Dialogue/InvocationRegistry/DialogueInvocationType.h"
#include "Dialogue/InvocationRegistry/InvocationInfo/ChangeObjectInteractionActivityStateDialogueInvocationInfo.h"
#include "Dialogue/InvocationRegistry/InvocationInfo/DialogueInvocationInfo_Base.h"
#include "DialogueGraphInvokeNodeInfo.generated.h"

UENUM()
enum class EInvokeNodeEventContainer
{
	Global,
	Character,
	Devices,
	MusicalInstruments
};

UCLASS(BlueprintType)
class DIALOGUEGRAPHRUNTIME_API UDialogueGraphInvokeNodeInfo : public UDialogueGraphNodeInfo_Base
{
	GENERATED_BODY()

public:	
	UPROPERTY(EditAnywhere)
	EDialogueInvocationType Invocation = EDialogueInvocationType::None;
	
	UPROPERTY(EditAnywhere, Instanced, meta=(EditCondition = "Invocation != EDialogueInvocationType::None"), export)
	UDialogueInvocationInfo_Base* InvocationInfo;

	UPROPERTY(EditAnywhere, meta=(EditCondition = "Invocation != EDialogueInvocationType::None"))
	bool bReinvokeOnRepeat = false;
	bool bIsInvoked = false;
	
protected:
	void OnInvocationTypeChanged()
	{
		if(InvocationInfo)	
		{
			InvocationInfo->MarkAsGarbage();
			InvocationInfo = nullptr;	
		}
		
		switch (Invocation)
		{
			case EDialogueInvocationType::ChangeObjectInteractionActivityState:
				InvocationInfo = NewObject<UChangeObjectInteractionActivityStateDialogueInvocationInfo>(GetOuter());
				break;
			default:
				InvocationInfo = NewObject<UDialogueInvocationInfo_Base>(GetOuter());
				break;
		}
	}
	
#if WITH_EDITOR
	virtual void PostInitProperties() override
	{
		Super::PostInitProperties();
		
		InvocationInfo = NewObject<UDialogueInvocationInfo_Base>(GetOuter());
	}
	
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override
	{
		Super::PostEditChangeProperty(PropertyChangedEvent);

		if (PropertyChangedEvent.Property && PropertyChangedEvent.Property->GetFName() == GET_MEMBER_NAME_CHECKED(UDialogueGraphInvokeNodeInfo, Invocation))
		{
			OnInvocationTypeChanged();
		}
	}
#endif
};
	
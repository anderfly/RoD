// River of Death Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "RODNextLocationTask.generated.h"

/**
 * 
 */
UCLASS()
class RIVER_OF_DEATH_API URODNextLocationTask : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	URODNextLocationTask();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

protected:
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "AI")
		float Radius = 1000.0f;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "AI")
		FBlackboardKeySelector AimLocationKey;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "AI")
		bool SelfCenter = true;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "AI")
		FBlackboardKeySelector CenterActorKey;
};

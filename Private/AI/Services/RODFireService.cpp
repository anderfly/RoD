// River of Death Game. All Rights Reserved.


#include "AI/Services/RODFireService.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "Component/RODAIPerceptionComponent.h"
#include "RODUtils.h"

URODFireService::URODFireService()
{
	NodeName = "Attack";
}

void URODFireService::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	const auto Controller = OwnerComp.GetAIOwner();
	const auto Blackboard = OwnerComp.GetBlackboardComponent();

	const auto HasAim = Blackboard && Blackboard->GetValueAsObject(EnemyActorKey.SelectedKeyName);


	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
}

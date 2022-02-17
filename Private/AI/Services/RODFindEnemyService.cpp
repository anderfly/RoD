// River of Death Game. All Rights Reserved.


#include "AI/Services/RODFindEnemyService.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "Component/RODAIPerceptionComponent.h"
#include "RODUtils.h"
URODFindEnemyService::URODFindEnemyService()
{
	NodeName = "Find Enemy";
}

void URODFindEnemyService::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	const auto BlackBoard = OwnerComp.GetBlackboardComponent();
	if(BlackBoard)
	{
		const auto Controller = OwnerComp.GetAIOwner();
		const auto PerceptionComponent = RODUtils::GetRODPlayerComponent<URODAIPerceptionComponent>(Controller);
		if(BlackBoard)
		{
			BlackBoard->SetValueAsObject(EnemyActorKey.SelectedKeyName, PerceptionComponent->GetClosestEnemy());
		}
		Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
	}
}

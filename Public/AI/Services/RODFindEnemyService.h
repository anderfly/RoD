// River of Death Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "RODFindEnemyService.generated.h"

/**
 * 
 */
UCLASS()
class RIVER_OF_DEATH_API URODFindEnemyService : public UBTService
{
	GENERATED_BODY()
	
public:
	URODFindEnemyService();

protected:
	//��������� �� ����������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
		FBlackboardKeySelector EnemyActorKey;
	//������� ������ ����������
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};

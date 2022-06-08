// River of Death Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "RODFireService.generated.h"

UCLASS()
class RIVER_OF_DEATH_API URODFireService : public UBTService
{
	GENERATED_BODY()
	
public:
	URODFireService();

protected:
	//��������� �� ����������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
		FBlackboardKeySelector EnemyActorKey;
	//������� ������ ����������
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};

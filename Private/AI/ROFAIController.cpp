// River of Death Game. All Rights Reserved.


#include "AI/ROFAIController.h"
#include "AI/ROFAICharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Component/RODAIPerceptionComponent.h"


AROFAIController::AROFAIController()
{
	RODAIPerceptionComponent = CreateDefaultSubobject<URODAIPerceptionComponent>("RODAIPerceptionComponent");
	SetPerceptionComponent(*RODAIPerceptionComponent);
}
//функция удержания фокуса на ближайшем объекте
void AROFAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	const auto AimActor = GetFocusOnActor();
	SetFocus(AimActor);
}

AActor* AROFAIController::GetFocusOnActor() const
{
	if (!GetBlackboardComponent()) return nullptr;
	return Cast<AActor>(GetBlackboardComponent()->GetValueAsObject(FocusOnKeyName));
}

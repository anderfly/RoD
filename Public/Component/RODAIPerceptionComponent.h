// River of Death Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Perception/AIPerceptionComponent.h"
#include "RODAIPerceptionComponent.generated.h"

/**
 * 
 */
UCLASS()
class RIVER_OF_DEATH_API URODAIPerceptionComponent : public UAIPerceptionComponent
{
	GENERATED_BODY()
	
public:
	AActor* GetClosestEnemy() const;
};

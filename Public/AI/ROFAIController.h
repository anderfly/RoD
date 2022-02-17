// River of Death Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ROFAIController.generated.h"

class URODAIPerceptionComponent;

UCLASS()
class RIVER_OF_DEATH_API AROFAIController : public AAIController
{
	GENERATED_BODY()
		
public:
	AROFAIController();
protected:
		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
		URODAIPerceptionComponent* RODAIPerceptionComponent;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
			FName FocusOnKeyName = "EnemyActor";

		virtual void Tick(float DeltaTime) override;

private:
	AActor* GetFocusOnActor() const;
};

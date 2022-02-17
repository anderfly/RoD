// River of Death Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RODHealthComponent.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnDeath)

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RIVER_OF_DEATH_API URODHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	URODHealthComponent();

	float GetHealth() const { return Health; }

	UFUNCTION(BlueprintCallable, Category="Health")
		bool IsDead() const { return FMath::IsNearlyZero(Health); }

	UFUNCTION(BlueprintCallable, Category = "Health")
		float GetHealthPercent() const { return Health / MaxHealth; }

	FOnDeath OnDeath;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite,Category = "Health", meta =(ClampMin = "0.0", ClampMax="1000.0"))
	float MaxHealth = 100.0f;



	virtual void BeginPlay() override;
			
private:

	float Health = 0.0f;
	UFUNCTION()
		void OnTakeAnyDamage(
			AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);

};

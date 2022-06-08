// River of Death Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RODHealthComponent.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnDeath)
DECLARE_MULTICAST_DELEGATE_OneParam(FOnHealthChanged, float)

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
	FOnHealthChanged OnHealthChanged;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Health", meta =(ClampMin = "0.0", ClampMax="1000.0"))
	float MaxHealth = 100.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Heal")
		bool AutoHeal = true;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Heal")
		float HealUpdateTime = 3.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Heal")
		float HealModifier = 0.1f;

	virtual void BeginPlay() override;
	

private:

	float Health = 0.0f;
	FTimerHandle HealTimerHandle;

	UFUNCTION()
		void OnTakeAnyDamage(
			AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);

	void HealUpdate();
	void SetHealth(float NewHealth);
};

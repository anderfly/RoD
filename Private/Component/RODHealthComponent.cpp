// River of Death Game. All Rights Reserved.


#include "Component/RODHealthComponent.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "TimerManager.h"

DEFINE_LOG_CATEGORY_STATIC(LogHealthComponent, All,All)

URODHealthComponent::URODHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void URODHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	
	SetHealth(MaxHealth);

	AActor* ComponentOwner = GetOwner();
	if(ComponentOwner)
	{
		ComponentOwner ->OnTakeAnyDamage.AddDynamic(this, &URODHealthComponent::OnTakeAnyDamage);
	}
}

void URODHealthComponent::OnTakeAnyDamage
(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	if (Damage <= 0.0f || IsDead() || !GetWorld()) return;

	SetHealth(Health - Damage);

	GetWorld()->GetTimerManager().ClearTimer(HealTimerHandle);

	if(IsDead())
	{
		OnDeath.Broadcast();
	}
	else if (AutoHeal)
	{
		GetWorld()->GetTimerManager().SetTimer(HealTimerHandle, this, &URODHealthComponent::HealUpdate, HealUpdateTime, true, HealUpdateTime);
	}

}

void URODHealthComponent::HealUpdate()
{
	SetHealth(Health + HealModifier);
	
	if (FMath::IsNearlyEqual(Health, MaxHealth && GetWorld()))
	{
		GetWorld()->GetTimerManager().ClearTimer(HealTimerHandle);
	}
}

void URODHealthComponent::SetHealth(float NewHealth)
{
	Health = FMath::Clamp(NewHealth, 0.0f, MaxHealth);
	OnHealthChanged.Broadcast(Health);
}

// River of Death Game. All Rights Reserved.


#include "Component/RODHealthComponent.h"
#include "GameFramework/Actor.h"

DEFINE_LOG_CATEGORY_STATIC(LogHealthComponent, All,All)

URODHealthComponent::URODHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void URODHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	check(MaxHealth > 0);
	Health = MaxHealth;
	AActor* ComponentOwner = GetOwner();
	if(ComponentOwner)
	{
		ComponentOwner ->OnTakeAnyDamage.AddDynamic(this, &URODHealthComponent::OnTakeAnyDamage);
	}
}

void URODHealthComponent::OnTakeAnyDamage
(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	if (Damage <= 0.0f || IsDead()) return;
	Health = FMath::Clamp(Health - Damage, 0.0f, MaxHealth);
	UE_LOG(LogHealthComponent, Display, TEXT("Damage: %f"), Health);
	if(IsDead())
	{
		OnDeath.Broadcast();
	}
}


// River of Death Game. All Rights Reserved.


#include "Weapon/RODWeapon.h"
#include "Components/SkeletalMeshComponent.h"

ARODWeapon::ARODWeapon()
{
	PrimaryActorTick.bCanEverTick = false;

	WeaponMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>("WeaponMesh");
	SetRootComponent(WeaponMeshComponent);
}

void ARODWeapon::BeginPlay()
{
	Super::BeginPlay();	
}


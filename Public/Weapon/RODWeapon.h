// River of Death Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RODWeapon.generated.h"

class USkeletalMeshComponent;

UCLASS()
class RIVER_OF_DEATH_API ARODWeapon : public AActor
{
	GENERATED_BODY()
	
public:	

	ARODWeapon();

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Weapon")
		USkeletalMeshComponent* WeaponMeshComponent;

	virtual void BeginPlay() override;

};

// River of Death Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RODDevDamageActorActor.generated.h"

UCLASS()
class RIVER_OF_DEATH_API ARODDevDamageActorActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARODDevDamageActorActor();

	UPROPERTY(VisibleAnyWhere, BlueprintReadWrite)
		USceneComponent* SceneComponent;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		float Radius = 300.0f;

	UPROPERTY(VisibleAnyWhere, BlueprintReadWrite)
		FColor SphereColor = FColor::Red;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		float Damage = 10.0f;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		bool DoFullDamage = false;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

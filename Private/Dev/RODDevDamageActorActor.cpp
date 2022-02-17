// River of Death Game. All Rights Reserved.


#include "Dev/RODDevDamageActorActor.h"
#include "DrawDebugHelpers.h"
#include "Kismet/GamePlayStatics.h"
// Sets default values
ARODDevDamageActorActor::ARODDevDamageActorActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>("SceneComponent");
	SetRootComponent(SceneComponent);
}

// Called when the game starts or when spawned
void ARODDevDamageActorActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARODDevDamageActorActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	DrawDebugSphere(GetWorld(), GetActorLocation(), Radius, 24, SphereColor);
	UGameplayStatics::ApplyRadialDamage(GetWorld(), Damage, GetActorLocation(), Radius, nullptr, {}, this, nullptr, DoFullDamage);
}


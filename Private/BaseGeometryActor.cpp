// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseGeometryActor.h"

DEFINE_LOG_CATEGORY_STATIC(LogBaseGeometry, All, All)

// Sets default values
ABaseGeometryActor::ABaseGeometryActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMesh");
	SetRootComponent(BaseMesh);
}

// Called when the game starts or when spawned
void ABaseGeometryActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseGeometryActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseGeometryActor::printTypes()
{
	UE_LOG(LogTemp, Display, TEXT("Hello Unreal"));
	UE_LOG(LogTemp, Warning, TEXT("Hello Unreal"));
	UE_LOG(LogTemp, Error, TEXT("Hello Unreal"));


	UE_LOG(LogTemp, Display, TEXT("Kills number = %d"), KillsNum);
}

void ABaseGeometryActor::printTransform()
{
	FTransform Transform = GetActorTransform();
	FVector Location = Transform.GetLocation();
	FRotator Rotator = Transform.Rotator();
	FVector Scale = Transform.GetScale3D();


	UE_LOG(LogTemp, Display, TEXT("Transform %s"), *Transform.ToString());
	UE_LOG(LogTemp, Display, TEXT("Location %s"), *Location.ToString());
	UE_LOG(LogTemp, Display, TEXT("Rotation %s"), *Rotator.ToString());
	UE_LOG(LogTemp, Display, TEXT("Scale %s"), *Scale.ToString());

}


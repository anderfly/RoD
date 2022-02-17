// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "BaseGeometryActor.generated.h"

UCLASS()
class RIVER_OF_DEATH_API ABaseGeometryActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseGeometryActor();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* BaseMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere)
	int32 KillsNum = 7;

	UPROPERTY(EditAnywhere)
	float health = 32.445;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	void printTypes();
	void printTransform();
};

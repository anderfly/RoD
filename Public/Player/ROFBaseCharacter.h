// River of Death Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ROFBaseCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class URODHealthComponent;

UCLASS()
class RIVER_OF_DEATH_API AROFBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AROFBaseCharacter();

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
		USpringArmComponent* SpringArmComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
		UCameraComponent* CameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
		URODHealthComponent* HealthComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Animation")
		UAnimMontage* DeathAnimMontage;

	virtual void BeginPlay() override;

public:	

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void MoveForward(float Amount);
	void MoveRight(float Amount);
	void OnDeath();
};
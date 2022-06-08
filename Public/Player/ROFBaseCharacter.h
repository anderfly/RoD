// River of Death Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ROFBaseCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class URODHealthComponent;
class DeathRenderComponent;
class USoundBase;

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

	UPROPERTY(EditDefaultsOnly, Category = "Death")
		UAnimMontage* DeathAnimMontage;

	UPROPERTY(EditDefaultsOnly, Category = "Death")
		USoundBase* DeathSound;

	UPROPERTY(EditDefaultsOnly, Category = "Movement")
		FVector2D LandedDamageVelocity = FVector2D(900.0f, 1500.0f);

	UPROPERTY(EditDefaultsOnly, Category = "Movement")
		FVector2D LandedDamage = FVector2D(10.0f, 100.0f);

	virtual void BeginPlay() override;

public:	

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void MoveForward(float Amount);
	void MoveRight(float Amount);

	void OnDeath();
	void OnHealthChanged(float Health);

	UFUNCTION()
		void OnGroundLanded(const FHitResult& Hit);
};
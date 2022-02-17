// River of Death Game. All Rights Reserved.


#include "Player/ROFBaseCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Component/RODHealthComponent.h"
#include "Components/TextRenderComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

DEFINE_LOG_CATEGORY_STATIC(LogBaseCharacter, All, All);

AROFBaseCharacter::AROFBaseCharacter()
{
 	PrimaryActorTick.bCanEverTick = true;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
	SpringArmComponent->SetupAttachment(GetRootComponent());
	SpringArmComponent->bUsePawnControlRotation = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(SpringArmComponent);

	HealthComponent = CreateDefaultSubobject<URODHealthComponent>("HealthComponent");
		}
void AROFBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &AROFBaseCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AROFBaseCharacter::MoveRight);
	PlayerInputComponent->BindAxis("LookUp", this, &AROFBaseCharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("TurnAround", this, &AROFBaseCharacter::AddControllerYawInput);
}

void AROFBaseCharacter::MoveForward(float Amount)
{
	AddMovementInput(GetActorForwardVector(), Amount);
}

void AROFBaseCharacter::MoveRight(float Amount)
{
	AddMovementInput(GetActorRightVector(), Amount);
}
void AROFBaseCharacter::OnDeath()
{
	UE_LOG(LogBaseCharacter, Display, TEXT("Player is dead: %s"), *GetName());
	PlayAnimMontage(DeathAnimMontage);

	GetCharacterMovement()->DisableMovement();

	SetLifeSpan(5.0f);
}
void AROFBaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	HealthComponent->OnDeath.AddUObject(this, &AROFBaseCharacter::OnDeath);


}

void AROFBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	const auto Health = HealthComponent->GetHealth();

}







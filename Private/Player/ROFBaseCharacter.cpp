// River of Death Game. All Rights Reserved.


#include "Player/ROFBaseCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Component/RODHealthComponent.h"
#include "Components/TextRenderComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundBase.h"

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
	PlayerInputComponent->BindAction("Jump", IE_Pressed,this,&AROFBaseCharacter::Jump);
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
	UGameplayStatics::SpawnSound2D(this, DeathSound);
	GetCharacterMovement()->DisableMovement();

	SetLifeSpan(5.0f);
}

void AROFBaseCharacter::OnHealthChanged(float Health)
{
}

void AROFBaseCharacter::OnGroundLanded(const FHitResult& Hit)
{
	const auto FallValocityZ = -GetCharacterMovement()->Velocity.Z;
	if (FallValocityZ < LandedDamageVelocity.X) return;
	const auto FinalDamage = FMath::GetMappedRangeValueClamped(LandedDamageVelocity, LandedDamage, FallValocityZ);
	TakeDamage(FinalDamage, FDamageEvent(), nullptr, nullptr);
}

void AROFBaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	OnHealthChanged(HealthComponent->GetHealth());
	HealthComponent->OnDeath.AddUObject(this, &AROFBaseCharacter::OnDeath);
	HealthComponent->OnHealthChanged.AddUObject(this, &AROFBaseCharacter::OnHealthChanged);

	LandedDelegate.AddDynamic(this, &AROFBaseCharacter::OnGroundLanded);
}

void AROFBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}







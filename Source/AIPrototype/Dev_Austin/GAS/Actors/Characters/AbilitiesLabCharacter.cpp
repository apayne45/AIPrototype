// Fill out your copyright notice in the Description page of Project Settings.


#include "Dev_Austin/GAS/Actors/Characters/AbilitiesLabCharacter.h"
#include "AbilitySystemGlobals.h"
#include "Components/CapsuleComponent.h"
#include "Dev_Austin/GAS/Components/LabAbilitySystemComponent.h"
#include "Dev_Austin/GAS/Attributes/LabHealthAttributeSet.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameplayAbilitiesModule.h"
#include "InputActionValue.h"

// Sets default values
AAbilitiesLabCharacter::AAbilitiesLabCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Construct GAS
	LabAbilitySystemComp = CreateDefaultSubobject<ULabAbilitySystemComponent>(TEXT("AbilitySystem"));
	LabAbilitySystemComp->SetIsReplicated(true);
	LabAbilitySystemComp->SetReplicationMode(AbilityReplicationMode);

	// Set size for collision capsule
	if (UCapsuleComponent* capsuleComponent = GetCapsuleComponent()) {
		capsuleComponent->InitCapsuleSize(42.f, 96.0f);
	}

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	if (UCharacterMovementComponent* moveComponent = GetCharacterMovement()) {
		moveComponent->bOrientRotationToMovement = true;
		moveComponent->RotationRate = FRotator(0.0f, 500.0f, 0.0f);

		// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
		// instead of recompiling to adjust them
		moveComponent->JumpZVelocity = 500.f;
		moveComponent->AirControl = 0.35f;
		moveComponent->MaxWalkSpeed = 500.f;
		moveComponent->MinAnalogWalkSpeed = 20.f;
		moveComponent->BrakingDecelerationWalking = 2000.f;
		moveComponent->BrakingDecelerationFalling = 1500.0f;
	}
}

// Called when the game starts or when spawned
void AAbilitiesLabCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AAbilitiesLabCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAbilitiesLabCharacter::PostInitializeComponents() 
{
	Super::PostInitializeComponents();

	//InitAbilitySystem();
}

void AAbilitiesLabCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// Init ability system for NPCs / enemies that have spawn into world
	InitAbilitySystem();
}

void AAbilitiesLabCharacter::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	// route the input
	DoMove(MovementVector.X, MovementVector.Y);
}

void AAbilitiesLabCharacter::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	// route the input
	DoLook(LookAxisVector.X, LookAxisVector.Y);
}

void AAbilitiesLabCharacter::DoMove(float Right, float Forward)
{
	if (GetController() != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = GetController()->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(ForwardDirection, Forward);
		AddMovementInput(RightDirection, Right);
	}
}

void AAbilitiesLabCharacter::DoLook(float Yaw, float Pitch)
{
	if (GetController() != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(Yaw);
		AddControllerPitchInput(Pitch);
	}
}

void AAbilitiesLabCharacter::DoJumpStart()
{
	// signal the character to jump
	Jump();
}

void AAbilitiesLabCharacter::DoJumpEnd()
{
	// signal the character to stop jumping
	StopJumping();
}

void AAbilitiesLabCharacter::InitAbilitySystem() 
{
	if (!LabAbilitySystemComp) {
		UE_LOG(LogTemp, Error, TEXT("AbilitiesCharacter::InitAbilitySystem : No valid AbilitySystemComp detected. Must add a 'LabAbilitySystemComp'"));
		return;
	}

	// Init ability system comp
	LabAbilitySystemComp->InitAbilityActorInfo(this, this);
}

UAbilitySystemComponent* AAbilitiesLabCharacter::GetAbilitySystemComponent() const 
{
	return LabAbilitySystemComp;
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "Dev_Austin/GAS/Actors/Characters/AbilitiesLabCharacter.h"
#include "Dev_Austin/GAS/Components/LabAbilitySystemComponent.h"
#include "Dev_Austin/GAS/Attributes/LabHealthAttributeSet.h"

// Sets default values
AAbilitiesLabCharacter::AAbilitiesLabCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	LabAbilitySystemComp = CreateDefaultSubobject<ULabAbilitySystemComponent>(TEXT("AbilitySystem"));
	HealthSet = CreateDefaultSubobject<ULabHealthAttributeSet>(TEXT("HealthSet"));
}

// Called when the game starts or when spawned
void AAbilitiesLabCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	if (LabAbilitySystemComp) {
		LabAbilitySystemComp->InitAbilityActorInfo(this, this);
	}
}

// Called every frame
void AAbilitiesLabCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAbilitiesLabCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

UAbilitySystemComponent* AAbilitiesLabCharacter::GetAbilitySystemComponent() const 
{
	return LabAbilitySystemComp;
}


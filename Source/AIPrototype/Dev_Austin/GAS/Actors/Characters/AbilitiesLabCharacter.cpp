// Fill out your copyright notice in the Description page of Project Settings.


#include "Dev_Austin/GAS/Actors/Characters/AbilitiesLabCharacter.h"
#include "AbilitySystemGlobals.h"
//#include "AttributeSet.h"
#include "Dev_Austin/GAS/Components/LabAbilitySystemComponent.h"
#include "Dev_Austin/GAS/Attributes/LabHealthAttributeSet.h"
#include "GameplayAbilitiesModule.h"

// Sets default values
AAbilitiesLabCharacter::AAbilitiesLabCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Construct GAS
	LabAbilitySystemComp = CreateDefaultSubobject<ULabAbilitySystemComponent>(TEXT("AbilitySystem"));
	HealthSet = CreateDefaultSubobject<ULabHealthAttributeSet>(TEXT("HealthSet"));
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

// Called to bind functionality to input
void AAbilitiesLabCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AAbilitiesLabCharacter::PostInitializeComponents() 
{
	Super::PostInitializeComponents();

	InitAbilitySystem();
}

void AAbilitiesLabCharacter::InitAbilitySystem() 
{
	if (!LabAbilitySystemComp) {
		UE_LOG(LogTemp, Error, TEXT("AbilitiesCharacter::InitAbilitySystem : No valid AbilitySystemComp detected. Must add a 'LabAbilitySystemComp'"));
		return;
	}

	// Init ability system comp
	LabAbilitySystemComp->InitAbilityActorInfo(this, this);

	// Init attribute sets
	UAbilitySystemGlobals* abilitySystemGlobals = IGameplayAbilitiesModule::Get().GetAbilitySystemGlobals();
	FAttributeSetInitter* attributeSetInitter = abilitySystemGlobals ? abilitySystemGlobals->GetAttributeSetInitter() : nullptr;
	if (attributeSetInitter) {
		attributeSetInitter->InitAttributeSetDefaults(LabAbilitySystemComp, *CharacterName.ToString(), 1, true);
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("AbilitiesCharacter::InitAbilitySystem : No valid FAttributeSetInitter detected. Check if data table is setup correctly."));
	}
}

UAbilitySystemComponent* AAbilitiesLabCharacter::GetAbilitySystemComponent() const 
{
	return LabAbilitySystemComp;
}


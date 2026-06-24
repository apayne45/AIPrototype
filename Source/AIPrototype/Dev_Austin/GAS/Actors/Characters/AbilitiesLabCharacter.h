// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "AbilitiesLabCharacter.generated.h"

// fwd declarations
class ULabAbilitySystemComponent;
class ULabHealthAttributeSet;

/**
 * Character class with ability system for testing out GAS
 */
UCLASS(config=Game)
class AIPROTOTYPE_API AAbilitiesLabCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

// Default
public:
	// Sets default values for this character's properties
	AAbilitiesLabCharacter();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void PostInitializeComponents() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

// Character identifier
protected:
	FName CharacterName = "DefaultCharacter";

public:
	const FName& GetCharacterName() const { return CharacterName; }

// Gameplay Ability System (GAS)
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Abilities)
	TObjectPtr<ULabAbilitySystemComponent> LabAbilitySystemComp;

	UPROPERTY()
	TObjectPtr<ULabHealthAttributeSet> HealthSet;

public:
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	virtual void InitAbilitySystem();
};

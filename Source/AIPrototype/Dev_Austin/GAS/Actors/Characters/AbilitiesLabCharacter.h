// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "AbilitiesLabCharacter.generated.h"

// fwd declarations
struct FInputActionValue;
enum class EGameplayEffectReplicationMode : uint8;
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

	virtual void PostInitializeComponents() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void PossessedBy(AController* NewController) override;

// Movement
protected:
	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

public:
	/** Handles move inputs from either controls or UI interfaces */
	UFUNCTION(BlueprintCallable, Category = "Input")
	virtual void DoMove(float Right, float Forward);

	/** Handles look inputs from either controls or UI interfaces */
	UFUNCTION(BlueprintCallable, Category = "Input")
	virtual void DoLook(float Yaw, float Pitch);

	/** Handles jump pressed inputs from either controls or UI interfaces */
	UFUNCTION(BlueprintCallable, Category = "Input")
	virtual void DoJumpStart();

	/** Handles jump pressed inputs from either controls or UI interfaces */
	UFUNCTION(BlueprintCallable, Category = "Input")
	virtual void DoJumpEnd();

// Character identifier
protected:
	FName CharacterName = "DefaultCharacter";

public:
	const FName& GetCharacterName() const { return CharacterName; }

// Gameplay Ability System (GAS)
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Abilities)
	TObjectPtr<ULabAbilitySystemComponent> LabAbilitySystemComp;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Abilities)
	EGameplayEffectReplicationMode AbilityReplicationMode;

public:
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	virtual void InitAbilitySystem();
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "LabAbilitySystemComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAbilitySystemInitialization, ULabAbilitySystemComponent*, AbilitySystemComponent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAbilitySystemSpecChanged, const FGameplayAbilitySpecHandle&, AbilitySpecHandle);

/**
 * Custom ability system component for AAbilitiesLabCharacter class
 */
UCLASS()
class AIPROTOTYPE_API ULabAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	virtual void OnRep_SpawnedAttributes(const TArray<UAttributeSet*>& PreviousSpawnedAttributes) override;

protected:
	virtual void OnGiveAbility(FGameplayAbilitySpec& AbilitySpec) override;
	virtual void OnRemoveAbility(FGameplayAbilitySpec& AbilitySpec) override;

public:
	UPROPERTY(BlueprintAssignable)
	FAbilitySystemInitialization OnSpawnedAttributes;

	UPROPERTY(BlueprintAssignable)
	FAbilitySystemSpecChanged OnAbilityGranted;

	UPROPERTY(BlueprintAssignable)
	FAbilitySystemSpecChanged OnAbilityRemoved;
};

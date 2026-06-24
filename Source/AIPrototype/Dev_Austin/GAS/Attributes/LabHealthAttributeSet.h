// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "LabHealthAttributeSet.generated.h"

// fwd declarations
struct FGameplayEffectModCallbackData;

// event delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FAttributeChangedEvent, UAttributeSet*, AttributeSet, float, OldValue, float, NewValue);

/**
 * Health attribute set for handling gameplay effects/abilities with GAS
 */
UCLASS()
class AIPROTOTYPE_API ULabHealthAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	ULabHealthAttributeSet();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldValue);
	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldValue);

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, ReplicatedUsing = OnRep_Health, meta = (HideFromModifiers))
	FGameplayAttributeData Health;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth)
	FGameplayAttributeData MaxHealth;

	UPROPERTY(VisibleAnywhere)
	FGameplayAttributeData Damage;

	ATTRIBUTE_ACCESSORS_BASIC(ULabHealthAttributeSet, Health);
	ATTRIBUTE_ACCESSORS_BASIC(ULabHealthAttributeSet, MaxHealth);
	ATTRIBUTE_ACCESSORS_BASIC(ULabHealthAttributeSet, Damage);

	UPROPERTY(BlueprintAssignable)
	FAttributeChangedEvent OnHealthChanged;
};

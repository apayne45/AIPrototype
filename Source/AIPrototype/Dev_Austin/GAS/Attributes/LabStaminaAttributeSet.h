// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "LabStaminaAttributeSet.generated.h"

// fwd declarations
struct FGameplayEffectModCallbackData;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FStaminaChangedEvent, UAttributeSet*, AttributeSet, float, OldValue, float, NewValue);

/**
 * Stamina attribute set for determining movement abilities (Ex: Dash)
 */
UCLASS()
class AIPROTOTYPE_API ULabStaminaAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	ULabStaminaAttributeSet();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue) override;
	//virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	UFUNCTION()
	void OnRep_Stamina(const FGameplayAttributeData& OldValue);
	UFUNCTION()
	void OnRep_MaxStamina(const FGameplayAttributeData& OldValue);

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, ReplicatedUsing = OnRep_Stamina)
	FGameplayAttributeData Stamina;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, ReplicatedUsing = OnRep_MaxStamina)
	FGameplayAttributeData MaxStamina;
	
	ATTRIBUTE_ACCESSORS_BASIC(ULabStaminaAttributeSet, Stamina);
	ATTRIBUTE_ACCESSORS_BASIC(ULabStaminaAttributeSet, MaxStamina);

	UPROPERTY(BlueprintAssignable)
	FStaminaChangedEvent OnStaminaChanged;
};

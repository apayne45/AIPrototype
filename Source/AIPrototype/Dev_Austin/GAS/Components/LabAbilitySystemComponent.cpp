// Fill out your copyright notice in the Description page of Project Settings.


#include "Dev_Austin/GAS/Components/LabAbilitySystemComponent.h"

void ULabAbilitySystemComponent::OnRep_SpawnedAttributes(const TArray<UAttributeSet*>& PreviousSpawnedAttributes)
{
	Super::OnRep_SpawnedAttributes(PreviousSpawnedAttributes);

	OnSpawnedAttributes.Broadcast(this);
}


void ULabAbilitySystemComponent::OnGiveAbility(FGameplayAbilitySpec& AbilitySpec)
{
	Super::OnGiveAbility(AbilitySpec);

	OnAbilityGranted.Broadcast(AbilitySpec.Handle);
}

void ULabAbilitySystemComponent::OnRemoveAbility(FGameplayAbilitySpec& AbilitySpec)
{
	Super::OnRemoveAbility(AbilitySpec);

	OnAbilityRemoved.Broadcast(AbilitySpec.Handle);
}
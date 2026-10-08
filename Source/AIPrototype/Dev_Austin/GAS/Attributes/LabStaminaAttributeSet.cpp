// Fill out your copyright notice in the Description page of Project Settings.


#include "Dev_Austin/GAS/Attributes/LabStaminaAttributeSet.h"
#include "Net/UnrealNetwork.h"

ULabStaminaAttributeSet::ULabStaminaAttributeSet() 
{
	InitStamina(100.0f);
	InitMaxStamina(100.0f);
}

void ULabStaminaAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ULabStaminaAttributeSet, Stamina);
	DOREPLIFETIME(ULabStaminaAttributeSet, MaxStamina);
}

void ULabStaminaAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	UE_LOG(LogTemp, Warning, TEXT("PreChange: Attribute '%s'"), *Attribute.AttributeName);

	if (Attribute == GetStaminaAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.0f, GetMaxStamina());
	}

	Super::PreAttributeChange(Attribute, NewValue);
}

void ULabStaminaAttributeSet::PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue)
{
	Super::PostAttributeChange(Attribute, OldValue, NewValue);

	UE_LOG(LogTemp, Warning, TEXT("PostChange: Attribute '%s' changed %.2f -> %.2f"), *Attribute.AttributeName, OldValue, NewValue);

	// apply/remove tag to indicate if stamina is full
	UAbilitySystemComponent* pASC = GetOwningAbilitySystemComponent();
	check(pASC);
	const FGameplayTag& staminaFullTag = FGameplayTag::RequestGameplayTag("Status.Stamina.Full");
	const bool bIsFull = (GetStamina() >= GetMaxStamina());
	const bool bWasFull = pASC->HasMatchingGameplayTag(staminaFullTag);
	
	if (bIsFull && !bWasFull) {
		pASC->AddLooseGameplayTag(staminaFullTag);
	}
	else if (!bIsFull && bWasFull) {
		pASC->RemoveLooseGameplayTag(staminaFullTag);
	}

	// broadcast stamina change events
	if (Attribute == GetStaminaAttribute()) 
	{
		OnStaminaChanged.Broadcast(this, OldValue, NewValue);
	}
	else if (Attribute == GetMaxStaminaAttribute()) 
	{
		const float CurrentStamina = GetStamina();
		OnStaminaChanged.Broadcast(this, CurrentStamina, CurrentStamina);
	}
}

//void ULabStaminaAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
//{
//	Super::PostGameplayEffectExecute(Data);
//}

void ULabStaminaAttributeSet::OnRep_Stamina(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULabStaminaAttributeSet, Stamina, OldValue);
	const float OldStamina = OldValue.GetCurrentValue();
	const float NewStamina = GetStamina();
	OnStaminaChanged.Broadcast(this, OldStamina, NewStamina);
}

void ULabStaminaAttributeSet::OnRep_MaxStamina(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULabStaminaAttributeSet, MaxStamina, OldValue);
	const float CurrentStamina = GetMaxStamina();
	OnStaminaChanged.Broadcast(this, CurrentStamina, CurrentStamina);
}
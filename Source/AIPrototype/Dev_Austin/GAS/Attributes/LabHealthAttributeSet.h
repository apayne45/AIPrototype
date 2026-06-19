// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "LabHealthAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class AIPROTOTYPE_API ULabHealthAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	ULabHealthAttributeSet();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated)
	FGameplayAttributeData Health;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated)
	FGameplayAttributeData MaxHealth;

	ATTRIBUTE_ACCESSORS_BASIC(ULabHealthAttributeSet, Health);
	ATTRIBUTE_ACCESSORS_BASIC(ULabHealthAttributeSet, MaxHealth);
};

// Fill out your copyright notice in the Description page of Project Settings.


#include "Dev_Austin/GAS/Attributes/LabHealthAttributeSet.h"
#include "Net/UnrealNetwork.h"

ULabHealthAttributeSet::ULabHealthAttributeSet() 
{
	InitHealth(100.0f);
	InitMaxHealth(100.0f);
}

void ULabHealthAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ULabHealthAttributeSet, Health);
	DOREPLIFETIME(ULabHealthAttributeSet, MaxHealth);
}

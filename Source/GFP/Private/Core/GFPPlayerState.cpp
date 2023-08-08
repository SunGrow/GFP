// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/GFPPlayerState.h"

#include "System/GFPAbilitySystemComponent.h"
#include "System/Gameplay/Attributes/PlayerAttributeSet.h"

AGFPPlayerState::AGFPPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UGFPAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
}

UAbilitySystemComponent* AGFPPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

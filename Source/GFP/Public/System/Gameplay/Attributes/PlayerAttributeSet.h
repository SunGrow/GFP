// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "PlayerAttributeSet.generated.h"

#define GAMEPLAYATTRIBUTE_DEFINITIONS(Var) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(UDFPAttributeSet, Var); \
GAMEPLAYATTRIBUTE_VALUE_GETTER(Var); \
GAMEPLAYATTRIBUTE_VALUE_SETTER(Var); \
GAMEPLAYATTRIBUTE_VALUE_INITTER(Var);

UCLASS()
class GFP_API UPlayerAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
};
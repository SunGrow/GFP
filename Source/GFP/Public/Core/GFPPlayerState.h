// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"

#include "GameFramework/PlayerState.h"
#include "GFPPlayerState.generated.h"

class UPlayerAttributeSet;
class UGFPAbilitySystemComponent;

class UGFPAbilitySystemComponent;

/**
 * 
 */
UCLASS()
class GFP_API AGFPPlayerState : public APlayerState,
								public IAbilitySystemInterface
{
	GENERATED_BODY()

	AGFPPlayerState();
public:
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly);
	TObjectPtr<UGFPAbilitySystemComponent> AbilitySystemComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly);
	TObjectPtr<UPlayerAttributeSet> PlayerAttributeSet;
};

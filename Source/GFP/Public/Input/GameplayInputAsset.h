// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "InputAction.h"
#include "GameplayInputAsset.generated.h"

/**
 * 
 */
UCLASS()
class GFP_API UGameplayInputAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	UInputAction* Movement = nullptr;

	UPROPERTY(EditDefaultsOnly)
	UInputAction* Sprint = nullptr;
	
	UPROPERTY(EditDefaultsOnly)
	UInputAction* Attack = nullptr;
};

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
	UInputAction* Move = nullptr;
	
	UPROPERTY(EditDefaultsOnly)
	UInputAction* Look = nullptr;
	
	UPROPERTY(EditDefaultsOnly)
	UInputAction* Jump = nullptr;
	
	UPROPERTY(EditDefaultsOnly)
	UInputAction* Interact = nullptr;
	
	UPROPERTY(EditDefaultsOnly)
	UInputAction* MainAction = nullptr;
	
	UPROPERTY(EditDefaultsOnly)
	UInputAction* SecondaryAction = nullptr;
};

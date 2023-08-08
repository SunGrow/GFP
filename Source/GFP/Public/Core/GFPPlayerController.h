// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "Input/GameplayInputAsset.h"

#include "GFPPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class GFP_API AGFPPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputMappingContext> BaseMappingContext = nullptr;
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UGameplayInputAsset> BaseInput = nullptr;
};

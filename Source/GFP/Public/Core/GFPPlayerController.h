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

	AGFPPlayerController();

public:
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UGameplayInputAsset> BaseMappingContext = nullptr;
	
	TObjectPtr<UGameplayInputAsset> GetInputAsset() const;
};

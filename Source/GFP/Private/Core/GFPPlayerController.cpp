// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/GFPPlayerController.h"

AGFPPlayerController::AGFPPlayerController()
{
}

TObjectPtr<UGameplayInputAsset> AGFPPlayerController::GetInputAsset() const
{
	return BaseMappingContext;
}

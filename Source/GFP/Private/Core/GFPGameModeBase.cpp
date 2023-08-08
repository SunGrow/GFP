// Copyright Epic Games, Inc. All Rights Reserved.

#include "Core/GFPGameModeBase.h"

#include "Character/PlayerCharacter.h"
#include "Core/GlobalGameState.h"
#include "Core/GameHUD.h"
#include "Core/GFPPlayerController.h"
#include "Core/GFPPlayerState.h"

AGFPGameModeBase::AGFPGameModeBase()
{
	DefaultPawnClass = APlayerCharacter::StaticClass();
	GameStateClass = AGlobalGameState::StaticClass();
	PlayerControllerClass = AGFPPlayerController::StaticClass();
	PlayerStateClass = AGFPPlayerState::StaticClass();
	HUDClass = AGameHUD::StaticClass();
}

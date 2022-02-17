// Copyright Epic Games, Inc. All Rights Reserved.


#include "River_of_DeathGameModeBase.h"
#include "Player/ROFBaseCharacter.h"
#include "Player/RODPlayerController.h"

ARiver_of_DeathGameModeBase::ARiver_of_DeathGameModeBase()
{
	DefaultPawnClass = AROFBaseCharacter::StaticClass();
	PlayerControllerClass = ARODPlayerController::StaticClass();
}

// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "Bomberman.h"
#include "BombermanGameMode.h"
#include "BombermanPlayerController.h"
#include "BombermanCharacter.h"
#include "Kismet/GameplayStatics.h"

ABombermanGameMode::ABombermanGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ABombermanPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void ABombermanGameMode::BeginPlay()
{
	Super::BeginPlay();

	// Create a seconds player
	UGameplayStatics::CreatePlayer(this, 1);
}
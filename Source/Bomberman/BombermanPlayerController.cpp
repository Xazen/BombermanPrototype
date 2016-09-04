// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "Bomberman.h"
#include "BombermanPlayerController.h"
#include "BombermanCharacter.h"

ABombermanPlayerController::ABombermanPlayerController()
{
}

void ABombermanPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
}

void ABombermanPlayerController::SetupInputComponent() 
{
	// set up gameplay key bindings
	Super::SetupInputComponent();
	InputComponent->BindAxis("MoveForward", this, &ABombermanPlayerController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ABombermanPlayerController::MoveRight);
}

void ABombermanPlayerController::MoveForward(float Value)
{
	ABombermanCharacter* const PlayerPawn = Cast<ABombermanCharacter>(GetPawn());
	if (PlayerPawn)
	{
		PlayerPawn->MoveForward(Value);
	}
}

void ABombermanPlayerController::MoveRight(float Value)
{
	ABombermanCharacter* const PlayerPawn = Cast<ABombermanCharacter>(GetPawn());
	if (PlayerPawn)
	{
		PlayerPawn->MoveRight(Value);
	}
}
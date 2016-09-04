// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/PlayerController.h"
#include "BombermanPlayerController.generated.h"

UCLASS()
class ABombermanPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ABombermanPlayerController();

protected:
	
	// Begin PlayerController interface
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;
	// End PlayerController interface

private:
	void MoveForward(float Value);
	void MoveRight(float Value);
};



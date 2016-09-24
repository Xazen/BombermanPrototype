// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Bomb.generated.h"

UCLASS()
class BOMBERMAN_API ABomb : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABomb();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	FORCEINLINE class UStaticMeshComponent* GetMesh() { return BombMesh; }

	UFUNCTION(BlueprintNativeEvent)
	void DidExplode();
	void DidExplode_Implementation();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bomb", Meta = (BlueprintProtected = "true"))
	float TimeToExplode;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Bomb", Meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* BombMesh;

	UPROPERTY(VisibleAnywhere, Category = "Bomb")
	float CurrentTimeToExplode;

	void Explode();
};

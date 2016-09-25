// Fill out your copyright notice in the Description page of Project Settings.

#include "Bomberman.h"
#include "Bomb.h"

// Sets default values
ABomb::ABomb()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TimeToExplode = 3.f;
	CurrentTimeToExplode = TimeToExplode;

	BombMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BombMesh"));
	RootComponent = BombMesh;

	ExplosionTrigger = CreateDefaultSubobject<USphereComponent>(TEXT("ExplosionTrigger"));
	ExplosionTrigger->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);
	ExplosionTrigger->SetSphereRadius(150.f);
	ExplosionTrigger->bGenerateOverlapEvents = true;
}

// Called when the game starts or when spawned
void ABomb::BeginPlay()
{
	Super::BeginPlay();

	// remove this line when the bomb can be spawn by the player
	CurrentTimeToExplode = TimeToExplode;

	// Move these two lines to constructur when bomb is spawned by the player
	ExplosionTrigger->OnComponentBeginOverlap.AddDynamic(this, &ABomb::TriggerEnter);
	ExplosionTrigger->OnComponentEndOverlap.AddDynamic(this, &ABomb::TriggerExit);
}

// Called every frame
void ABomb::Tick(float DeltaTime)
{
	Super::Tick( DeltaTime );
	CurrentTimeToExplode = FMath::Clamp<float>(CurrentTimeToExplode-DeltaTime, 0, TimeToExplode);
	if (CurrentTimeToExplode <= 0) 
	{
		Explode();
	}
}

void ABomb::DidExplode_Implementation()
{
	FString BombDebugString = GetName();
	UE_LOG(LogClass, Log, TEXT("did explode %s"), *BombDebugString);
}

void ABomb::Explode() 
{
	FString BombDebugString = GetName();
	FString DestroySuccess = (Destroy() ? "success" : "failed");

	UE_LOG(LogClass, Log, TEXT("%s will explode: %s"), *BombDebugString, *DestroySuccess);
}

void ABomb::TriggerEnter(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	FString OverlappedComponentName = OverlappedComponent->GetName();
	FString OverlappedActorName = OtherActor->GetName();
	FString OverlappedOtherComp = OtherComp->GetName();
	
	UE_LOG(LogClass, Log, TEXT("OverlappedComponent: %s \n OtherActor: %s \n OtherComp: %s \n OtherBodyIndex: %d \n"), *OverlappedComponentName, *OverlappedActorName, *OverlappedOtherComp, OtherBodyIndex);
	
}

void ABomb::TriggerExit(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogClass, Log, TEXT("ABomb TriggerExit"));
}
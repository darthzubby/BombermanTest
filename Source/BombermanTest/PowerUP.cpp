// Fill out your copyright notice in the Description page of Project Settings.

#include "BombermanTest.h"
#include "PowerUP.h"


// Sets default values
APowerUP::APowerUP(const FObjectInitializer& objectInitializer)
	:Super(objectInitializer)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Add BoxComonent 
	collisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("RootCollision"));

	//Set box size to 50/50/50 (fits one square)
	collisionBox->SetBoxExtent(FVector(50.0f, 50.0f, 50.0f), true);

	//Show in game - remove eventually
	collisionBox->SetHiddenInGame(false);

	//Attach the Overlap function
	collisionBox->OnComponentBeginOverlap.AddDynamic(this, &APowerUP::OnPowerUPOverlap);

	//Set BoxComponent as RootComponent
	RootComponent = collisionBox;
}

// Called when the game starts or when spawned
void APowerUP::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APowerUP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APowerUP::OnPowerUPOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "CollisionDetected");
	Destroy();
}


// Fill out your copyright notice in the Description page of Project Settings.

#include "BombermanTest.h"
#include "SpeedPowerUp.h"


void ASpeedPowerUp::OnPowerUPOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{

	if (OtherActor->GetClass()->ImplementsInterface(UUpdatePlayerInfo::StaticClass()))
	{
		if (speedUpdated == false)
		{
			IUpdatePlayerInfo::Execute_newPlayerSpeed(OtherActor, 1.0f);

			speedUpdated = true;
		}
	}

	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "SpeedBoost");
	Destroy();
}


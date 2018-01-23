// Fill out your copyright notice in the Description page of Project Settings.

#include "BombermanTest.h"
#include "IncreaseBombDamagePowerUp.h"


void AIncreaseBombDamagePowerUp::OnPowerUPOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{

	if (OtherActor->GetClass()->ImplementsInterface(UUpdatePlayerInfo::StaticClass()))
	{
		if (damageUpdated == false)
		{
			IUpdatePlayerInfo::Execute_newBombDamage(OtherActor, 1);

			damageUpdated = true;
		}

		Destroy();
	}

	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, "Increase Damage");

}


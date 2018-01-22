// Fill out your copyright notice in the Description page of Project Settings.

#include "BombermanTest.h"
#include "IncreaseBombAmountPowerUp.h"

void AIncreaseBombAmountPowerUp::OnPowerUPOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{

	if (OtherActor->GetClass()->ImplementsInterface(UUpdatePlayerInfo::StaticClass()))
	{
		if (bombTotalUpdated == false)
		{
			IUpdatePlayerInfo::Execute_newBombAmount(OtherActor, 1);

			bombTotalUpdated = true;
		}
	}

	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, "Increase bomb amount");
	Destroy();
}



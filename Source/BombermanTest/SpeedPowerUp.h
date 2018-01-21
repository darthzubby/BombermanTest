// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PowerUP.h"
#include "UpdatePlayerInfo.h"
#include "SpeedPowerUp.generated.h"


/**
 * 
 */
UCLASS()
class BOMBERMANTEST_API ASpeedPowerUp : public APowerUP
{
	GENERATED_BODY()


public:
	virtual void OnPowerUPOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult) override;

	bool speedUpdated = false;
	
};

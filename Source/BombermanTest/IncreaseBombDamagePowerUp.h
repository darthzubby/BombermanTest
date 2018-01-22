// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PowerUP.h"
#include "UpdatePlayerInfo.h"
#include "IncreaseBombDamagePowerUp.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMANTEST_API AIncreaseBombDamagePowerUp : public APowerUP
{
	GENERATED_BODY()
	
public:

	virtual void OnPowerUPOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult) override;

	bool damageUpdated = false;
	
	
};

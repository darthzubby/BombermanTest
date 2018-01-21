// Fill out your copyright notice in the Description page of Project Settings.

#include "BombermanTest.h"
#include "UpdatePlayerInfo.h"


// This function does not need to be modified.
UUpdatePlayerInfo::UUpdatePlayerInfo(const class FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
}

// Add default functionality here for any IUpdatePlayerInfo functions that are not pure virtual.

void IUpdatePlayerInfo::newPlayerSpeed_Implementation(float newSpeed)
{

}

void IUpdatePlayerInfo::newBombDamage_Implementation(int newDamage)
{
	
}

void IUpdatePlayerInfo::newBombAmount_Implementation(int newAmount)
{
	
}
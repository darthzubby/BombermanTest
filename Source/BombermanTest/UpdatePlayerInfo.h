// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UpdatePlayerInfo.generated.h"

// This class does not need to be modified.
//UINTERFACE(MinimalAPI)
UINTERFACE(BlueprintType)
//UINTERFACE()
class UUpdatePlayerInfo : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

/**
 * 
 */
class BOMBERMANTEST_API IUpdatePlayerInfo
{
	GENERATED_IINTERFACE_BODY()


	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Default")
		void newPlayerSpeed(float newSpeed);
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Default")
		void newBombDamage(int newDamage);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Default")
		void newBombAmount(int newAmount);

};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ConstellationPlane.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UConstellationPlane : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class STARFIGHTER_API IConstellationPlane
{
	GENERATED_BODY()

		// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void SetAtaqueConstellation(FString AtaqueConstellation) = 0;
	virtual void SetdDefensaConstellation(FString DefensaConstellation) = 0;
	virtual void SetdDesplazamientoConstellation(FString DesplazamientoConstellation) = 0;
};

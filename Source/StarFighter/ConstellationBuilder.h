// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ConstellationBuilder.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UConstellationBuilder : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class STARFIGHTER_API IConstellationBuilder
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	virtual void BuildAtaqueConstellation() = 0;
	virtual void BuildDefensaConstellation() = 0;
	virtual void BuildDesplazamientoConstellation() = 0;
	
	virtual class AConstellation* GetConstellation() = 0;

};

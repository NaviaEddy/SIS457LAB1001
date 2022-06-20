// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CapsulaGenerador.h"
#include "CapsulaGeneradorEnergia.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGHTER_API ACapsulaGeneradorEnergia : public ACapsulaGenerador
{
	GENERATED_BODY()
		virtual ACapsula* FabricarCapsula(FString NombreTipoCapsula) override;

};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CapsulaGenerador.h"
#include "CapsulaGeneradorVida.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGHTER_API ACapsulaGeneradorVida : public ACapsulaGenerador
{
	GENERATED_BODY()
		virtual ACapsula* FabricarCapsula(FString NombreTipoCapsula) override;
};

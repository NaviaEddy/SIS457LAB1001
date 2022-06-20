// Fill out your copyright notice in the Description page of Project Settings.


#include "CapsulaGeneradorVida.h"
#include "CapsulaVida.h"

ACapsula* ACapsulaGeneradorVida::FabricarCapsula(FString NombreTipoCapsula)
{
	if (NombreTipoCapsula.Equals("Armamento")) {
		return GetWorld()->SpawnActor<ACapsulaVida>(ACapsulaVida::StaticClass());
	}
    return nullptr;
}

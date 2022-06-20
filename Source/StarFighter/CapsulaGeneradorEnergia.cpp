// Fill out your copyright notice in the Description page of Project Settings.


#include "CapsulaGeneradorEnergia.h"
#include "CapsulaEnergia.h"

ACapsula* ACapsulaGeneradorEnergia::FabricarCapsula(FString NombreTipoCapsula)
{
	if (NombreTipoCapsula.Equals("Energia")) {
		return GetWorld()->SpawnActor<ACapsulaEnergia>(ACapsulaEnergia::StaticClass());
	}
    return nullptr;
}

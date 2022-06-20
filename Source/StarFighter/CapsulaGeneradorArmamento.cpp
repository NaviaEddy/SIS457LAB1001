// Fill out your copyright notice in the Description page of Project Settings.


#include "CapsulaGeneradorArmamento.h"
#include "CapsulaArmamento.h"

ACapsula* ACapsulaGeneradorArmamento::FabricarCapsula(FString NombreTipoCapsula)
{
	if (NombreTipoCapsula.Equals("Armamento")) {
		return GetWorld()->SpawnActor<ACapsulaArmamento>(ACapsulaArmamento::StaticClass());
	}
	return nullptr;
}

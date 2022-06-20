// Fill out your copyright notice in the Description page of Project Settings.


#include "CapsulaGenerador.h"

// Sets default values
ACapsulaGenerador::ACapsulaGenerador()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACapsulaGenerador::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACapsulaGenerador::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

ACapsula* ACapsulaGenerador:: GetCapsula(FString TipoCapsula)
{
	ACapsula* capsula = FabricarCapsula(TipoCapsula);
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Cyan, FString::Printf(TEXT("Fabricando Capsula %s"), *capsula->GetNombre()));
	capsula->Generar();
	capsula->Cargar();
	capsula->Desplegar();
	capsula->Destruir();

	return capsula;
}

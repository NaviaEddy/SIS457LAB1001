// Fill out your copyright notice in the Description page of Project Settings.


#include "CapsulaEnergia.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/CollisionProfile.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"

ACapsulaEnergia::ACapsulaEnergia()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Engine/BasicShapes/Cone.Cone'"));

	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsulaMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	RootComponent = CapsulaMeshComponent;
	CapsulaMeshComponent->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	CapsulaMeshComponent->SetStaticMesh(ShipMesh.Object);
	SetActorEnableCollision(true);
}

void ACapsulaEnergia::BeginPlay()
{
	Super::BeginPlay();

	Nombre = "Capsula Energia";
	TipoCapsula = "Capasula de Energia"; 
	TipoEfecto = "Incrementa energia";
	TipoDuracion = "Mientra este activo";
	TiempoDuracion = 10.0f;
}

void ACapsulaEnergia::Generar()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Emerald, TEXT("Generando una Capsula de Energia"));
}
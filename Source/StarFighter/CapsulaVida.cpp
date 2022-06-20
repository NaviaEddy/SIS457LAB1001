// Fill out your copyright notice in the Description page of Project Settings.


#include "CapsulaVida.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/CollisionProfile.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"

ACapsulaVida::ACapsulaVida()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));

	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsulaMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	RootComponent = CapsulaMeshComponent;
	CapsulaMeshComponent->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	CapsulaMeshComponent->SetStaticMesh(ShipMesh.Object);
	SetActorEnableCollision(true);
}

void ACapsulaVida::BeginPlay()
{
	Super::BeginPlay();

	Nombre = "Capsula Vida";
	TipoCapsula = "Capsula de Vida";
	TipoEfecto = "Incrementa vida"; 
	TipoDuracion = "Mientra este activo";
	TiempoDuracion = 10.0f;
}

void ACapsulaVida::Generar()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Emerald, TEXT("Generando una Capsula de Vida"));
}
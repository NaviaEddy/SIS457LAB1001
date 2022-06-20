// Fill out your copyright notice in the Description page of Project Settings.


#include "ConstellationSetBuilder.h"
#include "Constellation.h"

// Sets default values
AConstellationSetBuilder::AConstellationSetBuilder()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AConstellationSetBuilder::BeginPlay()
{
	Super::BeginPlay();
	 
	Constellation = GetWorld()->SpawnActor<AConstellation>(AConstellation::StaticClass());
	
	Constellation->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called every frame
void AConstellationSetBuilder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AConstellationSetBuilder::BuildAtaqueConstellation()
{
	if (!Constellation)
	{
		UE_LOG(LogTemp, Error, TEXT("BuildAtaqueConstellation():Constellation is NULL, make sure it's initialized."));
		return;
	}

	//Set de Soporte Torreta of the Torreta
	Constellation->SetAtaqueConstellation("Ataque Constellation");
}

void AConstellationSetBuilder::BuildDefensaConstellation()
{
	if (!Constellation)
	{
		UE_LOG(LogTemp, Error, TEXT("BuildDefensaConstellation():Constellation is NULL, make sure it's initialized."));
		return;
	}

	//Set de Soporte Torreta of the Torreta
	Constellation->SetDefensaConstellation("Defensa Constellation");
}

void AConstellationSetBuilder::BuildDesplazamientoConstellation()
{
	if (!Constellation)
	{
		UE_LOG(LogTemp, Error, TEXT("BuildDesplazamientoConstellation():Constellation is NULL, make sure it's initialized."));
		return;
	}

	//Set de Soporte Torreta of the Torreta
	Constellation->SetDesplazamientoConstellation("Desplazamiento Constellation");
}

AConstellation* AConstellationSetBuilder::GetConstellation()
{
	return Constellation;
}


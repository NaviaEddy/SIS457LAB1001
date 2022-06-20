// Copyright Epic Games, Inc. All Rights Reserved.


#include "StarFighterGameModeBase.h"
#include "NaveTerrestreEnemiga01.h"
#include "CapsulaGeneradorArmamento.h"
#include "CapsulaGeneradorEnergia.h"
#include "CapsulaGeneradorVida.h"

void AStarFighterGameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float ProbabilidadAparicionCapsula = FMath::RandRange(6, 12);

	if (ProbabilidadAparicionCapsula < 5.0f) 
	{
	ACapsulaGenerador* CapsulaGenerador_Armamento = GetWorld()->SpawnActor<ACapsulaGeneradorArmamento>(ACapsulaGeneradorArmamento::StaticClass());
	ACapsula* Capsula = CapsulaGenerador_Armamento->GetCapsula("Armamento");
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Turquoise, FString::Printf(TEXT("Capsula generada %s"), *Capsula->GetNombre()));
	}

	else 

		if (ProbabilidadAparicionCapsula > 5.0f && ProbabilidadAparicionCapsula < 10.0f) 
		{
		ACapsulaGenerador* CapsulaGenerador_Energia = GetWorld()->SpawnActor<ACapsulaGeneradorEnergia>(ACapsulaGeneradorEnergia::StaticClass());
		ACapsula* Capsula = CapsulaGenerador_Energia->GetCapsula("Energia");
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Turquoise, FString::Printf(TEXT("Capsula generada %s"), *Capsula->GetNombre()));
	    }

	else 

			if (ProbabilidadAparicionCapsula > 10.0f && ProbabilidadAparicionCapsula < 12.0f)
			{
			ACapsulaGenerador* CapsulaGenerador_Vida = GetWorld()->SpawnActor<ACapsulaGeneradorVida>(ACapsulaGeneradorVida::StaticClass());
			ACapsula* Capsula = CapsulaGenerador_Vida->GetCapsula("Vida");
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Turquoise, FString::Printf(TEXT("Capsula generada %s"), *Capsula->GetNombre()));
			}
}

void AStarFighterGameModeBase::BeginPlay()
{
	Super::BeginPlay();
} 

AStarFighterGameModeBase::AStarFighterGameModeBase()
{
	/*UE_LOG(LogTemp, Warning, TEXT("Dentro de constructor en GameModeBase"));
	GetWorld()->SpawnActor<ANaveTerrestreEnemiga01>(FVector::ZeroVector, FRotator::ZeroRotator);*/

	//SpawnNave<ANaveTerrestreEnemiga01>();
	PrimaryActorTick.bCanEverTick = true;

	//DefaultPawnClass = ANaveAereaJugador::StaticClass();

}

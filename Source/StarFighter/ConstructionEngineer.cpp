// Fill out your copyright notice in the Description page of Project Settings.


#include "ConstructionEngineer.h"
#include "Constellation.h"

// Sets default values
AConstructionEngineer::AConstructionEngineer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AConstructionEngineer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AConstructionEngineer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AConstructionEngineer::SetConstellationBuilder(AActor* Builder)
{
	ConstellationBuilder = Cast<IConstellationBuilder>(Builder);

	if (!ConstellationBuilder) 
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString::Printf(TEXT("Invalid Cast! See Output log for more details")));
		UE_LOG(LogTemp, Error, TEXT("SetConstellationBuilder(): The Actor is not a ConstellationBuilder! Are you sure that the Actor implements that interface?"));
	}
}

AConstellation* AConstructionEngineer::GetConstellation()
{
	if (ConstellationBuilder)
	{
		//Returns the Lodging of the Builder
		return ConstellationBuilder->GetConstellation();
	}
	//Log if the Builder is NULL
	UE_LOG(LogTemp, Error, TEXT("GetConstellation(): Return nullptr"));
	return nullptr;
}

void AConstructionEngineer::ConstructConstellation()
{

	//Log if the Builder is NULL
	if (!ConstellationBuilder)
	{
		UE_LOG(LogTemp, Error, TEXT("ConstructConstellation(): ConstellationBuilder is NULL, make sure it's inicialized."));
		return;
	}

	//Creates the buildings
	ConstellationBuilder->BuildAtaqueConstellation();
	ConstellationBuilder->BuildDefensaConstellation();
	ConstellationBuilder->BuildDesplazamientoConstellation();
}



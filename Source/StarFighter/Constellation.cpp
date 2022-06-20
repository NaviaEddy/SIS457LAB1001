// Fill out your copyright notice in the Description page of Project Settings.


#include "Constellation.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
AConstellation::AConstellation()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AConstellation::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AConstellation::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AConstellation::SetAtaqueConstellation(FString myAtaqueConstellation)
{
	AtaqueConstellation = myAtaqueConstellation;
}

void AConstellation::SetDefensaConstellation(FString myDefensaConstellation)
{
	DefensaConstellation = myDefensaConstellation;
}

void AConstellation::SetDesplazamientoConstellation(FString myDesplazamientoConstellation)
{
	DesplazamientoConstellation = myDesplazamientoConstellation;
}

void AConstellation::ConstellationCharacteristics()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Cyan, FString::Printf(TEXT("%s"), *AtaqueConstellation));
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Cyan, FString::Printf(TEXT("%s"), *DefensaConstellation));
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Cyan, FString::Printf(TEXT("%s"), *DesplazamientoConstellation));
}


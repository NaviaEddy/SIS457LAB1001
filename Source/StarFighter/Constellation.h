// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ConstellationPlane.h"
#include "Constellation.generated.h"

UCLASS()
class STARFIGHTER_API AConstellation : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AConstellation();

private:
	FString AtaqueConstellation;
	FString DefensaConstellation;
	FString DesplazamientoConstellation;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetAtaqueConstellation(FString myAtaqueConstellation);
	void SetDefensaConstellation(FString myDefensaConstellation);
	void SetDesplazamientoConstellation(FString myDesplazamientoConstellation);

	void ConstellationCharacteristics();
};

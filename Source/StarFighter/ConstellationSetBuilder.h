// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ConstellationBuilder.h"
#include "ConstellationSetBuilder.generated.h"

UCLASS()
class STARFIGHTER_API AConstellationSetBuilder : public AActor , public IConstellationBuilder
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AConstellationSetBuilder();

private:
	UPROPERTY(VisibleAnywhere, Category = "Constellation Set")
		class AConstellation* Constellation;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void BuildAtaqueConstellation() override;
	virtual void BuildDefensaConstellation() override;
	virtual void BuildDesplazamientoConstellation() override;

	virtual class AConstellation* GetConstellation() override;

};

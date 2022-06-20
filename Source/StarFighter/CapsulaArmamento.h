// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Capsula.h"
#include "CapsulaArmamento.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGHTER_API ACapsulaArmamento : public ACapsula
{
	GENERATED_BODY()

public:
	ACapsulaArmamento();

protected:
	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* CapsulaMeshComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	virtual void Generar() override;
	
};

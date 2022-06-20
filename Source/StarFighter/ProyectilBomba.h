// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Proyectil.h"
#include "ProyectilBomba.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGHTER_API AProyectilBomba : public AProyectil
{
	GENERATED_BODY()
public:

		AProyectilBomba();

	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};

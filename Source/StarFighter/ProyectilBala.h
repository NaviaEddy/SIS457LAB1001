// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Proyectil.h"
#include "ProyectilBala.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGHTER_API AProyectilBala : public AProyectil
{
	GENERATED_BODY()
public:

	AProyectilBala();

	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

};

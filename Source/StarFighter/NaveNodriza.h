// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProyectilBala.h"
#include "GameFramework/Actor.h"
#include "NaveNodriza.generated.h"

UCLASS()
class STARFIGHTER_API ANaveNodriza : public AActor
{
	GENERATED_BODY()

protected:
	/* The mesh component */
	UPROPERTY(Category = Mesh, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* ShipMeshComponent;
	
public:	
	// Sets default values for this actor's properties
	ANaveNodriza();
	float MoveSpeed;
	//The instance of this Class
	UPROPERTY()
		ANaveNodriza* Instance;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	//ProyectilBala

	void FireBala();

	//void FireShotBala();
	/* Handler for the fire timer expiry */
	void ShotTimerExpired();

	/** Offset from the ships location to spawn projectiles */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		FVector GunOffset;

	/* How fast the weapon will fire */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		float FireRate;

	const FVector FireDirection = FVector(-90.f, 0.f, 0.0f).GetClampedToMaxSize(1.0f);
	const FRotator FireRotation = FireDirection.Rotation();


	float TimeSinceLastShot;


private:

	/* Flag to control firing  */
	uint32 bCanFire : 1;

	/** Handle for efficient management of ShotTimerExpired timer */
	FTimerHandle TimerHandle_ShotTimerExpired;
};

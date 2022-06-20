// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Proyectil.generated.h"

class UProjectileMovementComponent;
class UStaticMeshComponent;
//class UCapsuleComponent;

UCLASS()
class STARFIGHTER_API AProyectil : public AActor
{
	GENERATED_BODY()
protected:
	/** Sphere collision component */
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* ProjectileMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
		UProjectileMovementComponent* ProjectileMovement;


	//UPROPERTY(EditAnywhere)
	//	UCapsuleComponent* CapsuleCollision;
protected:
	// Sets default values for this actor's properties
	AProyectil();
	/** Projectile movement component */

	/** Function to handle the projectile hitting something */
	//UFUNCTION()
	//	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	/** Returns ProjectileMesh subobject **/
	FORCEINLINE UStaticMeshComponent* GetProjectileMesh() const { return ProjectileMesh; }
	/** Returns ProjectileMovement subobject **/
	FORCEINLINE UProjectileMovementComponent* GetProjectileMovement() const { return ProjectileMovement; }


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

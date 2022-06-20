// Fill out your copyright notice in the Description page of Project Settings.


#include "ProyectilBomba.h"

AProyectilBomba::AProyectilBomba()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ProjectileBombaMeshAsset(TEXT("/Game/TwinStick/Meshes/Projectile3.Projectile3"));

	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.

	PrimaryActorTick.bCanEverTick = true;

	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	ProjectileMesh->SetStaticMesh(ProjectileBombaMeshAsset.Object);
	ProjectileMesh->SetupAttachment(RootComponent);
	ProjectileMesh->BodyInstance.SetCollisionProfileName("Projectile");
	ProjectileMesh->OnComponentHit.AddDynamic(this, &AProyectilBomba::OnHit);
	RootComponent = ProjectileMesh;

	// Use a ProjectileMovementComponent to govern this projectile's movement

	//ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement1"));
	//ProjectileMovement->UpdatedComponent = ProjectileMesh;
	//ProjectileMovement->InitialSpeed = 2000.f;
	//ProjectileMovement->MaxSpeed = 2000.f;
	//ProjectileMovement->bRotationFollowsVelocity = true;
	//ProjectileMovement->bShouldBounce = false;
	//ProjectileMovement->ProjectileGravityScale = 0.f; // No gravity

	//// Die after 3 seconds by default
	//InitialLifeSpan = 3.0f;
}

void AProyectilBomba::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	FVector NormalImpulse, const FHitResult& Hit)
{
	// Only add impulse and destroy projectile if we hit a physics
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr) && OtherComp->IsSimulatingPhysics())
	{
		OtherComp->AddImpulseAtLocation(GetVelocity() * 20.0f, GetActorLocation());
	}

	Destroy();
}

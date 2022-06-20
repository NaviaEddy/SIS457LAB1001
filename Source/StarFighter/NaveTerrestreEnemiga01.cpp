// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveTerrestreEnemiga01.h"

ANaveTerrestreEnemiga01::ANaveTerrestreEnemiga01()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> NaveEnemigaTerrestre(TEXT("/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO"));
	ShipMeshComponent->SetStaticMesh(NaveEnemigaTerrestre.Object);


	// Movement
	MoveSpeed = 50.0f;


	// Weapon
	GunOffset = FVector(90.f, 0.f, 0.f);
	FireRate = 10.0f;
	bCanFire = true;

	FireForwardValue = 10.0f;
	FireRightValue = 100.0f;


}

void ANaveTerrestreEnemiga01::FireBala()
{
	bCanFire = true;
}
void ANaveTerrestreEnemiga01::BeginPlay()
{
	Super::BeginPlay();

	TotalTime = 60.0f;

	/*TimeSinceLastShot = 0.0f;*/

	RandomStart = FMath::Rand();

}

void ANaveTerrestreEnemiga01::Tick(float DeltaTime)
{
	// Spawn projectile at an offset from this pawn
	const FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);

	Current_Location = this->GetActorLocation();
	Current_Rotation = this->GetActorRotation();

	Current_Location.Y += FMath::Sin(TotalTime + RandomStart);
	Current_Location.X += FMath::Sin(TotalTime + RandomStart);

	this->SetActorLocation(Current_Location - (Current_Velocity * DeltaTime));

	//TotalTime += DeltaTime;

	TimeSinceLastShot += DeltaTime;
	// If it's ok to fire again

	//while (TotalTime <= 60) 
	//do {

		if (TimeSinceLastShot >= 1.0f) {
			if (bCanFire == true)
			{

				UWorld* const World = GetWorld();
				if (World != nullptr)
				{
					// spawn the projectile
					World->SpawnActor<AProyectilBala>(SpawnLocation, FireRotation);

				}
				World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &ANaveTerrestreEnemiga01::ShotTimerExpired, FireRate);
				bCanFire = true;

			}
			TimeSinceLastShot = 0.0f;
		}
	//} while (TotalTime <= 60);
	//TotalTime--;
	//}
}

void ANaveTerrestreEnemiga01::ShotTimerExpired()
{
	bCanFire = true;
}



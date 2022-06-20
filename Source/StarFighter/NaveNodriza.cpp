// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveNodriza.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/CollisionProfile.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ANaveNodriza::ANaveNodriza()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO"));

	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ShipMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	RootComponent = ShipMeshComponent;
	ShipMeshComponent->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	ShipMeshComponent->SetStaticMesh(ShipMesh.Object);


	TArray<AActor*> Instances;

	UGameplayStatics::GetAllActorsOfClass(GetWorld(),
		ANaveNodriza::StaticClass(), Instances);
	if (Instances.Num() > 1)
	{
		//If exist at least one of them, set the instance with the first found one
		Instance = Cast<ANaveNodriza>(Instances[0]);
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,
			FString::Printf(TEXT("%s Ya existe"),*Instance->GetName()));
		//Then Destroy this Actor
		Destroy();
	}

	// Movement
	MoveSpeed = 25.0f;


	// Weapon
	//GunOffset = FVector(90.f, 0.f, 0.f);
	FireRate = 10.0f;
	bCanFire = true;
}

// Called when the game starts or when spawned
void ANaveNodriza::BeginPlay()
{
	Super::BeginPlay();
	
}

void ANaveNodriza::FireBala()
{
	bCanFire = true;
}

// Called every frame
void ANaveNodriza::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	srand(time(NULL));


	const FVector MoveDirection = FVector(-10.0f, 0.0f, 0.0f).GetClampedToMaxSize(1.0f);

	const FVector Movement = MoveDirection * MoveSpeed * DeltaTime;

	if (Movement.SizeSquared() > 0.0f)
	{
		const FRotator NewRotation = Movement.Rotation();
		FHitResult Hit(1.f);
		RootComponent->MoveComponent(Movement, NewRotation, true, &Hit);
	}

	//Spawn projectile at an offset from this pawn



	const FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset = FVector(90.f, 0.f, 0.f));


	TimeSinceLastShot += DeltaTime;


	if (TimeSinceLastShot >= 1.0f) {
		if (bCanFire == true)
		{

			UWorld* const World = GetWorld();
			if (World != nullptr)
			{
				// spawn the projectile
				World->SpawnActor<AProyectilBala>(SpawnLocation, FireRotation);
				World->SpawnActor<AProyectilBala>(SpawnLocation + 50.0f , FireRotation);
				World->SpawnActor<AProyectilBala>(SpawnLocation + 100.0f, FireRotation);
				World->SpawnActor<AProyectilBala>(SpawnLocation + -50.0f, FireRotation);
				World->SpawnActor<AProyectilBala>(SpawnLocation + -100.0f, FireRotation);
			}
			World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &ANaveNodriza::ShotTimerExpired, FireRate);
			bCanFire = true;

		}
		TimeSinceLastShot = 0.0f;
	}
}


void ANaveNodriza::ShotTimerExpired()
{
	bCanFire = true;
}


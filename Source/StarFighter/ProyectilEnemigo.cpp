//// Fill out your copyright notice in the Description page of Project Settings.
//
//#include "ProyectilEnemigo.h"
//#include "Components/StaticMeshComponent.h"
//#include "Components/CapsuleComponent.h"
//
//// Sets default values
//AProyectilEnemigo::AProyectilEnemigo()
//{
// 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
//	PrimaryActorTick.bCanEverTick = true;
//
//	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
//
//	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Projectile Mesh"));
//	CapsuleCollision = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collision"));
//
//	ProjectileMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
//	CapsuleCollision->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
//
//	bHit = false;
//	bDestroy = false;
//
//
//}
//
//// Called when the game starts or when spawned
//void AProyectilEnemigo::BeginPlay()
//{
//	Super::BeginPlay();
//	CurrentLocation = this->GetActorLocation();
//
//	OnActorBeginOverlap.AddDynamic(this, &AProyectilEnemigo::OnBeginOverLap);
//
//	
//}
//
//// Called every frame
//void AProyectilEnemigo::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//}
//void AProyectilEnemigo::OnBeginOverLap(AActor* ProjectileActor, AActor* OtherActor)
//{
//}


//// Fill out your copyright notice in the Description page of Project Settings.
//
//
//#include "ProyectilEnemigo1.h"
//
//AProyectilEnemigo1::AProyectilEnemigo1()
//{
//	static ConstructorHelpers::FObjectFinder<UStaticMesh> ProjectileBalaMesh(TEXT("/Game/TwinStick/Meshes/Projectile2.Projectile2"));
//	ProjectileMesh->SetStaticMesh(ProjectileBalaMesh.Object);
//
//}
//
//void AProyectilEnemigo1::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//	FVector NewLocation = FVector(CurrentLocation.X + (ProjectileSpeed * DeltaTime), CurrentLocation.Y, CurrentLocation.Z);
//
//	this->SetActorLocation(NewLocation);
//	CurrentLocation = NewLocation;
//}

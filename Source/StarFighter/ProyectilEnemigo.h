//// Fill out your copyright notice in the Description page of Project Settings.
//
//#pragma once
//
//#include "CoreMinimal.h"
//#include "GameFramework/Actor.h"
//#include "ProyectilEnemigo.generated.h"
//
//class UStaticMeshComponent;
//class UCapsuleComponent;
//
//UCLASS()
//class STARFIGHTER_API AProyectilEnemigo : public AActor
//{
//	GENERATED_BODY()
//	
//public:	
//	// Sets default values for this actor's properties
//	AProyectilEnemigo();
//
//	UPROPERTY(EditAnywhere)
//		float ProjectileSpeed;
//
//	UFUNCTION()
//		void OnBeginOverLap(AActor* ProjectileActor, AActor* OtherActor);
//
//	FVector CurrentLocation;
//
//	bool bHit;
//	bool bDestroy;
//
//protected:
//	// Called when the game starts or when spawned
//	virtual void BeginPlay() override;
//
//	UPROPERTY(EditAnywhere)
//		UStaticMeshComponent* ProjectileMesh;
//
//	UPROPERTY(EditAnywhere)
//		UCapsuleComponent* CapsuleCollision;
//
//public:	
//	// Called every frame
//	virtual void Tick(float DeltaTime) override;
//
//};

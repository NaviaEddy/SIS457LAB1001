// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ConstellationBuilder.h"
#include "ConstructionEngineer.generated.h"

UCLASS()
class STARFIGHTER_API AConstructionEngineer : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AConstructionEngineer();
	
private:
	IConstellationBuilder* ConstellationBuilder;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	void ConstructConstellation();

	void SetConstellationBuilder(AActor* Builder);

	class AConstellation* GetConstellation();

};

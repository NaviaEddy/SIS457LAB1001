// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveAerea.h"
#include "InventoryComponent.h"
#include "NaveAereaJugador.generated.h"

/**
 * 
 */

UCLASS()
class STARFIGHTER_API ANaveAereaJugador : public ANaveAerea
{
	GENERATED_BODY()

		/** The camera */
		UPROPERTY(Category = Camera, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* CameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(Category = Camera, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;

public:
	ANaveAereaJugador();

	// Begin Actor Interface
	virtual void Tick(float DeltaSeconds) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	// End Actor Interface

	//**Proyectil

	void Fire();

	/* Fire a shot in the specified direction */
	void FireShot(FVector FireDirection);



	//ProyectilBala

	void FireBala();

	void FireShotBala(FVector FireDirection);


	//ProyectilBomba

	void FireBomba();

	void FireShotBomba(FVector FireDirection);



	/* Handler for the fire timer expiry */
	void ShotTimerExpired();



	/** Offset from the ships location to spawn projectiles */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		FVector GunOffset;

	/* How fast the weapon will fire */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		float FireRate;

	//Inventario<>
	UPROPERTY()
		UInventoryComponent* ShipInventory;

	UPROPERTY()
		TMap <FString, int32> ShipInfo;

	UFUNCTION()
		void TakeItem(AInventoryActor* InventoryItem);

	UFUNCTION()
		void DropItem();

	UFUNCTION()
		virtual void NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved,
			FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;
	
	void ShowInventory();


	/** Returns CameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetCameraComponent() const { return CameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }




private:

	/* Flag to control firing  */
	uint32 bCanFire : 1;

	/** Handle for efficient management of ShotTimerExpired timer */
	FTimerHandle TimerHandle_ShotTimerExpired;

	float FireForwardValue;
	float FireRightValue;

};

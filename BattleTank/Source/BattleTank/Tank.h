// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/Actor.h"
#include "TankAimingComponent.h"
#include "Tank.generated.h"

class AProjectile;
class UTankkBarrel;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UTankAimingComponent* TankAimingComponenent = nullptr;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	AActor* CurrentTarget = nullptr;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UFUNCTION(BlueprintCallable, Category = Setup) void SetBarrelReference(UTankkBarrel* BarrelToSet);
	UFUNCTION(BlueprintCallable, Category = Setup) void SetTurrettReference(UTankTurret* TurretToSet);
	UFUNCTION(BlueprintCallable, Category = Setup) void Fire();
	void AimAt(FVector TargetLocation);
	UPROPERTY(EditDefaultsOnly, Category = Firing) float LaunchSpeed = 4000; 
	UPROPERTY(EditDefaultsOnly, Category = Setup) TSubclassOf<AProjectile> ProjectileBlueprint = nullptr;
	UTankkBarrel* Barrel = nullptr; // local barrel reference
	UPROPERTY(EditDefaultsOnly, Category = Firing)float ReloadTime = 3.0f;
	double lastfiretime = 0;
};

// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "Engine/World.h"
#include "TankkBarrel.h"
#include "Projectile.h"
#include "UObject/UObjectGlobals.h"

// Sets default values

ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TankAimingComponenent = CreateDefaultSubobject<UTankAimingComponent>(FName("TankAimingComponent"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::SetBarrelReference(UTankkBarrel* BarrelToSet)
{
	TankAimingComponenent->SetBarrelReference(BarrelToSet);
	Barrel = BarrelToSet;
}

void ATank::AimAt(FVector TargetLocation)
{
	TankAimingComponenent->AimAt(TargetLocation, LaunchSpeed);
}

void ATank::SetTurrettReference(UTankTurret* TurretToSet)
{
	TankAimingComponenent->SetTurretReference(TurretToSet);


}

void ATank::Fire()
{
	bool isReloaded = FPlatformTime::Seconds() - lastfiretime > ReloadTime;
	if (Barrel&&isReloaded) {
		AProjectile* projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, Barrel->GetSocketLocation(FName("Projectile")), Barrel->GetSocketRotation(FName("Projectile")));
		projectile->LaunchProjectile(LaunchSpeed, CurrentTarget);
		lastfiretime = FPlatformTime::Seconds();
	}
}

// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "TankkBarrel.h"
#include "TankTurret.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts


void UTankAimingComponent::SetBarrelReference(UTankkBarrel * BarrelToSet)
{
	if(BarrelToSet) Barrel = BarrelToSet;
}

void UTankAimingComponent::SetTurretReference(UTankTurret* TurretToSet) {
	if(TurretToSet) Turret = TurretToSet;
}

void UTankAimingComponent::AimAt(FVector target, float LaunchSpeed)
{

	FVector ProjectileVelocity, FiringLocation = Barrel->GetSocketLocation(FName("Projectile"));

	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity
	(
		this,
		ProjectileVelocity,
		FiringLocation,
		target,
		LaunchSpeed,
		false,
		0.0f,
		0.0f,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);
	if (bHaveAimSolution)
	{
		FVector AimDirection = ProjectileVelocity.GetSafeNormal();
		MoveBarrel(AimDirection);
		MoveTurret(AimDirection);
		float time = GetWorld()->GetTimeSeconds();
	}
}

void UTankAimingComponent::MoveBarrel(FVector AimDirection)
{
	FRotator CurrentDirection = Barrel->GetForwardVector().Rotation();
	FRotator AimDirectionRotator = AimDirection.Rotation();
	FRotator DeltaRotator = AimDirectionRotator - CurrentDirection;
	// TODO fix rotation around 0.
	Barrel->Elevate(DeltaRotator.Pitch);


}

void UTankAimingComponent::MoveTurret(FVector AimDirection)
{
	FRotator CurrentDirection = Turret->GetForwardVector().Rotation();
	FRotator AimDirectionRotator = AimDirection.Rotation();
	FRotator DeltaRotator = AimDirectionRotator - CurrentDirection;
	if(Turret)
	Turret->Rotate(DeltaRotator.Yaw);


}
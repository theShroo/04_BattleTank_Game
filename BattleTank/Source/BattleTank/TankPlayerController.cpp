// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Player Controller Begin Play"));
	ATank* player = GetControlledTank();
	if (player) {
		UE_LOG(LogTemp, Warning, TEXT("Player Controller on %s"), *(player->GetName()));

	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Player Controller Failed to find owner"));

	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardCrosshair();
}

void ATankPlayerController::AimTowardCrosshair()
{
	if (!GetControlledTank()) { return; }
	FVector Hitlocation;
	if (GetSightRayHitLocation(Hitlocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), *(Hitlocation.ToString()));
	}
	
}

bool ATankPlayerController::GetSightRayHitLocation(FVector & OUTHitLocation) const
{
	FRotator Rotation;
	FVector Position;

	GetControlledTank()->GetActorEyesViewPoint(Position, Rotation);

	FVector Target = Position + Rotation.Vector()*10000.0f;

	FHitResult Hit;
	bool result = GetWorld()->LineTraceSingleByObjectType(
		Hit,
		Position,
		Target,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		FCollisionQueryParams(FName(TEXT("")), true, this)
	);
	OUTHitLocation = Hit.ImpactPoint;
	return true;
}

ATank* ATankPlayerController::GetControlledTank() const 
{
	return Cast<ATank>(GetPawn());
}
// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Tank.h"


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
		GetControlledTank()->AimAt(Hitlocation);
	}
	
}

bool ATankPlayerController::GetSightRayHitLocation(FVector & OUTHitLocation) const
{

	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D Screenlocation = FVector2D(ViewportSizeX * CrosshairXPosition, ViewportSizeY * CrosshairYPosition);

	FVector LookDirection, Position;
	GetLookDirection(Screenlocation, LookDirection, Position);

	FHitResult Hit;
	GetWorld()->LineTraceSingleByChannel(
		Hit,
		PlayerCameraManager->GetCameraLocation(),
		PlayerCameraManager->GetCameraLocation()+(LookDirection*1000000.0f),
		ECollisionChannel::ECC_Visibility
	);
	OUTHitLocation = Hit.Location;
	ATank* tank = GetControlledTank();
	if (Hit.Actor != nullptr)
	{
		tank->CurrentTarget = Hit.Actor.Get();
		return true;
	}
	tank->CurrentTarget = nullptr;
	return false;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector &LookDirection, FVector& Position) const
{
	return DeprojectScreenPositionToWorld
	(
		ScreenLocation.X,
		ScreenLocation.Y,
		Position,
		LookDirection
	);
}

ATank* ATankPlayerController::GetControlledTank() const 
{
	return Cast<ATank>(GetPawn());
}
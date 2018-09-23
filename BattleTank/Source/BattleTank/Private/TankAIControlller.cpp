// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIControlller.h"
#include "Tank.h"


void ATankAIControlller::BeginPlay()
{
	Super::BeginPlay();
	ATank* Self = GetControlledTank();
	if (Self) {
		UE_LOG(LogTemp, Warning, TEXT("AI Controller on %s"), *(Self->GetName()));

	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI Controller Failed to find owner"));

	}
	ATank* Target = GetPlayerTank();
	if (Target) {
		UE_LOG(LogTemp, Warning, TEXT("AI Controller Targeting %s"), *(Target->GetName()));

	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI Controller Failed to find target"));

	}
}

void ATankAIControlller::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!GetPlayerTank()) { return; }
	GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

}

ATank* ATankAIControlller::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIControlller::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

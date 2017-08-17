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

ATank* ATankPlayerController::GetControlledTank() const 
{
	return Cast<ATank>(GetPawn());
}
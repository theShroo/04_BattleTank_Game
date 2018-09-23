// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIControlller.h"
#include "Tank.h"


void ATankAIControlller::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIControlller::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ATank* PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (!PlayerTank) { return; }
	Cast<ATank>(GetPawn())->AimAt(PlayerTank->GetActorLocation());
	Cast<ATank>(GetPawn())->Fire();
}

// Fill out your copyright notice in the Description page of Project Settings.

#include "TankkBarrel.h"
#include "Engine/World.h"



void UTankkBarrel::Elevate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	float ElevationChange = MaxDegreesPerSecond * RelativeSpeed * GetWorld()->GetDeltaSeconds();
	float RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	float Elevation = FMath::Clamp<float>(RawNewElevation, MinElevation, MaxElevation);
	SetRelativeRotation(FRotator(Elevation,0,0));
}

